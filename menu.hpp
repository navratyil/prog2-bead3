#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

class Menu : public Widget{
protected:
    std::vector<std::string> _tetelek;
    int _felso;
    int _felette;
    int _kivalasztott_hely;
    std::string _kivalasztott;
    int _kij_sorsz;
    int _ablak;
    std::vector<int> _ay;
public:
    Menu(Ablak * a, int x, int y, int sx, int sy, std::vector<std::string> tetelek) :
        Widget(a,x,y,sx,sy), _tetelek(tetelek)
        {
            _kij_sorsz=-1;
            _ablak=-1;
            _kivalasztott_hely=-1;
            _kivalasztott=-1;
            _felette=-1;
            _felso=0;
            type="menu";
        };

    virtual void rajzol() ;
    virtual void handle(genv::event ev);
    virtual int the_chosen_one();
};


#endif // MENU_HPP_INCLUDED
