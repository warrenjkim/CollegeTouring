#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

#include "database.h"
#include "traversals.h"
#include "adminlogin.h"
#include "admintools.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void updateCollegeList(bool sortByDistance);
    void on_CollegeModelList_clicked(const QModelIndex &index);
    void on_goToTraversalsButton_clicked();
    void on_actionLogin_triggered();
    void on_sortByNameCheckBox_toggled(bool checked);
    void on_souvenirOrDistComboBox_currentIndexChanged(int index);
    void on_sortByStateCheckBox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    traversals *traversalWindow;
    adminTools *adminWindow;
    database *db;
    QSqlQueryModel* collegeModel;
    QStringListModel* souvenirModel;
    QSqlQueryModel* infoModel;
    QString collegeName;
    QString menuItem;
    QString menuPrice;
    QString path;
    int souvenirComboBox;
    QModelIndex selectedCollege;
    bool sortByName;
    bool sortByState;
};
#endif // MAINWINDOW_H
