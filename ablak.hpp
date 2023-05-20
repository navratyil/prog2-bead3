#ifndef ABLAK_HPP_INCLUDED
#define ABLAK_HPP_INCLUDED

#include <vector>
#include "widgets.hpp"
#include "jatekmester.hpp"
#include "graphics.hpp"



class Ablak
{
protected:
    std::vector<Widget*> w;

    int XX=800;
    int YY=1200;
public:
    int gamestate=0;
    JatekMester mester;
    Ablak(int XX, int YY);
    virtual ~Ablak(){}
    void hozzaadas(Widget * v)
    {
        w.push_back(v);
    }
    void event_loop();

};


#endif // ABLAK_HPP_INCLUDED
