#include "fenetre.h"



Fenetre::Fenetre() : QWidget()
{
    setFixedSize(400, 200);

    /*bouton voiture*/
    bouton_voiture = new QRadioButton("Voiture",this) ;
    bouton_voiture->setToolTip("Louer une voiture");
    bouton_voiture->setFont(QFont("Comic Sans MS"));
    bouton_voiture->setCursor(Qt::PointingHandCursor);
    bouton_voiture->move(10,30);

    /*bouton bus*/
    bouton_bus = new QRadioButton("Bus",this) ;
    bouton_bus->setToolTip("Louer un bus");
    bouton_bus->setFont(QFont("Comic Sans MS"));
    bouton_bus->setCursor(Qt::PointingHandCursor);
    bouton_bus->move(100,30);

    /*bouton velo*/
    bouton_velo = new QRadioButton("Vélo",this);
    bouton_velo->setToolTip("Louer un vélo");
    bouton_velo->setFont(QFont("Comic Sans MS"));
    bouton_velo->setCursor(Qt::PointingHandCursor);
    bouton_velo->move(190,30);

    /*bouton valider location*/
    valider = new QPushButton("Valider",this);
    valider->setToolTip("Louer une voiture");
    valider->setFont(QFont("Comic Sans MS"));
    valider->setCursor(Qt::PointingHandCursor);
    valider->move(160,170);

    /* ajout du texte*/
    prix_texte = new QLabel("Prix à payer : 0     ",this);
    //prix_texte->setAlignment(Qt::AlignCenter);
    prix_texte->setFont(QFont("Comic Sans MS"));

    /*couleur du QLabel*/
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::blue);
    prix_texte->setPalette(*palette);

    /*action des QRadioButton*/
    QObject::connect(bouton_voiture, SIGNAL(clicked()), this, SLOT(voitureSlot()));
    QObject::connect(bouton_bus, SIGNAL(clicked()), this, SLOT(busSlot()));
    QObject::connect(bouton_velo, SIGNAL(clicked()), this, SLOT(veloSlot()));
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(validerSlot()));

    //QHBoxLayout *layout = new QHBoxLayout();

    //layout->addWidget(prix_texte);
    //setLayout(layout);


}

void Fenetre::voitureSlot(){
    vehicule = new Voiture();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix()))); //QString::fromStdString(std::to_string(prix))
    //std::cout << this->vehicule->getPrix() << std::endl;
}

void Fenetre::busSlot(){
    vehicule = new Bus();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));
    //std::cout << this->vehicule->getPrix() << std::endl;
}

void Fenetre::veloSlot(){
    vehicule = new Velo();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));
}

void Fenetre::validerSlot(){
    std::cout << "Validation" << std::endl;
    location = new Location(vehicule);
    std::cout << location->afficheSansChauffeur() << std::endl;

}

