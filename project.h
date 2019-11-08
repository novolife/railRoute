#ifndef PROJECT_H
#define PROJECT_H

#include <QtWidgets>

template<class QVector>

class Project
{
public:
    Project();

private:
    QString prjName;
    QVector *prjNodes;
};

#endif // PROJECT_H
