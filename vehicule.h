#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <sstream>

class Vehicule {
    public:
        Vehicule(){}
        virtual ~Vehicule(){}
        virtual float getPrix() const = 0;
        virtual std::string getNom() const = 0;
        virtual void setElectrique(bool e) = 0;

    protected:
        int identification;
        bool disponibe;
        float prix;
        std::string nom;

        //Date revision;
        //liste avis

        std::string toString(float i) const {
            std::ostringstream os;
            os << i;
            return os.str();
        }

};

#endif // VEHICULE_H
