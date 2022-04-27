#include "snake.h"
#include <QKeyEvent>
Snake::Snake(QPoint point):
    xy(point)
{
    Snake *next=nullptr;
}

void Snake::setPos(int x,int y)
{
    this->xy.setX(xy.x()+x);
    this->xy.setY(xy.y()+y);
}

QPoint Snake::getPos()
{
    return this->xy;
}

snakegame::snakegame(QPoint point)
{
    head=new Snake(point);
    head->next=NULL;
    direction='s';
    addsnake();addsnake();
}

void snakegame::addsnake()
{
    switch (this->direction) {
    case 'w':
    {
        Snake *temp=new Snake(QPoint(head->getPos().x(),head->getPos().y()-20));
        temp->next=head;head=temp;
        break;
    }
    case 's':
    {Snake *temp=new Snake(QPoint(head->getPos().x(),head->getPos().y()+20));
        temp->next=head;head=temp;
        break;
    }
    case 'a':
    {
        Snake *temp=new Snake(QPoint(head->getPos().x()-20,head->getPos().y()));
        temp->next=head;head=temp;
        break;
    }
    case 'd':
    {
        Snake *temp=new Snake(QPoint(head->getPos().x()+20,head->getPos().y()));
        temp->next=head;head=temp;
        break;
    }
    default:
        break;
    }
}

bool snakegame::eatfood(Food food)
{
    if(head->getPos()==food.getfood())
        return true;
    else
        return false;
}

bool snakegame::isgameover()
{
    Snake *temp=head->next;
    while(temp!=NULL)
    {
        if(temp->getPos()==head->getPos())
            return true;
        else
            temp=temp->next;
    }
    if(head->getPos().x()<0||head->getPos().x()>800||head->getPos().y()<0||head->getPos().y()>580)
        return true;
    return false;
}

void snakegame::movegame()
{
    addsnake();
    Snake *temp=head;
    Snake*temp1=temp;
    while(temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    delete temp;
    temp=NULL;
    temp1->next=NULL;
}

void snakegame::drawsnake(QPainter *paint)
{

    paint->save();
    QBrush bru(Qt::Dense4Pattern);
    bru.setColor(Qt::red);
    paint->setBrush(bru);
    Snake *temp=head->next;
    paint->drawEllipse(QPoint(head->getPos().x()+10,head->getPos().y()+10),10,10);
    while(temp!=NULL)
    {
        paint->drawRect(QRect(temp->getPos(),QSize(20,20)));
        temp=temp->next;
    }
    paint->restore();
}

bool snakegame::setdirection(QKeyEvent *event)
{
    char c=event->key();
    if(c!=Qt::Key_W&&c!=Qt::Key_S&&c!=Qt::Key_A&&c!=Qt::Key_D)
        return false;
    switch (event->key()) {
    case Qt::Key_W:
    {
        if(direction!='w'&&direction!='s')
            direction='w';
        else
            break;
        break;
    }
    case Qt::Key_S:
    {
        if(direction!='s'&&direction!='w')
            direction='s';
        else
            break;
        break;
    }
    case Qt::Key_A:
    {
        if(direction!='a'&&direction!='d')
            direction='a';
        else
            break;
        break;
    }
    case Qt::Key_D:
    {
        if(direction!='d'&&direction!='a')
            direction='d';
        else
            break;
        break;
    }
    default:
        break;
    };

    return true;
}

Food::Food(int a,int b)
{
    this->foodpos.setX(a);
    this->foodpos.setY(b);
}

void Food::setnewfood(Snake *head)
{
    this->foodpos.setX(rand()%40*20);
    this->foodpos.setY(rand()%30*20);
    Snake *temp=head;
    while(temp!=NULL)
    {
        if(temp->getPos()==foodpos)
        {
            setnewfood(head);
            return;
        }
        else
            temp=temp->next;
    }
}

QPoint Food::getfood()
{
    return foodpos;
}

void Food::setfood()
{

}

void Food::drawfood(QPainter *paint)
{
    paint->save();
    QBrush bru(Qt::green);
    paint->setBrush(bru);
    paint->drawEllipse(QPoint(foodpos.x()+10,foodpos.y()+10),13,8);
//    QRectF rectangle(10.0, 20.0, 80.0, 60.0);
//    int startAngle = 30 * 16;
//    int spanAngle = 120 * 16;
//    QPainter painter(this);
//    painter.drawArc(rectangle, startAngle, spanAngle);
    paint->restore();
}
