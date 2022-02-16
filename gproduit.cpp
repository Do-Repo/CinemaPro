#include "gproduit.h"
#include <QLabel>

GProduit::GProduit()
{
   Gestionproduit = new QWidget;
   Gestionproduit->setGeometry(QRect(10,10,80,80));
   Gestionproduit->setStyleSheet("background-color: rgb(51, 51, 51);");
}

QWidget *GProduit::getW()
{
    return Gestionproduit;
}


