#ifndef SNAKE_H
#define SNAKE_H

#include <QPoint>
#include <QRect>
#include <QPainter>
#include <QKeyEvent>
class snakegame;
class Snake;
class Food;
class Snake
{
public:
    Snake(QPoint point);
    QPoint getPos();
    void setPos(int x,int y);
    Snake *next;
private:
    //蛇坐标
    QPoint xy;
};
class Food
{
  public:
    Food(int ,int);
    void setnewfood(Snake *head);//设置新的食物
    QPoint getfood();//获取食物的坐标
    void setfood();//设置食物的坐标
    void drawfood(QPainter *paint);//绘制食物
private:
    QPoint foodpos;

};

class snakegame
{
public:
    snakegame(QPoint point);
    void addsnake();//添加蛇尾巴
    bool eatfood(Food food);//是否吃到食物
    bool isgameover();//是否撞倒墙壁或者自己
    void movegame();//蛇移动
    void drawsnake(QPainter *paint);//绘画蛇身
    bool setdirection(QKeyEvent *event);
    Snake* gethead()
    {
        return head ;
    }

private:
    Snake *head;
    char direction;//方向1234 上下左右
};

#endif // SNAKE_H
