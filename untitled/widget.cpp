#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QAction>
#include <QDebug>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    isgameover(false),
    isstartgame(false),
    snake(new snakegame(QPoint(400,300))),
    tim(new QTimer),
    level(200),
    food(rand()%40*20,rand()%30*20),
    score(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QAction *ac1=new QAction("等级一");
    QAction *ac2=new QAction("等级二");
    QAction *ac3=new QAction("等级三");
    ui->gamelevel->addActions(QList<QAction*>{ac1,ac2,ac3});
    connect(ac1,&QAction::triggered,this,[=]()
    {
        this->tim->setInterval(level);
        emit on_startgame_clicked();
    });
    this->setFixedSize(800,600);
    this->move(650,200);
    connect(ac2,&QAction::triggered,this,[=](){level=133,this->tim->setInterval(level);emit on_startgame_clicked();});
    connect(ac3,&QAction::triggered,this,[=](){level=66,this->tim->setInterval(level);emit on_startgame_clicked();});


    tim->setInterval(level);
    //连接定时器和画面更新
    connect(tim,&QTimer::timeout,this,[=]()
    {
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    if(this->snake->eatfood(food))
    {
        snake->addsnake();

        food.setnewfood(getsnakehead());
        score++;
    };
    if(snake->isgameover())
    {
        ui->startgame->show();
        ui->gamelevel->show();
        ui->exitgame->show();
        this->isstartgame=false;
        tim->stop();
        QMessageBox::information(this,"game over",QString("游戏结束 你的的分为%1").arg(score));
        score=0;
        this->close();
    }
    if(!isgameover&&isstartgame)
    {
        QPainter paint(this);
        snake->drawsnake(&paint);
        snake->movegame();
        food.drawfood(&paint);
    }
    else if(!isstartgame)
    {
        QPainter pain(this);
        drawInterface(&pain);
    }

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    snake->setdirection(event);
    qDebug()<<event->key();
}

void Widget::drawInterface(QPainter *paint)
{
    paint->save();
    QBrush bru(Qt::SolidPattern);
    bru.setColor(Qt::green);
    paint->setBrush(bru);
    paint->drawRect(QRect(QPoint(0,0),this->size()));
    paint->restore();
}


void Widget::on_startgame_clicked()
{
    ui->startgame->hide();
    ui->gamelevel->hide();
    ui->exitgame->hide();
    this->isstartgame=true;
    tim->start();
    update();
}

void Widget::on_exitgame_clicked()
{
    this->close();
}
