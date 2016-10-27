#pragma once

#define COMPANY_NAME    "ylink"
#define COMPANY_URL     "http://www.y-link.cn/"
#define APP_NAME        "IDT_Analyze"
#define APP_VERSION     "1.0.0"

#define DEFAULT_PATH_REG	"defaultPath"
#define RECENT_FILES_REG	"recentFiles"


#define MAX_RECENT_FILES	10

#ifdef Q_OS_WIN32
#define DEFAULT_FOLDER  (QString("C:/") + COMPANY_NAME)	
#endif // Q_OS_WIN32

#ifdef Q_OS_LINUX
#define DEFAULT_FOLDER  (QString("~/") + COMPANY_NAME)	
#endif // Q_OS_LINUX


