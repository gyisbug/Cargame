/*-------NOM:GAO YAN-------*/
#include "connect.h"

appCon::appCon(MyGLWidget* mw,Detect *imProc)
{
    mw_=mw;
    imProc_=imProc;
}
appCon::~appCon(){

}
void appCon::run(){

    mw_->show();
    while(cv::waitKey(5) < 0)
    {
        int d=imProc_->Process();
        mw_->updateDrawing(d);
    }
   //future.waitForFinished();
}

/*void appCon::closeEvent ( QCloseEvent * e )
{
    if( QMessageBox::question(this,
                             tr("Quit"),
                             tr("Are you sure to quit this application?"),
                              QMessageBox::Yes, QMessageBox::No )
                   == QMessageBox::Yes){
        e->accept();//

        qDebug()<<"ok";
    }
    else
      e->ignore();
}
*/
