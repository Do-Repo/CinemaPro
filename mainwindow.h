#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include <QGraphicsEffect>
#include "qtmaterialraisedbutton.h"
#include "qtmaterialtextfield.h"
#include "qtmaterialsnackbar.h"
#include "qtmaterialradiobutton.h"
#include <QLabel>
#include <qradiobutton.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addwidget(QWidget*);

private slots:
    void loginclicked();
    void quitclicked();
    void hidebuttons();
    void gesproduitclicked();
    void onwelcomeclicked();
    void onparkingclicked();
    void seepassword();

protected:
    Ui::MainWindow *ui;
    QLabel *cinemapp;
    QStackedWidget *stack;
    QtMaterialSnackbar *loginwarning;
    QRadioButton *seepw;
    QWidget *bigpanel,*sidepanel;
    QtMaterialRaisedButton *loginbtn,*quitbtn,*quitbtn2,*Gproduit,*Gparking,*welcomebtn;
    QtMaterialTextField *textfield,*logintext,*passwordtext;
};
#endif // MAINWINDOW_H
