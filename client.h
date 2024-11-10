#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>

class client
{
public:
    // Constructor
    client(int id_client = 0, QString nom_client = "", QString prenom_client = "", QString adresse = "", int num_tel = 0, QString email = "");

    // Functions to manage client data
    bool ajouter();
    bool supprimer(int id_client);
    bool update(int id_client, QString nom_client, QString prenom_client, QString adresse, int num_tel, QString email);
    QSqlQueryModel* afficher();

private:
    int id_client;
    QString nom_client;
    QString prenom_client;
    QString adresse;
    int num_tel;
    QString email;

    // Validation Functions
    bool isNumeric(QString str); // Check if a string is numeric (used for id_client and num_tel)
    bool isAlphabetic(QString str); // Check if a string contains only alphabetic characters (used for nom_client, prenom_client, adresse)
    bool isValidEmail(QString email); // Validate email format

    // Functions for validating inputs
    bool validateNumericInputs(); // Validate numeric inputs (id_client, num_tel)
    bool validateAlphabeticInputs(); // Validate alphabetic inputs (nom_client, prenom_client, adresse)
    bool validateEmail(); // Validate email format
};

#endif // CLIENT_H
