#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "chauffeur.h"
#include "vehicule.h"

class Vehicule;

class Location {
    protected:
        int identification;
        int duree;
        Vehicule* vehicule;
        Chauffeur chauffeur;
        std::string rdv_aller;
        std::string rdv_retour;
        std::string type_vehicule;

    public:
        Location(){}
        Location(Vehicule* v, Chauffeur c) : vehicule(v), chauffeur(c){}
        ~Location(){}

        std::string getNom() const{
            return chauffeur.getNom();
        }

        int getPrix() const{
            return vehicule->getPrix();
        }

        std::string affiche() const {return "Type vehicule loue : " + vehicule->getNom() + " , Prix : " + std::to_string(vehicule->getPrix())
                    + " Chauffeur : " + chauffeur.getNom() ;}

};

#endif // LOCATION_H
