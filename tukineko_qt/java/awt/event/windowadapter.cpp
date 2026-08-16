#include "windowadapter.h"

WindowAdapter::WindowAdapter(/*QObject* parent*/)
    //: QObject(parent)
{
}

WindowAdapter::~WindowAdapter()
{
}

void WindowAdapter::windowClosing(WindowEvent* e)
{
    Q_UNUSED(e);
}
