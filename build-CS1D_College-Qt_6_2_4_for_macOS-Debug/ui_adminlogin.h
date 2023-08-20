/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminLogin
{
public:
    QLineEdit *usernameBox;
    QLineEdit *passwordBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *mainMenuButton;
    QPushButton *submitButton;

    void setupUi(QWidget *adminLogin)
    {
        if (adminLogin->objectName().isEmpty())
            adminLogin->setObjectName(QString::fromUtf8("adminLogin"));
        adminLogin->resize(436, 315);
        adminLogin->setMouseTracking(true);
        usernameBox = new QLineEdit(adminLogin);
        usernameBox->setObjectName(QString::fromUtf8("usernameBox"));
        usernameBox->setGeometry(QRect(180, 140, 113, 24));
        passwordBox = new QLineEdit(adminLogin);
        passwordBox->setObjectName(QString::fromUtf8("passwordBox"));
        passwordBox->setEnabled(true);
        passwordBox->setGeometry(QRect(180, 180, 113, 24));
        passwordBox->setFocusPolicy(Qt::StrongFocus);
        passwordBox->setEchoMode(QLineEdit::Password);
        label = new QLabel(adminLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 140, 71, 16));
        label_2 = new QLabel(adminLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 180, 60, 16));
        label_3 = new QLabel(adminLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 281, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        label_3->setFont(font);
        mainMenuButton = new QPushButton(adminLogin);
        mainMenuButton->setObjectName(QString::fromUtf8("mainMenuButton"));
        mainMenuButton->setGeometry(QRect(280, 280, 141, 24));
        submitButton = new QPushButton(adminLogin);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(180, 220, 111, 24));
        submitButton->setMouseTracking(true);
        submitButton->setCheckable(false);
        submitButton->setAutoDefault(true);

        retranslateUi(adminLogin);

        QMetaObject::connectSlotsByName(adminLogin);
    } // setupUi

    void retranslateUi(QWidget *adminLogin)
    {
        adminLogin->setWindowTitle(QCoreApplication::translate("adminLogin", "Form", nullptr));
        usernameBox->setText(QString());
        passwordBox->setText(QString());
        label->setText(QCoreApplication::translate("adminLogin", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("adminLogin", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("adminLogin", "ADMIN LOGIN", nullptr));
        mainMenuButton->setText(QCoreApplication::translate("adminLogin", "Return to Main Menu", nullptr));
        submitButton->setText(QCoreApplication::translate("adminLogin", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminLogin: public Ui_adminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
