#include "fenetre.h"

Fenetre::Fenetre() : QWidget()
{
    setFixedSize(400, 200);

    /*bouton voiture*/
    bouton_voiture = new QRadioButton("Voiture",this) ;
    bouton_voiture->setToolTip("Louer une voiture");
    bouton_voiture->setFont(QFont("Comic Sans MS"));
    bouton_voiture->setCursor(Qt::PointingHandCursor);
    bouton_voiture->move(10,50);

    /*bouton bus*/
    bouton_bus = new QRadioButton("Bus",this) ;
    bouton_bus->setToolTip("Louer un bus");
    bouton_bus->setFont(QFont("Comic Sans MS"));
    bouton_bus->setCursor(Qt::PointingHandCursor);
    bouton_bus->move(100,50);


    /* ajout du texte*/
    prix_texte = new QLabel("Prix à payer : ",this);
    //prix_texte->setAlignment(Qt::AlignCenter);
    prix_texte->setFont(QFont("Comic Sans MS"));

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::blue);
    prix_texte->setPalette(*palette);


    //QHBoxLayout *layout = new QHBoxLayout();

    //layout->addWidget(prix_texte);
    //setLayout(layout);


}
