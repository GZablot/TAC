#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>
#include <string>
#include <iostream>
#include "location.h"
#include "chauffeur.h"
#include "vehicule.h"
#include "voiture.h"
#include "bus.h"
#include "velo.h"


class Fenetre : public QWidget
{
    Q_OBJECT

    public:
        Fenetre();
        ~Fenetre(){
            delete vehicule;
            delete location;
        }

    public slots:
        //void changerTexte();
        void voitureSlot();
        void busSlot();
        void veloSlot();
        void validerSlot();

    private:
        QRadioButton *bouton_voiture;
        QRadioButton *bouton_bus;
        QRadioButton *bouton_velo;
        QPushButton *valider;
        QLabel *prix_texte;
        Location* location;
        Vehicule* vehicule;
        Chauffeur chauffeur;
};

#endif // FENETRE_H
