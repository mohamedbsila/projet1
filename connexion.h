
#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "mainwindow.h"
class Connexion
{
    QSqlDatabase db;
public:
    Connexion();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECXION_H


