#ifndef BUS_H
#define BUS_H

#include <string>
#include "vehicule.h"

class Bus : public Vehicule
{

    public:
        Bus() : Vehicule() {}
        ~Bus() {}
        std::string getNom() const { return "Bus";}
        float getPrix() const { return Vehicule::prix + 50;}
        std::string affiche() const {return "Type vehicule : " + getNom() + " , Prix : " + std::to_string(getPrix());}
};

#endif // BUS_H
