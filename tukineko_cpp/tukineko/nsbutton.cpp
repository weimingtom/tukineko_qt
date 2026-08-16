#include "nsbutton.h"

NsButton::NsButton()
    : no(0)
    , x(0), y(0)
    , width(0), height(0)
    , u(0), v(0)
    , img(nullptr), imgHover(nullptr), imgClick(nullptr)
    , visible(true)
    , enabled(true)
{
}
