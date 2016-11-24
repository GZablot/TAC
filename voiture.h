#ifndef VOITURE_H
#define VOITURE_H

#include <string>
#include "vehicule.h"

class Voiture: public Vehicule
{
    public:
        Voiture(){:Vehicule()}
        std::string getNom() { return "Voiture";}
        int getPrix() const { return prix;}

    protected:
        int prix = 20;

};

#endif // VOITURE_H
