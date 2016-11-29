#ifndef BUS_H
#define BUS_H

#include <string>
#include "vehicule.h"

class Bus : public Vehicule
{

    public:
        Bus() : Vehicule() {}
        ~Bus() {}
        void setElectrique(bool e){}
        std::string getNom() const { return "Bus";}
        float getPrix() const { return Vehicule::prix + 50;}
        std::string affiche() const {return "Type vehicule : " + getNom() + " , Prix : " + toString(getPrix());}
};

#endif // BUS_H
