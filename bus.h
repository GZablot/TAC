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

        std::string getModele() const {return "Autobus Renault";}

        std::string getNom() const { return "Bus";}

        float getPrix() const { return Vehicule::prix + 50;}

        std::string affiche() const {return "Type vehicule : " + getNom() + " , Prix : " + std::to_string(getPrix()) + "€";}

        void setModele(std::string str){}
};

#endif // BUS_H
