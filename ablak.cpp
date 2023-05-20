#include "ablak.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>
#include <unistd.h>

using namespace genv;
using namespace std;

Ablak::Ablak(int X, int Y) : XX(X), YY(Y)
    {
        gout.open(XX,YY);
    }

void Ablak::event_loop()
{
    gout << move_to(0,0) << color(102, 135, 189) << box(800,800);

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

//fomenu
        if(gamestate==0){
        if(fokuszban>=0){
            if(w[fokuszban]->type=="menu" || w[fokuszban]->type=="gomb") w[fokuszban]->handle(ev);
        }
        gout << move_to(0,0) << color(102, 135, 189) << box(800,800);

        for(Widget* v:w){
             if(v->type=="menu" || v->type=="gomb") v->rajzol();
        }
        }

//jatek
        if(gamestate==1){
        if(fokuszban>=0){
            if(w[fokuszban]->type=="szamlalo" || w[fokuszban]->type=="static") w[fokuszban]->handle(ev);
        }
        gout << move_to(0,0) << color(102, 135, 189) << box(800,800);
        for(Widget* v:w){
             if(v->type=="szamlalo" || v->type=="static") v->rajzol();
        }

        }

        if(gamestate==2){
            gout << move_to(0,0) << color(102, 135, 189) << box(800,800);
            sleep(1);
            gout << move_to(400,400) << color(0,0,0) << text("nice");
        }

        gout << refresh;

        cout << gamestate;

    }
}




