#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>


class Vehicule {
    public:
        Vehicule(){}
        virtual ~Vehicule(){}
        virtual float getPrix() const = 0;
        virtual std::string getNom() const = 0;


    protected:
        int identification;
        bool disponibe;
        float prix;
        std::string nom;

        //Date revision;
        //liste avis

};

#endif // VEHICULE_H
