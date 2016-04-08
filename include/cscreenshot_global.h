#ifndef _CSCREENSHOT_GLOBAL_H_
#define _CSCREENSHOT_GLOBAL_H_

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(CSCREENSHOT_LIBRARY)
#  define CSCREENSHOTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CSCREENSHOTSHARED_EXPORT Q_DECL_IMPORT
#endif

#if 0
#define C_SCREENSHOTSHARED_LOG(text) qDebug()<<"C_SCREENSHOTSHARED_LOG:"<<text;
#define C_SCREENSHOTSHARED_LOG_FUNCTION C_SCREENSHOTSHARED_LOG(QString("Enter fuction:") + QString(Q_FUNC_INFO) + QString(__LINE__))
#else
#define C_SCREENSHOTSHARED_LOG(text)
#define C_SCREENSHOTSHARED_LOG_FUNCTION
#endif

#endif // _CSCREENSHOT_GLOBAL_H_
