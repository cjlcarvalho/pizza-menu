#include "cafe.h"

Cafe::Cafe(Component *decorated) :
    Decorator(decorated)
{

}

QString Cafe::preparar()
{
    QString preparo = Decorator::preparar();
    return preparo + colocarCafe();
}

Decorator *Cafe::clone()
{
    return new Cafe(nullptr);
}

QString Cafe::colocarCafe()
{
    return " com café";
}
