#include "MainWindow.h"
#include <QApplication>
#include <QProcessEnvironment>

#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QApplication::setApplicationName(APP_NAME);
	QApplication::setApplicationVersion(APP_VERSION);
	QApplication::setOrganizationName(COMPANY_NAME);
	QApplication::setOrganizationDomain(COMPANY_URL);

	QSettings settings;
#ifdef Q_OS_WIN32
    QString path = QProcessEnvironment::systemEnvironment().value("HOMEPATH") + "/" + COMPANY_NAME;
#endif
#ifdef Q_OS_LINUX
    QString path = QProcessEnvironment::systemEnvironment().value("HOME") + "/" + COMPANY_NAME;
#endif
	// 设置默认路径
	if (!settings.contains(DEFAULT_PATH_REG))
        settings.setValue(DEFAULT_PATH_REG, QVariant(path));
	// 保存最近文件路径
	if (!settings.contains(RECENT_FILES_REG))
		settings.setValue(RECENT_FILES_REG, QVariant(QStringList()));

    MainWindow w;
    w.show();

    return a.exec();
}
