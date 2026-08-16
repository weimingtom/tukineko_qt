#include "nssselect.h"

NsSelect::NsSelect(const QString& _message, const QString& _label, int _y, int _height, bool _subrutine, bool _selected)
    : message(_message), label(_label), y(_y), height(_height), subrutine(_subrutine), selected(_selected)
{
}

NsSelect::~NsSelect()
{
}
