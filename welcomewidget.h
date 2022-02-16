#ifndef WELCOMEWIDGET_H
#define WELCOMEWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
class welcomewidget : public QWidget
{
    Q_OBJECT
public:
    explicit welcomewidget(QWidget *parent = nullptr);
private:
    QWidget *Gw;
signals:

};

#endif // WELCOMEWIDGET_H
