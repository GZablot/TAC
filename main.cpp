#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "location.h"
#include "chauffeur.h"
#include "vehicule.h"
#include "fenetre.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Fenetre fenetre;
    fenetre.show();

    Location location;
    location.setChauffeur();
    location.setVehicule(2);
    cout << location.getNom() << location.getPrix() << endl;
    return a.exec();
}
