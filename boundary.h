#pragma once
#include <Windows.h>
class boundary
{
	
	public:
		const static int KLEFT = 2;
		const static int KUP = 2;
		const static int KWIDTH = 120;
		const static int KHEIGHT = 30;
		static int level;
		static int score;
		COORD m_coor;
	public:
		boundary();
		virtual ~boundary();
		void begin();
		void drawGameArea();
		void game_info();
		static void drawGameInfo();
		static void HideCursor();

};

