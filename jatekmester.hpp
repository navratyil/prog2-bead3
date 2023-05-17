#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class JatekMester{
protected:

std::vector<int> _allas;
std::vector<int> _megoldas;

public:

    void setter(std::vector<int> puzzle, std::vector<int> solution);
    bool ellenoriz();

};


#endif // JATEKMESTER_HPP_INCLUDED
