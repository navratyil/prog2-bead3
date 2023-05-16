#include "static.hpp"
#include "graphics.hpp"
#include <string>
using namespace genv;



void StaticText::rajzol()
{
    gout << font("LiberationSans-Regular.ttf", _sy/2);
    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
    gout << move_to(_x+2, _y+2) << color(102, 153, 255) << box(_sx-4, _sy-4);
    gout << move_to(_x+_sx/2-gout.twidth(std::to_string(_text))/2,_y+_sy/2-gout.cascent()/2-gout.cdescent()/2)
         << color(0, 0, 0) << text(std::to_string(_text));

}
//void StaticText::setter(std::string text){
//_text=text;
//}

void StaticText::handle(event ev)
{

}

