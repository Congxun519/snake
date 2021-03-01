#pragma once
#include "food.h"
#include "vector"
#include <conio.h>
using namespace std;

typedef enum {
	UP,DOWN,LEFT,RIGHT
}Directions;
class snake
{
public:
	snake(int x = 40, int y = 10, int length = 5, Directions direction = RIGHT, 
		int speed = 200, char m_spic = '*');
	virtual ~snake();
	void changeDirection();
	void move();
	bool eatFood(food *pfood);
	void showSnake();
	void eraseSnake();
	void tongguan();
	void growUp();
	bool isGameOver();
	static void gameJudge();
public:
	int m_length;
	int m_headx;
	int m_heady;
	int m_speed;
	char m_spic;
	Directions m_direction;
	vector<unit> m_vecBody;



};

