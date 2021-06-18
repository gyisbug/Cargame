/*-------NOM:GAO YAN-------*/
#ifndef CONNECT_H
#define CONNECT_H

#include <QObject>
#include"Detectimage.h"
#include "myglwidget.h"
#include <QApplication>
#include<QFuture>
#include<QtConcurrent/QtConcurrent>
#include <QtWidgets/QMessageBox>

//Utilisé pour connecter la fenêtre de jeu et la WEBCAM
class appCon:public QObject
{
    Q_OBJECT
public:
    appCon(MyGLWidget* mw,Detect* imProc);//Connectez deux formulaires
    ~appCon();
    void run();


private:
    MyGLWidget* mw_;
   // QWidget QMessageBox;
    Detect *imProc_;
    QFuture<void> myFuture;
    //void closeEvent(QCloseEvent *event);
};

#endif // CONNECT_H
