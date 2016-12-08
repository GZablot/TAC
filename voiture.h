#ifndef VOITURE_H
#define VOITURE_H

#include <string>
#include "vehicule.h"


class Voiture: public Vehicule
{
    public:
        Voiture() : Vehicule() {}
        ~Voiture() {}

        std::string modele;

        void setModele(std::string str){ this->modele = str ; }

        void setElectrique(bool e){}

        std::string getNom() const { return "Voiture";}

        std::string getModele() const {return this->modele;}

        float getPrix() const { return Vehicule::prix + 20;}

        std::string affiche() const {return "Type vehicule : " + getNom() + " , Modèle : " + getModele() + " , Prix : " + std::to_string(getPrix()) + "€";}

    protected:

};

#endif // VOITURE_H
