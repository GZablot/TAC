#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QApplication>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>
#include <string>
#include <iostream>
#include <QDate>
#include <QSpinBox>
#include "location.h"
#include "chauffeur.h"
#include "vehicule.h"
#include "voiture.h"
#include "bus.h"
#include "velo.h"
#include <QGroupBox>
#include <QMessageBox>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_bouton_bus_clicked();

    void on_bouton_voiture_clicked();

    void on_bouton_velo_clicked();

    void on_bouton_chauffeur_clicked();

    void on_bouton_sans_chauffeur_clicked();

    void on_bouton_electrique_clicked();

    void on_bouton_sans_electrique_clicked();

    void on_valider_clicked();


    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStringListModel *model;

    QList<QString> listeVehicules;

    Location* location;
    //Vehicule* vehicule;
    //Chauffeur* chauffeur;
};

#endif // MAINWINDOW_H
