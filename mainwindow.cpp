#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model = new QStringListModel(this);


    QStringList List;
    List << "Peugeot 3008" << "Renault Clio" << "Opel Astra" << "Renault Espace" << "Volkswagen Golf" << "Renault Megane" << "Peugeot 308" << "BMW Serie 1" << "Opel Agila" ;


    model->setStringList(List);


    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    setWindowTitle("TAC");

    ui->listView->
            setEditTriggers(QAbstractItemView::AnyKeyPressed |
                            QAbstractItemView::DoubleClicked);




    /*group box electrique*/
    ui->groupElectrique->setEnabled(false);

    /*bouton voiture*/
    ui->bouton_voiture->setToolTip("Louer une voiture");
    ui->bouton_voiture->setFont(QFont("Comic Sans MS"));
    ui->bouton_voiture->setCursor(Qt::PointingHandCursor);
    ui->bouton_voiture->setChecked(true);


    /*bouton bus*/
    ui->bouton_bus->setToolTip("Louer un bus");
    ui->bouton_bus->setFont(QFont("Comic Sans MS"));
    ui->bouton_bus->setCursor(Qt::PointingHandCursor);


    /*bouton velo*/
    ui->bouton_velo->setToolTip("Louer un vélo");
    ui->bouton_velo->setFont(QFont("Comic Sans MS"));
    ui->bouton_velo->setCursor(Qt::PointingHandCursor);


    /*bouton avec chauffeur*/
    ui->bouton_chauffeur->setToolTip("Véhicule avec chauffeur");
    ui->bouton_chauffeur->setFont(QFont("Comic Sans MS"));
    ui->bouton_chauffeur->setCursor(Qt::PointingHandCursor);


    /*bouton sans chauffeur*/
    ui->bouton_sans_chauffeur->setToolTip("Véhicule sans chauffeur");
    ui->bouton_sans_chauffeur->setFont(QFont("Comic Sans MS"));
    ui->bouton_sans_chauffeur->setCursor(Qt::PointingHandCursor);
    ui->bouton_sans_chauffeur->setChecked(true);

    /*bouton electrique*/
    ui->bouton_electrique->setToolTip("Velo avec assistance électrique");
    ui->bouton_electrique->setFont(QFont("Comic Sans MS"));
    ui->bouton_electrique->setCursor(Qt::PointingHandCursor);
    ui->bouton_electrique->setChecked(true);


    /*bouton sans electrique*/
    ui->bouton_sans_electrique->setToolTip("Velo avec assistance électrique");
    ui->bouton_sans_electrique->setFont(QFont("Comic Sans MS"));
    ui->bouton_sans_electrique->setCursor(Qt::PointingHandCursor);

    /*jour de début de la location*/
    ui->jourDebut->setMinimum(1);
    ui->jourDebut->setMaximum(31);
    ui->jourDebut->setPrefix("Jour : ");


    /*moi de début de la location*/
    ui->moisDebut->setMinimum(1);
    ui->moisDebut->setMaximum(12);
    ui->moisDebut->setPrefix("Mois : ");

    /*année de début de la location*/
    ui->anneeDebut->setMinimum(2016);
    ui->anneeDebut->setMaximum(2020);
    ui->anneeDebut->setPrefix("Annee : ");

    /*bouton valider location*/
    ui->valider->setToolTip("Louer une voiture");
    ui->valider->setFont(QFont("Comic Sans MS"));
    ui->valider->setCursor(Qt::PointingHandCursor);

    /* ajout du texte*/

    ui->prix_texte->setFont(QFont("Comic Sans MS"));

    /*couleur du QLabel*/
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::blue);
    ui->prix_texte->setPalette(*palette);

    /*creation liste chauffeur*/
    ui->saisie->setText("Saisir nom chauffeur");
    ui->saisie->setFont(QFont("Comic Sans MS"));
    ui->saisie->setEnabled(false);




    /*Par défaut voiture*/
    location = new Location();
    location->setVehicule(new Voiture());
    location->getVehicule()->setModele(ui->comboBox->currentText().toStdString());
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete location;
}

void MainWindow::on_pushButton_clicked()
{
    // Add button clicked
    // Adding at the end

    // Get the position
    int row = model->rowCount();

    // Enable add one or more rows
    model->insertRows(row,1);

    // Get the row for Edit mode
    QModelIndex index = model->index(row);

    // Enable item selection and put it edit mode
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_2_clicked()
{
    // Insert button clicked

    // Get the position
    int row = ui->listView->currentIndex().row();

    // Enable add one or more rows
    model->insertRows(row,1);

    // Get row for Edit mode
    QModelIndex index = model->index(row);

    // Enable item selection and put it edit mode
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void MainWindow::on_pushButton_3_clicked()
{
    // Delete button clicked
    // For delete operation,
    // we're dealing with a Model not a View
    // Get the position
    model->removeRows(ui->listView->currentIndex().row(),1);
}

void MainWindow::on_bouton_electrique_clicked()
{
    location->setElectrique(true);
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
}

void MainWindow::on_bouton_sans_electrique_clicked()
{
    location->setElectrique(false);
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
}

void MainWindow::on_bouton_chauffeur_clicked()
{
    location->setChauffeur(new Chauffeur("Jean"));
    if(ui->saisie->text().toStdString() == "Saisir nom chauffeur"){
        location->setChauffeur(new Chauffeur("Jean"));
    }else{
        location->setChauffeur(new Chauffeur(ui->saisie->text().toStdString()));
    }
    ui->saisie->setEnabled(true);
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
}

void MainWindow::on_bouton_sans_chauffeur_clicked()
{
    location->setChauffeur(NULL);
    ui->saisie->setEnabled(false);
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
}

void MainWindow::on_bouton_bus_clicked()
{
    location->setVehicule(new Bus());
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
    ui->groupChauffeur->setEnabled(true);
    ui->groupElectrique->setEnabled(false);
    ui->comboBox->setEnabled(false);
}

void MainWindow::on_bouton_voiture_clicked()
{
    location->setVehicule(new Voiture());
    location->getVehicule()->setModele(ui->comboBox->currentText().toStdString());
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
    ui->groupChauffeur->setEnabled(true);
    ui->groupElectrique->setEnabled(false);
    ui->comboBox->setEnabled(true);
}

void MainWindow::on_bouton_velo_clicked()
{
    location->setVehicule(new Velo());
    location->setChauffeur(NULL);
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
    ui->groupChauffeur->setEnabled(false);
    ui->groupElectrique->setEnabled(true);
    ui->comboBox->setEnabled(false);
}


void MainWindow::on_valider_clicked()
{
    int reponse = QMessageBox::question(this, "Valider location", "Voulez-vous valider la location ?",
                          QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes){
        if(ui->bouton_sans_chauffeur->isChecked() || ui->bouton_velo->isChecked()){
            location->setDateDebut(ui->jourDebut->value(), ui->moisDebut->value(), ui->anneeDebut->value());
            location->save();
            QMessageBox::information(this, "Validation OK", QString::fromStdString(location->decrit()));
        }else{
            location->setDateDebut(ui->jourDebut->value(), ui->moisDebut->value(), ui->anneeDebut->value());
            location->save();
            QMessageBox::information(this, "Validation OK", QString::fromStdString(location->decrit()));
        }
    }
}




void MainWindow::on_comboBox_activated(const QString &arg1)
{
    location->getVehicule()->setModele(arg1.toStdString());
    ui->prix_texte->setText(QString::fromStdString(location->decrit()));
}
