#include "connection.h"

connection::connection(){}

bool connection::createconnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("CPP_Project");
    db.setUserName("amani");
    db.setPassword("oracle");
    if (db.open()) test=true;
    return test;
}

void connection::closeconnection(){db.close();}

