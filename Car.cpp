/*-------NOM:GAO YAN-------*/
#include "Car.h"

Car::Car()
{
    quad_=gluNewQuadric();
}

Car::~Car()
{
    gluDeleteQuadric(quad_);
}

//Montrant le châssis de la voiture
void Car::Display()
{

        glBegin(GL_QUADS);

       /*
        GLfloat car_ambient[]   = {0.25f, 0.25f, 0.25f, 1.0f};
        GLfloat car_diffuse[]   = {0.4f, 0.4f, 0.4f, 1.0f};
        GLfloat car_specular[] = {0.75f, 0.75f, 0.75f, 1.0f};
        GLfloat car_emission[] = {0.f, 0.f, 0.f, 1.0f};

        */
        // Front face
        glNormal3f(0,0,-1);
        glVertex3f(-0.5f,0.1f,-1);
        glVertex3f(-0.5f,1.1f,-1);
        glVertex3f(0.5f,1.1f,-1);
        glVertex3f(0.5f,0.1f,-1);

        // Back face
        glNormal3f(0,0,1);
        glVertex3f(-0.5f,0.1f,1);
        glVertex3f(0.5f,0.1f,1);
        glVertex3f(0.5f,1.1f,1);
        glVertex3f(-0.5f,1.1f,1);

        // Top face
        glNormal3f(0,1,0);
        glVertex3f(-0.5f,1.1f,1);
        glVertex3f(0.5f,1.1f,1);
        glVertex3f(0.5f,1.1f,-1);
        glVertex3f(-0.5f,1.1f,-1);

        // Bottom face
        glNormal3f(0,-1,0);
        glVertex3f(-0.5f,0.1f,1);
        glVertex3f(-0.5f,0.1f,-1);
        glVertex3f(0.5f,0.1f,-1);
        glVertex3f(0.5f,0.1f,1);

        // Right face
        glNormal3f(1,0,0);
        glVertex3f(0.5f,1.1f,1);
        glVertex3f(0.5f,0.1f,1);
        glVertex3f(0.5f,0.1f,-1);
        glVertex3f(0.5f,1.1f,-1);

        // Left face
        glNormal3f(-1,0,0);
        glVertex3f(-0.5f,0.1f,1);
        glVertex3f(-0.5f,1.1f,1);
        glVertex3f(-0.5f,1.1f,-1);
        glVertex3f(-0.5f,0.1f,-1);

        glEnd();


        // Wheels


        //Front right wheel
        glPushMatrix();
        glTranslatef(.5f,.25f,-0.75);
        drawWheel();
        glPopMatrix();

        //Back right wheel
        glPushMatrix();
        glTranslatef(.5f,.25f,0.5);
        drawWheel();
        glPopMatrix();

        //Front left wheel
        glPushMatrix();
        glTranslatef(-0.75f,.25f,-0.75);
        drawWheel();
        glPopMatrix();

        //Back left wheel
        glPushMatrix();
        glTranslatef(-0.75f,.25f,0.5);
        drawWheel();
        glPopMatrix();


}

void Car::drawWheel(){

    GLfloat wheels[]={0.5,0.5,0.5,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, wheels);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wheels);
    glPushMatrix();
    glRotatef(90,0,1,0);

    glColor3f(.25f,.25f,.25f);
    gluCylinder(quad_,.25,.25,.25,12,1);

    glColor3f(.25f,.25f,.25f);
    gluDisk(quad_,0.,.20,12,1);

    glColor3f(.25f,.25f,.25f);
    glTranslatef(0.f,0.f,0.25f);
    gluDisk(quad_,0.,.25,12,1);

    glPopMatrix();
}






PlayerCar::PlayerCar() : Car()
{
    transx_=0;
    gyro_=true;
    oil_=150;

}
PlayerCar::~PlayerCar(){}
void PlayerCar::Drawcar()
{

        glPushMatrix();
        GLfloat car_ambient[]   = {0.25f, 0.25f, 0.25f, 1.0f};
        GLfloat car_diffuse[]   = {0.4f, 0.4f, 0.4f, 1.0f};
        GLfloat car_specular[] = {0.75f, 0.75f, 0.75f, 1.0f};
        GLfloat car_emission[] = {0.f, 0.f, 0.f, 1.0f};
        float car_shininess = 50.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT, car_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, car_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, car_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, car_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, car_shininess);


        /* GLfloat sun_light_position[] = {0.0f, 0.0f, 0.0f, 1.0f}; //光源的位置在世界坐标系圆心，齐次坐标形式
           GLfloat sun_light_ambient[]   = {0.0f, 0.0f, 0.0f, 1.0f}; //RGBA模式的环境光，为0
           GLfloat sun_light_diffuse[]   = {1.0f, 1.0f, 1.0f, 1.0f}; //RGBA模式的漫反射光，全白光
           GLfloat sun_light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};  //RGBA模式下的镜面光 ，全白光
           glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
           glLightfv(GL_LIGHT0, GL_AMBIENT,   sun_light_ambient);
           glLightfv(GL_LIGHT0, GL_DIFFUSE,   sun_light_diffuse);
           glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);



           GLfloat light_voiture_anbient[]={0.6,0.6,0.6,1};
           GLfloat light_voiture_diffuse[]={0.6,0.6,0.4,1};
           GLfloat light_voiture_specular[]={0.6,0.6,0.4,1};
           glMaterialfv(GL_FRONT, GL_AMBIENT, light_voiture_anbient);
           glMaterialfv(GL_FRONT, GL_DIFFUSE, light_voiture_diffuse);
           glMaterialfv(GL_FRONT,GL_SPECULAR,light_voiture_specular);
           glMaterialf(GL_FRONT,GL_SHININESS,30);
        */
        glTranslatef(transx_,0,0);
        Display();
        Tank();
        DrawGyro();


        glPopMatrix();
}
void PlayerCar::DrawGyro()
{
    beaconTimer_ = QTime::currentTime();//Clignotant
    int now = beaconTimer_.second();
     GLfloat gyrocolo1[]={1,0,0,1};
     GLfloat gyrocolo2[]={0,1,1,1};
     GLfloat pos[]={0,2,0,1};

            if (now%2 == 0){
                 glMaterialfv(GL_FRONT, GL_AMBIENT, gyrocolo1);
                 glMaterialfv(GL_FRONT, GL_DIFFUSE, gyrocolo1);
                 glLightfv(GL_LIGHT1,GL_DIFFUSE, gyrocolo1);
             }
             else
             {
                 glMaterialfv(GL_FRONT, GL_AMBIENT, gyrocolo2);
                 glMaterialfv(GL_FRONT, GL_DIFFUSE, gyrocolo2);
                 glLightfv(GL_LIGHT1,GL_DIFFUSE, gyrocolo2);
             }

            glLightfv(GL_LIGHT1,GL_POSITION, pos);


      glPushMatrix();
      glTranslatef(0.f,1.1f,-0.2f);
      GLUquadric* giro = gluNewQuadric();
      gluQuadricDrawStyle(giro, GLU_FILL);
      gluSphere(giro,0.1,20,20);
      gluDeleteQuadric(giro);

      glPopMatrix();
}
//TANK OF OIL
void PlayerCar::Tank()
{
    glBegin(GL_QUADS);
    glPushMatrix();


    GLfloat oil_color[]={1,1,0,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, oil_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, oil_color);
    glVertex3f(-0.2f,0.3f,1.1f);
    glVertex3f(0.2f,0.3f,1.1f);
    glVertex3f(0.2f,(0.3f+(oil_*0.8f/150.0)),1.1f);
    glVertex3f(-0.2f,(0.3f+(oil_*0.8f/150.0)),1.1f);


    glPopMatrix();
    glEnd();
}





OppCar::OppCar(float* f) : Car()
{
    srand(static_cast<unsigned int>(clock()));
    float HI = 3.f;
    float LO=-3.f;

    float x = LO + (rand())/float((RAND_MAX))*(HI-LO);

    posx_=x;
    speed_ =f;
    posz_=-200;
}
OppCar::~OppCar(){ }
void OppCar::Drawcar()
{
    glPushMatrix();

        GLfloat light_voiture[]={1,0,1,1};
        glMaterialfv(GL_FRONT, GL_AMBIENT, light_voiture);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, light_voiture);
        glMaterialfv(GL_FRONT,GL_SPECULAR,light_voiture);
        //glMaterialfv(GL_FRONT,GL_SHININESS,light_voiture);
        glMaterialf(GL_FRONT,GL_SHININESS,90);
        if(*speed_==0)
            posz_=posz_+2;
        else
            posz_=posz_+(*speed_*4);
        glTranslatef(posx_,0,posz_);
        Display();

    glPopMatrix();
}
