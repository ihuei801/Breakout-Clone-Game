#include "rocks.h"
#include <QPainter>
#include <QPixmap>
rocks::rocks(QWidget *parent,QString src) : QWidget(parent)
{

    this->setFixedSize(50,51);
    imagepath = src;
}

void rocks::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap rImg;
    rImg.load(imagepath);
    painter.drawPixmap(0,0,50,51,rImg);

}
