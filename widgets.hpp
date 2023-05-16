#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

struct Ablak;

class Widget {
protected:
    Ablak *_a;
    int _x, _y, _sx, _sy;
public:
    Widget(Ablak *a, int x, int y, int sx, int sy);
    virtual bool fokuszban(int ex, int ey);
    virtual void rajzol()=0;
    virtual void handle(genv::event ev)=0;
};
                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
