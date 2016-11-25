#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QRadioButton>
#include "chauffeur.h"
#include "voiture.h"
#include "location.h"
#include <iostream>
#include "fenetre.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Fenetre fenetre;
    fenetre.show();




    Chauffeur c("Jean");
    /*string nom = c.getNom();
    cout << nom << endl;*/

    Voiture v;
    /*std::string nomVoiture = v.getNom();
    int prix = v.getPrix();
    cout << nomVoiture << " " << prix  << endl;*/

    Location l(&v, c);
    cout << l.afficheAvecChauffeur() << endl;

    return a.exec();
}
