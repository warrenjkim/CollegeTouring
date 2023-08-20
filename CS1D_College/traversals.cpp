#include "traversals.h"
#include <mainwindow.h>

traversals::traversals(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traversals)
{
    ui->setupUi(this);

    QString path;

#if __APPLE__ && TARGET_OS_MAC
        path = "../../../../CS1D_College/college.db";
#elif __linux__
        path = "../CS1D_College/college.db";
#else
        path = "..\\CS1D_College\\college.db";
#endif

    db = new database(path);

    ui->totalDistanceLabel->hide();
}

traversals::~traversals()
{
    delete ui;
}

void traversals::on_returnButton_clicked()
{
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
    hide();
}


void traversals::on_dfsButton_clicked()
{

    auto colleges = db->getColleges();
    int size = colleges.size() + 1;

    graph dfs(size);

    std::vector<bool> visited(size, false);
    std::stack<int> stack;
    std::queue<QString> queue;

    //all needed to be changed here is the 2nd argument, change name to whatever you would like to start at, currently DFS starts at UCI
    dfs.DFS(visited, "University of California, Irvine (UCI)", true, stack, false, queue);

    //set row and column count of table
    ui->pathTable->setRowCount(size);
    ui->pathTable->setColumnCount(1);

    //stretches the columns and rows to fit the ui table with no extra space
    ui->pathTable->horizontalHeader()->setStretchLastSection(true);

    //hides table grid
    ui->pathTable->setShowGrid(false);

    //sets column header label
    QStringList headerLabel;
    headerLabel.push_back("Visit Itinerary");
    ui->pathTable->setHorizontalHeaderLabels(headerLabel);

    //ensures user cannot edit or highlight cells of table
    ui->pathTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pathTable->setFocusPolicy(Qt::NoFocus);
    ui->pathTable->setSelectionMode(QAbstractItemView::NoSelection);

    //makes it so user cannot stretch headers
    ui->pathTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->pathTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //counter used to represent row count in the while loop below
    int i = 0;

    //queue will be used in qt program to add items to the table
    while (!queue.empty())
    {
        QTableWidgetItem* item;
        item = new QTableWidgetItem;

        //sets text to the college name at the front of the queue
        item->setText(queue.front());

        //sets alignment and inserts the row into the table
        item->setTextAlignment(Qt::AlignCenter);
        ui->pathTable->setItem(i,0,item);

        queue.pop();
        i++;
    }

    ui->totalDistanceLabel->setText("Total Distance Traveled: " + QString::number(dfs.getTotalDistDFS()) + " miles");

    ui->totalDistanceLabel->show();

}


void traversals::on_bfsButton_clicked()
{
    auto colleges = db->getColleges();

    int size = colleges.size() + 1;
    //temp value testing with assignment #11 cities
    graph dfs(size);

    std::queue<QString> queue;

    dfs.BFS("Arizona State University");
    auto x = dfs.order;

    for(auto xx : x) {
        queue.emplace(xx.first.city);
    }

    //set row and column count of table
    ui->pathTable->setRowCount(size);
    ui->pathTable->setColumnCount(1);

    //stretches the columns and rows to fit the ui table with no extra space
    ui->pathTable->horizontalHeader()->setStretchLastSection(true);

    //hides table grid
    ui->pathTable->setShowGrid(false);

    //sets column header label
    QStringList headerLabel;
    headerLabel.push_back("Visit Itinerary");
    ui->pathTable->setHorizontalHeaderLabels(headerLabel);

    //ensures user cannot edit or highlight cells of table
    ui->pathTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pathTable->setFocusPolicy(Qt::NoFocus);
    ui->pathTable->setSelectionMode(QAbstractItemView::NoSelection);

    //makes it so user cannot stretch headers
    ui->pathTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->pathTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //counter used to represent row count in the while loop below
    int i = 0;

    //queue will be used in qt program to add items to the table
    while (!queue.empty())
    {
        if(i == 11) {
            break;
        }
        QTableWidgetItem* item;
        item = new QTableWidgetItem;

        //sets text to the college name at the front of the queue
        item->setText(queue.front());

        //sets alignment and inserts the row into the table
        item->setTextAlignment(Qt::AlignCenter);
        ui->pathTable->setItem(i,0,item);

        queue.pop();
        i++;
    }

    dfs.printDiscoveredEdges();
    dfs.printTotalDist();
    ui->totalDistanceLabel->setText("Total Distance Traveled: " + QString::number(dfs.getTotalDistDFS()) + " miles");

    ui->totalDistanceLabel->show();

    dfs.printAdjMatrix();
    dfs.printOrder();
}


void traversals::on_mstButton_clicked()
{
    auto colleges = db->getColleges();
    int size = colleges.size() + 1;

    graph mst(size);

    std::vector<bool> visited(size, false);
    std::stack<int> stack;
    std::queue<QString> queue;

    //all needed to be changed here is the 2nd argument, change name to whatever you would like to start at, currently DFS starts at UCI
    mst.MST("University of California, Irvine (UCI)", queue);

    //set row and column count of table
    ui->pathTable->setRowCount(size);
    ui->pathTable->setColumnCount(1);

    //stretches the columns and rows to fit the ui table with no extra space
    ui->pathTable->horizontalHeader()->setStretchLastSection(true);

    //hides table grid
    ui->pathTable->setShowGrid(false);

    //sets column header label
    QStringList headerLabel;
    headerLabel.push_back("Visit Itinerary");
    ui->pathTable->setHorizontalHeaderLabels(headerLabel);

    //ensures user cannot edit or highlight cells of table
    ui->pathTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pathTable->setFocusPolicy(Qt::NoFocus);
    ui->pathTable->setSelectionMode(QAbstractItemView::NoSelection);

    //makes it so user cannot stretch headers
    ui->pathTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->pathTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //counter used to represent row count in the while loop below
    int i = 0;

    //queue will be used in qt program to add items to the table
    while (!queue.empty())
    {
        QTableWidgetItem* item;
        item = new QTableWidgetItem;

        //sets text to the college name at the front of the queue
        item->setText(queue.front());

        //sets alignment and inserts the row into the table
        item->setTextAlignment(Qt::AlignCenter);
        ui->pathTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->pathTable->setItem(i,0,item);

        queue.pop();
        i++;
    }

    ui->totalDistanceLabel->setText("Total Distance Traveled: " + QString::number(mst.getTotalDistMST()) + " miles");

    ui->totalDistanceLabel->show();
}

