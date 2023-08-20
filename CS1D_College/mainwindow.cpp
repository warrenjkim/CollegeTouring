#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "traversals.h"
#include "adminlogin.h"
#include "admintools.h"

#include <unordered_map>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    collegeModel  = new QSqlQueryModel;
    souvenirModel = new QStringListModel;
    infoModel     = new QSqlQueryModel;
    traversalWindow = new traversals;
    adminWindow = new adminTools;
    path = "..\\CS1D_College\\college.db";
    souvenirComboBox = 0;

#if __APPLE__ && TARGET_OS_MAC
        path = "../../../../CS1D_College/college.db";
#elif __linux__
        path = "../CS1D_College/college.db";
#else
        path = "..\\CS1D_College\\college.db";
#endif

    database dataBaseBuild(path);
    //dataBaseBuild.resetWithFile();
    this->db = &dataBaseBuild;

    updateCollegeList(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete collegeModel;
    delete souvenirModel;
    delete infoModel;
    db->deleteAllColleges();
}

//
void MainWindow::updateCollegeList(bool sortByDistance) {
    QString sort = sortByDistance ? "DISTANCES" : "NAME";
    collegeModel->setQuery("SELECT NAME, STATE FROM COLLEGES ORDER BY " + sort);

    // college model is updated
    ui->CollegeModelList->setModel(collegeModel);

}

// When a college is selected from the college TableView the cooresponding souvenirs, undergrads and state are displayed on a differet tableView
void MainWindow::on_CollegeModelList_clicked(const QModelIndex &index)
{
    std::vector<Souvenir> souvenirList;
    QStringList itemText;

    // Gets Name of college selected from the List View
    collegeName = index.siblingAtColumn(0).data().toString();

    if(ui->souvenirOrDistComboBox->itemText(souvenirComboBox) == QString("Souvenirs")){

        // Copies the souvenir vectore from the college database for the selected college
        souvenirList = db->getCollegeByName(collegeName).souvenirs();

        // Loops through all souvenirs of selected college and adds them to the Souvenir Model
        for(size_t index = 0; index < souvenirList.size(); index++){

       QString nameBuffer = souvenirList[index].name();
       while(nameBuffer.length() < 45){
            nameBuffer = nameBuffer + " ";
       }

        itemText << nameBuffer + "$ " + QString::number(souvenirList[index].price()) + "\t\t\t\t\t";

        souvenirModel->setStringList(itemText);

//        // Souvenir model List is updated
//        ui->SouvenirModelList->setModel(souvenirModel);
        }
    }
    else if (ui->souvenirOrDistComboBox->itemText(souvenirComboBox) == QString("Distances")) {

        // Copies the souvenir vectore from the college database for the selected college
//        map::unordered_map<QString, float> distList(db->getCollegeByName(collegeName).distances());
        map::unordered_map<QString, float> distList = db->getCollegeByName(collegeName).distances();

        // map iterator created
        // iterator pointing to start of map
        auto it = distList.begin();
        //map::unordered_map<QString, float>::iterator it = distList.begin();

        // Loops through all souvenirs of selected college and adds them to the Souvenir Model
        // Iterating over the map using Iterator till map end.
            while (it != distList.end())
            {
                // Accessing the key
//                std::string word = it->first;
                itemText << it->first + "\n" + QString::number(it->second) + " Miles";

                 souvenirModel->setStringList(itemText);
                // Accessing the value
//                int count = it->second;

                // iterator incremented to point next item
                it++;
            }
    }

    // Souvenir model List is updated
    ui->SouvenirModelList->setModel(souvenirModel);

    // Resizes TableView Columns to fit
    ui->SouvenirModelList->resizeColumnsToContents();

    // Info model List is updated (State, Distances, Undergraduates)
    infoModel->setQuery("SELECT STATE, UNDERGRADS, DISTANCES FROM COLLEGES WHERE NAME =\"" + collegeName + "\"");
    ui->InfoModelList->setModel(infoModel);

    selectedCollege = index;
}
void MainWindow::on_goToTraversalsButton_clicked()
{
    traversalWindow->show();
    this->hide();
    delete ui;
}

void MainWindow::on_actionLogin_triggered()
{
    adminLogin* admin = new adminLogin;
    admin->setWindowTitle("Admin Login");
    admin->show();
    this->hide();
    delete ui;
}


void MainWindow::on_sortByNameCheckBox_toggled(bool checked)
{
    if(checked)
        MainWindow::updateCollegeList(0);
    else
        MainWindow::updateCollegeList(1);

    sortByName = checked;
}

void MainWindow::on_souvenirOrDistComboBox_currentIndexChanged(int index)
{
    souvenirComboBox = index;
    on_CollegeModelList_clicked(selectedCollege);
}

void MainWindow::on_sortByStateCheckBox_toggled(bool checked)
{
    if(checked && sortByName == false){
        collegeModel->setQuery("SELECT NAME FROM COLLEGES WHERE STATE =\"California\"");
        ui->CollegeModelList->setModel(collegeModel);
    }
    else if(checked && sortByName == true){
        collegeModel->setQuery("SELECT NAME FROM COLLEGES WHERE STATE =\"California\" ORDER BY NAME");
        ui->CollegeModelList->setModel(collegeModel);
    }
}

