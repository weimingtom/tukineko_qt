#include "NsSelect.h"

NsSelect::NsSelect(const QString &message, const QString &label, int y, int height, bool subrutine)
    : message(message)
    , label(label)
    , y(y)
    , height(height)
    , subrutine(subrutine)
    , selected(false)
{
}

NsSelect::NsSelect(const QString &message, const QString &label, int y, int height, bool subrutine, bool selected)
    : message(message)
    , label(label)
    , y(y)
    , height(height)
    , subrutine(subrutine)
    , selected(selected)
{
}
