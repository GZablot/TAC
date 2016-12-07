#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create model
    model = new QStringListModel(this);

    // Make data
    QStringList List;
    List << "Peugeot 3008" << "Renault Clio" << "Renault Espace" << "Renault Megane" << "Peugeot 308" ;

    // Populate our model
    model->setStringList(List);

    // Glue model and view together
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    // Add additional feature so that
    // we can manually modify the data in ListView
    // It may be triggered by hitting any key or double-click etc.
    ui->listView->
            setEditTriggers(QAbstractItemView::AnyKeyPressed |
                            QAbstractItemView::DoubleClicked);

    //setFixedSize(600, 380);



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
    vehicule = new Voiture();
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");


}

MainWindow::~MainWindow()
{
    delete ui;
    delete vehicule;
    delete location;
    delete chauffeur;
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
    vehicule->setElectrique(true);
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");
}

void MainWindow::on_bouton_sans_electrique_clicked()
{
    vehicule->setElectrique(false);
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");
}

void MainWindow::on_bouton_chauffeur_clicked()
{
    if(ui->saisie->text().toStdString() == "Saisir nom chauffeur"){
        chauffeur = new Chauffeur("Jean");
    }else{
        chauffeur = new Chauffeur(ui->saisie->text().toStdString());
    }
    ui->saisie->setEnabled(true);
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix() + this->chauffeur->getPrix())) + "€");
}

void MainWindow::on_bouton_sans_chauffeur_clicked()
{
    ui->saisie->setEnabled(false);
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");
}

void MainWindow::on_bouton_bus_clicked()
{
    vehicule = new Bus();
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");
    ui->groupChauffeur->setEnabled(true);
    ui->groupElectrique->setEnabled(false);
}

void MainWindow::on_bouton_voiture_clicked()
{
    vehicule = new Voiture();
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");
    ui->groupChauffeur->setEnabled(true);
    ui->groupElectrique->setEnabled(false);
}

void MainWindow::on_bouton_velo_clicked()
{
    vehicule = new Velo();
    chauffeur = NULL;
    ui->prix_texte->setText("Prix à payer : " + QString::fromStdString(std::to_string(this->vehicule->getPrix())) + "€");
    ui->groupChauffeur->setEnabled(false);
    ui->groupElectrique->setEnabled(true);
}


void MainWindow::on_valider_clicked()
{
    std::cout << "Validation" << std::endl;
    //TODO verifier si un bouton entre velo,bus est check
    int reponse = QMessageBox::question(this, "Valider location", "Voulez-vous valider la location ?",
                          QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes){
        if(ui->bouton_sans_chauffeur->isChecked() || ui->bouton_velo->isChecked()){
            location = new Location(vehicule);
            this->location->setPrix(this->vehicule->getPrix());
            QMessageBox::information(this, "Validation OK", QString::fromStdString(location->afficheSansChauffeur()));
        }else{
            location = new Location(vehicule, chauffeur);
            this->location->setPrix(this->vehicule->getPrix() + this->chauffeur->getPrix());
            QMessageBox::information(this, "Validation OK", QString::fromStdString(location->afficheAvecChauffeur()));
        }
    }
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    //QModelIndex i = ui->listView->currentIndex();
    QString texte = index.data(Qt::DisplayRole).toString();
    std::cout << texte.toStdString() << std::endl;
}
