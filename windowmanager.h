#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QWidget>
#include<QPushButton>
#include <QDialog>
#include<QMessageBox>
#include <QMouseEvent>
#include <QApplication>


class endwindow;
class startwindow ;
class Game;
class passwindow;

class WindowManager : public QWidget
{
    Q_OBJECT

public:
    explicit WindowManager();
    ~WindowManager();
signals:
   void Theagain();

private slots:
   void GetWindowMassge(int MeType,int type);


public:
   void init();

public:
    endwindow *endW;
    startwindow *startW;
    Game *gameW;
    passwindow *passW;



};

#endif // WINDOWMANAGER_H
