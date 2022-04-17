
#include <conio.h>   
#include <time.h>
#include <Windows.h>

#define KEY_ESC 27
#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)
#define KEY_ENTER '\r'

int GetKey(void);
void GotoXY(int x, int y);
void SetCursorVisible(BOOL tf);
double GetElapsedTime(clock_t start_time);
void PrintFrame(void);

struct Point
{
	int x;
	int y;
};

int main(void)
{
	double z = 0.2;
	int key;
	struct Point pos = { 39, 11 };         // �߰� ����
	clock_t start_time = clock();

	SetCursorVisible(FALSE);        // Ŀ�� ����
	PrintFrame();                   // �簢�� ������ �׸���

	GotoXY(pos.x, pos.y);                   // ���� ��ġ�� �̵� �� ���
	putchar('*');
	if (_kbhit())
	{
		key = GetKey();
	}



	while (1)
	{

		int key = GetKey();
		if (key == KEY_ESC)
			break;

		if (key == KEY_RIGHT)
		{
			while (1)
			{
				if (GetElapsedTime(start_time) > z)
				{
					GotoXY(pos.x, pos.y);
					putchar(' ');
					pos.x++;
					if (pos.x > 77)
						pos.x = 2;
					GotoXY(pos.x, pos.y);
					putchar('*');
					start_time = clock();
				}
				if (_kbhit()){
					key = GetKey();
					if (key == KEY_ENTER)
					{
						while (1){
							GotoXY(pos.x, pos.y);
							printf("*");
							if (_kbhit())
							{
								key = GetKey();
								if (key == KEY_ENTER)
									break;
							}
						}
						continue;
					}
					if (key == 43){
						z -= 0.03;
						continue;
					}
					if (key == 45)
					{
						z += 0.03;
						continue;
					}
					else break;
				}
			}
			continue;
		}


		if (key == KEY_LEFT)
		{
			while (1)
			{
				if (GetElapsedTime(start_time) > z)
				{
					GotoXY(pos.x, pos.y);
					putchar(' ');
					pos.x--;
					if (pos.x <2)
						pos.x = 77;
					GotoXY(pos.x, pos.y);
					putchar('*');
					start_time = clock();
				}
				if (_kbhit()){
					key = GetKey();
					if (key == KEY_ENTER)
					{
						while (1){
							GotoXY(pos.x, pos.y);
							printf("*");
							if (_kbhit())
							{
								key = GetKey();
								if (key == KEY_ENTER)
									break;
							}
						}
						continue;
					}
					if (key == 43){
						z -= 0.03;
						continue;
					}
					if (key == 45)
					{
						z += 0.03;
						continue;
					}
					else break;
				}
			}
			continue;
		}


		if (key == KEY_UP)
		{
			while (1){
				if (GetElapsedTime(start_time) > z)
				{
					GotoXY(pos.x, pos.y);
					putchar(' ');
					pos.y--;
					if (pos.y < 1)
						pos.y = 21;
					GotoXY(pos.x, pos.y);
					putchar('*');
					start_time = clock();
				}
				if (_kbhit()){
					key = GetKey();
					if (key == KEY_ENTER)
					{
						while (1){
							GotoXY(pos.x, pos.y);
							printf("*");
							if (_kbhit())
							{
								key = GetKey();
								if (key == KEY_ENTER)
									break;
							}
						}
						continue;
					}
					if (key == 43){
						z -= 0.03;
						continue;
					}
					if (key == 45)
					{
						z += 0.03;
						continue;
					}
					else break;
				}
			}
			continue;
		}


		if (key == KEY_DOWN)
		{
			while (1){
				if (GetElapsedTime(start_time) > z)
				{
					GotoXY(pos.x, pos.y);
					putchar(' ');
					pos.y++;
					if (pos.y > 21)
						pos.y = 1;
					GotoXY(pos.x, pos.y);
					putchar('*');
					start_time = clock();
				}
				if (_kbhit()){
					key = GetKey();
					if (key == KEY_ENTER)
					{
						while (1){
							GotoXY(pos.x, pos.y);
							printf("*");
							if (_kbhit())
							{
								key = GetKey();
								if (key == KEY_ENTER)
									break;
							}
						}
						continue;
					}
					if (key == 43){
						z -= 0.03;
						continue;
					}
					if (key == 45)
					{
						z += 0.03;
						continue;
					}
					else break;
				}
			}
			continue;
		}



		/*if (GetElapsedTime(start_time) > z)
		{
		GotoXY(pos.x, pos.y);
		putchar(' ');
		pos.x++;
		if (pos.x > 77)
		pos.x = 2;
		GotoXY(pos.x, pos.y);
		putchar('*');
		start_time = clock();
		}*/
	}
}

void PrintFrame(void)
{
	// ���� '*' ���ڰ� ������ �� �ִ� ������ ��ǥ�� (2, 1)���� (77, 21)���� ����
	printf("��������������������������������������������������������������������������������\n");
	for (int i = 0; i < 21; i++)
		printf("��                                                                            ��\n");
	printf("��������������������������������������������������������������������������������");
}

int GetKey(void)
{
	int ch = _getch();

	if (ch == 0 || ch == 224)
		// ����Ű�� ��� 0 �Ǵ� 224�� ���� ���� �Էµ�
		ch = 256 + _getch();
	// �� ������ �ش� ����Ű�� ���� 72(Up), 
	// 80(Down), 75(Left), 77(Right) ���� �Էµ�
	return ch;
}

void GotoXY(int x, int y)
{   // COORD ����ü ������ ���� �̵��� ��ġ ����
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

double GetElapsedTime(clock_t start_time)
{
	clock_t current_time = clock();
	return ((double)(current_time - start_time) / CLOCKS_PER_SEC);
}

void SetCursorVisible(BOOL tf)	// ȭ�� Ŀ���� On/Off
{
	CONSOLE_CURSOR_INFO ci = { 10, tf };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}
