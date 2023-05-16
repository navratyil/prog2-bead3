#include "widgets.hpp"
#include "graphics.hpp"
#include "ablak.hpp"
using namespace genv;

Widget::Widget(Ablak *a, int x, int y, int sx, int sy) : _a(a), _x(x), _y(y), _sx(sx), _sy(sy)
 {
    a->hozzaadas(this);
 }

bool Widget::fokuszban(int ex, int ey)
{
    if(_x<ex && _x+_sx>ex && _y<ey && _y+_sy>ey){
        return true;
    }else{
        return false;
    }
}






