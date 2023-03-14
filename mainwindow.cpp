#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "perso.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QFileInfo>
#include <QLineEdit>
#include "statistique.h"
#include"connexion.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
  //  ui->le_nom->setValidator( new QIntValidator(9999999, 100000000, this));///accepte seulement les entiers
   //    ui->le_nom->setValidator( new QIntValidator(0, 99999999, this));
  // ui->le_password->setValidator( new QIntValidator(9999999, 100000000, this));
    QRegExp rx("[A-Z][a-z]*");
   // ui->le_cin->setValidator(new QRegExpValidator(rx, this));
   // ui->le_password->setValidator(new QRegExpValidator(rx, this));
    //ui->tab_perso->setModel(o.afficher());

    QRegularExpression passwordRegex("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    QValidator* passwordValidator = new QRegularExpressionValidator(passwordRegex, this);
  //  ui->le_prenom->setValidator(passwordValidator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString  cheminAbsolu;
void MainWindow::on_pb_ajouter_clicked()
{


    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString password=ui->le_password->text();


    int cin_e=ui->le_cin->text().toInt();
      QString photos;

       photos=cheminAbsolu;


    perso o(nom,prenom,password,cin_e,photos);
    bool test=o.ajouter();

    if (test){

    QMessageBox::information(nullptr, QObject::tr("Ajout d'un perso"),
                           QObject::tr("Ajout effectué\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );
    ui->tab_perso->setModel(o.afficher());//refreche
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Ajout d'un perso"),
                               QObject::tr("Ajout non effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );
     }
    //tasyi9a
  ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_password->clear();
    ui->le_cin->clear();
}

void MainWindow::on_pb_supprimer_clicked()
{
    perso o1; o1.setnom(ui->le_nom_supp->text());

    bool test=o1.supprimer(o1.getnom());
    if (test){

    QMessageBox::information(nullptr, QObject::tr("Supprimer un perso"),
                           QObject::tr("Supprimer effectué\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );
    ui->tab_perso->setModel(o.afficher());//refreche
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un perso"),
                               QObject::tr("Supprimer non effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );}
    ui->le_nom_supp->clear();



}
void MainWindow::on_pb_modifier_clicked()
{
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString password=ui->le_password->text();
    int cin_e=ui->le_cin->text().toInt();
QString photos=cheminAbsolu;
        perso o(nom,prenom,password,cin_e,photos);


         bool test=o.modifier(o.getnom());
         if(test)
       {
             ui->tab_perso->setModel( o.afficher());//refresh

       QMessageBox::information(nullptr, QObject::tr("Modifier un perso"),
                         QObject::tr("client modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else{
             QMessageBox::critical(nullptr, QObject::tr("Modifier un perso"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}

         ui->le_nom->clear();
         ui->le_prenom->clear();
         ui->le_password->clear();
         ui->le_cin->clear();
}


QString MainWindow::on_pb_image_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename, QString()) !=0)
    {
        QImage image;

        bool valid = image.load(filename);
        if(valid)
        {
             ui->tb_image->setPixmap(QPixmap::fromImage(image));
             QFileInfo fileinfo(filename);
             cheminAbsolu =fileinfo.filePath();
             ui->label_image->setText(cheminAbsolu);
            QMessageBox::information(nullptr, QObject::tr("Image importer\n"),
                                     QObject::tr("Imporation de image avec succée\n""Click Cancel to exit."), QMessageBox::Cancel);
            return cheminAbsolu;

        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Image importer"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            //erreur
        }
    }

}


void MainWindow::on_pb_trier_nom_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.trinom();
                   if(test){


                 QMessageBox::information(nullptr, QObject::tr("trier les  persos par nom"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                  ui->tableView->setModel(o.trinom());

               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  persos par nom"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );

}

void MainWindow::on_pb_trier_prenom_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.triprenom();
                   if(test){
 ui->tableView->setModel(o.triprenom());

                 QMessageBox::information(nullptr, QObject::tr("trier les  persos par prenom"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);



               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  persos par prenom"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );


}

void MainWindow::on_pb_trier_password_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.tripassword();
                   if(test){
 ui->tableView->setModel(o.tripassword());

                 QMessageBox::information(nullptr, QObject::tr("trier les  persos par password"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);



               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  persos par password"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );


}
void MainWindow::on_pb_chercher_nom_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString nome;

                perso o;
    nome =o.getnom();

        nome= ui->le_nom_ch->text();

        model->setQuery("Select * from boukaBouka "
                        "where nom='"+nome+"' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));


           bool test=o.chercher_nom();
           if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("affichage perso .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(model);
         ui->tableView->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }



}
void MainWindow::on_pb_chercher_prenom_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString prenomx;

                perso o;
    prenomx =o.getprenom();

        prenomx= ui->le_prenom_ch->text();
        qDebug() << "Before creating model: model = " << model;
        model = new QSqlQueryModel();
        qDebug() << "After creating model: model = " << model;
        model->setQuery("Select * from boukaBouka "
                        "where prenom='666' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));

           /*if (model == nullptr) {
               // model is null
               QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                                 QObject::tr("null .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           } else {
               // model is not null
               QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                                 QObject::tr("not .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           }*/

           bool test=o.chercher_prenom();
           if(test)
         {
         /*QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("affichage perso .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);*/
         ui->tableView->setModel(model);
         ui->tableView->show();
model = nullptr;

    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }


}

/*void MainWindow::on_pb_chercher_password_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString passworde;

                perso o;
    passworde =o.getpassword();

        passworde= ui->le_password_ch->text();

        model->setQuery("Select * from booukaBouka "
                        "where password='"+passworde+"' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));


           bool test=o.chercher_password();
           if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("affichage perso .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(model);
         ui->tableView->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }


}

*/
void MainWindow::on_pb_login_clicked()
{
    QString cinee = ui->le_cin_2->text();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM booukaBouka WHERE cine='" + cinee + "'");

    if (model->rowCount() > 0) {
        // the value of cinee was found in the database
        QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                    QObject::tr("Erreur .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::information(nullptr, QObject::tr("Ajout d'un perso"),
                               QObject::tr("Ajout effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );
    }
}








void MainWindow::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
login1 w;
w.show();

}










void MainWindow::on_pb_chercher_nom_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString nome;

                perso o;
    nome =o.getnom();

        nome= ui->le_cin_2->text();

        model->setQuery("Select * from boukaBouka "
                        "where nom='"+nome+"' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));


           bool test=o.chercher_nom();
           if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("affichage perso .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(model);
         ui->tableView->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un perso"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }



}
