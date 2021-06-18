/*-------NOM:GAO YAN-------*/
#include <qopengl.h>
#include <GL/glu.h>
#include <math.h>
#include<QDebug>
#include<iomanip>
#include<random>
#include<iostream>
#include <vector>
#include <QTime>


// Classe dediee pour la gestion de la voiture
class Car
{
public:
    // Constructeur
    Car();
    //Car(float colorR, float colorG, float colorB);
    // Destructeur
    ~Car();

    // Methode d'affichage
    void Display();//Dessinez une voiture rectangulaire
    void drawWheel();//Dessinez les quatre roues du véhicule

private:
    GLUquadric* quad_ = nullptr;



};
//Dessinez et gérer le voiture du joueur.
class PlayerCar : public Car
{
public:
    PlayerCar();
    ~PlayerCar();

    void moveleft(){transx_-=0.1f;};
    void moveright(){transx_+=0.1f;};
    void Drawcar();//Paramètres de couleur et de lumière ambiante de voiture
    void DrawGyro();//Paramètres de couleur et de lumière ambiante de gyro
    void Tank();//Gestion des réservoirs

    bool getgyro(){return gyro_;};//D'affichge de gyro
    void setgyro(bool b){gyro_=b;};//D'affichge de gyro

    float gettransx(){return transx_;};//positon
    void settransx(float f){transx_=f;};

    int getoil(){return oil_;}//oil+
    void setoil(int o){oil_=o;}

private:
    bool gyro_;
    float transx_;
    int oil_;
    QTime beaconTimer_;
};
//Dessinez et gérer le véhicule opposé.
class OppCar : public Car
{
public:
    OppCar(float* f);
    ~OppCar();

    void Drawcar();

    float getspeed(){return *speed_;};
    void setspeed(float f){*speed_=f;};

    float getposx(){return posx_;};
    void setposx(float b){posx_=b;};

    float getposz(){return posz_;};
    void setposz(float b){posz_=b;};


private:
    float *speed_=nullptr;
    float posz_;
    float posx_;

};
