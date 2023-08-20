/********************************************************************************
** Form generated from reading UI file 'admintools.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINTOOLS_H
#define UI_ADMINTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminTools
{
public:
    QFrame *frame_4;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLabel *label_7;
    QComboBox *updateNameComboBox;
    QLabel *label_8;
    QDoubleSpinBox *updatePriceSpinBox;
    QPushButton *updatePriceButton;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *newSouvenirName;
    QLabel *label_5;
    QDoubleSpinBox *newPriceBox;
    QPushButton *addButton;
    QFrame *frame_3;
    QLabel *label_6;
    QComboBox *deleteComboBox;
    QPushButton *deleteButton;
    QFrame *frame;
    QLabel *label;
    QComboBox *collegeNameEditBox;
    QPushButton *addCollegesButton;
    QLabel *label_9;
    QPushButton *returnButton;

    void setupUi(QWidget *adminTools)
    {
        if (adminTools->objectName().isEmpty())
            adminTools->setObjectName(QString::fromUtf8("adminTools"));
        adminTools->resize(800, 600);
        adminTools->setWindowOpacity(100.000000000000000);
        frame_4 = new QFrame(adminTools);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(400, 220, 281, 141));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Sunken);
        frame_4->setLineWidth(2);
        frame_4->setMidLineWidth(3);
        formLayout_2 = new QFormLayout(frame_4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, label_2);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        updateNameComboBox = new QComboBox(frame_4);
        updateNameComboBox->setObjectName(QString::fromUtf8("updateNameComboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, updateNameComboBox);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        updatePriceSpinBox = new QDoubleSpinBox(frame_4);
        updatePriceSpinBox->setObjectName(QString::fromUtf8("updatePriceSpinBox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, updatePriceSpinBox);

        updatePriceButton = new QPushButton(frame_4);
        updatePriceButton->setObjectName(QString::fromUtf8("updatePriceButton"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, updatePriceButton);

        frame_2 = new QFrame(adminTools);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 220, 261, 141));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(2);
        frame_2->setMidLineWidth(3);
        formLayout = new QFormLayout(frame_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_3);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        newSouvenirName = new QLineEdit(frame_2);
        newSouvenirName->setObjectName(QString::fromUtf8("newSouvenirName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, newSouvenirName);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        newPriceBox = new QDoubleSpinBox(frame_2);
        newPriceBox->setObjectName(QString::fromUtf8("newPriceBox"));
        newPriceBox->setMaximum(1000.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, newPriceBox);

        addButton = new QPushButton(frame_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, addButton);

        frame_3 = new QFrame(adminTools);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 390, 261, 111));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Sunken);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(3);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 5, 241, 21));
        deleteComboBox = new QComboBox(frame_3);
        deleteComboBox->setObjectName(QString::fromUtf8("deleteComboBox"));
        deleteComboBox->setGeometry(QRect(10, 30, 241, 24));
        deleteButton = new QPushButton(frame_3);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(10, 70, 241, 24));
        frame = new QFrame(adminTools);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 100, 661, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(2);
        frame->setMidLineWidth(3);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 281, 16));
        collegeNameEditBox = new QComboBox(frame);
        collegeNameEditBox->setObjectName(QString::fromUtf8("collegeNameEditBox"));
        collegeNameEditBox->setGeometry(QRect(20, 40, 281, 24));
        addCollegesButton = new QPushButton(adminTools);
        addCollegesButton->setObjectName(QString::fromUtf8("addCollegesButton"));
        addCollegesButton->setGeometry(QRect(400, 390, 281, 31));
        label_9 = new QLabel(adminTools);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 20, 621, 71));
        QFont font;
        font.setPointSize(48);
        font.setBold(true);
        label_9->setFont(font);
        returnButton = new QPushButton(adminTools);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(520, 510, 161, 31));

        retranslateUi(adminTools);

        QMetaObject::connectSlotsByName(adminTools);
    } // setupUi

    void retranslateUi(QWidget *adminTools)
    {
        adminTools->setWindowTitle(QCoreApplication::translate("adminTools", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("adminTools", "Change Souvenir Price", nullptr));
        label_7->setText(QCoreApplication::translate("adminTools", "Name", nullptr));
        label_8->setText(QCoreApplication::translate("adminTools", "Price", nullptr));
        updatePriceButton->setText(QCoreApplication::translate("adminTools", "Update Price", nullptr));
        label_3->setText(QCoreApplication::translate("adminTools", "Add New Souvenir", nullptr));
        label_4->setText(QCoreApplication::translate("adminTools", "Name", nullptr));
        label_5->setText(QCoreApplication::translate("adminTools", "Price", nullptr));
        addButton->setText(QCoreApplication::translate("adminTools", "Add", nullptr));
        label_6->setText(QCoreApplication::translate("adminTools", "Delete Souvenirs", nullptr));
        deleteButton->setText(QCoreApplication::translate("adminTools", "Delete", nullptr));
        label->setText(QCoreApplication::translate("adminTools", "Select a college to edit:", nullptr));
        addCollegesButton->setText(QCoreApplication::translate("adminTools", "Add New Colleges", nullptr));
        label_9->setText(QCoreApplication::translate("adminTools", "Maintenance Tools", nullptr));
        returnButton->setText(QCoreApplication::translate("adminTools", "Return to Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminTools: public Ui_adminTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINTOOLS_H
