#ifndef PERSO_H
#define PERSO_H

#include <QString>
#include <QSqlQueryModel>
class perso
{
public:
    perso();
    perso(QString,QString,QString,int,QString);
    //les getteurs
    QString getnom();
    QString getprenom();
    QString getpassword();
    int getcin_e();
    QString getphotos();
    //les setteurs
    void setnom(QString);
    void setprenom(QString);
    void setpassword(QString);
    void setcin_e(int);
    void setphotos(QString);
    /*CRUD*/
    bool ajouter();
    QSqlQueryModel* afficher();///requette de password sql
    bool supprimer(QString);
    bool modifier(QString nom);
    /*trier les persos*/
QSqlQueryModel * trinom();
QSqlQueryModel * triprenom();
QSqlQueryModel * tripassword();
/*chercher un perso*/
bool chercher_nom();
bool chercher_prenom();
bool chercher_password();
bool login(int cine, QString password);
private:
    QString nom;
    QString prenom;
    QString password;
    int cin_e;
     QString photos;
};

#endif // PERSO_H
