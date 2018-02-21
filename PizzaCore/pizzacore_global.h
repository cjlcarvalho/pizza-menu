#ifndef PIZZACORE_GLOBAL_H
#define PIZZACORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PIZZACORE_LIBRARY)
#  define PIZZACORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define PIZZACORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PIZZACORE_GLOBAL_H
