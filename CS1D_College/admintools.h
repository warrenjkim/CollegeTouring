#ifndef ADMINTOOLS_H
#define ADMINTOOLS_H

#include "database.h"
#include "college.h"
#include "ui_traversals.h"

#include <QWidget>
#include <QMessageBox>
#include <vector>

// Author : Danny Cowles

namespace Ui {
class adminTools;
}

///
/// \brief The adminTools class consists of admin maintenance tools (adding, deleting, editing souvenirs) and its ui
///
class adminTools : public QWidget
{
    Q_OBJECT

public:
    explicit adminTools(QWidget *parent = nullptr);

    ///
    /// \brief destructor
    ///
    ~adminTools();

private slots:
    ///
    /// \brief triggered when user clicks "add souvenir", error checks input, and then adds to souvenir vector for specific college and updates db
    ///
    void on_addButton_clicked();

    ///
    /// \brief user selects a college from "select a college to edit" combo box and then populates the information on the delete and edit price combo boxes
    /// \param index
    ///
    void on_collegeNameEditBox_currentIndexChanged(int index);

    ///
    /// \brief triggered when user clicks "delete souvenir button", deletes selected souvenir from souvenir vector and updates db
    ///
    void on_deleteButton_clicked();

    ///
    /// \brief triggered when user selects a souvenir from the edit price area, sets the value of the spin box to its price
    /// \param index of souvenir in the vector, used to delete via deleteSouvenir()
    ///
    void on_updateNameComboBox_currentIndexChanged(int index);

    ///
    /// \brief triggered when user presses "update price" button, amount in spin box becomes the new price of the selected souvenir
    ///
    void on_updatePriceButton_clicked();

    ///
    /// \brief returns user to admin login screen
    ///
    void on_returnButton_clicked();

    ///
    /// \brief user selects that they want to add the new colleges to the database
    ///
    void on_addCollegesButton_clicked();

private:
    Ui::adminTools *ui;
    database* db; /*!< database object */
    map::unordered_map<int, College> colleges; /*!< college map that holds <int, college> */
    College collegeModify; /*!< college object that holds the current object being modified by admin */
};

#endif // ADMINTOOLS_H
