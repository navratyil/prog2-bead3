#include "jatekmester.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>

using namespace genv;
using namespace std;

void JatekMester::setter(vector<int> puzzle, vector<int> solution)
{
    _allas=puzzle;
    _megoldas=solution;
}

vector<bool> JatekMester::ellenoriz()
{
    vector<bool> hibak(81, true);

    for(int sor=0;sor<9;sor++){
        vector<bool> vizsgalt(10,false);

        for(int oszlop=0;oszlop<9;oszlop++){
            int szam=_allas[sor*9+oszlop];
            if(szam!=0){
                if(vizsgalt[szam]){
                  hibak[sor*9+oszlop]=false;
                  //cout << "found ";
                }
            }
            vizsgalt[szam]=true;
        }
    }

    for(int sor=8;sor>=0;sor--){
        vector<bool> vizsgalt(10,false);

        for(int oszlop=8;oszlop>=0;oszlop--){
            int szam=_allas[sor*9+oszlop];
            if(szam!=0){
                if(vizsgalt[szam]){
                  hibak[sor*9+oszlop]=false;
                  //cout << "found ";
                }
            }
            vizsgalt[szam]=true;
        }
    }


    for(int oszlop=0;oszlop<9;oszlop++){
        vector<bool> vizsgalt(10,false);

        for(int sor=0;sor<9;sor++){
            int szam=_allas[sor*9+oszlop];
            if(szam!=0){
                if(vizsgalt[szam]){
                  hibak[sor*9+oszlop]=false;
                }
            }
            vizsgalt[szam]=true;
        }
    }

    for(int oszlop=8;oszlop>=0;oszlop--){
        vector<bool> vizsgalt(10,false);

        for(int sor=8;sor>=0;sor--){
            int szam=_allas[sor*9+oszlop];
            if(szam!=0){
                if(vizsgalt[szam]){
                  hibak[sor*9+oszlop]=false;
                }
            }
            vizsgalt[szam]=true;
        }
    }


//    for(bool i : hibak)
//    {
//        cout << i << ' ';
//    }

    return hibak;
}

