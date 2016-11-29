#ifndef VELO_H
#define VELO_H

#include <string>
#include "vehicule.h"

class Velo : public Vehicule
{
    bool electrique;

        public:
            Velo() : Vehicule() {}
            ~Velo() {}
            void setElectrique(bool e){this->electrique = e;}
            std::string getNom() const { return "Velo";}
            float getPrix() const {
                if(electrique)
                    return Vehicule::prix + 20;
                else
                    return Vehicule::prix + 10;
            }
            std::string affiche() const {return "Type vehicule : " + getNom() + " , Prix : " + std::to_string(getPrix());}
};

#endif // VELO_H
