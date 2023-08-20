#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "mainwindow.h"

#include <mainwindow.h>

//Author : Danny Cowles

adminLogin::adminLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);

}

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::on_mainMenuButton_clicked()
{
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
    this->hide();
}

void adminLogin::on_submitButton_clicked()
{
    //sets "key", correct credentials to open admin tools
    QString userNameKey = "admin";
    QString passwordKey = "password";

    //retrieves user input from username and password boxes
    QString userNameInput = ui->usernameBox->text();
    QString passwordInput = ui->passwordBox->text();

    //checks if the input matches the key
    if (userNameInput == userNameKey && passwordInput == passwordKey)
    {

        adminTools* admin = new adminTools;
        admin->setWindowTitle("Maintenance");
        admin->show();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password!");

    }
}

