#include "commondata.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

CommonData::CommonData()
{
    day = 1;

    name << QString("<span style=color:#e83929;background-color:#f9f2f4;>綾小路清隆</span>")
         << QString("<span style=color:#0f2350;background-color:#f9f2f4;>堀北鈴音</span>")
         << QString("<span style=color:#e6b422;background-color:#f9f2f4;>轻井沢恵</span>")
         << QString("<span style=color:#8d6449;background-color:#f9f2f4;>櫛田桔梗</span>")
         << QString("<span style=color:green;background-color:#f9f2f4;>葛城康平</span>")
         << QString("<span style=color:#c4a3bf;background-color:#f9f2f4;>坂柳有栖</span>")
         << QString("<span style=color:#f6bfbc;background-color:#f9f2f4;>一之瀬帆波</span>")
         << QString("<span style=color:#5b2c6f;background-color:#f9f2f4;>龍园翔</span>")
         << QString("<span style=color:#0095d9;background-color:#f9f2f4;>伊吹澪</span>")
         << QString("<span style=color:#e597b2;background-color:#f9f2f4;>佐倉愛里</span>")
         << QString("<span style=color:#5b6356;background-color:#f9f2f4;>平田洋介</span>")
         << QString("<span style=color:#fcc800;background-color:#f9f2f4;>高元寺六助</span>")
         << QString("<span style=color:red;background-color:#f9f2f4;>須藤健</span>")
         << QString("<span style=color:yellow;background-color:#f9f2f4;>茶柱佐枝</span>");

    symbol << QString("0】")
           << QString("1】")
           << QString("2】")
           << QString("3】")
           << QString("4】")
           << QString("5】")
              << QString("6】")
                 << QString("7】")
                    << QString("8】")
                       << QString("9】")
                          << QString("10】")
                             << QString("11】")
                                << QString("12】")
                                   << QString("19】");


    dayFileNM << "NoFile" << "day1.csv" << "day2.csv" << "day3.csv" << "day4.csv"
              << "day5.csv" << "day6.csv" << "day7.csv" << "day8.csv";

    voteFileNM << "NoFile" << "vote1.csv" << "vote2.csv" << "vote3.csv" << "vote4.csv"
               << "vote5.csv" << "vote6.csv" << "vote7.csv" << "vote8.csv";

    fvoteFileNM << "NoFile" << "fvote1.csv" << "fvote2.csv" << "fvote3.csv" << "fvote4.csv"
                << "fvote5.csv" << "fvote6.csv" << "fvote7.csv" << "fvote8.csv";
    read();
}

void CommonData::read()
{
    QFile dataFile("answer.csv");
    if(!dataFile.open(QIODevice::ReadOnly)){
        qInfo() << "ayanokouzi: check your file name";
    }

    QTextStream stream(&dataFile);
    while(!stream.atEnd()){
        answer << stream.readLine();
    }

    dataFile.close();
}
