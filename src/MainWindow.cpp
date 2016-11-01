#include "MainWindow.h"
#include "ui_main.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	dbHander(Q_NULLPTR)
{
    ui->setupUi(this);

	initMenuAndToolbar();
}

MainWindow::~MainWindow()
{
    delete ui;
	delete dbHander;
}


void MainWindow::initMenuAndToolbar()
{
	
}


void MainWindow::on_actionOpen_triggered()
{
	QFileDialog dialog(this, tr("Open project file"), settings.value(DEFAULT_PATH_REG).toString(), tr("Project file (*.ylink)"));
	if (dialog.exec())
	{
		QString filepath = dialog.selectedFiles().constFirst();
		QString dirpath = dialog.directory().path();
		QStringList recentFiles = settings.value(RECENT_FILES_REG).toStringList();

		// 建立数据库处理类
		dbHander = new DbHandler(filepath, this);
		//ui->label->setPixmap(dbHander->getBigImage(0));

		// 设置注册表
		settings.setValue(DEFAULT_PATH_REG, QVariant(dirpath));
		qint8 result = recentFiles.indexOf(filepath);
		if (-1 == result)
		{
			if (MAX_RECENT_FILES <= recentFiles.count())
			{
				recentFiles.pop_front();
			}
		}
		else
		{
			recentFiles.removeAt(result);
		}
		recentFiles.append(filepath);
		settings.setValue(RECENT_FILES_REG, QVariant(recentFiles));
	}
}


void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSaveAs_triggered()
{
	QString filepath = QFileDialog::getSaveFileName(this,
													tr("Save as"),
													settings.value(DEFAULT_PATH_REG).toString(),
													tr("Project files (*.ylink)")
													);
	qDebug() << filepath;
}


void MainWindow::on_actionSaveImage_triggered()
{
	QString filepath = QFileDialog::getSaveFileName(this,
													tr("Save images"),
													settings.value(DEFAULT_PATH_REG).toString(),
													tr("Image files (*.png)")
	);
	qDebug() << filepath;
}

void MainWindow::on_actionExit_triggered()
{
	this->close();
}
