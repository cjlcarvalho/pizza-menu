#include "decorator.h"

void Decorator::setDecorated(Component *decorated)
{
    m_decorated = decorated;
}

QString Decorator::preparar()
{
    return m_decorated->preparar();
}
