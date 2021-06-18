/*-------NOM:GAO YAN-------*/
#include "myglwidget.h"


// Declarations des constantes
const unsigned int WIN = 800;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{

    setFixedSize(WIN, WIN);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

        // Connexion du timer
        connect(&m_AnimationTimer_,  &QTimer::timeout, [&] {
        m_TimeElapsed_ += 1.0f;
        pcar_->setgyro(!pcar_->getgyro());
         //bidon fonction du temp
        if (!setnewgame_) gui_->increasetime();
        if(vitesse_!=0 && pcar_->getoil()>0)
        {
            pcar_->setoil(pcar_->getoil()-1);

        }
        else if (pcar_->getoil()==0)
        {
            newgame(tr("Insufficient oil !"));
        }

        update();
    });

    m_AnimationTimer_.setInterval(100);
    m_AnimationTimer_.start();

}
MyGLWidget::~MyGLWidget(){

    delete bid_;
    delete ground_;
    delete gui_;
    delete pcar_;
    delete oppcar_;

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{

    vitesse_= 1;//Vitesse d'initialisation

    bid_ = new Bidon(&vitesse_);
    gui_=new UI(this);
    pcar_ = new PlayerCar();
    oppcar_ = new OppCar(&vitesse_);
    ground_ = new Ground(&vitesse_);

    glClearColor(.3f,.5f,.5f,1.f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    //Lumière sun
    GLfloat sun_light_position[] = {0.0f, 20.0f, 50.0f, 1.0f};
    GLfloat sun_light_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat sun_light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat sun_light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);


    //Lumière diffuse
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

/*void MyGLWidget::gameOver()
{
    emit endGame();

}*/
// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{

    glViewport(0, 0, width, height);
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    //QPainter painter(this);
    //painter.beginNativePainting();
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.,1.,2,2000.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,3.5f,5,
              0,1,0,
              0,1,0);

    ground_->Display();
    pcar_->Drawcar();
    if(!setnewgame_)
    {
        oppcar_->Drawcar();
        detectcollision();
        bid_->displayBidon();
        if(pcar_->gettransx()>3.3f || pcar_->gettransx()<-3.3f)
        {

            //qDebug("road");
            newgame(tr("Please drive on the road!"));
        }
        if (oppcar_->getposz()>10)
        {
            delete oppcar_;
            oppcar_ = new OppCar(&vitesse_);
        }
        if (bid_->getposz()>3)
        {
            delete bid_;
            bid_= new Bidon(&vitesse_);
        }
    }
    //painter.drawText(width()/9,height()-height()/8, QString("Speed : ")+QString::number((int)(vitesse_*120))+QString("kph"));
    //painter.drawText(5*width()/9,height()-height()/8, QString("Oil : ")+QString::number((int)(vitesse_*120))+QString("kph"));
    //painter.end();
}

void MyGLWidget::newgame(QString a)
{
    setnewgame_=true;
    delete pcar_;
    delete oppcar_;
    delete bid_;
    vitesse_= 0;
    pcar_ = new PlayerCar();
    QMessageBox::information(this,tr("GAME OVER"),a);
    vitesse_= 1;
    setnewgame_=false;
    oppcar_ = new OppCar(&vitesse_);
    bid_ = new Bidon(&vitesse_);
    gui_->resettime();
}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    //qDebug("touche");
    switch(event->key())
    {
        //case Qt::Key_Left:
        case Qt::Key_A:
            if(vitesse_!=0)
            {
                //qDebug("fleche");
                pcar_->moveleft();
            }
            break;
        //case Qt::Key_Right:
        case Qt::Key_D:
            if(vitesse_!=0)
            {
                //qDebug("fleche");
                pcar_->moveright();
            }
            break;
        case Qt::Key_Space:
            vitesse_=0;
            break;
        case Qt::Key_Enter:
            vitesse_=1;
            break;
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    //update();
}
void MyGLWidget::mousePressEvent(QMouseEvent *event){

    if (event-> button()==Qt::LeftButton)
    {


        GLint hits;
        GLuint selectBuff[512];
        glSelectBuffer(512,selectBuff);

        glRenderMode(GL_SELECT);
        glInitNames();
        glPushName(0);

        glPushMatrix();

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT,viewport);
        gluPickMatrix(event->x(),(viewport[3]-event->y()),4.0,4.0,viewport);// x,y,largeur,longueur,viewport

        gluPerspective(70.,1.,2,2000.);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(0,3.5f,5,
                  0,1,0,
                  0,1,0);


        glLoadName(1);
        bid_->drawBidon();
        glPopMatrix();
        glFlush();
        hits = glRenderMode(GL_RENDER);
        MyGLWidget::processHits(hits,selectBuff);
    }
}
void MyGLWidget::processHits(GLint hits, GLuint buffer[]){


    if (hits>0){
        if(!bid_->getstatus())
        {
            qDebug()<<"Bidon picked ";
            bid_->setstatus(true);
            pcar_->setoil((pcar_->getoil()+50));
            if(pcar_->getoil()>150)
                pcar_->setoil(150);
        }
    }
    else{
        qDebug()<< "Bidon no picked ";
    }
}


void MyGLWidget::detectcollision()
{
    float xcar,xopp,zopp;

    xcar=pcar_->gettransx();
    xopp=oppcar_->getposx();
    zopp=oppcar_->getposz();

    if (zopp+1>=-1) // l'opp car est Proche
    {
        if ((xcar<=xopp && xcar+0.6f>=xopp-0.6f) || (xcar>=xopp && xcar-0.6f<=xopp+0.6f))
        {
            qDebug("Boom!!");
            newgame(tr("Have an accident!"));

        }
    }

}
void MyGLWidget::updateDrawing(int direction){
    if(direction==1){
        pcar_->moveleft();

    }
    if(direction==2){
        pcar_->moveright();
    }
    if (direction==0){
        vitesse_=0;
    }
    if (direction==3){
        vitesse_=1;
    }

    update();
}
