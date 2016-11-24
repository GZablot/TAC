#ifndef VOITURE_H
#define VOITURE_H

#include <string>
#include "vehicule.h"


class Voiture: public Vehicule
{
    public:
        Voiture() : Vehicule() {}
        ~Voiture() {}
        std::string getNom() const { return "Voiture";}
        float getPrix() const { return Vehicule::prix + 20;}

        std::string affiche() const {return "Type vehicule : " + getNom() + " , Prix : " + std::to_string(getPrix());}

    protected:

};

#endif // VOITURE_H
