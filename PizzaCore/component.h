#ifndef COMPONENT_H
#define COMPONENT_H

#include "pizzacore_global.h"

#include <QObject>
#include <QString>

class PIZZACORESHARED_EXPORT Component : public QObject
{
    Q_OBJECT

public:
    virtual QString preparar() = 0;
};

Q_DECLARE_INTERFACE(Component, "org.qt-project.PizzaCore.Component")

#endif // COMPONENT_H
