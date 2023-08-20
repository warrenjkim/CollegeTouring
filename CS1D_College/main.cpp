#include "mainwindow.h"
#include "database.h"
#include "unordered_map.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QString path;

#if __APPLE__ && TARGET_OS_MAC
        path = "../../../../CS1D_College/college.db";
#elif __linux__
        path = "../CS1D_College/college.db";
#else
        path = "..\\CS1D_College\\college.db";
#endif

    map::unordered_map<QString, float> map;

    database db(path);

    //comment this line to have changes persist
    db.resetWithFile();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
