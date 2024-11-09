#include "client.h"
#include <QSqlQueryModel>


#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>



client::client(int id_client, QString nom_client , QString prenom_client,  QString adresse,int num_tel,QString email )
{
this -> id_client=id_client;
this -> nom_client=nom_client;
this -> prenom_client=prenom_client;
this -> adresse=adresse;
this -> num_tel=num_tel;
this -> email=email;
}

bool client::ajouter()
{
      QSqlQuery query ;
      QString res = QString::number(id_client);
      //bch nhot kal requete mtaa l securité
      query.prepare("insert into client(id_client,nom_client,prenom_client,adresse,email,num_tel)" "values(:id_client, :nom_client, :prenom_client, :adresse, :email, :num_tel)");
      //les variables liéés
      query.bindValue(":id_client",res);
      query.bindValue(":nom_client",nom_client);
      query.bindValue(":prenom_client",prenom_client);
      query.bindValue(":adresse",adresse);
      query.bindValue(":email",email);
      query.bindValue(":num_tel",num_tel);

      return query.exec(); // executer la req

}

QSqlQueryModel* client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM client");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id_client"));

    model->setHeaderData (1,Qt:: Horizontal, QObject::tr("nom_client"));

    model->setHeaderData (2,Qt:: Horizontal, QObject::tr("prenom_client"));

    return model;

    }


bool client::supprimer(int id_client)
{

    QSqlQuery query;
    QString res=QString::number(id_client);
    query.prepare("delete from client where ID= :id_client");
    query.bindValue(":id_client",res);
    return query.exec();
}

bool client::update(int id_client, QString nom_client, QString prenom_client, QString adresse,int num_tel,QString email) {
    QSqlQuery query;
    query.prepare("UPDATE client SET nom_client = :nom_client, prenom_client = :prenom_client, adresse = :adresse, num_tel = :num_tel, email = :email WHERE id_client = :id_client");

    query.bindValue(":id_client", id_client);
    query.bindValue(":nom_client", nom_client);
    query.bindValue(":prenom_client", prenom_client);
    query.bindValue(":adresse", adresse);
    query.bindValue(":num_tel", num_tel);
    query.bindValue(":email", email);

    return query.exec(); // Execute the update query
}
