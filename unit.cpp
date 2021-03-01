#include "unit.h"
#include "iostream"
#include <windows.h>
#include <conio.h>
#include<cstdlib>
#include<time.h> 
using namespace std;
unit::unit(int x , int y, const char pic) {
	m_x = x;
	m_y = y;
	m_pic = pic;
}
unit::~unit() {
	
}
void unit::show() {
	gotoxy(m_x, m_y);
	//set_color(4);
	cout <<m_pic;
	
}

void unit::erase() {
	gotoxy(m_x, m_y);
	cout << " ";
}
void unit::gotoxy(int x,int y) {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x;
	position.Y = y;
	//�����������Ȼ��ʼ��ӡ
	SetConsoleCursorPosition(screen, position);
}
void unit::set_color(int x)
{
	HANDLE winHandle;
	winHandle = GetStdHandle((STD_OUTPUT_HANDLE));//�����޸������д��ڵ���ɫ
	SetConsoleTextAttribute(winHandle, x);
}
//��ɫ����

   // color(0);	    printf("��ɫ\n");
   // color(1); 	printf("��ɫ\n");
   // color(2); 	printf("��ɫ\n");
   // color(3); 	printf("����ɫ\n");
   // color(4);  	printf("��ɫ\n");
   // color(5);  	printf("��ɫ\n");
   // color(6); 	printf("��ɫ\n");
   // color(7);  	printf("��ɫ\n");
   // color(8);  	printf("��ɫ\n");
   // color(9); 	printf("����ɫ\n");
   // color(10); 	printf("����ɫ\n");
   // color(11); 	printf("��ǳ��ɫ\n");
   // color(12);    printf("����ɫ\n");
   // color(13);  	printf("����ɫ\n");
   // color(14); 	printf("����ɫ\n");
   // color(15); 	printf("����ɫ\n");
   // color(16);    //��Ϊ�������15���ָ�Ĭ�ϵ���ɫ
