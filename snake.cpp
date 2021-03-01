#include "snake.h"
#include "boundary.h"
int boundary::score = 0;
int boundary::level = 1;
boundary temp;
snake::snake(int x , int y , int length, Directions direction , int speed , char pic) {
	m_headx = x;
	m_heady = y;
	m_length = length;
	m_direction = direction;
	m_speed = speed;
	m_spic = pic;
	for (int i = 0; i < m_length; i++) {
		unit myUnit(0, 0, m_spic);
		m_vecBody.push_back(myUnit);
		switch (m_direction)
		{
		case UP:
			m_vecBody[i].m_x = m_headx;
			m_vecBody[i].m_y =m_heady-i;
			break;
		case DOWN:
			m_vecBody[i].m_x = m_headx;
			m_vecBody[i].m_y = m_heady + i;
			break;
		case RIGHT:
			m_vecBody[i].m_x = m_headx-i;
			m_vecBody[i].m_y = m_heady;
			break;
		case LEFT:
			m_vecBody[i].m_x = m_headx+i;
			m_vecBody[i].m_y = m_heady;
			break;
		default:
			break;
		}

	}
}
snake::~snake() {

}
void snake::changeDirection() {
	char ch='q';
	if(_kbhit())
		ch = _getch();
		switch (ch)
		{
		case 72:
		case 'w':
		case 'W':
			if (m_direction != DOWN)
				m_direction = UP;
			break;
		case 75:
		case 'a':
		case 'A':
			if (m_direction != RIGHT)
				m_direction = LEFT;
			break;
		case 80:
		case 's':
		case 'S':
			if (m_direction != UP)
				m_direction = DOWN;
			break;
		case 77:
		case 'd':
		case 'D':
			if (m_direction != LEFT)
				m_direction = RIGHT;
			break;
		case ' ':
		{
			int m = MessageBox(NULL, L"游戏暂停，是否继续？", L" ", MB_YESNO | MB_ICONINFORMATION);
			if (m == IDNO)//选择了“否”
				gameJudge();
			break;
		}
		case '+':
			if (m_speed >= 30)
				m_speed -= 30;
			break;
		case 27:
			gameJudge();
			break;
		}

}

void snake::move() {
		for (int i = m_length - 1; i > 0; i--)
		{
			m_vecBody[i].m_x = m_vecBody[i - 1].m_x;
			m_vecBody[i].m_y = m_vecBody[i - 1].m_y;
		}
		switch (m_direction)
		{
		case UP:
			m_vecBody[0].m_y--;
			break;
		case DOWN:
			m_vecBody[0].m_y++;
			break;
		case RIGHT:
			m_vecBody[0].m_x++;
			break;
		case LEFT:
			m_vecBody[0].m_x--;
			break;
		default:
			break;
		}
		showSnake();
		
		
		Sleep(m_speed);
		
		eraseSnake();
		
		
		changeDirection();
}


bool snake::eatFood(food *pfood) {
		if (m_vecBody.front().m_x == pfood->m_x && m_vecBody.front().m_y == pfood->m_y) {

			pfood->erase();
			
			return true;
		}
		return false;
	
}


void snake::showSnake() {
	for (int i = 0; i < m_length; i++) {
		m_vecBody[i].show();
	}
		
		
}

void snake::eraseSnake() {
	for (int i = 0; i < m_length; i++) {
		m_vecBody[i].erase();
	}
}
void snake::tongguan() {
	if (boundary::level == 10)
	{
		MessageBox(NULL, L"恭喜你，完成通关！！！", L" ", MB_OK | MB_ICONINFORMATION);
		system("cls");
		food::gotoxy((temp.m_coor.X) / 2 - 5, temp.m_coor.Y / 2);
		cout << "游戏结束 !!!" << endl;
		Sleep(5000);
		exit(0);
	}
}
void snake::growUp() {
	unit myUnit(0, 0, m_spic);
	m_vecBody.push_back(myUnit);
	m_length++;
	boundary::score += 10;
	if(m_speed>=30)
		m_speed += 5;
	if (boundary::score % 30 == 0) {
		tongguan();
		boundary::level++;
		m_speed += 20;
	}
		
	/*if(m_speed>30)

	if (m_length > 5)
	{
		m_speed = 150;
		
	}
	else if (m_length > 10)
	{
		m_speed = 100;
		boundary::level++;
	}
	else if(m_length > 15)
	{
		m_speed = 80;
		boundary::level++;
	}
	else if (m_length > 20)
	{
		m_speed = 60;
		boundary::level++;
	}
	else if (m_length > 25)
	{
		m_speed = 40;
		boundary::level++;
	}
	else if (m_length > 30)
	{
		m_speed = 30;
		boundary::level++;
	}
	else if (m_length > 35)
	{
		m_speed = 25;
		boundary::level++;
	}
	else if (m_length > 50)
	{
		m_speed = 20;
		boundary::level++;
	}*/
	boundary::drawGameInfo();
}


bool snake::isGameOver() {

	for (vector<unit>::iterator it = m_vecBody.begin()+1; it != m_vecBody.end(); ++it) {
		if (m_vecBody.front().m_x == (*it).m_x && m_vecBody.front().m_y == (*it).m_y)

			return true;
	}
	
	if (m_vecBody.front().m_x == temp.KLEFT || m_vecBody.front().m_x ==temp.m_coor.X / 3 * 2 ||
		m_vecBody.front().m_y == temp.KUP * 2 || m_vecBody.front().m_y == temp.m_coor.Y- temp.KUP) {
		return true;
	}
	return false;
}

void snake::gameJudge() {
	MessageBox(NULL, L"游戏结束", L" ", MB_OK | MB_ICONINFORMATION);
	system("cls");
	food::gotoxy((temp.m_coor.X)/ 2 -5, temp.m_coor.Y / 2 );
	cout << "Game Over !!!" << endl;
	Sleep(5000);
	exit(0);
}