#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

class entity
{
public:
    //virtual void set_stats() = 0;
    //virtual int attack() = 0;
protected:
    float health;
    float attackPower;
    int level;
};

namespace player_entity
{
    class player
    {
    public:
        player(std::string& _name);
        void get_stats();
        int attack();
    private:
        std::string name;
    };
}

namespace monster_entity
{
    class goblin : public entity
    {
    public:
        goblin();
    private:
    };

    class orc : public entity
    {
    public:
        orc();
    private:
    };
}


typedef player_entity::player pChar;