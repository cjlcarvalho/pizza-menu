#ifndef CAFE_H
#define CAFE_H

#include "cafe_global.h"

#include "../PizzaCore/decorator.h"

class CAFESHARED_EXPORT Cafe : public Decorator
{
    Q_OBJECT
    Q_INTERFACES(Decorator)
    Q_CLASSINFO("name", "Café")
    Q_PLUGIN_METADATA(IID "org.qt-project.cafe.Cafe")

public:
    Cafe(Component *decorated = nullptr);
    QString preparar();
    Decorator *clone();

private:
    QString colocarCafe();
};

#endif // CAFE_H
