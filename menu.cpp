#include "menu.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace genv;

void Menu::rajzol()
{
    gout << font("LiberationSans-Regular.ttf", 20);
    _ablak = gout.cascent()+gout.cdescent()+2;

    if(_tetelek.size()<5){
        _kij_sorsz=_tetelek.size();
    }else{
        _kij_sorsz=5;
    }

    _sy=_kij_sorsz*_ablak;

    for(int i=0; i<=((_kij_sorsz-1)*_ablak); i+=_ablak){
        gout << move_to(_x, _y+i) << color(255,255,255) << box(_sx,_ablak);
        _ay.push_back(_y+i);

        gout << move_to(_x+2, _y+2+i);
        gout << color(50,50,50);

        if(_felette==i/_ablak)gout << color(150,100,100);
        gout << box(_sx-4,_ablak-4);

        gout << move_to(_x+2, _y+2+i) << color(255,255,255) << text(_tetelek[i/_ablak+_felso]);

        //std::cout << ' ' <<_ay[i/_ablak];
    }

}

void Menu::handle(event ev)
{
    for(int i=0;i<_kij_sorsz;i++){
        if (ev.type == ev_mouse && (ev.pos_x>_x && ev.pos_x<_x+_sx && ev.pos_y>_ay[i] && ev.pos_y<_ay[i]+25) && ev.button==btn_left) {
            _felette = i;
        }
    }

    if(ev.type==ev_mouse){
        if(ev.button==btn_left){
            _kivalasztott_hely=_felette+_felso;
            _kivalasztott=_tetelek[_kivalasztott_hely];
            //std::cout << _kivalasztott_hely << ' ';
        }

        if(ev.button==btn_wheelup && _felso-1 >= 0){
            _felso--;
            _felette++;
        }

        if(ev.button==btn_wheeldown && _felso < _tetelek.size()-_kij_sorsz){
            _felso++;
            _felette--;
        }
    }
}

int Menu::the_chosen_one()
{
    return _kivalasztott_hely;
}
