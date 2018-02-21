#ifndef BORDARECHEADA_H
#define BORDARECHEADA_H

#include "bordarecheada_global.h"

#include "../PizzaCore/decorator.h"

class BORDARECHEADASHARED_EXPORT BordaRecheada : public Decorator
{
    Q_OBJECT
    Q_INTERFACES(Decorator)
    Q_PLUGIN_METADATA(IID "org.qt-project.bordarecheada.BordaRecheada")

public:
    BordaRecheada(Component *decorated = nullptr);
    QString preparar();

private:
    QString rechear();
};

#endif // BORDARECHEADA_H