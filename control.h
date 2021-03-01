#pragma once
#include "iostream"
#include "unit.h"
#include<cstdlib>
#include<time.h> 
#include "food.h"
#include "boundary.h"
#include "snake.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
class control
{
public:
	
	control();
	virtual ~control();
	void Init_Console();
	void makeFoodJudge();
	void init();
	
public:
	snake* mySnake;
	food* myFood;
	boundary* myBoundary;

};

