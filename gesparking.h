#ifndef GESPARKING_H
#define GESPARKING_H
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include <QWidget>
#include <QTableWidget>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QHeaderView>
class Gesparking : public QWidget
{
    Q_OBJECT
public:
    explicit Gesparking(QWidget *parent = nullptr);
private slots:
    void onprintclicked();
    void onaddclicked();
    void onmodifyclicked();
    void ondeleteclicked();
    void closeadd();
protected:
    QtMaterialSnackbar *selectwarning;
    QtMaterialRaisedButton *addbtn,*addbtn2,*cancelbtn,*deletebtn,*modifybtn, *printpdf;
    QTableWidget *parkingtable;
    QtMaterialTextField *txtspot,*txtcarowner,*txtlicense;
    QWidget* gparking,*tablewidget,*transparentbg,*customdrawer;
signals:

};

#endif // GESPARKING_H
