#ifndef PIZZA_H
#define PIZZA_H

#include "component.h"

class Pizza : public Component
{
public:
    Pizza();
    QString preparar();
};

#endif // PIZZA_H
