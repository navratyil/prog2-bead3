#include "counter.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace genv;

void Counter::rajzol()
{
    gout << font("LiberationSans-Regular.ttf", _sy/2);


    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);
    gout << move_to(_x+2, _y+2) << color(102, 153, 255) << box(_sx-4, _sy-4);

//    gout << move_to(_x+_sx-20, _y) << color(255,255,255) << box(20, _sy/2+1);
//    gout << move_to(_x, _y+_sy/2) << color(255,255,255) << box(20, _sy/2-1);

//    gout << move_to(_x+_sx-18, _y+2) << color(255, 153, 0) << box(16, _sy/2-3);
//    gout << move_to(_x+2, _y+_sy/2+1) << color(255, 153, 0) << box(16, _sy/2-3);

    gout << move_to(_x+_sx-15, _y+_sy/4) << color(100,100,100)
         << line(10,0) << move(-5,-5) << line(0,10);
    gout << move_to(_x+5, _y+(_sy/4)*3) << color(100,100,100)
         << line(10,0);

    gout << move_to(_x+_sx/2-gout.twidth(std::to_string(_szam))/2,_y+_sy/2-gout.cascent()/2-gout.cdescent()/2)
         << color(_r, _g, _b);

    if(_szam!=0) gout << text(std::to_string(_szam));
}

void Counter::handle(event ev)
{
//    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left){
//        _allithato=!_allithato;
//    }

    szam_allitas(ev);
    lambda();
}

void Counter::szam_allitas(event ev)
{
    if(ev.type==ev_key && ev.keycode==key_up && _szam<_mx){
        _szam++;
    }

    if(ev.type==ev_key && ev.keycode==key_down && _szam>_mn){
        _szam--;
    }

    if(ev.type==ev_key && ev.keycode==key_pgup && _szam<=_mx-10){
        _szam+=10;
    }else{
        if(ev.type==ev_key && ev.keycode==key_pgup && _szam>_mx-10) _szam=_mx;
    }

    if(ev.type==ev_key && ev.keycode==key_pgdn && _szam>=_mn+10){
        _szam-=10;
    }else{
        if(ev.type==ev_key && ev.keycode==key_pgdn && _szam<_mn+10) _szam=_mn;
    }

    if(ev.type==ev_key && ev.keycode==key_space){
        if(_mx>=0 && _mn<=0){
                _szam=0;
            }else{
                _szam=(_mn+_mx)/2;
            }
    }

    if(ev.type==ev_mouse && ev.button==btn_left && _szam+1<=_mx && (ev.pos_x>_x+_sx-20 && ev.pos_x<_x+_sx && ev.pos_y>_y && ev.pos_y<_y+_sy/2) ){
        _szam++;
    }
    if(ev.type==ev_mouse && (ev.pos_x>_x && ev.pos_x<_x+20 && ev.pos_y>_y+_sy/2 && ev.pos_y<_y+_sy) && _szam-1>=_mn && ev.button==btn_left){
        _szam--;
    }
}

int Counter::number()
{
    return _szam;
}

void Counter::setter(int a)
{
    _szam=a;
}

void Counter::colorsetter(bool szin)
{
    _r=255;_g=255;_b=153;
    if(!szin){
        _r=255;_g=0;_b=0;
    }
}
