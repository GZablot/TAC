#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>

class Vehicule {

    int identification;
    bool disponibe;
    std::string Nom;
    int Prix;
    //Date revision;
    //liste avis

protected:

    Vehicule(std::string n, int p) : Nom(n), Prix(p){}

public:

    virtual ~Vehicule(){}

    int getPrix(){
        return this->Prix;
    }

    virtual std::string getNom(){
        return this->Nom;
    }
};

class Voiture: public Vehicule
{
public:
    Voiture() : Vehicule("Location d'une voiture", 20){}

    ~Voiture() {
#ifdef VERB_DESTR
        std::cout << "  ~Voiture()" << std::endl;
#endif
    }
};

class Bus: public Vehicule{

public:

    Bus() : Vehicule("Location d'un bus", 50){}

    ~Bus(){

#ifdef VERB_DESTR
        std::cout << "  ~Bus()" << std::endl;
#endif
    }
};

class Velo : public Vehicule {
public:
    Velo() : Vehicule("Location d'un velo", 10){}

    ~Velo(){
#ifdef VERB_DESTR
        std::cout << "  ~Velo()" << std::endl;
#endif
    }

};

#endif // VEHICULE_H
