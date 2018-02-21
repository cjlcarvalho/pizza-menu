#ifndef DECORATOR_H
#define DECORATOR_H

#include "component.h"

class Decorator : public Component
{
protected:
    Decorator(Component *decorated);
    QString preparar();

private:
    Component *m_decorated;
};

#endif // DECORATOR_H
