#include "mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <QLabel>
#include <QPalette>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{




    this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/image/ball.png"));
    this->setWindowTitle("Qt Break the Bricks");



    title = new QLabel("",this);

    Bar = new bar(this);
    Bar->setVisible(0);
    Ball = new ball(this);
    Ball->setVisible(0);



    rockImg[0]=":/image/rock1.png";
    rockImg[1]=":/image/rock2.png";
    rockImg[2]=":/image/rock3.png";
    rockImg[3]=":/image/rock4.png";
    rockImg[4]=":/image/rock5.png";
    rockImg[5]=":/image/rock6.png";
    rockImg[6]=":/image/rock7.png";
    rockImg[7]=":/image/rock8.png";
    rockImg[8]=":/image/rock9.png";
    rockImg[9]=":/image/rock10.png";
    rockImg[10]=":/image/rock11.png";
    rockImg[11]=":/image/rock12.png";
    rockImg[12]=":/image/rock13.png";
    rockImg[13]=":/image/rock14.png";
    rockImg[14]=":/image/rock15.png";
    rockImg[15]=":/image/rock16.png";
    rockImg[16]=":/image/rock17.png";
    rockImg[17]=":/image/rock18.png";
    rockImg[18]=":/image/rock19.png";
    rockImg[19]=":/image/rock20.png";
    rockImg[20]=":/image/rock21.png";
    rockImg[21]=":/image/rock22.png";
    rockImg[22]=":/image/rock23.png";
    rockImg[23]=":/image/rock24.png";
    rockImg[24]=":/image/rock25.png";
    rockImg[25]=":/image/rock26.png";
    rockImg[26]=":/image/rock27.png";
    rockImg[27]=":/image/rock28.png";
    rockImg[28]=":/image/rock29.png";
    rockImg[29]=":/image/rock30.png";
    rockImg[30]=":/image/rock31.png";
    rockImg[31]=":/image/rock32.png";
    rockImg[32]=":/image/rock33.png";
    rockImg[33]=":/image/rock34.png";
    rockImg[34]=":/image/rock35.png";
    rockImg[35]=":/image/rock36.png";
    for(int i=0;i<31;i++){
        Rocks[i] = new rocks(this,rockImg[i]);
        Rocks[i]->setVisible(0);
    }

    shootballm = new easyMusic("musicFile/shoot.wav",100,0);
    bomptowallm = new easyMusic("musicFile/bomptowall.wav",100,0);
    bomptobarm = new easyMusic("musicFile/bomptobar.wav",100,0);
    bomptorockm[0] = new easyMusic("musicFile/bomptorock.WAV",100,0);
    bomptorockm[1] = new easyMusic("musicFile/bomptorock2.WAV",100,0);
    win = new easyMusic("musicFile/win.wav",100,0);
    selected = new easyMusic("musicFile/selected.wav",60,0);
    bgm = new easyMusic("musicFile/background.wav",80,0);
    losemusic = new easyMusic("musicFile/lose.wav",80,0);
    scrollmenu = new easyMusic("musicFile/scrollmenu.wav",80,0);
    stab = new easyMusic("musicFile/stabbing.wav",80,0);
    readygo = new easyMusic("musicFile/readygo.wav",60,0);







    brmindex=0;



    menu_selection[0] = new QLabel("Start",this);
    menu_selection[1] = new QLabel("Help",this);
    menu_selection[2] = new QLabel("Exit",this);
    scoreboard = new QLabel("[]",this);
    score = new QLabel("00",this);
    bestscore = new QLabel("00",this);
    newest = new QLabel("new",this);
    highscore=0;
    help_information = new QLabel(" ",this);
    rotatedpen = new QLabel(" ",this);
    producer = new QLabel("製作人 : 黃廷耀、黃懿慧 ",this);
    penImg[0]=":/image/rbar0.png";
    penImg[1]=":/image/rbar1.png";
    penImg[2]=":/image/rbar2.png";
    penImg[3]=":/image/rbar3.png";
    penImg[4]=":/image/rbar4.png";
    penImg[5]=":/image/rbar5.png";
    penImg[6]=":/image/rbar6.png";
    penImg[7]=":/image/rbar7.png";
    pen_number=0;
    pentimer = new QTimer(this);
    connect(pentimer,SIGNAL(timeout()),this,SLOT(penrotate()));
    //    ->s
    rotatedpen->setGeometry(50, 50, 100, 100);

    rotatedpen->setVisible(0);


    QPixmap helpImg,titleImg;
    helpImg.load(":/image/help.png");
    help_information->setPixmap(helpImg);
    titleImg.load(":/image/Title.PNG");
    title->setPixmap(titleImg);





    createlabel();
    animetype=0;
    animecounter=0;
    startanime();
    //gameMenu();



}
void MainWindow::paintEvent(QPaintEvent *)
{



    QPainter painter(this);
    QPixmap bgImg;
    bgImg.load(":/image/background.jpg");
    //bgImg.scaled(40,40,Qt::KeepAspectRatio);
    painter.drawPixmap(0,0,800,600,bgImg);


}
void MainWindow::mousePressEvent(QMouseEvent *event)
{

    int i;
    if(gamemod==menu){
        if(event->button()==Qt::MidButton){
            if(menumod==Start){
                title->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameStart();

            }
            else if(menumod==Help){
                title->setVisible(0);
                Ball->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameHelp();

            }
            else if(menumod==Exit){
                this->~MainWindow();

            }
        }
        else if(event->button()==Qt::MidButton){
            if(menumod==Start){
                title->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameStart();

            }
            else if(menumod==Help){
                title->setVisible(0);
                Ball->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameHelp();

            }
            else if(menumod==Exit){
                this->~MainWindow();

            }

        }
        else if(event->button()==Qt::LeftButton){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod-1+3)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
        else if(event->button()==Qt::LeftButton){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod-1+3)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
        else if(event->button()==Qt::RightButton){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod+1)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
        else if(event->button()==Qt::RightButton){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod+1)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
    }
    else if(gamemod==start){
        if(event->button()==Qt::RightButton){

            if(Bar->x()+200<800){
               for(i=0;i<20;i++){
                Bar->move(Bar->x()+1,Bar->y());
                if(ballon){
                   Ball->move(Ball->x()+1,Ball->y());

                }

               }
            }

        }
        else if(event->button()==Qt::LeftButton){

            if(Bar->x()>0){

               for(i=0;i<20;i++){
                Bar->move(Bar->x()-1,Bar->y());
                if(ballon){
                    Ball->move(Ball->x()-1,Ball->y());
                }
               }
            }
        }
        else if(event->button()==Qt::MidButton){

            if(ballon){
                //playshootmusic
                ballon=0;
                ballTimer->start(20);
                shootballm->play();

            }

        }
    }
    else if(gamemod==lose){
        if(event->button()==Qt::MidButton){
            scoreboard->setVisible(0);
            score->setVisible(0);
            bestscore->setVisible(0);
            newest->setVisible(0);
            win->stop();
            gameMenu();

        }
        else if(event->button()==Qt::MidButton){
            scoreboard->setVisible(0);
            score->setVisible(0);
            bestscore->setVisible(0);
            newest->setVisible(0);
            gameMenu();

        }
    }
    else if(gamemod==pause){
        if(event->button()==Qt::MidButton){

            gameStart();

        }
        else if(event->button()==Qt::MidButton){

            gameStart();

        }
    }
    else if(gamemod==redy){
        if(event->button()==Qt::MidButton){

            gameStart();

        }
        else if(event->button()==Qt::MidButton){

            gameStart();

        }
    }
    else if(gamemod==help){
        if(event->button()==Qt::MidButton){
            help_information->setVisible(0);
            selected->stop();
            gameMenu();

        }
        else if(event->button()==Qt::MidButton){
            help_information->setVisible(0);
            selected->stop();
            gameMenu();

        }
    }

}




void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int i;
    if(gamemod==menu){
        if(event->key()==Qt::Key_Space){
            if(menumod==Start){
                title->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameStart();

            }
            else if(menumod==Help){
                title->setVisible(0);
                Ball->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameHelp();

            }
            else if(menumod==Exit){
                this->~MainWindow();

            }
        }
        else if(event->key()==Qt::Key_Enter){
            if(menumod==Start){
                title->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameStart();

            }
            else if(menumod==Help){
                title->setVisible(0);
                Ball->setVisible(0);
                menu_selection[0]->setVisible(0);
                menu_selection[1]->setVisible(0);
                menu_selection[2]->setVisible(0);
                rotatedpen->setVisible(0);
                selected->play();
                gameHelp();

            }
            else if(menumod==Exit){
                this->~MainWindow();

            }

        }
        else if(event->key()==Qt::Key_Up){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod-1+3)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
        else if(event->key()==Qt::Key_Left){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod-1+3)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
        else if(event->key()==Qt::Key_Down){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod+1)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
        else if(event->key()==Qt::Key_Right){
            QPalette pe;
            pe.setColor(QPalette::WindowText,Qt::darkGreen);
            menu_selection[menumod]->setPalette(pe);
            pe.setColor(QPalette::WindowText,Qt::white);
            menumod=(menumod+1)%3;
            menu_selection[menumod]->setPalette(pe);
            rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
            scrollmenu->stop();
            scrollmenu->play();
        }
    }
    else if(gamemod==start){
        if(event->key()==Qt::Key_Right){

            if(Bar->x()+200<800){
               for(i=0;i<20;i++){
                Bar->move(Bar->x()+1,Bar->y());
                if(ballon){
                   Ball->move(Ball->x()+1,Ball->y());

                }

               }
            }

        }
        else if(event->key()==Qt::Key_Left){

            if(Bar->x()>0){

               for(i=0;i<20;i++){
                Bar->move(Bar->x()-1,Bar->y());
                if(ballon){
                    Ball->move(Ball->x()-1,Ball->y());
                }
               }
            }
        }
        else if(event->key()==Qt::Key_Space){

            if(ballon){
                //playshootmusic
                ballon=0;
                ballTimer->start(20);
                shootballm->play();

            }

        }
    }
    else if(gamemod==lose){
        if(event->key()==Qt::Key_Space){
            scoreboard->setVisible(0);
            score->setVisible(0);
            bestscore->setVisible(0);
            newest->setVisible(0);
            win->stop();
            gameMenu();

        }
        else if(event->key()==Qt::Key_Enter){
            scoreboard->setVisible(0);
            score->setVisible(0);
            bestscore->setVisible(0);
            newest->setVisible(0);
            gameMenu();

        }
    }
    else if(gamemod==pause){
        if(event->key()==Qt::Key_Space){

            gameStart();

        }
        else if(event->key()==Qt::Key_Enter){

            gameStart();

        }
    }
    else if(gamemod==redy){
        if(event->key()==Qt::Key_Space){

            gameStart();

        }
        else if(event->key()==Qt::Key_Enter){

            gameStart();

        }
    }
    else if(gamemod==help){
        if(event->key()==Qt::Key_Space){
            help_information->setVisible(0);
            selected->stop();
            gameMenu();

        }
        else if(event->key()==Qt::Key_Enter){
            help_information->setVisible(0);
            selected->stop();
            gameMenu();

        }
    }


}
MainWindow::~MainWindow()
{

}

void MainWindow::createlabel()
{
    //title
    title->setFont(QFont("Courier New",40, 80 ));
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    title->setPalette(pe);
    //title->setAlignment(Qt::AlignCenter);
    title->setGeometry(220, 50, 550, 400 );
    title->setVisible(0);
    //menu
    menu_selection[0]->setFont(QFont("Courier New",30, 80 ));
    pe.setColor(QPalette::WindowText,Qt::darkGreen);
    menu_selection[0]->setPalette(pe);
    menu_selection[0]->setGeometry(130, 375, 300, 50 );
    menu_selection[0]->setVisible(0);
    //
    menu_selection[1]->setFont(QFont("Courier New",30, 80 ));
    pe.setColor(QPalette::WindowText,Qt::darkGreen);
    menu_selection[1]->setPalette(pe);
    menu_selection[1]->setGeometry(350, 375, 300, 50 );
    menu_selection[1]->setVisible(0);
    //
    menu_selection[2]->setFont(QFont("Courier New",30, 80 ));
    pe.setColor(QPalette::WindowText,Qt::darkGreen);
    menu_selection[2]->setPalette(pe);
    menu_selection[2]->setGeometry(550, 375, 300, 50 );
    menu_selection[2]->setVisible(0);

    //help
    help_information->setFont(QFont("Courier New",30, 80 ));
    pe.setColor(QPalette::WindowText,Qt::red);
    help_information->setPalette(pe);
    help_information->setGeometry(50, 75, 800 ,400 );
    help_information->setVisible(0);
    //produce
    producer->setFont(QFont("Courier New",20, 80 ));
    pe.setColor(QPalette::WindowText,Qt::darkGreen);
    producer->setPalette(pe);
    producer->setGeometry(220, 350, 400 ,40 );
    producer->setVisible(0);





    //score
    score->setFont(QFont("Courier New", 70, 80 ));
    pe.setColor(QPalette::WindowText,Qt::white);
    score->setPalette(pe);
    score->setAlignment(Qt::AlignCenter);
    score->setGeometry(500,155, 100, 70);
    score->setVisible(0);
    bestscore->setFont(QFont("Courier New", 70, 80 ));
    pe.setColor(QPalette::WindowText,Qt::white);
    bestscore->setPalette(pe);
    bestscore->setAlignment(Qt::AlignCenter);
    bestscore->setGeometry(500,285, 100, 70);
    bestscore->setVisible(0);

    //scoreboard
    QPixmap sb;
    sb.load(":/image/scoreboard.png");
    scoreboard->setPixmap(sb);
    scoreboard->setGeometry(140, 85 , 517, 363);
    scoreboard->setVisible(0);

    //new
    QPixmap n;
    n.load(":/image/new.png");
    newest->setPixmap(n);
    newest->setGeometry(450, 220 , 156, 82);
    newest->setVisible(0);
}
void MainWindow::penrotate()
{
    pentimer->start(100);
    QPixmap pixmap(penImg[pen_number++%8]);
    rotatedpen->setPixmap(pixmap.scaled(100,100, Qt::IgnoreAspectRatio));
    if(pen_number==8000)pen_number=0;
}

void MainWindow::createballsandbar()
{
    Bar->setVisible(1);
    Bar->move(300,450);
    Ball->setVisible(1);
    Ball->move(370,405);

    ballon=1;
    balldir=0;
    ballTimer = new QTimer(this);
    connect(ballTimer,SIGNAL(timeout()),this,SLOT(ballAction()));
}

void MainWindow::createrocks()
{
    for(int i=0;i<4;i++){
        rockPos[i].x=10;
    }
    for(int i=4;i<8;i++){
        rockPos[i].x=70;
    }
    for(int i=8;i<10;i++){
        rockPos[i].x=130;
    }
    rockPos[10].x=250;
    for(int i=11;i<14;i++){
        rockPos[i].x=310;
    }
    for(int i=14;i<17;i++){
        rockPos[i].x=370;
    }
    for(int i=17;i<20;i++){
        rockPos[i].x=430;
    }
    rockPos[20].x=490;
    for(int i=21;i<23;i++){
        rockPos[i].x=610;
    }
    for(int i=23;i<27;i++){
        rockPos[i].x=670;

    }
    for(int i=27;i<31;i++){
        rockPos[i].x=730;
    }
    rockPos[0].y=100;
    rockPos[4].y=100;
    rockPos[8].y=100;
    rockPos[11].y=100;
    rockPos[17].y=100;
    rockPos[21].y=100;
    rockPos[23].y=100;
    rockPos[27].y=100;
    rockPos[1].y=160;
    rockPos[5].y=160;
    rockPos[10].y=160;
    rockPos[12].y=160;
    rockPos[14].y=160;
    rockPos[18].y=160;
    rockPos[20].y=160;
    rockPos[24].y=160;
    rockPos[28].y=160;
    rockPos[2].y=220;
    rockPos[6].y=220;
    rockPos[13].y=220;
    rockPos[15].y=220;
    rockPos[19].y=220;
    rockPos[25].y=220;
    rockPos[29].y=220;
    rockPos[3].y=280;
    rockPos[7].y=280;
    rockPos[9].y=280;
    rockPos[16].y=280;
    rockPos[22].y=280;
    rockPos[26].y=280;
    rockPos[30].y=280;
    for(int i=0;i<31;i++){
        rockPos[i].broken=0;
    }
    for(int i=0;i<31;i++){
        Rocks[i]->setVisible(1);
        Rocks[i]->move(rockPos[i].x,rockPos[i].y);
        rockPos[i].broken=0;
    }

    bompcount=0;

}
void MainWindow::ballAction()
{

    if(bompcount==31){
        win->play();
        ballTimer->stop();
        gameEnd();

    }
    for(int i=0;i<5;i++){
    if(balldir==0){

        bool dirchange = checkbomp(Ball->x()+1,Ball->y()-1);
        int bompwall = bomptoboundary(Ball->x()+1,Ball->y()-1);
        if(bompwall==2){
              printf("gameover\n");
               ballTimer->stop();
               losemusic->play();
               gameEnd();

               break;
                //gameover();


         }
        else if(dirchange){
            while(balldir!=1 && balldir!=3){
                balldir = rand()%4;
            }

        }
        else if(bompwall){

        }
        else{
             Ball->move(Ball->x()+1,Ball->y()-1);
        }


    }
    else if(balldir==1){

            bool dirchange = checkbomp(Ball->x()-1,Ball->y()-1);
            int bompwall = bomptoboundary(Ball->x()-1,Ball->y()-1);
            if(bompwall==2){
                printf("gameover\n");
                ballTimer->stop();
                losemusic->play();
                gameEnd();
                break;
                //gameover();



            }
            else if(dirchange){
                while(balldir!=0 && balldir!=2){
                    balldir = rand()%4;
                }

            }
            else if(bompwall){

            }
            else{
            Ball->move(Ball->x()-1,Ball->y()-1);
            }



    }
    else if(balldir==2){

            bool dirchange = checkbomp(Ball->x()-1,Ball->y()+1);
            int bompwall = bomptoboundary(Ball->x()-1,Ball->y()+1);
            if(bompwall==2){
                printf("gameover\n");
                ballTimer->stop();
                losemusic->play();
                gameEnd();
                break;
                //gameover();


            }
            else if(dirchange){
                while(balldir!=1 && balldir!=3){
                    balldir = rand()%4;
                }


            }
            else if(bompwall){

            }
            else{
                Ball->move(Ball->x()-1,Ball->y()+1);
            }


    }
    else if(balldir==3){

            bool dirchange = checkbomp(Ball->x()+1,Ball->y()+1);
            int bompwall = bomptoboundary(Ball->x()+1,Ball->y()+1); //bompwall=2:gameover
            if(bompwall==2){
                printf("gameover\n");
                ballTimer->stop();
                losemusic->play();
                gameEnd();
                break;




            }
            else if(dirchange){
                while(balldir!=0 && balldir!=2){
                    balldir = rand()%4;
                }



            }
            else if(bompwall){

            }
            else{
                Ball->move(Ball->x()+1,Ball->y()+1);
            }



    }
    }

}
bool MainWindow::checkbomp(int ball_x, int ball_y)
{
    int i;


        for(i=0;i<31;i++){
            if(rockPos[i].broken==0 && ball_x+50>=rockPos[i].x && ball_x+50<rockPos[i].x+50 && ball_y>=rockPos[i].y && ball_y<=rockPos[i].y+50){
                rockPos[i].broken=1;
                Rocks[i]->setVisible(0);
                bomptorockm[brmindex]->stop();
                brmindex=(brmindex+1)%2;
                bomptorockm[brmindex]->play();
                bompcount++;
                return true;

            }
        }
        for(i=0;i<31;i++){
            if(rockPos[i].broken==0 && ball_x>=rockPos[i].x && ball_x<=rockPos[i].x+50 && ball_y>=rockPos[i].y && ball_y<=rockPos[i].y+50){
                rockPos[i].broken=1;
                Rocks[i]->setVisible(0);
                bomptorockm[brmindex]->stop();
                brmindex=(brmindex+1)%2;
                bomptorockm[brmindex]->play();
                bompcount++;
                return true;

            }
        }

        for(i=0;i<31;i++){
            if(rockPos[i].broken==0 && ball_x>=rockPos[i].x && ball_x<=rockPos[i].x+50 && ball_y+45>=rockPos[i].y && ball_y+45<=rockPos[i].y+50){
                rockPos[i].broken=1;
                Rocks[i]->setVisible(0);
                bomptorockm[brmindex]->stop();
                brmindex=(brmindex+1)%2;
                bomptorockm[brmindex]->play();
                bompcount++;
                return true;

            }
        }
        for(i=0;i<31;i++){
            if(rockPos[i].broken==0 && ball_x+50>=rockPos[i].x && ball_x+50<=rockPos[i].x+50 && ball_y+45>=rockPos[i].y && ball_y+45<=rockPos[i].y+50){
                rockPos[i].broken=1;
                Rocks[i]->setVisible(0);
                bomptorockm[brmindex]->stop();
                brmindex=(brmindex+1)%2;
                bomptorockm[brmindex]->play();
                bompcount++;
                return true;

            }
        }
        return false;


}


int MainWindow::bomptoboundary(int ball_x,int ball_y)
 {
    int ischange=0;
    if(ball_x<0){
        bomptowallm->stop();
         bomptowallm->play();
         if(balldir==1){
             balldir=0;
         }
         else if(balldir==2){
             balldir=3;
         }
         return 1;
     }
    else if(ball_x+50>800){
        bomptowallm->stop();
        bomptowallm->play();
        if(balldir==0){
            balldir=1;
        }
        else if(balldir==3){
            balldir=2;
        }
        return 1;

    }
    else if(ball_y<0){
        bomptowallm->stop();
        bomptowallm->play();
        if(balldir==1){
            balldir=2;
        }
        else if(balldir==0){
            balldir=3;
        }
        return 1;
     }

    else if(ball_x>=Bar->x() && ball_x<=Bar->x()+200 && ball_y+45>=Bar->y() && ball_y<=Bar->y()+29){
        if(balldir==3){
            balldir=0;
            ischange=1;
        }
        else if(balldir==2){
            balldir=1;
            ischange=1;
        }
        else if(balldir==1){
            return 0;
        }
        bomptobarm->play();
        return 1;
     }
    else if(ball_x+50>=Bar->x() && ball_x+50<=Bar->x()+200 && ball_y+45>=Bar->y() && ball_y<=Bar->y()+29){
        bomptobarm->play();
        if(ischange==0){
            if(balldir==3){
                 balldir=0;
            }
            else if(balldir==2){
                balldir=1;
            }
            else if(balldir==0){
                return 0;
            }
        }
        return 1;
    }
    else if(ball_y+45>Bar->y()+29){
        printf("isdead\n");
         return 2;
    }
    else{
         return 0;
     }

 }

void MainWindow::gameEnd()
{
    gamemod=lose;
    printf("gameover\n");
    score->setNum(bompcount);
    if(bompcount>highscore){
        highscore=bompcount;
        newest->setVisible(1);
    }
    bestscore->setNum(highscore);
    score->setVisible(1);
    scoreboard->setVisible(1);
    bestscore->setVisible(1);


}

void MainWindow::gameStart()
{
    gamemod=start;
    Bar->setVisible(1);
    Bar->move(300,450);
    Ball->setVisible(1);
    Ball->move(370,405);
    title->setVisible(0);
    createballsandbar();
    createrocks();
    printf("gamestart\n");
}

void MainWindow::gameRedy()
{
    gamemod=redy;
}
void MainWindow::gameHelp()
{
    gamemod=help;
    help_information->setVisible(1);

}
void MainWindow::gameMenu()
{
    gamemod=menu;
    menumod=Start;
    printf("gamemenu\n");
    for(int i=0;i<31;i++){
        Rocks[i]->setVisible(0);
    }    
    Ball->setVisible(1);
    Bar->setVisible(0);
    rotatedpen->setVisible(1);
    menu_selection[0]->setVisible(1);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    menu_selection[0]->setPalette(pe);
    pe.setColor(QPalette::WindowText,Qt::darkGreen);
    menu_selection[1]->setPalette(pe);
    pe.setColor(QPalette::WindowText,Qt::darkGreen);
    menu_selection[2]->setPalette(pe);
    menu_selection[1]->setVisible(1);
    menu_selection[2]->setVisible(1);
    rotatedpen->move(menu_selection[menumod]->x()-100,menu_selection[menumod]->y()-20);
    Ball->move(480,269);
    title->setVisible(1);
    penrotate();

    bgm->play();
    bgm->setPlayInLoop();




}

void MainWindow::gamePause()
{
    gamemod=pause;
}


void MainWindow::startanime()
{
    createballsandbar();
    Ball->move(180,0);
    s_b_anime = new QTimer(this);
    connect(s_b_anime,SIGNAL(timeout()),this,SLOT(start_ball_anime()));
    Rocks[14]->move(370,160);
    Rocks[14]->setVisible(1);
    Bar->setVisible(0);
    QPixmap pixmap(penImg[4]);
    rotatedpen->setPixmap(pixmap.scaled(100,100, Qt::IgnoreAspectRatio));
    rotatedpen->setVisible(1);
    rotatedpen->move(-717,245);



    s_b_anime->start(5);


}
void MainWindow::start_ball_anime()
{
    if(Ball->x()+50==370&&animetype==0){
        title->setVisible(1);
        Rocks[14]->setVisible(0);
        animetype=1;
        bomptorockm[brmindex]->play();
    }
    else if(Ball->y()==269&&animetype==1){
        animetype=2;
        stab->play();
    }
    else if(Ball->x()==479&&animetype==2){
        animetype=3;
        Ball->move(480,(Ball->y()));
        producer->setVisible(1);
        bomptobarm->play();
        readygo->play();
    }

    if(animetype==0){
        Ball->move((Ball->x()+1),(Ball->y()+1));
        rotatedpen->move(rotatedpen->x()+3,rotatedpen->y());
    }
    else if(animetype==1){
        Ball->move((Ball->x()-1),(Ball->y()+1));
        rotatedpen->move(rotatedpen->x()+3,rotatedpen->y());
    }
    else if(animetype==2){
        Ball->move((Ball->x()+2),(Ball->y()));
        //rotatedpen->move(rotatedpen->x()+3,rotatedpen->y());
    }
    else if(animecounter==1100){
        s_b_anime->stop();
        gameMenu();
        producer->setVisible(0);
        return;
    }

    animecounter++;



}
