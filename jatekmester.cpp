#include "jatekmester.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace genv;
using namespace std;

void JatekMester::setter(vector<int> puzzle, vector<int> solution)
{
    _allas=puzzle;
    _megoldas=solution;
}

void JatekMester::ellenoriz()
{
    int helyes=0;
    for(int i=0;i<9;i++)
    {
        if(_allas[i]==_megoldas[i] && _allas[8]!=0) helyes++;
    }
    if(helyes==9) cout << "ugyes";
}

