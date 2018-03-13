#include "bacon.h"

Bacon::Bacon()
{
}

QString Bacon::preparar()
{
    QString preparo = Decorator::preparar();
    return preparo + encherDeBacon();
}

Decorator *Bacon::clone()
{
    return new Bacon;
}

QString Bacon::encherDeBacon()
{
    return " com bacon";
}
