#ifndef PASSWINDOW_H
#define PASSWINDOW_H

#include <QWidget>
#include<QPushButton>
#include <QDialog>
#include<QMessageBox>
#include <QMouseEvent>
#include <QApplication>

class Game;
namespace Ui {
class passwindow;
}

class passwindow : public QWidget
{
    Q_OBJECT

public:
    explicit passwindow(QWidget *parent = nullptr);
    ~passwindow();
signals:
void managerMasseg(int MeType,int type);

private slots:
      void againGame();
private:

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::passwindow *ui;
    bool l_press;
    QPoint l_pos;

};
#endif // PASSWINDOW_H
