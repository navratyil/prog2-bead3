#include "jatekmester.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>

using namespace genv;
using namespace std;

void JatekMester::setter(vector<int> a)
{
    _allas=a;
}

void JatekMester::ellenoriz()
{
     if(_allas[0]==4 && _allas[1]==2) cout << "jo";
}

