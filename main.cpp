#include <QApplication>
#include "myglwidget.h"
#include "connect.h"
#include "Detectimage.h"

int main(int argc, char *argv[])
{
    // Creation de l'application QT
    QApplication a(argc, argv);

    // Creation du widget
    MyGLWidget* glWidget= new MyGLWidget;
    glWidget->setWindowTitle("CarGame");
    //glWidget->show();
    int frame[]={640,480};
    Detect* imgProc=new Detect(frame);

    //glWidget.show();
    appCon appM=appCon(glWidget,imgProc);
    appM.run();
    // Execution de l'application QT
    //a.connect(glWidget, SIGNAL(endGame()), &a, SLOT(quit()));
    return a.exec();
           glWidget->close();
           //a.exit();
}
