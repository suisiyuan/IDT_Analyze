#include "MainWindow.h"
#include <QApplication>

#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QApplication::setApplicationName(APP_NAME);
	QApplication::setApplicationVersion(APP_VERSION);
	QApplication::setOrganizationName(COMPANY_NAME);
	QApplication::setOrganizationDomain(COMPANY_URL);

	QSettings settings;
	if (!settings.contains(DEFAULT_PATH_REG))
		settings.setValue(DEFAULT_PATH_REG, QVariant(DEFAULT_FOLDER));
	if (!settings.contains(RECENT_FILES_REG))
		settings.setValue(RECENT_FILES_REG, QVariant(QStringList()));


    MainWindow w;
    w.show();

    return a.exec();
}
