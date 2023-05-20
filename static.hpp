#ifndef STATIC_HPP_INCLUDED
#define STATIC_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class StaticText : public Widget{
protected:
    int _text;
public:
    StaticText(Ablak *a, int x, int y, int sx, int sy, int text) :
        Widget(a,x,y,sx,sy),_text(text) {type="static";};
    virtual void rajzol() ;
    virtual void handle(genv::event ev);
//    void setter(std::string text);

};




#endif // STATIC_HPP_INCLUDED
