#include "boundary.h"
#include "unit.h"
#include "iostream"
#include <conio.h>

using namespace std;
boundary::boundary() {
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;


}
boundary::~boundary() {

}
/*** 隐藏光标 ***/
void boundary::HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void boundary::begin() {
	system("color 2f");
	char a;
	unit::gotoxy(m_coor.X/2-5, m_coor.Y / 2-5);
	cout << "1.开始游戏";
	unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5+5);
	cout << "2.退出游戏";
	a = _getch();
	switch (a) {
	case '1':
		system("cls");
		break;

	case '2':
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "欢迎下次再来！";
		Sleep(3000);
		exit(0);
		break;
	default:
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "输入错误，请重新输入！" << endl;
		Sleep(2000);
		system("cls");
		begin();
	}
	system("color 3f");
}
void boundary::drawGameArea() {
	//unit::set_color(15);
	for (int i = KLEFT; i <= m_coor.X / 3 * 2; i++)
	{
		unit::gotoxy(i, KUP);
		cout << "■";
		unit::gotoxy(i, KUP + 2);
		cout << "■";
		unit::gotoxy(i, m_coor.Y - KUP);
		cout << "■";
	}

	for (int i = KUP + 1; i <= m_coor.Y  - KUP; i++)
	{
		unit::gotoxy(KLEFT, i);
		cout << "■";
		unit::gotoxy(m_coor.X/ 3 * 2, i);
		cout << "■";
	}

}

void boundary::drawGameInfo() {
	//todo
	//unit::set_color(15);
	unit::gotoxy(KLEFT + 2, KUP + 1);

	cout << "游戏名称：贪吃蛇 	编写者：杜聪"<<' ';
	cout << "	当前得分："<<score<< "	当前关卡："<<level;

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}

void boundary::game_info()
{

	unit::gotoxy(m_coor.X / 3 * 2+3, 2);
	cout << "★游戏说明：";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 3);
	cout << "A.每过一关移速自动加20";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 4);
	cout << "B.最高移速30";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 6);
	cout << "向左移动：← A a";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 7);
	cout << "向右移动：→ D d";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 8);
	cout << "向下移动：↓ S s";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 9);
	cout << "向上移动：↑ W w";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 10);
	cout << "控制加速：+";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 11);
	cout << "暂停游戏：空格";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 12);
	cout << "开始游戏：任意键";
}