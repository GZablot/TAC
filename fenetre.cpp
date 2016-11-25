#include "fenetre.h"

Fenetre::Fenetre() : QWidget(){
    setFixedSize(400, 200);
    setWindowTitle(toQString("Transport à la carte de la ville B"));

    /*bouton voiture*/
    bouton_voiture.setText("Voiture") ;
    bouton_voiture.setToolTip("Louer une voiture");
    bouton_voiture.setFont(QFont("Comic Sans MS"));
    bouton_voiture.setCursor(Qt::PointingHandCursor);
    bouton_voiture.move(10,50);
    mapper.setMapping(&bouton_voiture, "voiture");
    connect(&mapper, SIGNAL(mapped(const QString&)), this, SLOT(gereBouton(const QString&)));

    /*bouton bus*/
    bouton_bus.setText("Bus") ;
    bouton_bus.setToolTip("Louer un bus");
    bouton_bus.setFont(QFont("Comic Sans MS"));
    bouton_bus.setCursor(Qt::PointingHandCursor);
    bouton_bus.move(100,50);
    mapper.setMapping(&bouton_bus, "bus");

    /* ajout du texte*/
    prix_texte = new QLabel("Veuillez choisir le type de location.",this);
    //prix_texte->setAlignment(Qt::AlignCenter);
    prix_texte->setFont(QFont("Comic Sans MS"));

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::blue);
    prix_texte->setPalette(*palette);


    //QHBoxLayout *layout = new QHBoxLayout();

    //layout->addWidget(prix_texte);
    //setLayout(layout);

}
/*
void Fenetre::gereBouton(const QString& ti) {
  const int type = ti[0].toLatin1() - 'A', ident = ti[1].toLatin1() - '1';
  bool ok = (type >= nbTypeConfirm) || (valeur[type] < 0);
  if (! ok) {
    ok = fenetre.confirme(type);
    if (! ok)
      bouton[type][valeur[type]].setChecked(true);
  }
  if (ok) {
    pizzeria.ajoute(type, ident);
    if (type < nbTypeConfirm)  valeur[type] = ident;
    description.setText( toQString( pizzeria.pizza().decrit() ) );
    for(int tp = type; tp < pizzeria.nbTypes; tp++) {
      if ( (tp > type) && (tp < nbTypeConfirm) )  valeur[tp] = -1;
      for(int id = 0; id < pizzeria.nbIdent(tp); id++) {
    if ( bouton[tp][id].isChecked() && (tp > type) ) {
      bouton[tp][id].setAutoExclusive(false);
      bouton[tp][id].setChecked(false);
      bouton[tp][id].setAutoExclusive(tp < nbTypeConfirm);
    }
    bouton[tp][id].setEnabled
      ( (tp == type + 1) ||
        ( (tp == type) && (! bouton[tp][id].isChecked() ) ) );
      }
    }
  }
}*/

