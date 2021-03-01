#include "iostream"
#include "unit.h"
#include<cstdlib>
#include<time.h> 
#include "food.h"
#include "boundary.h"
#include "snake.h"
#include "control.h"

using namespace std;

int main() {
	
	////system("mode con cols=120 lines=42");
	//boundary::HideCursor();
	//boundary myBoundary;
	//snake mySnake;
	//food MyFood;
	//food *p = &MyFood;
	////myBoundary.begin();
	//myBoundary.drawGameArea();
	//myBoundary.drawGameInfo();
	//MyFood.createPos();
	///*vector<int> a;
	//for (int i = 0; i < 10; i++) {
	//	a.push_back(i);
	//}
	//for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
	//	cout << (*it) << endl;
	//}*/
	////mySnake.eraseSnake();
	//mySnake.showSnake();
	//while (_kbhit){

	//	
	//	mySnake.move();
	//	if (mySnake.eatFood(p)) {
	//		mySnake.growUp();
	//		p->createPos();
	//	}
	//}

	///*while (1)
	//{
	//	mySnake.move();
	//}*/
	//
	
	control *myControl=new control();
	myControl->init();
	system("pause");

	return 0;

}