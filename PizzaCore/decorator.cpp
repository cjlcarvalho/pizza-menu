#include "decorator.h"

Decorator::Decorator(Component *decorated) :
    m_decorated(decorated)
{

}

QString Decorator::preparar()
{
    return m_decorated->preparar();
}
