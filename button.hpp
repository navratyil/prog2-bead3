#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

class Button : public Widget{
protected:
    bool _nyomva=false;
    std::string _text;
public:

    Button(Ablak* a, int x, int y, int sx, int sy, std::string text) :
        Widget(a,x,y,sx,sy), _text(text){    type = "gomb";};

    virtual void rajzol();
    virtual void handle(genv::event ev);
    virtual bool megnyomva();
    virtual void akcio()=0;

    //std::string getter();
};

class FunktorButton : public Button{
std::function<void()> _f;

public:
    FunktorButton(Ablak *a, int x, int y, int sx, int sy, std::string text, std::function<void()> f)
    : Button(a,x,y,sx,sy,text), _f(f){};
    virtual void akcio(){
        _f();
    }
} ;


#endif // BUTTON_HPP_INCLUDED
