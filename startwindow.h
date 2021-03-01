#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include<QPushButton>
#include <QDialog>
#include<QMessageBox>
#include <QMouseEvent>
#include <QApplication>
//#include <QSound>

namespace Ui {
class startwindow;
}

class startwindow : public QWidget
{
    Q_OBJECT

public:
    explicit startwindow( QWidget *parent = nullptr);
    ~startwindow();

    signals:
    void managerMasseg(int MeType,int type);
public slots:
    void thegame();

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::startwindow *ui;
    bool l_press;
    QPoint l_pos;
};

#endif // STARTWINDOW_H
