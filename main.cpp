#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QRadioButton>
#include "chauffeur.h"
#include "voiture.h"
#include "location.h"
#include <iostream>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    //Fenetre fenetre;
    //fenetre.show();

    MainWindow mainwindow;
    mainwindow.show();




    /*Chauffeur c("Jean");
    string nom = c.getNom();
    cout << nom << endl;

    Voiture v;
    std::string nomVoiture = v.getNom();
    int prix = v.getPrix();
    cout << nomVoiture << " " << prix  << endl;

    Location l(&v, c);
    cout << l.afficheAvecChauffeur() << endl;*/

    return a.exec();
}
