#ifndef DECORATOR_H
#define DECORATOR_H

#include "component.h"

#include "pizzacore_global.h"

#include <QObject>
#include <QtPlugin>

class PIZZACORESHARED_EXPORT Decorator : public Component
{
    Q_OBJECT

public:
    void setDecorated(Component *decorated);
    virtual QString preparar();
    virtual Decorator *clone() = 0;

protected:
    Decorator(Component *decorated = nullptr);

private:
    Component *m_decorated;
};

Q_DECLARE_INTERFACE(Decorator, "org.qt-project.PizzaCore.Decorator")

#endif // DECORATOR_H
