#include "ball.h"
#include <QPixmap>
#include <QPainter>
ball::ball(QWidget *parent) : QWidget(parent)
{
     this->setFixedSize(55,59);
}

void ball::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap ballImg;
    ballImg.load(":/image/ball.png");
    painter.drawPixmap(0,0,50,54,ballImg);



}
