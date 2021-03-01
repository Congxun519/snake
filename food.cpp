#include "food.h"
#include "time.h"
#include "boundary.h"
boundary p;
food::food(int x , int y , const char pic) :unit(x,y,pic){
	
}

food::~food()
{

}

void food::createPos() {

	srand((unsigned)time(NULL));
	m_x = boundary::KLEFT + 2 + rand() % (p.m_coor.X/ 3 * 2-p.KLEFT- boundary::KLEFT-1);
	m_y = boundary::KUP * 2 + 1 + rand() % (p.m_coor.Y - p.KUP * 3 - boundary::KUP -1);
	/*m_x= boundary::KLEFT +1 + rand() % (boundary::KWIDTH-8);
	m_y = boundary::KUP*2 +1 + rand() % (boundary::KHEIGHT-10);*/
	/*m_x = 114;
	m_y = 24;*/
	show();
}
void food::show() {
	gotoxy(m_x, m_y);
	//set_color(6);
	cout << m_pic;
}