#include "client.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QRegularExpression>
#include <QMessageBox>

client::client(int id_client, QString nom_client, QString prenom_client, QString adresse, int num_tel, QString email)
{
    this->id_client = id_client;
    this->nom_client = nom_client;
    this->prenom_client = prenom_client;
    this->adresse = adresse;
    this->num_tel = num_tel;
    this->email = email;
}

// Function to validate if input is numeric (for id_client and num_tel)
bool client::isNumeric(QString str) {
    bool ok;
    str.toInt(&ok);  // Check if the string can be converted to an integer
    return ok;
}

// Function to validate if input is alphabetic (for nom_client, prenom_client, and adresse)
bool client::isAlphabetic(QString str) {
    QRegularExpression re("^[A-Za-z\\s]+$");  // Only letters and spaces allowed
    return re.match(str).hasMatch();
}

// Function to validate if input is a valid email format
bool client::isValidEmail(QString email) {
    QRegularExpression re("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    return re.match(email).hasMatch();
}

// Validation for numeric inputs (id_client and num_tel)
bool client::validateNumericInputs() {
    if (!isNumeric(QString::number(id_client))) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("id client doit étre numérique."));
        return false;
    }
    if (!isNumeric(QString::number(num_tel))) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("num tel doit étre numérique."));
        return false;
    }
    return true;
}

// Validation for alphabetic inputs (nom_client, prenom_client, adresse)
bool client::validateAlphabeticInputs() {
    if (!isAlphabetic(nom_client)) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("Le nom doit contenir uniquement des caractères alphabétiques."));
        return false;
    }
    if (!isAlphabetic(prenom_client)) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("Le prenom doit contenir uniquement des caractères alphabétiques."));
        return false;
    }
    if (!isAlphabetic(adresse)) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("L'adresse doit contenir uniquement des caractères alphabétiques."));
        return false;
    }
    return true;
}

// Validation for email format
bool client::validateEmail() {
    if (!isValidEmail(email)) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("Format d'email invalide."));
        return false;
    }
    return true;
}

// Adding a client (ajouter)
bool client::ajouter()
{
    // Validate numeric inputs (id_client and num_tel)
    if (!validateNumericInputs()) {
        return false;
    }

    // Validate alphabetic inputs (nom_client, prenom_client, adresse)
    if (!validateAlphabeticInputs()) {
        return false;
    }

    // Validate email format
    if (!validateEmail()) {
        return false;
    }

    QSqlQuery query;
    QString res = QString::number(id_client);

    query.prepare("insert into client(id_client, nom_client, prenom_client, adresse, email, num_tel)"
                  " values(:id_client, :nom_client, :prenom_client, :adresse, :email, :num_tel)");

    query.bindValue(":id_client", res);
    query.bindValue(":nom_client", nom_client);
    query.bindValue(":prenom_client", prenom_client);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":num_tel", num_tel);

    return query.exec(); // Execute the query
}

// Display clients in a model (afficher)
QSqlQueryModel* client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM client");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));

    return model;
}

// Delete a client (supprimer)
bool client::supprimer(int id_client)
{
    // Validate numeric input (id_client)
    if (!isNumeric(QString::number(id_client))) {
        QMessageBox::critical(nullptr, QObject::tr("Input Error"),
                              QObject::tr("ID Client must be numeric."));
        return false;
    }

    QSqlQuery query;
    QString res = QString::number(id_client);

    query.prepare("delete from client where id_client = :id_client");
    query.bindValue(":id_client", res);
    return query.exec();
}

// Update client data (update)
bool client::update(int id_client, QString nom_client, QString prenom_client, QString adresse, int num_tel, QString email)
{
    // Validate numeric inputs (id_client and num_tel)
    if (!validateNumericInputs()) {
        return false;
    }

    // Validate alphabetic inputs (nom_client, prenom_client, adresse)
    if (!validateAlphabeticInputs()) {
        return false;
    }

    // Validate email format
    if (!validateEmail()) {
        return false;
    }

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
