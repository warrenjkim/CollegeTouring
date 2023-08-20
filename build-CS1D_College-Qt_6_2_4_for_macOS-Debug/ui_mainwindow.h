/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QWidget *centralwidget;
    QTableView *CollegeModelList;
    QLabel *CollegeLabel;
    QTableView *SouvenirModelList;
    QLabel *CollegeLabel_2;
    QLabel *CollegeLabel_3;
    QTableView *InfoModelList;
    QPushButton *pushButton_3;
    QPushButton *goToTraversalsButton;
    QPushButton *pushButton_5;
    QSpinBox *spinBox;
    QCheckBox *sortByNameCheckBox;
    QComboBox *comboBox;
    QCheckBox *sortByStateCheckBox;
    QComboBox *souvenirOrDistComboBox;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExit;
    QMenu *menuLogin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 198, 220);"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CollegeModelList = new QTableView(centralwidget);
        CollegeModelList->setObjectName(QString::fromUtf8("CollegeModelList"));
        CollegeModelList->setGeometry(QRect(30, 60, 221, 321));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CollegeModelList->sizePolicy().hasHeightForWidth());
        CollegeModelList->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        font.setPointSize(11);
        CollegeModelList->setFont(font);
        CollegeModelList->setFocusPolicy(Qt::NoFocus);
        CollegeModelList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(0, 0, 139);\n"
"selection-color: rgb(255, 255, 255);"));
        CollegeModelList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        CollegeModelList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        CollegeModelList->setAutoScroll(false);
        CollegeModelList->setAutoScrollMargin(5);
        CollegeModelList->setDragDropOverwriteMode(false);
        CollegeModelList->setAlternatingRowColors(true);
        CollegeModelList->setSelectionMode(QAbstractItemView::SingleSelection);
        CollegeModelList->setSelectionBehavior(QAbstractItemView::SelectRows);
        CollegeModelList->setShowGrid(false);
        CollegeModelList->setGridStyle(Qt::SolidLine);
        CollegeModelList->setSortingEnabled(false);
        CollegeModelList->horizontalHeader()->setVisible(false);
        CollegeModelList->horizontalHeader()->setMinimumSectionSize(50);
        CollegeModelList->horizontalHeader()->setDefaultSectionSize(200);
        CollegeModelList->verticalHeader()->setVisible(false);
        CollegeModelList->verticalHeader()->setHighlightSections(true);
        CollegeLabel = new QLabel(centralwidget);
        CollegeLabel->setObjectName(QString::fromUtf8("CollegeLabel"));
        CollegeLabel->setGeometry(QRect(30, 20, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setPointSize(14);
        CollegeLabel->setFont(font1);
        CollegeLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 198, 220);\n"
"color: rgb(0, 0, 0);"));
        CollegeLabel->setAlignment(Qt::AlignCenter);
        SouvenirModelList = new QTableView(centralwidget);
        SouvenirModelList->setObjectName(QString::fromUtf8("SouvenirModelList"));
        SouvenirModelList->setGeometry(QRect(350, 170, 291, 211));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SouvenirModelList->sizePolicy().hasHeightForWidth());
        SouvenirModelList->setSizePolicy(sizePolicy1);
        SouvenirModelList->setFont(font);
        SouvenirModelList->setFocusPolicy(Qt::NoFocus);
        SouvenirModelList->setAutoFillBackground(true);
        SouvenirModelList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(0, 0, 139);\n"
"selection-color: rgb(255, 255, 255);"));
        SouvenirModelList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SouvenirModelList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        SouvenirModelList->setAutoScroll(false);
        SouvenirModelList->setAutoScrollMargin(5);
        SouvenirModelList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        SouvenirModelList->setDragDropOverwriteMode(false);
        SouvenirModelList->setAlternatingRowColors(true);
        SouvenirModelList->setSelectionMode(QAbstractItemView::SingleSelection);
        SouvenirModelList->setSelectionBehavior(QAbstractItemView::SelectRows);
        SouvenirModelList->setShowGrid(false);
        SouvenirModelList->setWordWrap(true);
        SouvenirModelList->horizontalHeader()->setVisible(false);
        SouvenirModelList->horizontalHeader()->setMinimumSectionSize(50);
        SouvenirModelList->horizontalHeader()->setDefaultSectionSize(200);
        SouvenirModelList->verticalHeader()->setVisible(false);
        CollegeLabel_2 = new QLabel(centralwidget);
        CollegeLabel_2->setObjectName(QString::fromUtf8("CollegeLabel_2"));
        CollegeLabel_2->setGeometry(QRect(350, 20, 71, 31));
        CollegeLabel_2->setFont(font1);
        CollegeLabel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 198, 220);\n"
"color: rgb(0, 0, 0);"));
        CollegeLabel_2->setAlignment(Qt::AlignCenter);
        CollegeLabel_3 = new QLabel(centralwidget);
        CollegeLabel_3->setObjectName(QString::fromUtf8("CollegeLabel_3"));
        CollegeLabel_3->setGeometry(QRect(470, 20, 141, 31));
        CollegeLabel_3->setFont(font1);
        CollegeLabel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 198, 220);\n"
"color: rgb(0, 0, 0);"));
        CollegeLabel_3->setAlignment(Qt::AlignCenter);
        InfoModelList = new QTableView(centralwidget);
        InfoModelList->setObjectName(QString::fromUtf8("InfoModelList"));
        InfoModelList->setGeometry(QRect(350, 60, 281, 31));
        sizePolicy.setHeightForWidth(InfoModelList->sizePolicy().hasHeightForWidth());
        InfoModelList->setSizePolicy(sizePolicy);
        InfoModelList->setFont(font);
        InfoModelList->setFocusPolicy(Qt::NoFocus);
        InfoModelList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(225, 225, 225);\n"
"selection-color: rgb(0, 0, 0);"));
        InfoModelList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        InfoModelList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        InfoModelList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        InfoModelList->setAutoScroll(false);
        InfoModelList->setAutoScrollMargin(5);
        InfoModelList->setDragDropOverwriteMode(false);
        InfoModelList->setAlternatingRowColors(true);
        InfoModelList->setSelectionMode(QAbstractItemView::SingleSelection);
        InfoModelList->setSelectionBehavior(QAbstractItemView::SelectRows);
        InfoModelList->setShowGrid(false);
        InfoModelList->setGridStyle(Qt::SolidLine);
        InfoModelList->setSortingEnabled(false);
        InfoModelList->horizontalHeader()->setVisible(false);
        InfoModelList->horizontalHeader()->setMinimumSectionSize(50);
        InfoModelList->horizontalHeader()->setDefaultSectionSize(200);
        InfoModelList->verticalHeader()->setVisible(false);
        InfoModelList->verticalHeader()->setHighlightSections(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 460, 219, 30));
        pushButton_3->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift")});
        font2.setPointSize(11);
        font2.setBold(false);
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);"));
        pushButton_3->setAutoDefault(true);
        pushButton_3->setFlat(false);
        goToTraversalsButton = new QPushButton(centralwidget);
        goToTraversalsButton->setObjectName(QString::fromUtf8("goToTraversalsButton"));
        goToTraversalsButton->setGeometry(QRect(380, 510, 219, 30));
        goToTraversalsButton->setMaximumSize(QSize(16777215, 30));
        goToTraversalsButton->setFont(font2);
        goToTraversalsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);"));
        goToTraversalsButton->setAutoDefault(true);
        goToTraversalsButton->setFlat(false);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(660, 300, 111, 30));
        pushButton_5->setMaximumSize(QSize(16777215, 30));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);"));
        pushButton_5->setAutoDefault(true);
        pushButton_5->setFlat(false);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(660, 240, 51, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift")});
        font3.setPointSize(10);
        spinBox->setFont(font3);
        spinBox->setFocusPolicy(Qt::WheelFocus);
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(225, 225, 225);\n"
""));
        spinBox->setFrame(true);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setReadOnly(false);
        spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinBox->setKeyboardTracking(true);
        spinBox->setProperty("showGroupSeparator", QVariant(false));
        spinBox->setMinimum(1);
        spinBox->setMaximum(100);
        spinBox->setValue(1);
        sortByNameCheckBox = new QCheckBox(centralwidget);
        sortByNameCheckBox->setObjectName(QString::fromUtf8("sortByNameCheckBox"));
        sortByNameCheckBox->setGeometry(QRect(40, 400, 151, 19));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(187, 198, 220, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(159, 11, 25, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        sortByNameCheckBox->setPalette(palette);
        sortByNameCheckBox->setFont(font);
        sortByNameCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(187, 198, 220);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(, 11, 25);\n"
""));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 460, 191, 31));
        comboBox->setFont(font1);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        sortByStateCheckBox = new QCheckBox(centralwidget);
        sortByStateCheckBox->setObjectName(QString::fromUtf8("sortByStateCheckBox"));
        sortByStateCheckBox->setGeometry(QRect(40, 430, 151, 19));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        sortByStateCheckBox->setPalette(palette1);
        sortByStateCheckBox->setFont(font);
        sortByStateCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(187, 198, 220);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(, 11, 25);\n"
""));
        souvenirOrDistComboBox = new QComboBox(centralwidget);
        souvenirOrDistComboBox->addItem(QString());
        souvenirOrDistComboBox->addItem(QString());
        souvenirOrDistComboBox->setObjectName(QString::fromUtf8("souvenirOrDistComboBox"));
        souvenirOrDistComboBox->setGeometry(QRect(420, 130, 141, 31));
        souvenirOrDistComboBox->setFont(font1);
        souvenirOrDistComboBox->setAutoFillBackground(false);
        souvenirOrDistComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(660, 350, 111, 30));
        pushButton_6->setMaximumSize(QSize(16777215, 30));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);"));
        pushButton_6->setAutoDefault(true);
        pushButton_6->setFlat(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuLogin = new QMenu(menubar);
        menuLogin->setObjectName(QString::fromUtf8("menuLogin"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuExit->menuAction());
        menubar->addAction(menuLogin->menuAction());
        menuLogin->addSeparator();
        menuLogin->addSeparator();
        menuLogin->addAction(actionLogin);

        retranslateUi(MainWindow);

        pushButton_3->setDefault(true);
        goToTraversalsButton->setDefault(true);
        pushButton_5->setDefault(true);
        pushButton_6->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login as Admin", nullptr));
        CollegeLabel->setText(QCoreApplication::translate("MainWindow", "Colleges", nullptr));
        CollegeLabel_2->setText(QCoreApplication::translate("MainWindow", "State", nullptr));
        CollegeLabel_3->setText(QCoreApplication::translate("MainWindow", "Undergraduates", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Plan a Trip", nullptr));
        goToTraversalsButton->setText(QCoreApplication::translate("MainWindow", "View Graph Traversals", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add to Cart", nullptr));
        sortByNameCheckBox->setText(QCoreApplication::translate("MainWindow", "Sort by Name", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Alabama", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Alaska", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Arizona", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Arkansas", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "California", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Colorado", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Connecticut", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Delaware", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Florida", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Georgia", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "Hawaii", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "Idaho", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "Illinois", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "Indiana", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "Iowa", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "Kansas", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "Kentucky", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "Louisiana", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("MainWindow", "Maine", nullptr));
        comboBox->setItemText(19, QCoreApplication::translate("MainWindow", "Maryland", nullptr));
        comboBox->setItemText(20, QCoreApplication::translate("MainWindow", "Massachusetts", nullptr));
        comboBox->setItemText(21, QCoreApplication::translate("MainWindow", "Michigan", nullptr));
        comboBox->setItemText(22, QCoreApplication::translate("MainWindow", "Minnesota", nullptr));
        comboBox->setItemText(23, QCoreApplication::translate("MainWindow", "Mississippi", nullptr));
        comboBox->setItemText(24, QCoreApplication::translate("MainWindow", "Missouri", nullptr));
        comboBox->setItemText(25, QCoreApplication::translate("MainWindow", "Montana", nullptr));
        comboBox->setItemText(26, QCoreApplication::translate("MainWindow", "Nebraska", nullptr));
        comboBox->setItemText(27, QCoreApplication::translate("MainWindow", "Nevada", nullptr));
        comboBox->setItemText(28, QCoreApplication::translate("MainWindow", "New Hampshire", nullptr));
        comboBox->setItemText(29, QCoreApplication::translate("MainWindow", "New Jersey", nullptr));
        comboBox->setItemText(30, QCoreApplication::translate("MainWindow", "New Mexico", nullptr));
        comboBox->setItemText(31, QCoreApplication::translate("MainWindow", "New York", nullptr));
        comboBox->setItemText(32, QCoreApplication::translate("MainWindow", "North Carolina", nullptr));
        comboBox->setItemText(33, QCoreApplication::translate("MainWindow", "North Dakota", nullptr));
        comboBox->setItemText(34, QCoreApplication::translate("MainWindow", "Ohio", nullptr));
        comboBox->setItemText(35, QCoreApplication::translate("MainWindow", "Oklahoma", nullptr));
        comboBox->setItemText(36, QCoreApplication::translate("MainWindow", "Oregon", nullptr));
        comboBox->setItemText(37, QCoreApplication::translate("MainWindow", "Pennsylvania", nullptr));
        comboBox->setItemText(38, QCoreApplication::translate("MainWindow", "Rhode Island", nullptr));
        comboBox->setItemText(39, QCoreApplication::translate("MainWindow", "South Carolina", nullptr));
        comboBox->setItemText(40, QCoreApplication::translate("MainWindow", "South Dakota", nullptr));
        comboBox->setItemText(41, QCoreApplication::translate("MainWindow", "Tennessee", nullptr));
        comboBox->setItemText(42, QCoreApplication::translate("MainWindow", "Texas", nullptr));
        comboBox->setItemText(43, QCoreApplication::translate("MainWindow", "UtahItem", nullptr));
        comboBox->setItemText(44, QCoreApplication::translate("MainWindow", "Vermont", nullptr));
        comboBox->setItemText(45, QCoreApplication::translate("MainWindow", "Virginia", nullptr));
        comboBox->setItemText(46, QCoreApplication::translate("MainWindow", "Washington", nullptr));
        comboBox->setItemText(47, QCoreApplication::translate("MainWindow", "West Virginia", nullptr));
        comboBox->setItemText(48, QCoreApplication::translate("MainWindow", "Wisconsin", nullptr));
        comboBox->setItemText(49, QCoreApplication::translate("MainWindow", "Wyoming", nullptr));

        sortByStateCheckBox->setText(QCoreApplication::translate("MainWindow", "Sort by State", nullptr));
        souvenirOrDistComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Souvenirs", nullptr));
        souvenirOrDistComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Distances", nullptr));

        pushButton_6->setText(QCoreApplication::translate("MainWindow", "View Cart", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuExit->setTitle(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuLogin->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
