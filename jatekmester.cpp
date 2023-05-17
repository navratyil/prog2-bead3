#include "jatekmester.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace genv;
using namespace std;

void JatekMester::setter(vector<int> puzzle, vector<int> solution)
{
    _allas=puzzle;
    _megoldas=solution;
}

bool JatekMester::ellenoriz()
{
    bool helyes=true;
    for(int i=0;i<81;i++)
    {
        if(_allas[i]!=0){
            int egyezes=0;

            for(int j=0;j<9;j++){
                if(_allas[j]==3) egyezes++;
            }

            if(egyezes!=0){
                helyes=false;
            }

        }

    }
    //if(helyes==9) cout << "ugyes";

    return helyes;
}

