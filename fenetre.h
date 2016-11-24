#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>

class Fenetre : public QWidget
{
    public:
        Fenetre();

    private:
        QRadioButton *bouton_voiture;
        QRadioButton *bouton_bus;
        QLabel *prix_texte;
};

#endif // FENETRE_H
