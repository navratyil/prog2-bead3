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

    for(int rsor=0; rsor<3; rsor++){
        for(int roszlop=0; roszlop<3; roszlop++){
            std::vector<bool> vizsgalt(10, false);

            for(int sor=0; sor<3;sor++){
                for(int oszlop=0;oszlop<3; oszlop++){
                    int globalSor=rsor*3+sor;
                    int globalOszlop=roszlop*3+oszlop;
                    int szam=_allas[globalSor*9+globalOszlop];

                    if(szam!=0){
                        if(vizsgalt[szam]){
                            hibak[globalSor*9+globalOszlop]=true;
                        vizsgalt[szam] = true;
                        }
                    }
                }
            }
        }
    }

    for(int rsor=2; rsor>=0; rsor--){
        for(int roszlop=2; roszlop>=0; roszlop--){
            std::vector<bool> vizsgalt(10, false);

            for(int sor=2; sor>=0;sor--){
                for(int oszlop=2;oszlop>=0; oszlop--){
                    int globalSor=rsor*3+sor;
                    int globalOszlop=roszlop*3+oszlop;
                    int szam=_allas[globalSor*9+globalOszlop];

                    if(szam!=0){
                        if(vizsgalt[szam]){
                            hibak[globalSor*9+globalOszlop]=true;
                        vizsgalt[szam] = true;
                        }
                    }
                }
            }
        }
    }


//    for(bool i : hibak)
//    {
//        cout << i << ' ';
//    }

    return hibak;
}

