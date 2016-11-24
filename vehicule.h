#ifndef VEHICULE_H
#define VEHICULE_H

class Vehicule {
    public:

        virtual ~Vehicule() = 0;
        virtual int getPrix() const;


    protected:
        int identification;
        bool disponibe;
        int prix;
        Vehicule(){}
        //Date revision;
        //liste avis

};

#endif // VEHICULE_H
