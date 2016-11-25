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

        enum IdVehicule{
            voiture = 1,
            bus = 2,
            velo = 3
        };

        Location() : chauffeur(NULL), vehicule(NULL){}

        std::string getNom() const{
            return vehicule->getNom()+chauffeur->getNom();
        }

        int getPrix() const{
            return vehicule->getPrix()+chauffeur->getPrix();
        }

        ~Location(){
        }

        void setVehicule(const IdVehicule iv){
            switch((int) iv){
            case voiture: vehicule = new Voiture();
                break;
            case bus: vehicule = new Bus();
                break;
            case velo: vehicule = new Velo();
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
