#include "bacon.h"

Bacon::Bacon(Component *decorated) :
    Decorator(decorated)
{
}

QString Bacon::preparar()
{
    QString preparo = Decorator::preparar();
    return preparo + encherDeBacon();
}

Decorator *Bacon::clone()
{
    return new Bacon(nullptr);
}

QString Bacon::encherDeBacon()
{
    return " com bacon";
}
