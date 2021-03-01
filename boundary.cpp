#include "boundary.h"
#include "unit.h"
#include "iostream"
#include <conio.h>

using namespace std;
boundary::boundary() {
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼������ */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;


}
boundary::~boundary() {

}
/*** ���ع�� ***/
void boundary::HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void boundary::begin() {
	system("color 2f");
	char a;
	unit::gotoxy(m_coor.X/2-5, m_coor.Y / 2-5);
	cout << "1.��ʼ��Ϸ";
	unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5+5);
	cout << "2.�˳���Ϸ";
	a = _getch();
	switch (a) {
	case '1':
		system("cls");
		break;

	case '2':
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "��ӭ�´�������";
		Sleep(3000);
		exit(0);
		break;
	default:
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "����������������룡" << endl;
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
		cout << "��";
		unit::gotoxy(i, KUP + 2);
		cout << "��";
		unit::gotoxy(i, m_coor.Y - KUP);
		cout << "��";
	}

	for (int i = KUP + 1; i <= m_coor.Y  - KUP; i++)
	{
		unit::gotoxy(KLEFT, i);
		cout << "��";
		unit::gotoxy(m_coor.X/ 3 * 2, i);
		cout << "��";
	}

}

void boundary::drawGameInfo() {
	//todo
	//unit::set_color(15);
	unit::gotoxy(KLEFT + 2, KUP + 1);

	cout << "��Ϸ���ƣ�̰���� 	��д�ߣ��Ŵ�"<<' ';
	cout << "	��ǰ�÷֣�"<<score<< "	��ǰ�ؿ���"<<level;

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}

void boundary::game_info()
{

	unit::gotoxy(m_coor.X / 3 * 2+3, 2);
	cout << "����Ϸ˵����";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 3);
	cout << "A.ÿ��һ�������Զ���20";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 4);
	cout << "B.�������30";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 6);
	cout << "�����ƶ����� A a";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 7);
	cout << "�����ƶ����� D d";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 8);
	cout << "�����ƶ����� S s";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 9);
	cout << "�����ƶ����� W w";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 10);
	cout << "���Ƽ��٣�+";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 11);
	cout << "��ͣ��Ϸ���ո�";
	unit::gotoxy(m_coor.X / 3 * 2 + 3, 12);
	cout << "��ʼ��Ϸ�������";
}