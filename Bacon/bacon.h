#ifndef BACON_H
#define BACON_H

#include "bacon_global.h"

#include "../PizzaCore/decorator.h"

class BACONSHARED_EXPORT Bacon : public Decorator
{
    Q_OBJECT
    Q_INTERFACES(Decorator)
    Q_CLASSINFO("name", "Bacon")
    Q_PLUGIN_METADATA(IID "org.qt-project.bacon.Bacon")

public:
    Bacon();
    QString preparar();
    Decorator *clone();

private:
    QString encherDeBacon();
};

#endif // BACON_H
