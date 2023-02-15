#include "sceneofvote.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>



SceneOfVote::SceneOfVote(QGraphicsView *view, QGraphicsScene *scene, CommonData * rcd, QObject *parent)
    : QGraphicsScene{parent}, cd(rcd)
{
    mView = view;
    mMainScene = scene;
    arrow = new QShortcut(mView); //shortcut can't new N times ,don't know why


//    answerOfWolf << true << false << false << false << false
//                 << true << false << false << true << false
//                 << false << false << false;
    QStringList tfList = cd->answer[0].split(",");
    for(QString aws: tfList){
        if(aws.toInt() == 1){
            answerOfWolf.append(true);
        }
        else{
            answerOfWolf.append(false);
        }
    }


    setSceneRect(1,2, 1300, 700);
//    fileNameOfCSV = QString("vote1.csv");


//    countLine = 0;
//    countReason = 0;
//    character = nullptr;



//    iniVote();

}

void SceneOfVote::iniVote()
{
    countLine = 0;
    countReason = 0;
    character = nullptr;

    trackingVote.clear();
    voteIndex.clear();
    votedIndex.clear();
    voteReason.clear();
    statisticVote = QVector<int>(13, 0);

    countFinalReason = 0;
    fSpeechNumber.clear();
    fSpeechReason.clear();
    finalVote.clear();
    killedNumber.clear();
    finalReason.clear();
    j = 0;

    needFinal = false;

    fileNameOfCSV = cd->voteFileNM[cd->day];
    read(fileNameOfCSV);

    showVoteList();

    triangle = new Triangle;
    timer = new QTimer(this);
    pb = new PlayButton;
    triangle->setPos(1000,150);
    this->addItem(triangle);
    connect(triangle, &Triangle::shited, this, &SceneOfVote::showReason);

//    arrow = new QShortcut(mView);
    arrow->setKey(Qt::Key_Space);
    connect(arrow, &QShortcut::activated, this, &SceneOfVote::showReason);

    pb->setPos(1100, 200);
    this->addItem(pb);
    connect(pb, &PlayButton::shit, this, &SceneOfVote::beginAutoPLay);



}



void SceneOfVote::showVoteList()
{
//    this->clear();
    QStringList isAlive = cd->answer[cd->day].split(",");
    for(int i = 0; i != 13; i++){
        Vote * vote = new Vote(i, isAlive[i].toInt());
//        vote->showVote();
        vote->setPos(33 + i * 95, 550);
        this->addItem(vote);
        trackingVote.append(vote);
    }
}

void SceneOfVote::read(QString fileName)
{
    QFile dataFile(fileName);
    if(!dataFile.open(QIODevice::ReadOnly)){
        qInfo() << "maybe need check file name";
    }
    QTextStream stream(&dataFile);
    while(!stream.atEnd()){
        QStringList sl = stream.readLine().split(",");
//        qInfo() << sl.size();
        voteIndex.append(sl[0].toInt());
        voteReason.append(sl[1]);
        votedIndex.append(sl[2].toInt());



        countLine++;
    }
    giveCharacterName(voteReason);
//    qInfo() << voteIndex.size();
    dataFile.close();
}

void SceneOfVote::showReason()
{

    if(character){
        this->removeItem(character);
        delete character;
//        this->removeItem(reason);
    }
//    qInfo() << "ここ？";
    character = new QGraphicsPixmapItem;
    character->setPixmap(QPixmap(QString(":/elite/") +
                                 QString::number(voteIndex[countReason]) +
                                 QString("n.png")));
    character->setPos(270,175);
    this->addItem(character);

    reason = new QGraphicsTextItem(character);
//    reason->setPlainText(voteReason[countReason]);
    reason->setHtml(voteReason[countReason]);
    reason->setTextWidth(500);
    reason->setFont(QFont("ubuntu", 25));
    reason->setPos(character->boundingRect().width() + 10,
                   (character->boundingRect().height() - reason->boundingRect().height()) / 2);

    trackingVote[votedIndex[countReason]]->setVoteCounter();
    statisticVote[votedIndex[countReason]]++;
//    QString str("");
//    for(int i = 0; i != statisticVote.size(); i++){
//        str += QString::number(statisticVote[i]);
//        str += QString(" ,");
//    }
//    qInfo() << str;
// 　さき　Debugを使うべきだったな
    countReason++;
    if(countLine == countReason){
    //        qInfo() << "ここ？";
        //何のかの判断で
        //find max value, than use count()
    //        QString str("");
    //        for(int i = 0; i != statisticVote.size(); i++){
    //            str += QString::number(statisticVote[i]);
    //            str += QString(" ,");
    //        }
    //        qInfo() << str << "もうだめだ";
        int max = *std::max_element(statisticVote.constBegin(), statisticVote.constEnd());
        int countMax = statisticVote.count(max);
    //        qInfo() << countMax << " :"<< max;
        triangle->disconnect();
        arrow->disconnect();
        pb->disconnect();
        pb->isAuto = false;
        pb->changePolygon();
        timer->disconnect();
        finalRead();

        if(countMax > 1){

            connect(pb, &PlayButton::shit, this, &SceneOfVote::beginAutoFinal);
            connect(triangle, &Triangle::shited, this, &SceneOfVote::showFinalReason);
        }
        else{
            //直接遺言だ
            connect(pb, &PlayButton::shit, this, &SceneOfVote::beginAutoYuigon);
            connect(triangle, &Triangle::shited, this, &SceneOfVote::showyuigon);
        }
        return;
    }
}

void SceneOfVote::finalRead()
{
//    QFile dataFile("fvote1.csv");
    QFile dataFile(cd->fvoteFileNM[cd->day]);

    if(!dataFile.open(QIODevice::ReadOnly)){
        qInfo() << "check your file name";
    }
    bool isFinal = false;

    QTextStream stream(&dataFile);
    while(!stream.atEnd()){
        QStringList line = stream.readLine().split(",");
        if(line.size() == 13){
            isFinal = true;
            finalVote = line;

        }
        else if(isFinal){
            killedNumber.append(line[0].toInt());
            finalReason.append(line[1]);
        }
        else{
            fSpeechNumber.append(line[0].toInt());
            fSpeechReason.append(line[1]);
        }
    }
    giveCharacterName(finalReason);
    giveCharacterName(fSpeechReason);

    dataFile.close();
}

void SceneOfVote::showFinalReason()
{
    if(character){
        this->removeItem(character);
        delete character;
    }
    character = new QGraphicsPixmapItem;
    character->setPixmap(QPixmap(QString(":/elite/") +
                                 QString::number(fSpeechNumber[countFinalReason]) +
                                 QString("n.png")));
    character->setPos(270,175);
    this->addItem(character);

    reason = new QGraphicsTextItem(character);
//    reason->setPlainText(fSpeechReason[countFinalReason]);
    reason->setHtml(fSpeechReason[countFinalReason]);
    reason->setTextWidth(500);
    reason->setFont(QFont("ubuntu", 25));
    reason->setPos(character->boundingRect().width() + 10,
                   (character->boundingRect().height() - reason->boundingRect().height()) / 2);

    countFinalReason++;
    if(countFinalReason == fSpeechNumber.size()){

        triangle->disconnect();
        timer->disconnect();
        pb->disconnect();
//        qInfo() << " !";
        pb->isAuto = false;
        pb->changePolygon();
        connect(triangle, &Triangle::shited, this, &SceneOfVote::showFinalVote);
        connect(pb, &PlayButton::shit, this, &SceneOfVote::beginAutoFinalVote);
        return;
    }
}

void SceneOfVote::showFinalVote()
{
    for(int i = 0; i != 13; i++){
        if(finalVote[i].toInt() == i){
            continue;
        }
        trackingVote[i]->showFinalScore(finalVote[i]);
    }

    triangle->disconnect();
    pb->disconnect();
    pb->isAuto = false;
    pb->changePolygon();
    if(timer){
        timer->disconnect();
    }
    connect(pb, &PlayButton::shit, this, &SceneOfVote::beginAutoYuigon);
    connect(triangle, &Triangle::shited, this, &SceneOfVote::showyuigon);

}

void SceneOfVote::showyuigon()
{

    if(j == killedNumber.size()){
        pb->disconnect();
        timer->disconnect();
        playChoice();
        return;
    }
    if(character){
        this->removeItem(character);
        delete character;
    }
    character = new QGraphicsPixmapItem;
    character->setPixmap(QPixmap(QString(":/elite/") +
                                 QString::number(killedNumber[j]) +
                                 QString("n.png")));
    character->setPos(270,175);
    this->addItem(character);

    reason = new QGraphicsTextItem(character);
    reason->setPlainText(finalReason[j]);
    reason->setHtml(finalReason[j]);
    reason->setTextWidth(500);
    reason->setFont(QFont("ubuntu", 25));
    reason->setPos(character->boundingRect().width() + 10,
                   (character->boundingRect().height() - reason->boundingRect().height()) / 2);

    j++;

}

void SceneOfVote::playChoice()
{
    this->clear();
    playerChooseList.clear();
    for(int i = 0; i != 13; i++){
        PhotoToPlayer * ptp = new PhotoToPlayer(QString::number(i));
        if(i < 4){
            ptp->setPos(150 + i * 160 ,50);
        }
        else if( i >= 4 && i <= 8){
            ptp->setPos(250 + (i - 4) * 160,270);
        }
        else{
            ptp->setPos(350 + (i - 8) * 160, 490);
        }
        playerChooseList.append(ptp);
        this->addItem(ptp);
//        qInfo() << playerChooseList[i]->getIsChoosed();
    }

    playTri = new Triangle;
    playTri->setPos(1100, 200);
    this->addItem(playTri);
    connect(playTri, &Triangle::shited, this, &SceneOfVote::checkPlayersChoose);

}

void SceneOfVote::giveCharacterName(QStringList &rawData)
{
    for(int i = 12; i != -1; i--){
        rawData.replaceInStrings(cd->symbol[i], cd->name[i]);
    }
}

void SceneOfVote::checkPlayersChoose()
{
    int wolf = 3;
    int count = 0;
    for (int i = 0; i != 13; i++) {
        if(playerChooseList[i]->getIsChoosed())
        {
            count++;
//            playerChooseList[i]->setIsChoosed(false);
        }
    }
//    qInfo() << count;

    if(count == 3){
        playTri->disconnect();

        QGraphicsTextItem * ms = new QGraphicsTextItem;
        ms->setFont(QFont("ubuntu", 40));
        ms->setPlainText("YOU ARE RIGHT");
        ms->setPos((1300 - ms->boundingRect().width()) / 2, 250);

        for(int i = 0; i != 13; i++){
            if(answerOfWolf[i] != playerChooseList[i]->getIsChoosed()){

//                qInfo() << i << "i : " << answerOfWolf[i] << " : " << playerChooseList[i]->getIsChoosed();
                ms->setPlainText("WRONG");
                ms->setPos((1300 - ms->boundingRect().width()) / 2, 250);
                break;
            }
        }
        this->clear();
//        this->addItem(playTri); //point すら 死んでる
        playTri = new Triangle;
        playTri->setPos(600, 350);
        this->addItem(playTri);
        connect(playTri, &Triangle::shited, this, &SceneOfVote::switchScene);
        this->addItem(ms);

    }
    else if(count < wolf){
        QMessageBox msg(QMessageBox::Information,
                        tr(""),
                        tr("选择人数【不足】三人， 请重新选择"),
                        QMessageBox::Ok);
        msg.show();
        msg.exec();
        playTri->disconnect();
        playChoice();
    }
    else{
        QMessageBox msg(QMessageBox::Information,
                        tr(""),
                        tr("选择人数【超过】三人， 请重新选择"),
                        QMessageBox::Ok);
        msg.show();
        msg.exec();
        playTri->disconnect();
        playChoice();
    }

}

void SceneOfVote::switchScene()
{
    cd->day++;
    playTri->disconnect();
    this->clear();
    mView->setScene(mMainScene);

    //connect to initalvote
}

void SceneOfVote::beginAutoPLay()
{

    connect(timer, &QTimer::timeout, this, &SceneOfVote::showReason);
    timer->start(200);
}

void SceneOfVote::beginAutoFinal()
{
    connect(timer, &QTimer::timeout, this, &SceneOfVote::showFinalReason);
    timer->start(200);
}

void SceneOfVote::beginAutoFinalVote()
{
    connect(timer, &QTimer::timeout, this, &SceneOfVote::showFinalVote);
    timer->start(200);
}

void SceneOfVote::beginAutoYuigon()
{
    connect(timer, &QTimer::timeout, this, &SceneOfVote::showyuigon);
    timer->start(200);
}
