#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include "chauffeur.h"
#include "vehicule.h"

#include <iostream>
#include <iomanip>
#include <sstream>

class Location {

        int identification;
        int duree;
        Vehicule *vehicule;
        Chauffeur *chauffeur;
        std::string nom;
        std::string rdv_aller;
        std::string rdv_retour;
        std::string type_vehicule;

    public:
        Location() : chauffeur(NULL), vehicule(NULL){}

        std::string getNom() const{
            return vehicule->getNom()+chauffeur->getNom();
        }

        int getPrix() const{
            return vehicule->getPrix()+chauffeur->getPrix();
        }

        ~Location(){
        }

        void setVehicule(int v){
            switch(v){
            case 1: vehicule = new Voiture();
                break;
            case 2: vehicule = new Bus();
                break;
            case 3: vehicule = new Velo();
            }
        }

        void setChauffeur(){
            chauffeur = new Chauffeur();
        }

        void decrit(std::ostream &os) const{
            if(chauffeur != NULL){
                os << "Vous avez loué : " << vehicule->getNom() << "avec un chauffeur du nom de : "
                   << chauffeur->getNom() << " au prix de : " << this->getPrix();
            }else{
                os << "Vous avez loué : " << vehicule->getNom() << " au prix de : " << this->getPrix();
            }
        }
};

#endif // LOCATION_H
