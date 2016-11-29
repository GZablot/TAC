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
        Vehicule* vehicule;
        Chauffeur* chauffeur;
        std::string rdv_aller;
        std::string rdv_retour;
        std::string type_vehicule;

    public:
        Location(){}
        Location(Vehicule* v): vehicule(v){}
        Location(Vehicule* v, Chauffeur* c) : vehicule(v), chauffeur(c){}
        ~Location(){}

        std::string getNom() const{
            return chauffeur->getNom();
        }

        int getPrix() const{
            return vehicule->getPrix() + chauffeur->getPrix();
        }

        void setVehicule(Vehicule* v){
            this->vehicule = v;
        }

        void setChauffeur(Chauffeur* c){
            this->chauffeur = c;
        }

        void setPrix(int prix){
            this->prix = prix;
        }

        std::string toString(float i) const {
            std::ostringstream os;
            os << i;
            return os.str();
        }

        std::string afficheSansChauffeur() const {
            return "Type vehicule loue : " + vehicule->getNom() + " , Prix : " + toString(vehicule->getPrix())  ;
        }

        std::string afficheAvecChauffeur() const {
            return "Type vehicule loue : " + vehicule->getNom() + " , Prix : " + toString(vehicule->getPrix() + chauffeur->getPrix())
                    + " , Chauffeur : " + chauffeur->getNom() ;
        }

};

#endif // LOCATION_H
