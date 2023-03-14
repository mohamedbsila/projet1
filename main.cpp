
#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include "login1.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    bool test=c.createconnect();
   // login1 w;
 MainWindow k;
 k.show();
 int conn=2;
   while(conn==1){

    //  k.show();
    // k.close();
      conn=2;
 }



    if(test)
    {
    //w.show();
    QMessageBox::information(nullptr,QObject::tr("Bienvenue"),
                             QObject::tr("connection successful aahahahah.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr,QObject::tr("Bienvenue"),
                                 QObject::tr("connection Failed.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}

