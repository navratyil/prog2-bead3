//#include "graphics.hpp"
#include "widgets.hpp"
#include "counter.hpp"
#include "menu.hpp"
#include "button.hpp"
#include "static.hpp"
#include "ablak.hpp"
#include "jatekmester.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <unistd.h>

using namespace std;
//using namespace genv;

const int X=800;
const int Y=800;

//void mezo_ertek();


struct MyAblak : public Ablak
{
    FunktorButton * bu1;
    vector<Counter*> mezok;
    Counter* mezo;
    StaticText* stabil;
    Menu* nehezseg;
    vector<int> allas;
    vector<int> megoldas;
    JatekMester mester;
    vector<string> v;
    bool vege=false;

    MyAblak() : Ablak(X,Y)
    {

        bu1 = new FunktorButton(this,X/2-100,Y/2-100,200,70, "Play",[&](){jatek(allas, megoldas);});

        v.push_back("konnyu");
        v.push_back("kozepes");
        v.push_back("nehez");

        nehezseg = new Menu(this,X/2-100,Y/2,200,40, v);
    }

    void mezo_ertek()
    {
        vector<bool> hibak;
        int i=0;
        for(Counter *p : mezok)
        {
            allas[i]=p->number();
            i++;
        }

        mester.setter(allas, megoldas);
        hibak=mester.ellenoriz();

//        for(bool i : hibak)
//        {
//            cout << i << ' ';
//        }

        i=0;
        for(Counter *p : mezok)
        {
            p->colorsetter(hibak[i]==true);
            i++;
        }

        if(vege){
            gamestate=2;
        }

        if(allas==megoldas) vege=true;
    }

    void jatek(vector<int>& allas, vector<int>& megoldas)
    {
        if(nehezseg->the_chosen_one()!=-1){
//        cout << 1;
        int sortores=0;

        for(int i=1;i<=81;i++)
        {
            mezo = new Counter(this, 40+((i-1)%9)*80,40+sortores*80,80,80,0,9,[&](){mezo_ertek();});
            mezok.push_back(mezo);
            if((i%9)==0) sortores++;
            allas.push_back(0);
        }

        ifstream bf;


        switch(nehezseg->the_chosen_one()){
        case 0:
            bf.open("easy.txt");
            break;
        case 1:
            bf.open("medium.txt");
            break;
        case 2:
            bf.open("hard.txt");
            break;
        }


        sortores=0;
        int a=0;

        for(int i=1;i<=81;i++)
        {
            bf >> a;

//            cout << a;
            if(a!=0){
            stabil = new StaticText(this, 40+((i-1)%9)*80,40+sortores*80,80,80,a);
            allas[i-1]=a;
            mezok[i-1]->setter(a);
            }
            if((i%9)==0) sortores++;
//            cout << allas[i-1];
        }

        for(int i=0; i<81; i++)
        {
            bf >> a;
            megoldas.push_back(a);
        }

        bf.close();
        mester.setter(allas, megoldas);
        gamestate=1;
        //for(int i : allas) cout << i << ' ';
    }}


};



int main()
{
    MyAblak a;
    a.event_loop();

return 0;
}
