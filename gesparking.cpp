#include "gesparking.h"
#include <QDebug>
Gesparking::Gesparking(QWidget *parent) : QWidget(parent)
{

    gparking = new QWidget(this);
    gparking->setGeometry(QRect(0,0,600,480));
    gparking->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Car");
    addbtn->setGeometry(QRect(10,20,100,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove Car");
    deletebtn->setGeometry(QRect(10,70,100,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify Spot");
    modifybtn->setGeometry(QRect(10,120,100,30));
    modifybtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,170,100,30));
    printpdf->setHaloVisible(false);

    tablewidget = new QWidget(this);
    tablewidget->setGeometry(160,20,400,410);
    tablewidget->setStyleSheet("background-color: white;"
                               "border-radius: 10px");

    parkingtable = new QTableWidget(1,4,tablewidget);
    parkingtable->setStyleSheet("background:transparent");
    parkingtable->setGeometry(0,10,447,400);
    parkingtable->verticalHeader()->setVisible(false);
    parkingtable->setHorizontalHeaderLabels(QStringList() << "Spot N°" << "State" << "Car Owner" <<"License");
    parkingtable->setStyleSheet("background-color: transparent");


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

    cancelbtn = new QtMaterialRaisedButton(customdrawer);
    cancelbtn->setText("Cancel");
    cancelbtn->setHaloVisible(false);
    cancelbtn->setGeometry(QRect(175,420,120,30));

    txtcarowner = new QtMaterialTextField(customdrawer);
    txtcarowner->setTextColor("black");
    txtcarowner->setInkColor("black");
    txtcarowner->setLabel("Car owner");
    txtcarowner->setGeometry(QRect(50,70,250,60));

    txtlicense = new QtMaterialTextField(customdrawer);
    txtlicense->setTextColor("black");
    txtlicense->setInkColor("black");
    txtlicense->setLabel("License plate");
    txtlicense->setGeometry(QRect(50,140,250,60));

    txtspot = new QtMaterialTextField(customdrawer);
    txtspot->setTextColor("black");
    txtspot->setInkColor("black");
    txtspot->setLabel("Car spot:");
    txtspot->setGeometry(QRect(50,0,250,60));

    selectwarning = new QtMaterialSnackbar(tablewidget);


    connect(modifybtn, SIGNAL(clicked()),this,SLOT(onmodifyclicked()));
    connect(deletebtn, SIGNAL(clicked()), this, SLOT(ondeleteclicked()));
    connect(addbtn, SIGNAL(clicked()),this, SLOT(onaddclicked()));
    connect(cancelbtn, SIGNAL(clicked()),this, SLOT(closeadd()));
}

void Gesparking::onprintclicked(){

}

void Gesparking::onaddclicked(){
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtcarowner->setVisible(true);
    txtlicense->setVisible(true);
    txtspot->setVisible(true);
    QPropertyAnimation *A_customdrawer,*A_transbg;
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
void Gesparking::closeadd(){
    addbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtcarowner->setVisible(false);
    txtlicense->setVisible(false);
    txtspot->setVisible(false);
    QPropertyAnimation *A_customdrawer,*A_transbg;
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
void Gesparking::onmodifyclicked(){
    selectwarning->addMessage("Please select the information you want to modify");
    selectwarning->setTextColor("red");
    selectwarning->setBoxWidth(400);
    selectwarning->setGeometry(QRect(0,300,400,70));
    selectwarning->setBackgroundColor("black");
    selectwarning->show();
}
void Gesparking::ondeleteclicked(){

    selectwarning->addMessage("Please select the information you want to delete");
    selectwarning->setTextColor("red");
    selectwarning->setBoxWidth(400);
    selectwarning->setGeometry(QRect(0,300,400,70));
    selectwarning->setBackgroundColor("black");
    selectwarning->show();
}
