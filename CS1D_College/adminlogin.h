#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include "admintools.h"

#include <QMessageBox>
#include <QWidget>

// Author : Danny Cowles

namespace Ui {
class adminLogin;
}

///
/// \brief The adminLogin class consists of the username & password login system to access the maintenace tools
///
class adminLogin : public QWidget
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = nullptr);

    ///
    /// \brief destructor
    ///
    ~adminLogin();

private slots:
    ///
    /// \brief returns user to the main menu screen
    ///
    void on_mainMenuButton_clicked();

    ///
    /// \brief once user has entered credentials and presses the submit button, if the credentials match admin set
    ///        username and password, they are logged into the maintenance screen
    ///
    void on_submitButton_clicked();

private:
    Ui::adminLogin *ui;
};

#endif // ADMINLOGIN_H
