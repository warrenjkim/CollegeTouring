/********************************************************************************
** Form generated from reading UI file 'traversals.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVERSALS_H
#define UI_TRAVERSALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_traversals
{
public:
    QTableWidget *pathTable;
    QPushButton *dfsButton;
    QPushButton *bfsButton;
    QPushButton *mstButton;
    QLabel *label;
    QLabel *totalDistanceLabel;
    QPushButton *returnButton;

    void setupUi(QWidget *traversals)
    {
        if (traversals->objectName().isEmpty())
            traversals->setObjectName(QString::fromUtf8("traversals"));
        traversals->resize(800, 600);
        traversals->setMinimumSize(QSize(606, 0));
        pathTable = new QTableWidget(traversals);
        pathTable->setObjectName(QString::fromUtf8("pathTable"));
        pathTable->setGeometry(QRect(20, 70, 341, 411));
        dfsButton = new QPushButton(traversals);
        dfsButton->setObjectName(QString::fromUtf8("dfsButton"));
        dfsButton->setGeometry(QRect(430, 70, 131, 31));
        bfsButton = new QPushButton(traversals);
        bfsButton->setObjectName(QString::fromUtf8("bfsButton"));
        bfsButton->setGeometry(QRect(430, 120, 131, 31));
        mstButton = new QPushButton(traversals);
        mstButton->setObjectName(QString::fromUtf8("mstButton"));
        mstButton->setGeometry(QRect(430, 170, 131, 31));
        label = new QLabel(traversals);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 431, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Text Semibold")});
        font.setPointSize(36);
        font.setBold(true);
        label->setFont(font);
        totalDistanceLabel = new QLabel(traversals);
        totalDistanceLabel->setObjectName(QString::fromUtf8("totalDistanceLabel"));
        totalDistanceLabel->setGeometry(QRect(20, 490, 341, 31));
        QFont font1;
        font1.setPointSize(12);
        totalDistanceLabel->setFont(font1);
        returnButton = new QPushButton(traversals);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(450, 530, 141, 31));

        retranslateUi(traversals);

        QMetaObject::connectSlotsByName(traversals);
    } // setupUi

    void retranslateUi(QWidget *traversals)
    {
        traversals->setWindowTitle(QCoreApplication::translate("traversals", "Form", nullptr));
        dfsButton->setText(QCoreApplication::translate("traversals", "DFS", nullptr));
        bfsButton->setText(QCoreApplication::translate("traversals", "BFS", nullptr));
        mstButton->setText(QCoreApplication::translate("traversals", "MST", nullptr));
        label->setText(QCoreApplication::translate("traversals", "Tree Traversals", nullptr));
        totalDistanceLabel->setText(QCoreApplication::translate("traversals", "Total Distance Traveled: ", nullptr));
        returnButton->setText(QCoreApplication::translate("traversals", "Return to Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class traversals: public Ui_traversals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVERSALS_H
