#include "admintools.h"
#include "ui_admintools.h"

#include <mainwindow.h>

//Author : Danny Cowles

adminTools::adminTools(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminTools)
{
    ui->setupUi(this);

    QString path;

#if __APPLE__ && TARGET_OS_MAC
        path = "../../../../CS1D_College/college.db";
#elif __linux__
        path = "../CS1D_College/college.db";
#else
        path = "..\\CS1D_College\\college.db";
#endif

    db = new database(path);

    //retrieves database information and stores in a map
    colleges = db->getColleges();

    //retrieves the college that is currently selected in the name combo box
    collegeModify = db->getCollegeByName(ui->collegeNameEditBox->currentText());

    //clears the name combo box
    ui->collegeNameEditBox->clear();

    QString collegeName;

    //code to set edit name combo box to hold all current college names
    for (auto& x : colleges)
    {
        collegeName = x.second.name();

        ui->collegeNameEditBox->addItem(collegeName);
    }

    if (colleges.size() == 13)
    {
        ui->addCollegesButton->hide();
    }
    else
    {
        ui->addCollegesButton->show();
    }
}

adminTools::~adminTools()
{
    delete ui;
    delete db;
}

void adminTools::on_addButton_clicked()
{
    //bool var to hold whether the input information is in acceptable format (both name and price are entered)
    bool valid;

    //retrieves current souvenirs from the college being modified
    std::vector<Souvenir> souvenirs = collegeModify.souvenirs();

    //college can have max 7 souvenirs, so check the size of the vector to see how many items there are
    if (souvenirs.size() == 7)
    {
        QMessageBox::critical(this, "Could not add souvenir", "Maximum number of souvenirs reached");
        return;
    }
    else
    {
        valid = true;
    }

    //ensures that a valid name and price are entered
    if (ui->newSouvenirName->text() == "")
    {
        QMessageBox::critical(this, "Error", "Please enter a valid name");
        valid = false;
    }
    else if (ui->newPriceBox->value() == 0)
    {
        QMessageBox::critical(this, "Error", "Please enter a valid price");
        valid = false;
    }

    if (valid)
    {
        //adds new souvenir to the current college and updates the db to allow changes to persist
        collegeModify.addSouvenir(ui->newSouvenirName->text(),ui->newPriceBox->value());
        db->updateCollege(collegeModify);
    }

    //calls method to update combo boxes after addition of a souvenir
    on_collegeNameEditBox_currentIndexChanged(0);

    //clears name and price selections, for future additions
    ui->newSouvenirName->clear();
    ui->newPriceBox->clear();

}

void adminTools::on_collegeNameEditBox_currentIndexChanged(int index)
{
    //retrieves the new college being modified as the user selects a new college from the combo box
    collegeModify = db->getCollegeByName(ui->collegeNameEditBox->currentText());

    //retrieves current souvenirs from the college being modified
    std::vector<Souvenir> souvenirs = collegeModify.souvenirs();

    //clears combo boxes holding souvenir information, ensures deletions, additions, and price changes persist;
    ui->deleteComboBox->clear();
    ui->updateNameComboBox->clear();

    //setting up contents of souvenir information on the delete combo box
    for (size_t i = 0; i < souvenirs.size(); i++)
    {
        ui->deleteComboBox->addItem(souvenirs[i].name() + " - $" + QString::number(souvenirs[i].price()));
    }

    //setting up contents of name information on the
    for (size_t i = 0; i < souvenirs.size(); i++)
    {
        ui->updateNameComboBox->addItem(souvenirs[i].name());
    }

}

void adminTools::on_deleteButton_clicked()
{

    //retrieves the name of the souvenir the user would like to delete
    QString souvenirDeletion = ui->deleteComboBox->currentText();

    //splits the string by the "-"  (ex. format name - $price)
    //list[0] = name
    //list[1] = price
    QStringList list = souvenirDeletion.split(" - ");

    //deletes the requrested souvenir from the current college
    collegeModify.deleteSouvenir(list[0]);

    //updates db to allow for persistence
    db->updateCollege(collegeModify);

    //calls method to update combo boxes after deletion of a souvenir
    on_collegeNameEditBox_currentIndexChanged(0);

}


void adminTools::on_updateNameComboBox_currentIndexChanged(int index)
{
    //retrieves current souvenirs from the college being modified
    std::vector<Souvenir> souvenirs = collegeModify.souvenirs();

    //sets the spin box to hold the price of the currently selected souvenir
    ui->updatePriceSpinBox->setValue(souvenirs[index].price());
}


void adminTools::on_updatePriceButton_clicked()
{
    //retrieves current souvenirs from the college being modified
    std::vector<Souvenir> souvenirs = collegeModify.souvenirs();

    //stores the value of the price spin box
    float updatePrice = ui->updatePriceSpinBox->value();

    //if the user spams the update button, there is no need to update the price if it will be the same, so only update price if the spin box holds a different value than the current price
    if (souvenirs[ui->updateNameComboBox->currentIndex()].price() != updatePrice)
    {
        //changes the price of the currently selected souvenir to the price given in the spin box
        collegeModify.setPrice(ui->updateNameComboBox->currentText(), updatePrice);

        //updates db to allow for persistence
        db->updateCollege(collegeModify);

        //calls method to update combo boxes after changing the price of a souvenir
        on_collegeNameEditBox_currentIndexChanged(0);
    }

}

void adminTools::on_returnButton_clicked()
{
    //closes maintenance ui screen, returns user to the login screen
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
    hide();
}


void adminTools::on_addCollegesButton_clicked()
{
    //adds new colleges from new files if they havent already been added
    db->addAdminColleges();

    QMessageBox::information(this, "College Add Message", "Success! The new colleges have been added to the database");

    //on_collegeNameEditBox_currentIndexChanged(0);

    ui->addCollegesButton->hide();

    //clears the name combo box
    ui->collegeNameEditBox->clear();

    QString collegeName;

    colleges = db->getColleges();

    //code to set edit name combo box to hold all current college names
    for (auto& x : colleges)
    {
        collegeName = x.second.name();

        ui->collegeNameEditBox->addItem(collegeName);
    }
}

