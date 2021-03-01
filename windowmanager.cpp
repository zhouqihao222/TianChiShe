#include "endwindow.h"
#include"startwindow.h"
#include"passwindow.h"
#include"Game.h"
#include <QTimer>
#include "windowmanager.h"

WindowManager::WindowManager()
{
    endW = NULL;
    startW= NULL;
    gameW= NULL;
    passW=NULL;


}
void WindowManager::init()
{
   if(startW==NULL)
   {
      startW=new startwindow();
      connect(startW,&startwindow::managerMasseg,this,&WindowManager::GetWindowMassge);
   }
   startW->show();
//    if(passW==NULL)
//      {
//         passW=new passwindow();
//         connect(passW,&passwindow::managerMasseg,this,&WindowManager::GetWindowMassge);
//      }
//      passW->show();

}
void  WindowManager::GetWindowMassge(int MeType,int type)
{
    if(MeType==0)
    {
        startW->close();
        if(startW!=NULL)
        {
            delete startW;
            startW=NULL;
        }
        if(type==1)
        {
            if(gameW==NULL)
            {
               gameW=new Game();
               connect(gameW,&Game::managerMasseg,this,&WindowManager::GetWindowMassge);
            }
            gameW->show();
        }

    }
    if(MeType==1)
    {
//        gameW->close();
//        if(gameW!=NULL)
//        {
//            delete gameW;
//            gameW=NULL;
//        }
//      gameW->food=(QRectF(qrand()%(this->width()/20)*20,qrand()%(this->height()/20)*20,gameW->TheWidth,gameW->TheWidth));
        gameW->c->s_body.clear();
        gameW->c->snakebody();
        gameW->timer->stop();
        gameW->d->is_alive=false;
        gameW->update();
        gameW->close();
        if(type==2)
        {
            if(endW==NULL)
            {
               endW=new endwindow();
               connect(endW,&endwindow::managerMasseg,this,&WindowManager::GetWindowMassge);
            }
            endW->show();
        }
        if(type==3)
        {
            if(passW==NULL)
            {
               passW=new passwindow();
               connect(passW,&passwindow::managerMasseg,this,&WindowManager::GetWindowMassge);
            }
            passW->show();
        }

    }

    if(MeType==2)
    {
        endW->close();
        if(endW!=NULL)
        {
            delete endW;
            endW=NULL;
        }
        if(type==0)
        {
            if(startW==NULL)
            {
               startW=new startwindow();
               connect(startW,&startwindow::managerMasseg,this,&WindowManager::GetWindowMassge);
            }
            startW->show();
        }

    }
    if(MeType==3)
    {
        passW->close();
        if(passW!=NULL)
        {
            delete passW;
            passW=NULL;
        }
        if(type==0)
        {
            if(startW==NULL)
            {
               startW=new startwindow();
               connect(startW,&startwindow::managerMasseg,this,&WindowManager::GetWindowMassge);
            }
            startW->show();
        }

    }
}
WindowManager::~WindowManager()
{

}
