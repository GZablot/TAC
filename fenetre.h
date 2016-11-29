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


class Fenetre : public QWidget
{
    Q_OBJECT

    public:
        Fenetre();
        ~Fenetre(){
            delete location;
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
        std::string toString(float i) const;

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
        QPushButton *valider;
        QLabel *prix_texte;
        Location* location;
};

#endif // FENETRE_H
