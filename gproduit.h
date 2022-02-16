#ifndef GPRODUIT_H
#define GPRODUIT_H
#include <QWidget>


class GProduit : public QWidget
{

protected:
    QWidget *Gestionproduit;
public:
    GProduit();
    QWidget* getW();
};

#endif // GPRODUIT_H
