#include "perso.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QCryptographicHash>

perso::perso()
{
nom=" " ;prenom=" " ;password=" ";cin_e=0;photos=" ";
}
perso::perso(QString nom,QString prenom,QString password,int cin_e,QString photos)
{
    this->nom=nom;
    this->prenom=prenom;
    this->password=password;
    this->cin_e=cin_e;
    this->photos=photos;
}
QString perso::getnom()
{return nom;}
QString perso::getprenom()
{return prenom;}
QString perso::getpassword()
{return password;}
int perso::getcin_e()
{return cin_e;}
QString perso::getphotos()
{return photos;}
void perso::setnom(QString nom)
{this->nom=nom;}
void perso::setprenom(QString prenom)
{this->prenom=prenom;}
void perso::setpassword(QString password)
{this->password=password;}
void perso::setcin_e(int cin_e)
{this->cin_e=cin_e;}
void perso::setphotos(QString photos)
{this->photos=photos;}

bool perso::ajouter()
{
    // Hash the password using the SHA-256 algorithm
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Convert the hash to a hexadecimal string
    QString hashString = QString::fromLatin1(hash.toHex());

    QSqlQuery query;
    QString nom_string= QString(nom);
    QString prenom_string= QString(prenom);
    QString cin_e_string= QString::number(cin_e);
    QString photos_string= QString(photos);
    query.prepare("INSERT INTO boukaBouka (nom, password, prenom, cine, photos) "
                  "VALUES (:cin_e, :prenom , :password, :nom, :photos)");
    query.bindValue(":nom", nom_string);
    query.bindValue(":prenom", prenom_string);
    query.bindValue(":password", hashString); // Use the hashed password instead of the plain text password
    query.bindValue(":cin_e", cin_e_string);
    query.bindValue(":photos", photos_string);
    return query.exec();
}

bool perso::supprimer(QString nom)
{
    QSqlQuery query;

    query.prepare("Delete from boukaBouka ");
    query.bindValue(":nom", nom);
      return query.exec();

}
QSqlQueryModel* perso::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM boukaBouka");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("photos"));
    return model;

}

    bool perso::modifier(QString nom)
      {
          QSqlQuery query;
          QString res= QString(nom);
          // Hash the password using the SHA-256 algorithm
          QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

          // Convert the hash to a hexadecimal string
          QString hashString = QString::fromLatin1(hash.toHex());
          query.prepare("UPDATE boukaBouka SET nom=:nom, password=:password, prenom=:prenom ,photos=:photos WHERE cin=:cin");
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":password", hashString);
          query.bindValue(":cin_e", cin_e);
          query.bindValue(":photos", photos);


          return    query.exec();
}

 QSqlQueryModel * perso::trinom(){


  QSqlQueryModel *model = new QSqlQueryModel();


        model->setQuery("select * FROM boukaBouka order by cine");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
        return  model;
 }
 QSqlQueryModel * perso::triprenom(){


  QSqlQueryModel *model = new QSqlQueryModel();

        model->setQuery("select nom,prenom,password,cine FROM boukaBouka order by prenom ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
        return  model;
 }
QSqlQueryModel * perso::tripassword()
{
    QSqlQueryModel *model = new QSqlQueryModel();

          model->setQuery("select nom,prenom,password,cine FROM boukaBouka order by password");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
          return  model;
}
bool perso::chercher_nom()
{

    QSqlQuery query;

            QSqlQueryModel* model=new QSqlQueryModel();

               query.prepare("select nom,prenom,password,cine from boukaBouka where nome=nom " );
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));

                  return model;

}
bool perso::chercher_prenom()
{
    QSqlQuery query;

            QSqlQueryModel* model=new QSqlQueryModel();

               query.prepare("select nom,prenom,password,cine from boukaBouka where prenomx=prenom " );
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));

                  return model;
}
bool perso::chercher_password()
{
    QSqlQuery query;

            QSqlQueryModel* model=new QSqlQueryModel();

               query.prepare("select nom,prenom,password,cine from boukaBouka where passworde=password " );
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));

                  return model;
}
bool login(int cine, QString password)
{
    // Hash the password using the SHA-256 algorithm
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Convert the hash to a hexadecimal string
    QString hashString = QString::fromLatin1(hash.toHex());

    QSqlQuery query;
    query.prepare("SELECT * FROM boukaBouka WHERE cine = :cine");
    query.bindValue(":cine", cine);

    if(query.exec() && query.next()) {
        // Retrieve the hashed password from the database
        QString hashedPassword = query.value("password").toString();

        // Compare the hashed password with the user's hashed password
        if (hashedPassword == hashString) {
            // Login successful
            return true;
        }
    }

    // Login failed
    return false;
}
