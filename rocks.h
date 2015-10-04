#ifndef ROCKS_H
#define ROCKS_H

#include <QWidget>
#include <QString>

class rocks : public QWidget
{
    Q_OBJECT
public:
    explicit rocks(QWidget *parent = 0,QString =NULL);
    bool checkbomp(int, int);
protected:
    void paintEvent(QPaintEvent *);
private:
     QString imagepath;
     int x;
     int y;

signals:

public slots:
};

#endif // ROCKS_H
