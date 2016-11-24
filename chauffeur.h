#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include <string>
#include <iomanip>

class Chauffeur {

    std::string nom;
    bool disponible;
    bool permis_voiture;
    bool permis_bus;
    //Date visite_medicale;

    public:
        Chauffeur(){}
        ~Chauffeur(){}

        std::string getNom() const{
            return "Jean";
        }

        int getPrix() const{
            return 20;
        }
};
#endif // CHAUFFEUR_H
