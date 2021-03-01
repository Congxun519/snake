#pragma once
#include "unit.h"
#include "vector"
class food :
    public unit
{
public:
    food(int x = 0, int y = 0, char pic = '#');
    virtual ~food();
    void createPos();
    void show();
};

