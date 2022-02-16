#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{

}
bool Database::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("lasttime");
db.setUserName("plswork");
db.setPassword("esprit18");

if (db.open()){
test=true; qDebug() << "database opened";}
 return  test;
}
void Database::closeconnection(){
    db.close();
    qDebug() << "database closed";
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
bool Database::loginconnection(QString username, QString password){
    bool connected = false;
    QSqlQuery query(QSqlDatabase::database("lasttime"));
    query.prepare(QString("SELECT * FROM ACCOUNTS WHERE USERNAME =:username AND PASSWORD =:password"));
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    if(!query.exec()){qDebug() <<"failed exec";}
    else{
        while(query.next()){
            QString usernameFromDB=query.value(1).toString();
            QString passwordFromDB=query.value(2).toString();
            if ((usernameFromDB == username )&& (passwordFromDB == password))connected = true;
            }
    }
    return connected;
}
void Database::showtable(){
    int num_rows=0,r=0,c=0;
    loading = true;
    QSqlQuery q(QSqlDatabase::database("lasttime"));
    if(!q.exec("SELECT count(ID) AS num_rows FROM PRODUCTS")) qDebug() << q.lastError().text();
    q.first();
    num_rows=q.value(0).toInt();
    table->setRowCount(num_rows);
    table->setSortingEnabled(false);
    if(!q.exec("SELECT * FROM PRODUCTS")) qDebug() <<q.lastError().text();
    for(r=0,q.first();q.isValid();q.next(),++r){
        for(c=0;c<5;++c){
            table->setItem(r,c, new QTableWidgetItem(q.value(c).toString()));
        }
    }
    loading = false;
}
void Database::addproduct(QString pname,QString ptype,QString pdate,QString pquantity){

    QSqlQuery query(QSqlDatabase::database("lasttime"));
    int num_rows;
    if(!query.exec("SELECT count(ID) AS num_rows FROM PRODUCTS")) qDebug() << query.lastError().text();
    else{
    query.first();
    num_rows=query.value(0).toInt()+1;
    query.prepare("INSERT INTO PRODUCTS (ID, PNAME, PTYPE, PDATE, PQUANTITY) VALUES (:ID, :pname, :ptype, :pdate, :pquantity)");
    query.bindValue(":ID",num_rows);
    query.bindValue(":pname",pname);
    query.bindValue(":ptype",ptype);
    query.bindValue(":pdate",pdate);
    query.bindValue(":pquantity",pquantity);
    if(query.exec()) qDebug() <<"added product";}
}

void Database::changetable(){
    if (loading){loading = false; return;}
}
bool Database::updatetable(int id, QString pname, QString ptype, QString pdate ,QString pquantity){
    bool done = false; int num_rows;
    QString res = QString::number(id);
    QSqlQuery query(QSqlDatabase::database("lasttime"));
    if(!query.exec("SELECT count(ID) AS num_rows FROM PRODUCTS")) qDebug() << query.lastError().text();
    query.first();
    num_rows=query.value(0).toInt();
    if((res <= num_rows)&&(res > 0)){
    query.prepare("UPDATE PRODUCTS SET PNAME =:pname, PTYPE =:ptype, PQUANTITY =:pquantity, PDATE =:pdate WHERE ID =:ID");
    query.bindValue(":ID",res);
    query.bindValue(":pname",pname);
    query.bindValue(":ptype",ptype);
    query.bindValue(":pdate",pdate);
    query.bindValue(":pquantity",pquantity);
    if(!query.exec()) qDebug() <<query.lastError().text();
    else done = true;}
    return done;
}
bool Database::deletetable(int id){
    bool done = false;int num_rows;
    QString res = QString::number(id);
    QSqlQuery query(QSqlDatabase::database("lasttime"));if(!query.exec("SELECT count(ID) AS num_rows FROM PRODUCTS")) qDebug() << query.lastError().text();
    query.first();
    num_rows=query.value(0).toInt();
    if((res <= num_rows)&&(res > 0)){
    query.prepare("DELETE FROM PRODUCTS WHERE ID=:ID");
    query.bindValue(":ID",res);
    if(query.exec()) done = true;
    else done = false;}
    return done;
}
Database::~Database(){

}
