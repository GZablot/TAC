#include "fenetre.h"



Fenetre::Fenetre() : QWidget()
{
    setFixedSize(600, 300);

    /*group box vehicule*/
    groupVehicule = new QGroupBox("Louer un Vehicule",this);
    groupVehicule->move(40,20);

    /*group box chauffeur*/
    groupChauffeur = new QGroupBox("Chauffeur",this);
    groupChauffeur->move(40,120);

    /*bouton voiture*/
    bouton_voiture = new QRadioButton("Voiture",groupVehicule) ;
    bouton_voiture->setToolTip("Louer une voiture");
    bouton_voiture->setFont(QFont("Comic Sans MS"));
    bouton_voiture->setCursor(Qt::PointingHandCursor);
    bouton_voiture->move(10,30);
    bouton_voiture->setChecked(true);


    /*bouton bus*/
    bouton_bus = new QRadioButton("Bus",groupVehicule) ;
    bouton_bus->setToolTip("Louer un bus");
    bouton_bus->setFont(QFont("Comic Sans MS"));
    bouton_bus->setCursor(Qt::PointingHandCursor);
    bouton_bus->move(200,30);

    /*bouton velo*/
    bouton_velo = new QRadioButton("Vélo",groupVehicule);
    bouton_velo->setToolTip("Louer un vélo");
    bouton_velo->setFont(QFont("Comic Sans MS"));
    bouton_velo->setCursor(Qt::PointingHandCursor);
    bouton_velo->move(350,30);

    /*bouton avec chauffeur*/
    bouton_chauffeur = new QRadioButton("Avec Chauffeur",groupChauffeur);
    bouton_chauffeur->setToolTip("Véhicule avec chauffeur");
    bouton_chauffeur->setFont(QFont("Comic Sans MS"));
    bouton_chauffeur->setCursor(Qt::PointingHandCursor);
    bouton_chauffeur->move(60,30);

    /*bouton sans chauffeur*/
    bouton_sans_chauffeur = new QRadioButton("Sans Chauffeur",groupChauffeur);
    bouton_sans_chauffeur->setToolTip("Véhicule sans chauffeur");
    bouton_sans_chauffeur->setFont(QFont("Comic Sans MS"));
    bouton_sans_chauffeur->setCursor(Qt::PointingHandCursor);
    bouton_sans_chauffeur->move(280,30);
    bouton_sans_chauffeur->setChecked(true);


    /*bouton valider location*/
    valider = new QPushButton("Valider",this);
    valider->setToolTip("Louer une voiture");
    valider->setFont(QFont("Comic Sans MS"));
    valider->setCursor(Qt::PointingHandCursor);
    valider->move(160,270);

    /* ajout du texte*/
    prix_texte = new QLabel("Prix à payer : 0     ",this);
    //prix_texte->setAlignment(Qt::AlignCenter);
    prix_texte->setFont(QFont("Comic Sans MS"));

    /*couleur du QLabel*/
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::blue);
    prix_texte->setPalette(*palette);

    /*creation liste chauffeur*/
    saisie = new QLineEdit(groupChauffeur);
    saisie->setText("Saisir nom chauffeur");
    saisie->move(60,60);

    QStringList List;
    List << "Clair de Lune" << "Reverie" << "Prelude";



    /*Par défaut voiture*/
    vehicule = new Voiture();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));

    /*action des QRadioButton*/
    QObject::connect(bouton_voiture, SIGNAL(clicked()), this, SLOT(voitureSlot()));
    QObject::connect(bouton_bus, SIGNAL(clicked()), this, SLOT(busSlot()));
    QObject::connect(bouton_velo, SIGNAL(clicked()), this, SLOT(veloSlot()));
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(validerSlot()));
    QObject::connect(bouton_chauffeur, SIGNAL(clicked()), this, SLOT(chauffeurSlot()));
    QObject::connect(bouton_sans_chauffeur, SIGNAL(clicked()), this, SLOT(sansChauffeurSlot()));

    //QHBoxLayout *layout = new QHBoxLayout();

    //layout->addWidget(prix_texte);
    //setLayout(layout);


}

void Fenetre::chauffeurSlot(){
    chauffeur = new Chauffeur(saisie->text().toStdString());
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix() + this->chauffeur->getPrix())));

}

void Fenetre::sansChauffeurSlot(){
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));
}


void Fenetre::voitureSlot(){
    vehicule = new Voiture();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));
}

void Fenetre::busSlot(){
    vehicule = new Bus();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));
}

void Fenetre::veloSlot(){
    vehicule = new Velo();
    prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())));
}

void Fenetre::validerSlot(){
    std::cout << "Validation" << std::endl;
    //TODO verifier si un bouton entre velo,bus est check
    int reponse = QMessageBox::question(this, "Valider location", "Voulez-vous valider la location ?",
                          QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes){
        if(bouton_sans_chauffeur->isChecked()){
            location = new Location(vehicule);
            this->location->setPrix(this->vehicule->getPrix());
            std::cout << location->afficheSansChauffeur() << std::endl;
        }else{
            location = new Location(vehicule, chauffeur);
            this->location->setPrix(this->vehicule->getPrix() + this->chauffeur->getPrix());
            std::cout << location->afficheAvecChauffeur() << std::endl;
        }
    }
}

