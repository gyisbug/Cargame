/*-------NOM:GAO YAN-------*/
#include <qopengl.h>
#include <math.h>
#include <QImage>
#include <QGLWidget>
#include<GL/glu.h>

// Dessinez le ciel, la terre, la route et gérez sa texture et faites défiler
class Ground
{
public:
    // Constructeur avec parametres
    Ground(float *speed);

    // Destructeur
    ~Ground();

    // Methode d'affichage
    void Display();


private:
    GLuint* texture;
    float* vitessep_=nullptr;
    float shift_=0;


};
