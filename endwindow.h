#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QWidget>
#include<QPushButton>
#include <QDialog>
#include<QMessageBox>
#include <QMouseEvent>
#include <QApplication>
#include <QSound>

class Game;
namespace Ui {
class endwindow;
}

class endwindow : public QWidget
{
    Q_OBJECT

public:
    explicit endwindow(QWidget *parent = nullptr);
    ~endwindow();
signals:
void managerMasseg(int MeType,int type);

private slots:
      void againgame();
private:

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::endwindow *ui; 
    bool l_press;
    QPoint l_pos;


    QSound *sound3;


};

#endif // ENDWINDOW_H
