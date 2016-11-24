#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include <string>
#include <iomanip>

class Chauffeur {

    public:
        Chauffeur(){}
        Chauffeur(std::string n) : nom(n) {}
        virtual ~Chauffeur(){}
        virtual std::string getNom(){
            return nom;
        }


    protected:
        std::string nom;
        bool disponible;
        bool permis_voiture;
        bool permis_bus;
        //Date visite_medicale;



};
#endif // CHAUFFEUR_H