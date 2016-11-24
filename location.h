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
        int prix;
        Vehicule vehicule;
        Chauffeur chauffeur;
        std::string nom;
        std::string rdv_aller;
        std::string rdv_retour;
        std::string type_vehicule;

    public:
        Location(){}
        Location(Vehicule v, Chauffeur c) : vehicule(v), chauffeur(c){}

        int getNom(){
            return vehicule.getNom();
        }

        std::string getPrix(){
            return Chauffeur.get
        }

        ~Location(){}
};

#endif // LOCATION_H
