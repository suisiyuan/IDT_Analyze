#pragma once

#include <QObject>

class DbHandler : public QObject
{
    Q_OBJECT
public:
    explicit DbHandler(QObject *parent = 0);

signals:

public slots:
};
