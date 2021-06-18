/*-------NOM:GAO YAN-------*/
#ifndef BIDON_H
#define BIDON_H
#include <qopengl.h>
#include <QImage>
#include <GL/glu.h>
#include<QGLWidget>
#include<QDebug>

//Dessiner le bidon, et gérez sa texture, son emplacement et ses événements de sélection
class Bidon
{
public:
    Bidon(float *f);
    ~Bidon();
    void drawBidon();//dessiner le bidon et gere le texture
    void displayBidon();//Gérer les événements de sélection
    float getposz(){return posz_;};//Methode postionZ
    void setstatus(bool b){picked_=b;};//Juger le statut de la sélection
    float getstatus(){return picked_;};//Juger le statut de la sélection

private:
    GLuint* texture;
    bool picked_=false;
    float *speed_=nullptr;
    float posz_;
    float posx_;
    GLUquadric* quadrique_ = gluNewQuadric();

    float x_Border_Right_ = 4;
    float x_Border_Left_ = -4;


};

#endif // BIDON_H
