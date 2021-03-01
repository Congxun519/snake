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
	SetConsoleTitleA("̰����");
	COORD dSiz = { 80, 25 };
	SetConsoleScreenBufferSize(hOut, dSiz);//���ô��ڻ�������С
	CONSOLE_CURSOR_INFO _guan_biao = { 1, FALSE };//���ù���С�����ع��
	SetConsoleCursorInfo(hOut, &_guan_biao);
	//system("color 6f");//���û�����ɫ
	PlaySound(TEXT("D:\\myProject\\zcerulmzzfp.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//PlaySound(TEXT("D:\\myProject\\zcerulmzzfp.wav"), NULL, SND_FILENAME | SND_SYNC );
}
//���λ��
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
				int m = MessageBox(NULL, L"��Ϸ�������Ƿ����¿�ʼ��", L" ", MB_YESNO | MB_ICONINFORMATION);
				if (m == IDYES)//ѡ���ˡ��ǡ�
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
//			int m = MessageBox(NULL, L"��Ϸ�������Ƿ����¿�ʼ��", L" ", MB_YESNO | MB_ICONINFORMATION);
//			if (m == IDYES)//ѡ���ˡ��ǡ�
//			{
//				system("cls");
//				init();
//				
//			}
//			else
//			{
//				MessageBox(NULL, L"��Ϸ����", L" ", MB_OK | MB_ICONINFORMATION);
//				food::gotoxy(38, 15);
//				cout << "��Ϸ����" << endl;
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