#include "Tukineko.h"
#include "NsWindow.h"

namespace tukineko {

void Tukineko::main(const QStringList &args)
{
    Q_UNUSED(args)
    new NsWindow();
}

}
