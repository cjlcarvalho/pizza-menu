#ifndef PIZZA_H
#define PIZZA_H

#include "../PizzaCore/component.h"

class Pizza : public Component
{
    Q_INTERFACES(Component)
public:
    Pizza();
    QString preparar();
};

#endif // PIZZA_H
