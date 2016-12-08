#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <QDate>
#include <QString>
#include <iostream>
#include <fstream>
#include <ostream>
#include "chauffeur.h"
#include "vehicule.h"

class Vehicule;

class Location {
    protected:
        int identification;
        int duree;
        int prix;
        QDate *dateDebut = NULL;
        Vehicule* vehicule;
        Chauffeur* chauffeur = NULL;
        std::string rdv_aller;
        std::string rdv_retour;
        std::string type_vehicule;

    public:
        Location(){}
        Location(Vehicule* v): vehicule(v){}
        Location(Vehicule* v, Chauffeur* c) : vehicule(v), chauffeur(c){}
        ~Location(){delete chauffeur; delete vehicule;}

        std::string getNom() const{
            return chauffeur->getNom();
        }

        int getPrix() const{
            return vehicule->getPrix() + chauffeur->getPrix();
        }

        void setVehicule(Vehicule* v){
            this->vehicule = v;
        }

        Vehicule* getVehicule(){
            return this->vehicule;
        }

        void setChauffeur(Chauffeur* c){
            this->chauffeur = c;
        }

        void setPrix(int prix){
            this->prix = prix;
        }


        void setElectrique(bool e){
            vehicule->setElectrique(e);
        }

        void setDateDebut(int j, int m, int a){
            dateDebut = new QDate(a, m, j);
        }

        void save(){
            std::ofstream file;
            file.open("fichier_location.txt", std::ofstream::out |std::ofstream::app);
            file << decrit() << "\n";
            file.close();
        }

        std::string decrit() const {
            if(this->chauffeur == NULL){
                if(this->dateDebut == NULL){
                    return "Type vehicule loué : " + vehicule->getNom() + " , Prix : " + std::to_string(vehicule->getPrix()) + " € , Modèle : " + vehicule->getModele();
                }else{
                    return "Type vehicule loué : " + vehicule->getNom() + " , Prix : " + std::to_string(vehicule->getPrix()) + " €  , Modèle : "
                            + vehicule->getModele() + ", pour la date du : " + dateDebut->toString().toStdString();
                }
            }else{
                if(this->dateDebut == NULL){
                    return "Type vehicule loué : " + vehicule->getNom() + " , Prix : " + std::to_string(vehicule->getPrix() + chauffeur->getPrix())
                            + " € , Modèle : " + vehicule->getModele() + " , Chauffeur : " + chauffeur->getNom();
                }else{
                    return "Type vehicule loué : " + vehicule->getNom() + " , Prix : " + std::to_string(vehicule->getPrix() + chauffeur->getPrix())
                            + " €, Modèle : " + vehicule->getModele() + " , Chauffeur : " + chauffeur->getNom() + " , pour la date du : " + dateDebut->toString().toStdString();
                }
            }
        }

};

#endif // LOCATION_H
