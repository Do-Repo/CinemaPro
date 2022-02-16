#include "gesproduit.h"
#include <QDebug>


Gesproduit::Gesproduit(QWidget *parent) : QWidget(parent)
{

    gproduit = new QWidget(this);
    gproduit->setGeometry(QRect(0,0,600,480));
    gproduit->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Product");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Product");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Product");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,170,120,30));
    printpdf->setHaloVisible(false);

    tablewidget = new QWidget(this);
    tablewidget->setGeometry(160,20,400,410);
    tablewidget->setStyleSheet("background-color: white;"
                               "border-radius: 10px");
    tempdb.createconnect();
    tempdb.table = new QTableWidget(100,5,tablewidget);
    tempdb.table->setGeometry(0,10,447,400);
    tempdb.table->setStyleSheet("background:transparent");
    tempdb.table->verticalHeader()->setVisible(false);
    tempdb.table->setHorizontalHeaderLabels(QStringList() <<" ID" <<"P. Name" << "P. Type" << "Quantity" <<"Valid until");
    tempdb.table->hideColumn(0);
    tempdb.showtable();
    tempdb.closeconnection();

    transparentbg = new QWidget(this);
    transparentbg->setGeometry(QRect(-500,0,500,600));
    transparentbg->setStyleSheet("background-color: rgba(0, 0, 0, 0.75);"
                                 "border-radius: 0px;");

    customdrawer = new QWidget(this);
    customdrawer->setGeometry(QRect(-300,0,300,600));
    customdrawer->setStyleSheet("background-color: white;"
                                "border-radius: 0px;");

    addbtn2 = new QtMaterialRaisedButton(customdrawer);
    addbtn2->setText("Add");
    addbtn2->setHaloVisible(false);
    addbtn2->setGeometry(QRect(45,420,120,30));

    addbtn3 = new QtMaterialRaisedButton(customdrawer);
    addbtn3->setText("Modify");
    addbtn3->setHaloVisible(false);
    addbtn3->setGeometry(QRect(45,420,120,30));

    deletebtn2 = new QtMaterialRaisedButton(customdrawer);
    deletebtn2->setText("Delete");
    deletebtn2->setHaloVisible(false);
    deletebtn2->setGeometry(QRect(45,420,120,30));

    cancelbtn = new QtMaterialRaisedButton(customdrawer);
    cancelbtn->setText("Cancel");
    cancelbtn->setHaloVisible(false);
    cancelbtn->setGeometry(QRect(175,420,120,30));

    txtid = new QtMaterialTextField(customdrawer);
    txtid->setTextColor("black");
    txtid->setInkColor("black");
    txtid->setLabelColor("red");
    txtid->setLabel("Product ID");
    txtid->setGeometry(QRect(50,0,250,60));

    txtname = new QtMaterialTextField(customdrawer);
    txtname->setTextColor("black");
    txtname->setInkColor("black");
    txtname->setLabel("Product Name");
    txtname->setGeometry(QRect(50,70,250,60));

    txtquantity = new QtMaterialTextField(customdrawer);
    txtquantity->setTextColor("black");
    txtquantity->setInkColor("black");
    txtquantity->setLabel("Quantity");
    txtquantity->setGeometry(QRect(50,280,250,60));

    txttype = new QtMaterialTextField(customdrawer);
    txttype->setTextColor("black");
    txttype->setInkColor("black");
    txttype->setLabel("Type");
    txttype->setGeometry(QRect(50,140,250,60));

    txtvalid = new QtMaterialTextField(customdrawer);
    txtvalid->setTextColor("black");
    txtvalid->setInkColor("black");
    txtvalid->setLabel("Valid until");
    txtvalid->setGeometry(QRect(50,210,250,60));

    selectwarning = new QtMaterialSnackbar(tablewidget);
    connect(modifybtn, SIGNAL(clicked()),this,SLOT(onmodifyclicked()));
    connect(addbtn,SIGNAL(clicked()),this, SLOT(onaddclicked()));
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(addproduct()));
    connect(cancelbtn, SIGNAL(clicked()),this, SLOT(closeadd()));
    connect(deletebtn, SIGNAL(clicked()),this,SLOT(ondeleteclicked()));
}
void Gesproduit::onprintclicked(){

}

void Gesproduit::onaddclicked(){
    txtid->setVisible(true);
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtname->setVisible(true);
    txttype->setVisible(true);
    txtquantity->setVisible(true);
    txtvalid->setVisible(true);
    addbtn3->setVisible(false);
    deletebtn2->setVisible(false);
    txtid->setEnabled(false);
    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(customdrawer->geometry());
    A_customdrawer->setEndValue(QRect(-53,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(transparentbg->geometry());
    A_transbg->setEndValue(QRect(100,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);


}
void Gesproduit::addproduct(){
   tempdb.createconnect();
   tempdb.addproduct(txtname->text(),txttype->text(),txtvalid->text(),txtquantity->text());
   tempdb.showtable();
   tempdb.closeconnection();
   closeadd();
}
void Gesproduit::closeadd(){
    addbtn3->setVisible(false);
    addbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtid->setVisible(false);
    txtname->setVisible(false);
    txttype->setVisible(false);
    txtquantity->setVisible(false);
    txtvalid->setVisible(false);
    addbtn3->setVisible(false);
    deletebtn2->setVisible(false);

    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(QRect(-53,0,300,600));
    A_customdrawer->setEndValue(QRect(-300,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(QRect(100,0,500,600));
    A_transbg->setEndValue(QRect(-500,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
}

void Gesproduit::onmodifyclicked(){
    addbtn3->setVisible(true);
    cancelbtn->setVisible(true);
    txtname->setVisible(true);
    txttype->setVisible(true);
    txtquantity->setVisible(true);
    txtvalid->setVisible(true);
    txtid->setVisible(true);
    addbtn2->setVisible(false);
    // open animation
    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(customdrawer->geometry());
    A_customdrawer->setEndValue(QRect(-53,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(transparentbg->geometry());
    A_transbg->setEndValue(QRect(100,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
    connect(addbtn3,SIGNAL(clicked()),this,SLOT(productmodified()));
}
void Gesproduit::productmodified(){
    tempdb.createconnect();
    int id = txtid->text().toInt();
    if(!tempdb.updatetable(id,txtname->text(),txttype->text(),txtvalid->text(),txtquantity->text()))
    {
        selectwarning->addMessage("Please enter a valid ID");
        selectwarning->setTextColor("red");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();}
    else {
        selectwarning->addMessage("Product updated successfully");
        selectwarning->setTextColor("green");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();
    }
    closeadd();
    tempdb.showtable();
    tempdb.closeconnection();
}
void Gesproduit::ondeleteclicked(){
    deletebtn2->setVisible(true);
    txtname->setVisible(false);
    txtquantity->setVisible(false);
    txttype->setVisible(false);
    txtvalid->setVisible(false);
    addbtn2->setVisible(false);
    addbtn3->setVisible(false);
    cancelbtn->setVisible(true);
    txtid->setVisible(true);
    // open animation
    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(customdrawer->geometry());
    A_customdrawer->setEndValue(QRect(-53,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(transparentbg->geometry());
    A_transbg->setEndValue(QRect(100,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()));

}
void Gesproduit::deleted(){
    tempdb.createconnect();
    int id = txtid->text().toInt();
    if(!tempdb.deletetable(id))
    {
        selectwarning->addMessage("Please enter a valid ID");
        selectwarning->setTextColor("red");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();}
    else {
        selectwarning->addMessage("Product deleted successfully");
        selectwarning->setTextColor("green");
        selectwarning->setBoxWidth(400);
        selectwarning->setGeometry(QRect(0,300,400,70));
        selectwarning->setBackgroundColor("black");
        selectwarning->show();
    }
    closeadd();
    tempdb.showtable();
    tempdb.closeconnection();
}
