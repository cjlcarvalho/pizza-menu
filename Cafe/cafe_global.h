#ifndef CAFE_GLOBAL_H
#define CAFE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CAFE_LIBRARY)
#  define CAFESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CAFESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CAFE_GLOBAL_H
