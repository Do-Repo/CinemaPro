#ifndef GESPRODUIT_H
#define GESPRODUIT_H
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include <QWidget>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QGraphicsEffect>
#include <QTableView>
#include <QPropertyAnimation>
#include <QHeaderView>
#include "database.h"
class Gesproduit : public QWidget
{
    Q_OBJECT
public:
    explicit Gesproduit(QWidget *parent = nullptr);
private:
    Database tempdb;
private slots:
    void onprintclicked();
    void onaddclicked();
    void ondeleteclicked();
    void onmodifyclicked();
    void addproduct();
    void productmodified();
    void deleted();
    void closeadd();
public:
    QPropertyAnimation *A_customdrawer,*A_transbg;
    QtMaterialSnackbar *selectwarning;
    QtMaterialRaisedButton *addbtn,*addbtn2,*addbtn3,*cancelbtn,*deletebtn,*deletebtn2,*modifybtn, *printpdf;
    QTableWidget *producttable;
    QtMaterialTextField *txttype,*txtid,*txtname,*txtquantity,*txtvalid;
    QWidget* gproduit,*tablewidget,*transparentbg,*customdrawer;
signals:

};

#endif // GESPRODUIT_H
