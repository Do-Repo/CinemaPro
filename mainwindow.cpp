#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcoreapplication.h>
#include "gesproduit.h"
#include "welcomewidget.h"
#include "gesparking.h"
#include "QSqlQuery"
#include "database.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    this->setGraphicsEffect(effect);

    bigpanel = new QWidget(this);
    //bigpanel->setParent(this);
    bigpanel->setGeometry(QRect(0,0,700,500));
    bigpanel->setStyleSheet("background-color: rgb(255,255,255);"
                            "border-radius:15px");
    sidepanel = new QWidget(this);
    //sidepanel->setParent(this);
    sidepanel->setGeometry(QRect(-200,0,350,500));
    sidepanel->setStyleSheet("background-color: rgb(51, 51, 51);"
                             "border-radius:15px");
    cinemapp = new QLabel(sidepanel);
    //cinemapp->setParent(sidepanel);
    cinemapp->setGeometry(QRect(100,0,240,490));
    cinemapp->setStyleSheet("image: url(:/images/Tekengebied 1.png);"
                            "background-color: rgba(255,255,255,0);border: 0px;");

    loginbtn = new QtMaterialRaisedButton(bigpanel);
    //loginbtn->setParent(bigpanel);
    loginbtn->setText("Login");
    loginbtn->setGeometry(QRect(210,450,200,30));
    loginbtn->setHaloVisible(false);

    quitbtn = new QtMaterialRaisedButton(bigpanel);
    //quitbtn->setParent(bigpanel);
    quitbtn->setText("Exit");
    quitbtn->setGeometry(QRect(440,450,200,30));
    quitbtn->setHaloVisible(false);

    passwordtext = new QtMaterialTextField(bigpanel);
    passwordtext->setLabel("password");
    passwordtext->setInkColor("black");
    passwordtext->setGeometry(QRect(160,200,530,60));
    passwordtext->setMaxLength(20);

    seepw = new QRadioButton(bigpanel);
    seepw->setText("");
    seepw->setGeometry(QRect(600,240,15,15));
    passwordtext->setEchoMode(QLineEdit::Password);
    connect(seepw,SIGNAL(clicked()),this,SLOT(seepassword()));

    logintext = new QtMaterialTextField(bigpanel);
    logintext->setLabel("username");
    logintext->setInkColor("black");
    logintext->setGeometry(QRect(160,100,530,60));
    logintext->setMaxLength(20);
    loginwarning = new QtMaterialSnackbar(this);

    Gproduit = new QtMaterialRaisedButton(sidepanel);
    //Gproduit->setParent(sidepanel);
    Gproduit->setText("Gestion Produit");
    Gproduit->setGeometry(QRect(800,120,200,30)); // between buttons 55 pix
    Gproduit->setHaloVisible(false);

    Gparking = new QtMaterialRaisedButton(sidepanel);
    //Gparking->setParent(sidepanel);
    Gparking->setText("Gestion Parking");
    Gparking->setGeometry(QRect(800,65,200,30));
    Gparking->setHaloVisible(false);

    quitbtn2 = new QtMaterialRaisedButton(sidepanel);
    //quitbtn2->setParent(sidepanel);
    quitbtn2->setText("Exit");
    quitbtn2->setGeometry(QRect(800,175,200,30));
    quitbtn2->setHaloVisible(false);

    welcomebtn = new QtMaterialRaisedButton(sidepanel);
    //welcome->setParent(sidepanel);
    welcomebtn->setText("Welcome");
    welcomebtn->setGeometry(QRect(800,10,200,30));
    welcomebtn->setHaloVisible(false);

    stack = new QStackedWidget(bigpanel);
    QWidget *ayesm = new Gesproduit;
    QWidget *welcome = new welcomewidget;
    QWidget *gsparking = new Gesparking;
    stack->setStyleSheet("background-color: rgb(255,255,255);");
    stack->setGeometry(QRect(1000,10,690,480));
    stack->addWidget(welcome);
    stack->addWidget(gsparking);
    stack->addWidget(ayesm);

    connect(welcomebtn, SIGNAL(clicked()),this, SLOT(onwelcomeclicked()));
    connect(Gparking, SIGNAL(clicked()),this, SLOT(onparkingclicked()));
    connect(Gproduit, SIGNAL(clicked()),this, SLOT(gesproduitclicked()));
    connect(quitbtn2, SIGNAL(clicked()),this, SLOT(quitclicked()));
    connect(quitbtn, SIGNAL(clicked()),this, SLOT(quitclicked()));
    connect(loginbtn, SIGNAL(clicked()), this, SLOT(loginclicked()));
}
void MainWindow::hidebuttons(){
    quitbtn->setVisible(false);
    loginbtn->setVisible(false);
    logintext->setVisible(false);
    seepw->setVisible(false);
    passwordtext->setVisible(false);
}
void MainWindow::loginclicked()
{
    Database db;
    db.createconnect();
    QString username = logintext->text();
    QString password = passwordtext->text();

    if(db.loginconnection(username,password)){
                QPropertyAnimation *A_sidepanel,*A_password,*A_radiobtn,*A_username,*A_loginbtn,*A_quitbtn,*A_stack,*A_quitbtn2,*A_logo,*A_welcome,*A_gparking,*A_gproduit;
                A_gparking = new QPropertyAnimation(Gparking,"geometry");
                A_username = new QPropertyAnimation(logintext,"geometry");
                A_password = new QPropertyAnimation(passwordtext,"geometry");
                A_radiobtn = new QPropertyAnimation(seepw,"geometry");
                A_gproduit = new QPropertyAnimation(Gproduit,"geometry");
                A_sidepanel = new QPropertyAnimation(sidepanel,"geometry");
                A_loginbtn = new QPropertyAnimation(loginbtn,"geometry");
                A_quitbtn = new QPropertyAnimation(quitbtn,"geometry");
                A_quitbtn2 = new QPropertyAnimation(quitbtn2,"geometry");
                A_logo = new QPropertyAnimation(cinemapp,"geometry");
                A_welcome = new QPropertyAnimation(welcomebtn,"geometry");
                A_stack = new QPropertyAnimation(stack,"geometry");
                //Duration in ms
                A_username->setDuration(1500);
                A_password->setDuration(1500);
                A_radiobtn->setDuration(1500);
                A_logo->setDuration(8000);
                A_quitbtn2->setDuration(200);
                A_loginbtn->setDuration(1500);
                A_sidepanel->setDuration(1500);
                A_quitbtn->setDuration(1500);
                A_stack->setDuration(2000);
                A_welcome->setDuration(2000);   //number 1
                A_gparking->setDuration(2100);  //number 2
                A_gproduit->setDuration(2200);  //number 3
                A_quitbtn2->setDuration(2300);  //number 4
                //set start value
                A_radiobtn->setStartValue(seepw->geometry());
                A_username->setStartValue(logintext->geometry());
                A_password->setStartValue(passwordtext->geometry());
                A_quitbtn->setStartValue(quitbtn->geometry());
                A_sidepanel->setStartValue(sidepanel->geometry());
                A_loginbtn->setStartValue(loginbtn->geometry());
                A_quitbtn2->setStartValue(quitbtn2->geometry());
                A_gparking->setStartValue(Gparking->geometry());
                A_gproduit->setStartValue(Gproduit->geometry());
                A_welcome->setStartValue(welcomebtn->geometry());
                A_stack->setStartValue(stack->geometry());
                //set end value
                A_password->setEndValue(QRect(1060,200,530,60));
                A_username->setEndValue(QRect(1060,100,530,60));
                A_radiobtn->setEndValue(QRect(900,240,15,15));
                A_logo->setEndValue(QRect(300,0,240,490));
                A_sidepanel->setEndValue(QRect(600,0,250,500));
                A_loginbtn->setEndValue(QRect(800,450,200,30));
                A_quitbtn->setEndValue(QRect(800,450,200,30));
                A_stack->setEndValue(QRect(10,10,690,480));
                A_welcome->setEndValue(QRect(0,10,200,30));     //number 1
                A_gparking->setEndValue(QRect(0,65,200,30));    //number 2
                A_gproduit->setEndValue(QRect(0,120,200,30));   //number 3
                A_quitbtn2->setEndValue(QRect(0,175,200,30));   //number 4
                //special effects
                A_password->setEasingCurve(QEasingCurve::InOutQuint);
                A_username->setEasingCurve(QEasingCurve::InOutQuint);
                A_radiobtn->setEasingCurve(QEasingCurve::InOutQuint);
                A_logo->setEasingCurve(QEasingCurve::OutQuint);
                A_stack->setEasingCurve(QEasingCurve::InOutQuint);
                A_sidepanel->setEasingCurve(QEasingCurve::InOutQuint);
                A_loginbtn->setEasingCurve(QEasingCurve::InOutQuint);
                A_quitbtn2->setEasingCurve(QEasingCurve::InOutQuint);
                A_gparking->setEasingCurve(QEasingCurve::InOutQuint);
                A_gproduit->setEasingCurve(QEasingCurve::InOutQuint);
                A_quitbtn->setEasingCurve(QEasingCurve::InOutQuint);
                A_welcome->setEasingCurve(QEasingCurve::InOutQuint);
                //hide the buttons on page switch
                connect(A_quitbtn,SIGNAL(finished()),this,SLOT(hidebuttons()));
                //delte when finished
                A_password->start(QPropertyAnimation::DeleteWhenStopped);
                A_username->start(QPropertyAnimation::DeleteWhenStopped);
                A_radiobtn->start(QPropertyAnimation::DeleteWhenStopped);
                A_stack->start(QPropertyAnimation::DeleteWhenStopped);
                A_gproduit->start(QPropertyAnimation::DeleteWhenStopped);
                A_gparking->start(QPropertyAnimation::DeleteWhenStopped);
                A_logo->start(QPropertyAnimation::DeleteWhenStopped);
                A_loginbtn->start(QPropertyAnimation::DeleteWhenStopped);
                A_quitbtn->start(QPropertyAnimation::DeleteWhenStopped);
                A_sidepanel->start(QPropertyAnimation::DeleteWhenStopped);
                A_quitbtn2->start(QPropertyAnimation::DeleteWhenStopped);
                A_welcome->start(QPropertyAnimation::DeleteWhenStopped);
                db.closeconnection();
    }else{
                loginwarning->addMessage("Invalid username or password");
                loginwarning->setTextColor("red");
                loginwarning->setBoxWidth(400);
                loginwarning->setGeometry(QRect(210,430,430,70));
                loginwarning->setBackgroundColor("black");
                loginwarning->show();}


}
void MainWindow::onwelcomeclicked(){
    stack->setCurrentIndex(0);
}
void MainWindow::gesproduitclicked(){
    stack->setCurrentIndex(2);

}
void MainWindow::onparkingclicked(){
    stack->setCurrentIndex(1);
}
void MainWindow::quitclicked(){
    close();
}
void MainWindow::seepassword(){
    if(seepw->isChecked()){
    passwordtext->setEchoMode(QLineEdit::Normal);
   }
    else{
    passwordtext->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::addwidget(QWidget *widget){
    stack->addWidget(widget);
}
MainWindow::~MainWindow()
{
    delete ui;
}

