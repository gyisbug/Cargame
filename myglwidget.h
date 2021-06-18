/*-------NOM:GAO YAN-------*/
#ifndef MGL_H
#define MGL_H
#include "Car.h"
#include "Ground.h"
#include"bidon.h"
#include "Guitime.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <GL/glu.h>
#include <QTimer>
#include<QMouseEvent>
#include<QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include<QMessageBox>
#include <qpainter.h>

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    ~MyGLWidget();
    void mousePressEvent(QMouseEvent *event);
    void processHits(GLint hits,GLuint buffer[]);//hits
    void updateDrawing(int d);


//signals:
    //void endGame();

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent* event);


    //
    void detectcollision();//Détection de collision
    void newgame(QString a);//Réinitialiser un nouveau jeu
//protected slots:

    //void gameOver();
private:
    PlayerCar * pcar_;
    OppCar * oppcar_;
    Bidon * bid_;
    float vitesse_;
    UI *gui_;
    Ground * ground_;
    float m_TimeElapsed_ { 0.0f };
    QTimer m_AnimationTimer_;
    bool setnewgame_;


};
#endif
