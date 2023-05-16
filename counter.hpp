#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

class Counter : public Widget{
protected:
    //bool _allithato;
    int _mn;
    int _mx;
    int _szam;
    std::function<void()> _f;
public:
    Counter(Ablak *a, int x, int y, int sx, int sy, int mn, int mx,std::function<void()> f) :
        Widget(a,x,y,sx,sy), _mn(mn), _mx(mx), _f(f)
        {
            //_allithato=false;
            if(mx>=0 && mn<=0){
                _szam=0;
            }else{
                _szam=(mn+mx)/2;
            }
        };
    virtual void rajzol() ;
    virtual void handle(genv::event ev);
    virtual void szam_allitas(genv::event ev);
    virtual int number();
    virtual void setter(int a);
    virtual int lambda()
    {
        _f();
    };
};


#endif // COUNTER_HPP_INCLUDED
