#include "ablak.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Ablak::Ablak(int X, int Y) : XX(X), YY(Y)
    {
        gout.open(XX,YY);
    }

void Ablak::event_loop()
{
    gout << move_to(0,0) << color(0,0,0) << box(XX,YY);
    for(Widget* v:w){
        v->rajzol();
    }
    gout << refresh;

    event ev;
    int fokuszban=-1;

    while(gin >> ev && ev.keycode!=key_escape){
        if(ev.type==ev_mouse && ev.button==btn_left){
            for(int i=0;i<w.size();i++){
                if(w[i]->fokuszban(ev.pos_x,ev.pos_y)){
                   fokuszban=i;
                }
            }
        }

        if(fokuszban>=0){
            w[fokuszban]->handle(ev);

        }

        gout << move_to(0,0) << color(0,0,0) << box(400,400);

        for(Widget* v:w){
            v->rajzol();
        }

        //mester.handle();

        gout << refresh;

    }
}




