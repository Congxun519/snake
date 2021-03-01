#include "control.h"

control::control() {

	this->mySnake = new snake();
	this->myFood = new food();
	this->myBoundary = new boundary();

}
control::~control() {
	delete myBoundary;
	myBoundary = NULL;
	delete myFood;
	myFood = NULL;
	delete mySnake;
	mySnake = NULL;

}
void control::Init_Console()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitleA("贪吃蛇");
	COORD dSiz = { 80, 25 };
	SetConsoleScreenBufferSize(hOut, dSiz);//设置窗口缓冲区大小
	CONSOLE_CURSOR_INFO _guan_biao = { 1, FALSE };//设置光标大小，隐藏光标
	SetConsoleCursorInfo(hOut, &_guan_biao);
	//system("color 6f");//设置画布颜色
	PlaySound(TEXT("D:\\myProject\\zcerulmzzfp.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//PlaySound(TEXT("D:\\myProject\\zcerulmzzfp.wav"), NULL, SND_FILENAME | SND_SYNC );
}
//光标位置
void control::makeFoodJudge() {

	for (vector<unit>::iterator it = mySnake->m_vecBody.begin() ; it != mySnake->m_vecBody.end(); ++it) {
		if (myFood->m_x == (*it).m_x && myFood->m_y == (*it).m_y) {
			myFood->createPos();
			break;
		}
			
	}
}
void control::init() {
	//myBoundary->HideCursor();
	
	Init_Console();
	myBoundary->begin();
	myBoundary->drawGameArea();
	myBoundary->drawGameInfo();
	myBoundary->game_info();
	myFood->createPos();
	mySnake->showSnake();
	makeFoodJudge();
	int key = _getch();
	if (key) {
		while (1) {

			mySnake->eraseSnake();
			mySnake->move();
			if (mySnake->isGameOver())
			{
				int m = MessageBox(NULL, L"游戏结束，是否重新开始？", L" ", MB_YESNO | MB_ICONINFORMATION);
				if (m == IDYES)//选择了“是”
				{
					system("cls");
					control* temp = new control();
					temp->init();

				}
				else
				{
					snake::gameJudge();
					
				}

			}
			if (mySnake->eatFood(myFood)) {
				//PlaySound(TEXT("D:\\myProject\\eatfood.wav"), NULL, SND_FILENAME | SND_ASYNC );
				mySnake->growUp();
				myFood->createPos();

			}
		}




	}
}



//void control::init() {
//	boundary::HideCursor();
//	boundary myBoundary;
//	snake mySnake;
//	food MyFood;
//	food* p = &MyFood;
//	//myBoundary.begin();
//	myBoundary.drawGameArea();
//	myBoundary.drawGameInfo();
//	MyFood.createPos();
//	/*vector<int> a;
//	for (int i = 0; i < 10; i++) {
//		a.push_back(i);
//	}
//	for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//		cout << (*it) << endl;
//	}*/
//	//mySnake.eraseSnake();
//	//mySnake.showSnake();
//	while (_kbhit) {
//
//
//		mySnake.move();
//		if (mySnake.isGameOver())
//		{
//			int m = MessageBox(NULL, L"游戏结束，是否重新开始？", L" ", MB_YESNO | MB_ICONINFORMATION);
//			if (m == IDYES)//选择了“是”
//			{
//				system("cls");
//				init();
//				
//			}
//			else
//			{
//				MessageBox(NULL, L"游戏结束", L" ", MB_OK | MB_ICONINFORMATION);
//				food::gotoxy(38, 15);
//				cout << "游戏结束" << endl;
//				Sleep(5000);
//				exit(0);
//			}
//			
//		}
//		if (mySnake.eatFood(p)) {
//			mySnake.growUp();
//			p->createPos();
//		}
//	}
//
//}