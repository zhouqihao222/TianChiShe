#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QRectF>
#include <QPainter>
#include <QPen>
#include<QtCore>
#include <QBrush>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QDialog>
#include<QMessageBox>
#include<QPainter>
#include <QCoreApplication>
#include "passwindow.h"
#include "food.h"
#include "wall.h"
#include "snake.h"
#include "cat.h"
#include "strawberry.h"
#include <QSound>
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class startwindow;
class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
signals:
void managerMasseg(int MeType,int type);

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


    void setcat();
    void setstrawberry();

    void DeleteLast();
    bool snakeStrike();
    enum Move{A,S,D,W};

protected slots:
    void timeOut();

private:
    Ui::Game *ui;
    bool l_press; 
    QPoint l_pos;

    QSound *sound;
    QSound *sound1;
    QSound *sound2;
    QSound *bgm;

public:
    void s_speed();
    void theuserlev();
    void playbgm();

    int speed = 140;

    //初始向上
    int move = W;

    int lev=1;
    int userlev=1;

    bool Over;
    bool Start;

    food *a;
    wall *b;
    snake *c;
    cat *d;
    strawberry *e;
    QMediaPlayer *myPlayer;

    QTimer *timer;
    QTimer *bgm_timer;
    QTimer *cat_timer;
    QTimer *strawberry_timer;

    int scores=0;
    int ALevSpace=50;

    int TheWidth = 20;
    int TheHeight = 20;

};
#endif // GAME_H
