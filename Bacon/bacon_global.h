#ifndef BACON_GLOBAL_H
#define BACON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BACON_LIBRARY)
#  define BACONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BACONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BACON_GLOBAL_H
