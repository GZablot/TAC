#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "chauffeur.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    Chauffeur c("Jean");
    std::string nom = c.getNom();
    cout << nom << endl;
    return a.exec();
}
