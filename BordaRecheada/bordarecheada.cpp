#include "bordarecheada.h"

BordaRecheada::BordaRecheada()
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

Decorator *BordaRecheada::clone()
{
    return new BordaRecheada;
}
