#include "mainwindow.h"
#include "welcome.h"
#include "contestant.h"
#include "rectbutton.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QTextCodec>
#include <QVector>
#include "triangle.h"
#include "notation.h"
#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextCursor>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    cd = new CommonData;
    scene = new QGraphicsScene(1, 2, 1300, 700, this);

    view = new QGraphicsView(this);
    view->setFixedSize(1302, 704);
    view->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(view);

    sceneOfVote = new SceneOfVote(view, scene, cd, this);
    view->setScene(scene);
//    write();
//    sequenceCounter = 0;
//    speechCounter = 0;
//    speech = nullptr;
//    character = nullptr;
//    triangle = new Triangle;
//    timer = new QTimer;
//    read();


    //warning : not main scene add them to func mainscene();

}

void MainWindow::welcome()
{
    scene->clear();

    Welcome * wc = new Welcome;
    scene->setBackgroundBrush(QPixmap(""));
    connect(wc, &Welcome::shited, this, &MainWindow::mainScene);
    scene->addItem(wc);

//    QTextDocument  * doc = new QTextDocument;
////    doc->setHtml(QString("欢迎来到<span style=color:red>实力至上</span>人狼游戏教室，点击任意角色开始"));

//    QTextCharFormat cf;
//    cf.setFont(QFont("ubuntu", 24));

//    QPen outline(Qt::red, 2);
//    cf.setTextOutline(outline);

//    QTextCursor cursor = QTextCursor(doc);
//    cursor.insertText(QString("欢迎来到实力至上人狼游戏教室，点击任意角色开始"), cf);

//    QGraphicsTextItem * acg = new QGraphicsTextItem(wc);
//    acg->setDocument(doc);
//    acg->setTextInteractionFlags(Qt::TextEditable);
//    acg->setHtml(QString("AGG<span style=color:red>GCC</span>AGG"));
}

void MainWindow::notationForPlayer()
{

    QVector<int> mark = {
        10, 11, 11, 11, 11, 11, 12, 12, 12,
        20, 21, 21, 21, 21, 21, 22, 22, 22,
        30, 31, 31, 31, 31, 31, 32, 32, 32,
        40, 41, 41, 41, 41, 41, 42, 42, 42,
        50, 51, 52, 52, 52, 52, 52, 52, 52, 53, 53, 53, 53, 54, 55,
        60, 61, 61, 61, 61, 61, 62, 62, 62,
        70, 71, 71, 67, 71, 71, 72, 72, 72
    };
    for (int i = 0; i < mark.size() ; i++ ) {
        Notation * notation = new Notation(mark[i]);
        scene->addItem(notation);
    }


}

void MainWindow::write()
{
//    QFile dataFile("day1.csv");
    QFile dataFile(cd->dayFileNM[cd->day]);

    if(!dataFile.open(QIODevice::WriteOnly)){
        qDebug() << "cant open to write day1.csv";
        return;
    }
    QTextStream youngStream(&dataFile);
//    youngStream.setCodec(QTextCodec::codecForName("utf-8"));
    youngStream << "1" << ","
                << QString("天は人の上に人を造らず、人の下に人を造らず")
                << ","
                << "gay" << "\n"
                << tr("学問に励めか否かあとでさをつく") << "\n";

    //    dataFile.close();
}

void MainWindow::read()
{
//    QFile dataFile("day1.csv");
    QFile dataFile(cd->dayFileNM[cd->day]);
//    qInfo() << cd->dayFileNM[cd->day];

    if(!dataFile.open(QIODevice::ReadOnly)){
        qDebug() << "can't open check file name";
    }
    QTextStream oldStream(&dataFile);
//    QStringList inListStream = oldStream.readAll();
//    QString inStream  = oldStream.readLine();
    while(!oldStream.atEnd())
    {

        QStringList line = oldStream.readLine().split(",");
        sequenceOfNumber.append(line[0].toInt());
        sequenceOfReason.append(line[1]);
//        if(cd->dayFileNM[cd->day] == QString("day4.csv"))
//        {
////            qInfo() << sequenceCounter;
//        }
//        int i = 0;
//        for(QString item: line.split(",")){
//            switch(i){
//            case 0: {
////                qInfo() << item;
//                sequenceOfNumber << item.toInt();
//                i++;
//                break;
//            }
//            case 1:{
////                qInfo() << item;
//                sequenceOfReason << item;
//                i--;
//                break;
//            }

//            }
//        }
        sequenceCounter++;
    }
    giveCharacterName(sequenceOfReason);
//    qInfo() << sequenceOfNumber[2] + 19;
//    qInfo() << sequenceOfReason[2];
//    qInfo() << sequenceCounter;
//    dataFile.close();
}

void MainWindow::takeSpeech()
{

    if(character){
//        scene->removeItem(speech);
        scene->removeItem(character);
//        delete speech;
        delete character;
    }


    character = new QGraphicsPixmapItem();
    character->setPixmap(QPixmap(":/elite/" + QString::number(sequenceOfNumber[speechCounter]) +"c.png"));
    character->setFlag(QGraphicsItem::ItemIsMovable);
//    character->setZValue(-1);
    character->setPos(200, 180);
    scene->addItem(character);

//    speech = new QGraphicsTextItem(sequenceOfReason[speechCounter], character);
    speech = new QGraphicsTextItem(character);
    speech->setHtml(sequenceOfReason[speechCounter]);
//    speech->setFlag(QGraphicsItem::ItemIsMovable);
    speech->setFont(QFont("ubuntu", 30));
    speech->setTextWidth(500);
    speech->setPos(character->boundingRect().width() + 20,
                   ((character->boundingRect().height() - 380) - speech->boundingRect().height()) / 2);
//    scene->addItem(speech);

    speechCounter++;

    if(speechCounter == sequenceCounter){
        timer->disconnect();
        arrow->disconnect();
    //        delete arrow;
        scene->removeItem(pb);
        delete pb;
    //        scene->removeItem(triangle);

    //        RectButton * rb = new RectButton;
    //        rb->setRect(500, 300, 300, 100);
    //        rb->setBrush(Qt::darkCyan);
    //        scene->addItem(rb);
    //        connect(rb, &RectButton::shited, this, &MainWindow::voteScene);
        triangle->disconnect();
        bool isGameOver = gameOver();
        if(!isGameOver){
            connect(triangle, &Triangle::shited, this, &MainWindow::voteScene);
        }
        else{
            connect(triangle, &Triangle::shited, this, &MainWindow::welcome);
        }

        return;
    }
}

void MainWindow::giveCharacterName(QStringList &rawData)
{
    for(int i = 12; i != -1; i--){
        rawData.replaceInStrings(cd->symbol[i], cd->name[i]);
    }
}

bool MainWindow::gameOver()
{
    bool isGmaeOver = false;

//    int wolf1 = 0, wolf2 = 0, wolf3 = 0;
    QVector<int> wolfIndex;
    QStringList aws = cd->answer[0].split(",");
    for(int i = 0; i < 13; i++){
        if(aws[i].toInt()){
            wolfIndex.append(i);
        }
    }
    QStringList oneDay = cd->answer[cd->day].split(",");
    int countAliveWolf = oneDay[wolfIndex[0]].toInt() + oneDay[wolfIndex[1]].toInt() + oneDay[wolfIndex[2]].toInt();
    int countALiveHunman = 0;
    for (int i = 0; i < 13; i++) {
        if(oneDay[i].toInt() == 1 && i != wolfIndex[0] && i != wolfIndex[1] && i != wolfIndex[2])   {
                countALiveHunman++;
        }
    }


    if(!countAliveWolf){
        isGmaeOver = true;
    }
    else if(countALiveHunman <= countAliveWolf){
        isGmaeOver = true;
    }
    return isGmaeOver;
}

void MainWindow::mainScene()
{
//    qInfo() << "phase : " << "1";
    scene->clear();
//    qInfo() << "phase : " << "2";

    scene->setBackgroundBrush(QPixmap(":/elite/bar.png").scaled(1302, 704));
    triangle = new Triangle;
    timer = new QTimer;
    arrow = new QShortcut(this);
    cd->day = 1;
//    qInfo() << "phase : " << "3";

    iniDayN();
//    qInfo() << "phase : " << "4";

    notationForPlayer();
    //290 * 690 //2D photo
//    qInfo() << "phase : " << "5";



    triangle->setPos(1150, 250);
    scene->addItem(triangle);

//    takeSpeech();
//    connect(triangle, &Triangle::shited, this, &MainWindow::takeSpeech);


//    timer = new QTimer;
//    pb = new PlayButton;
//    pb->setPos(1100, 200);
//    scene->addItem(pb);
//    connect(pb, &PlayButton::shit, this, &MainWindow::beginAutoPlay);
}

void MainWindow::voteScene()
{
    if(character){
//        scene->removeItem(speech);
        scene->removeItem(character);
//        delete speech;
        delete character;
    }

    triangle->disconnect();
    //
    //triangle connect to initalize dayN
    connect(triangle, &Triangle::shited, this, &MainWindow::iniDayN);
    sceneOfVote->setSceneRect(1, 2, 1300, 700);
    view->setScene(sceneOfVote);
    sceneOfVote->iniVote();

//    RectButton * rb = new RectButton;
//    rb->setRect(500, 300, 300, 100);
//    rb->setBrush(Qt::darkCyan);
//    sceneOfVote->addItem(rb);
//    connect(rb, &RectButton::shited, this, &MainWindow::sceneSwitch);
}

void MainWindow::sceneSwitch()
{
    view->setScene(scene);
}

void MainWindow::beginAutoPlay()
{

    if(pb->isAuto){
        connect(timer, &QTimer::timeout, this, &MainWindow::takeSpeech);
        timer->start(4000);
    }
    else{
        timer->disconnect();
    }

}

void MainWindow::iniDayN()
{


    speechCounter = 0;
    speech = nullptr;
    character = nullptr;

    sequenceCounter = 0;
    sequenceOfNumber.clear();
    sequenceOfReason.clear();

    read();
//    qInfo() << "phase : " << "day1";

    if(!contestantsList.isEmpty() && cd->day != 1){
        for(auto c: contestantsList){
            scene->removeItem(c);
            delete c;
        }
    }
//    qInfo() << "phase : " << "day2";

    contestantsList.clear();

    QStringList eliteStatus = cd->answer[cd->day].split(",");

    for(int i = 0; i != 13; i++){
        Contestant * ctt = new Contestant(eliteStatus[i].toInt());
        ctt->setPixmap(QPixmap(QString(":/elite/") + QString::number(i) + QString("n.png")).scaled(160,160));
        scene->addItem(ctt);
        if((i < 5) == 1){ //size 8;
            ctt->setPos(250 + 90 + 160 + (4 - i) * 160 , 0);
         }
        else if(i >= 5 && i <= 7){

             ctt->setPos(0, 180 + 180 * (i - 5));

        }else{
            ctt->setPos(250 + 90 + 160 + 160 * (i - 8) , 540);
        }

        contestantsList.append(ctt);
    }



    pb = new PlayButton;
    pb->setPos(1250, 200);
    scene->addItem(pb);
    connect(pb, &PlayButton::shit, this, &MainWindow::beginAutoPlay);

    //short cut
//    arrow = new QShortcut(this);
    arrow->setKey(Qt::Key_Right);
    connect(arrow, &QShortcut::activated, this, &MainWindow::takeSpeech);

//    triangle = new Triangle;
    triangle->disconnect();
    connect(triangle, &Triangle::shited, this, &MainWindow::takeSpeech);

}

