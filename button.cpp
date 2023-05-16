#include "button.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace genv;
using namespace std;

void Button::rajzol()
{

    gout << move_to(_x, _y) << color(35, 105, 39) << box(_sx,_sy);
    gout << move_to(_x+2, _y+2) << color(171, 221, 255) << box(_sx-4,_sy-4);

    gout << font("LiberationSans-Regular.ttf", 50);
    gout << move_to(_x+_sx/2-gout.twidth(_text)/2,_y+_sy/2-gout.cascent()/2-gout.cdescent()/2)
         << color(35, 105, 39) << text(_text);


}

void Button::handle(event ev)
{

    if(ev.type==ev_mouse && ev.button==btn_left){
        _nyomva=true;
        akcio();
    }else{
    if(ev.type==ev_mouse && ev.button==-btn_left){
        _nyomva=false;
    }}

}

bool Button::megnyomva()
{
    return _nyomva;
}

//std::string Button::getter(){
//return _text;
//}
