#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include <string>
#include <iomanip>

class Chauffeur {

    public:
        Chauffeur(){}
        Chauffeur(std::string n) : nom(n) {}
        ~Chauffeur(){}
        std::string getNom() const{
            return nom;
        }

        int getPrix() const{
            return prix;
        }


    protected:
        std::string nom;
        float prix = 20.;
        bool disponible;
        bool permis_voiture;
        bool permis_bus;
        //Date visite_medicale;



};
#endif // CHAUFFEUR_H
