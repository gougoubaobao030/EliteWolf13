#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QStringList>

class CommonData
{
public:
    int day;
    QStringList name;
    QStringList symbol;
    QStringList answer;
    QStringList dayFileNM;
    QStringList voteFileNM;
    QStringList fvoteFileNM;
    CommonData();
    void read();
};

#endif // COMMONDATA_H
