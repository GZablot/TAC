#ifndef VELO_H
#define VELO_H

#include <string>
#include "vehicule.h"

class Velo : public Vehicule
{
    public:
        Velo() : Vehicule() {}
        ~Velo() {}
        std::string getNom() const { return "Velo";}
        float getPrix() const { return Vehicule::prix + 10;}
        std::string affiche() const {return "Type vehicule : " + getNom() + " , Prix : " + std::to_string(getPrix());}
};

#endif // VELO_H
