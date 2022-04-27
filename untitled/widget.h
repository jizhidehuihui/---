#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "snake.h"
#include <QPoint>
#include <QTimer>
#include <QKeyEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Snake* getsnakehead()
    {
        return snake->gethead();
    }

private slots:
    void on_startgame_clicked();

    void on_exitgame_clicked();

private:
    Ui::Widget *ui;
    //蛇头
    snakegame *snake;
    QTimer *tim;
    bool isgameover;
    bool isstartgame;

private:
    void drawInterface(QPainter* paint);
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
        int level;//速度
        Food food;//食物
        int score;//得分
};

#endif // WIDGET_H
