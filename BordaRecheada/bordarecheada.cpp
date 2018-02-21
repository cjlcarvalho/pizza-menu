#include "bordarecheada.h"

BordaRecheada::BordaRecheada(Component *decorated) :
    Decorator(decorated)
{
}

QString BordaRecheada::preparar()
{
    QString preparo = Decorator::preparar();
    return preparo + rechear();
}

QString BordaRecheada::rechear()
{
    return " com borda recheada";
}
