#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>

class client {
    QString nom_client, prenom_client, adresse, email;
    int id_client;
    int num_tel;

public:
    client() {}
    client(int id_client, QString nom_client, QString prenom_client, QString adresse, int num_tel, QString email);

    // Getters
    QString getNom_client() { return nom_client; }
    QString getPrenom_client() { return prenom_client; }
    QString getAdresse() { return adresse; }
    int getID_client() { return id_client; }
    int getNum_tel() { return num_tel; }
    QString getEmail() { return email; }

    // Setters
    void setNom_client(QString n) { nom_client = n; }
    void setPrenom_client(QString pre) { prenom_client = pre; }
    void setAdresse(QString ad) { adresse = ad; } // Correction ici
    void setID_client(int id_client) { this->id_client = id_client; }
    void setNum_tel(int num_tel) { this->num_tel = num_tel; }

    // Fonctionnalités
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool update(int id_client, QString nom_client, QString prenom_client, QString adresse, int num_tel, QString email);
};

#endif // CLIENT_H

