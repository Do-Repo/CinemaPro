#include "welcomewidget.h"


welcomewidget::welcomewidget(QWidget *parent) : QWidget(parent)
{
    Gw = new QWidget(this);
    Gw->setGeometry(QRect(0,0,600,480));
    Gw->setStyleSheet("background-color: #696969");


}

