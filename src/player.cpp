#include "entities.h"

pChar::player(std::string& _name)
{
    name = _name;
}

void pChar::get_stats()
{
    std::cout << name;
}