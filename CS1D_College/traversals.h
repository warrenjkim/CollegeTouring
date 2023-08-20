#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include <QWidget>
#include <stack>

#include "ui_traversals.h"
#include "graph.h"
#include "database.h"

//Author : Danny Cowles

namespace Ui {
class traversals;
}

class traversals : public QWidget
{
    Q_OBJECT

public:
    explicit traversals(QWidget *parent = nullptr);

    ///
    /// \brief destructor
    ///
    ~traversals();

private slots:
    ///
    /// \brief retrurns user to the main menu
    ///
    void on_returnButton_clicked();

    ///
    /// \brief completes the dfs algorithm
    ///
    void on_dfsButton_clicked();

    ///
    /// \brief completes the bfs algorithm
    ///
    void on_bfsButton_clicked();

    ///
    /// \brief completes the mst algorithm
    ///
    void on_mstButton_clicked();

private:
    database* db;
    Ui::traversals *ui;
};

#endif // TRAVERSALS_H
