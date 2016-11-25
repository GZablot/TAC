
#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSignalMapper>
#include "location.h"

class Fenetre : public QWidget
{
public:
    Fenetre();

protected:
    QRadioButton bouton[3];
    QSignalMapper mapper;
    Location location;

private:
    QRadioButton bouton_voiture;
    QRadioButton bouton_bus;
    QLabel *prix_texte;

    static QString toQString(const char *str){
        return QString::fromUtf8(str);
    }

    static QString toQString(const std::string str){
        return toQString(str.c_str() );
    }
private slots:
    void gereBouton(const QString& ti);
};

#endif // FENETRE_H
