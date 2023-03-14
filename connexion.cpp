
#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("mouhanned");
db.setUserName("mohamed");//inserer nom de l'utilisateur
db.setPassword("b52100610");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connexion::closeConnection(){db.close();}

