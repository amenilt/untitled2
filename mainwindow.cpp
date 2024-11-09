#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "client.h"



#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(cl.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
//recuperer les données
int id_client=ui->lineEdit_ID_client->text().toInt();
QString nom_client=ui->lineEdit_nom_client->text();
QString prenom_client=ui->lineEdit_prenom_client->text();
int num_tel=ui->lineEdit_num_tel->text().toInt();
QString adresse=ui->lineEdit_adresse->text();
QString email=ui->lineEdit_email->text();
client cl(id_client, nom_client, prenom_client, adresse, num_tel, email);


bool test=cl.ajouter();
if(test)
{
    ui->tableView->setModel(cl.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("ajout effectué\n" "click to exit."));


}
else {
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("ajout non effectué.\n""click cancel to exit"),
                          QMessageBox::Cancel);
}
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_client=ui->lineEdit_ID_client->text().toInt();
    bool test=cl.supprimer(id_client);
    if(test)
    {
        ui->tableView->setModel(cl.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectué\n" "click to exit."));


    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("ajout non effectué.\n""click cancel to exit"),
                              QMessageBox::Cancel);

}
}

void MainWindow::on_pushButton_update_clicked() {
    int id_client = ui->lineEdit_ID_client->text().toInt();
    QString nom_client = ui->lineEdit_nom_client->text();
    QString prenom_client = ui->lineEdit_prenom_client->text();
    int num_tel = ui->lineEdit_num_tel->text().toInt();
    QString adresse = ui->lineEdit_adresse->text();
    QString email = ui->lineEdit_email->text();


    bool test = cl.update(id_client, nom_client, prenom_client, adresse, num_tel, email);
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("update effectué\n" "click to exit."));
    } else {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("update non effectué.\n" "click cancel to exit."),
                              QMessageBox::Cancel);
    }
}


