#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;
class unit
{
public:
	int m_x;
	int m_y;
	char m_pic;
	
public:
	void show();
	void erase();
	static void gotoxy(int x, int y);
	unit(int x = 0, int y = 0,const char m_pic = '*');
	virtual ~unit();
	static void set_color(int x);
};