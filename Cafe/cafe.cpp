#include "cafe.h"

Cafe::Cafe()
{

}

QString Cafe::preparar()
{
    QString preparo = Decorator::preparar();
    return preparo + colocarCafe();
}

Decorator *Cafe::clone()
{
    return new Cafe;
}

QString Cafe::colocarCafe()
{
    return " com café";
}
