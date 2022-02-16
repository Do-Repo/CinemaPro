#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QHeaderView>
#include <QMainWindow>
#include <QTableWidget>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include <QGraphicsEffect>
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include "qtmaterialradiobutton.h"
#include <QLabel>
#include <qradiobutton.h>
class Database : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;
    bool loading;
public slots:
    bool createconnect();
    void closeconnection();
    bool loginconnection(QString,QString);
    void showtable();
    void changetable();
    bool updatetable(int,QString,QString,QString,QString);
    bool deletetable(int);
    void addproduct(QString,QString,QString,QString);
public:
    QTableWidget *table;
    ~Database();
    explicit Database(QObject *parent = nullptr);

signals:

};

#endif // DATABASE_H
