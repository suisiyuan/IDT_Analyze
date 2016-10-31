#pragma once

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPixmap>
#include <QVector>

class DbHandler : public QObject
{
    Q_OBJECT
public:
    DbHandler(QObject *parent = Q_NULLPTR);
	DbHandler(QString filepath, QObject *parent = Q_NULLPTR);

	~DbHandler();


	typedef enum {
		NoError,
		OpenFailed,
		NoProjectInfo,
		NoBigImages,
		NoImages
	}ErrorCode;

	typedef struct {
		quint32 depth;
		QPixmap pixmap;
	}SmallImage;

	void openDatabase(QString filepath);
	ErrorCode lastError() { return errorCode; }

	QPixmap getBigImage(quint16 index);
	QVector<QPixmap> getSmallImage(quint32 start, quint32 end);


signals:

public slots:

private:
	QSqlDatabase database;	// 数据路变量
	ErrorCode errorCode;	// 错误代码

};
