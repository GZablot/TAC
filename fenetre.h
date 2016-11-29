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
#include <QGroupBox>
#include <QMessageBox>
#include <QLineEdit>
#include <QStringList>

class Fenetre : public QWidget
{
    Q_OBJECT

    public:
        Fenetre();
        ~Fenetre(){
            delete vehicule;
            delete location;
            delete chauffeur;
        }

    public slots:
        //void changerTexte();
        void voitureSlot();
        void busSlot();
        void veloSlot();
        void validerSlot();
        void chauffeurSlot();
        void sansChauffeurSlot();
        void electriqueSlot();
        void sansElectriqueSlot();

    private:
        QRadioButton *bouton_voiture;
        QRadioButton *bouton_bus;
        QRadioButton *bouton_velo;
        QRadioButton *bouton_chauffeur;
        QRadioButton *bouton_sans_chauffeur;
        QRadioButton *bouton_electrique;
        QRadioButton *bouton_sans_electrique;
        QGroupBox *groupVehicule;
        QGroupBox *groupChauffeur;
        QGroupBox *groupElectrique;
        QLineEdit *saisie;
        QPushButton *valider;
        QLabel *prix_texte;
        Location* location;
        Vehicule* vehicule;
        Chauffeur* chauffeur;
};

#endif // FENETRE_H
