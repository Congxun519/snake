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
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}
void unit::set_color(int x)
{
	HANDLE winHandle;
	winHandle = GetStdHandle((STD_OUTPUT_HANDLE));//用来修改命令行窗口的颜色
	SetConsoleTextAttribute(winHandle, x);
}
//颜色函数

   // color(0);	    printf("黑色\n");
   // color(1); 	printf("蓝色\n");
   // color(2); 	printf("绿色\n");
   // color(3); 	printf("湖蓝色\n");
   // color(4);  	printf("红色\n");
   // color(5);  	printf("紫色\n");
   // color(6); 	printf("黄色\n");
   // color(7);  	printf("白色\n");
   // color(8);  	printf("灰色\n");
   // color(9); 	printf("淡蓝色\n");
   // color(10); 	printf("淡绿色\n");
   // color(11); 	printf("淡浅绿色\n");
   // color(12);    printf("淡红色\n");
   // color(13);  	printf("淡紫色\n");
   // color(14); 	printf("淡黄色\n");
   // color(15); 	printf("亮白色\n");
   // color(16);    //因为这里大于15，恢复默认的颜色
