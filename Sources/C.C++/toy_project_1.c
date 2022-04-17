#include <stdio.h>
#include <stdlib.h>
typedef struct chunk
{
	int start;
	int size;
	struct chunk *link;
}Chunk;
typedef struct addr
{
	int start;
	int size;
}Addr;
Chunk *available;
Addr myalloc(int request_size);
Addr myalloc_best(int request_size);
void myfree(Addr start_address);
void myrenew(Chunk* start_address);
void init(Chunk *space);
void print_(Chunk * a);

#define Max_bytes 100
void scene_1(void)
{
	Addr a, b, c, d;
	printf("처음 상태 \n");
	print_(available);
	// 메뉴 설계 gui 출력함수 설계
	printf("a를 30할당\n");
	a = myalloc(30);
	printf("b를 10할당\n");
	b = myalloc(10);
	printf("c를 10할당\n");
	c = myalloc(10);
	printf("a를 해제\n");
	myfree(a);
	printf("a를 40할당\n");
	a = myalloc(40);
	printf("c를 해제\n");
	myfree(c);
	printf("c를 10할당\n");
	c = myalloc(10);
	printf("d를 30할당\n");
	d = myalloc(30);
	printf("b를 해제\n");
	myfree(b);	
	//하나하나 마다 할당못하는지 확인하려면 매우 비효율적임
}
void best_scene_1(void)
{
	Addr a, b, c, d;
	printf("처음 상태 \n");
	print_(available);
	// 메뉴 설계 gui 출력함수 설계
	printf("a를 30할당\n");
	a = myalloc_best(30);
	printf("b를 10할당\n");
	b = myalloc_best(10);
	printf("c를 10할당\n");
	c = myalloc_best(10);
	printf("a를 해제\n");
	myfree(a);
	printf("a를 40할당\n");
	a = myalloc_best(40);
	printf("c를 해제\n");
	myfree(c);
	printf("c를 10할당\n");
	c = myalloc_best(10);
	printf("d를 30할당\n");
	d = myalloc_best(30);
	printf("b를 해제\n");
	myfree(b);
}
int main(void)
{
	Addr a = { 0,0 }, b = { 0,0 }, c = { 0,0 }, d = { 0,0 };
	int a_ = 1, b_ = 2, c_ = 3, d_ = 4;
	int menu, menu_1 = 0,me, size, name;
	Chunk* free_space = (Chunk*)malloc(sizeof(Chunk));
	init(free_space);
	printf("----------------------------------------------------------------------------------------------\n");
	printf("1.FIRST-FIT\n");
	printf("2.BEST-FIT\n");
	printf("----------------------------------------------------------------------------------------------\n");
	scanf("%d", &me);
	printf("----------------------------------------------------------------------------------------------\n");
	printf("1.시나리오\n");
	printf("2.사용자입력\n");
	printf("----------------------------------------------------------------------------------------------\n");
	scanf("%d", &menu);
	if (me==1 &&menu == 1)
	{
		printf("미리 저장된 시나리오를 실행합니다.\n");
		scene_1();
	}
	else if (me == 2 && menu == 1)
	{
		printf("미리 저장된 시나리오를 실행합니다.\n");
		best_scene_1();
	}
	else if (me ==1 && menu == 2)
	{
		while (menu_1 != -1)
		{
			printf("사용자 입력을 누르셨습니다. -1을 입력하시면 종료합니다.\n");
			printf(" 1 . 할당 \n2. 해제 \n");
			scanf("%d", &menu_1);




			if (menu_1 == 1)
			{

				printf("할당할 번호(1~4)와 메모리 크기를 누르십시오 (4개까지 할당하실 수 있습니다.)\n");
				scanf("%d %d", &name, &size);
				switch (name)
				{
				case 1:
					printf("1를%d만큼 할당합니다.\n", size);
					a = myalloc(size);
					if (a.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n"); 
					break;
				case 2:
					printf("2를%d만큼 할당합니다.\n", size);
					b = myalloc(size);
					if (b.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n"); 
					break;
				case 3:
					printf("3를%d만큼 할당합니다.\n", size);
					c = myalloc(size); 
					if (c.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n"); 
					break;
				case 4:
					printf("4를%d만큼 할당합니다.\n", size);
					d = myalloc(size);
					if (d.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n"); 
					break;
				}
				continue;
			}

			else if (menu_1 == 2)
			{

				printf("해제할 번호(1~4)\n");
				scanf("%d ", &name);
				switch (name)
				{
					//두번 프리하려 시도하는것도 가능하면 막을 수 있어야함
				case 1:
					/*if (a.size == 0)
						printf("안됩니다. 아무 번호나 다시누르십시오\n"); continue;*/
					printf("1을 해제합니다.\n");
					myfree(a);
					break;
				case 2:
					printf("2을 해제합니다.\n");
					myfree(b);
					break;
				case 3:
					printf("3을 해제합니다.\n");
					myfree(c);
					break;
				case 4:
					printf("4을 해제합니다.\n");
					myfree(d);
					break;
				}
				continue;
			}
		}


	}
	else if (me == 2 && menu == 2)
	{
		while (menu_1 != -1)
		{
			printf("사용자 입력을 누르셨습니다. -1을 입력하시면 종료합니다. 똑같은 메모리 두번 할당은 하시면 안됩니다.\n");
			printf(" 1 . 할당 \n2. 해제 \n");
			scanf("%d", &menu_1);


			if (menu_1 == 1)
			{

				printf("할당할 번호(1~4)와 메모리 크기를 누르십시오 (4개까지 할당하실 수 있습니다.)\n");
				scanf("%d %d", &name, &size);
				switch (name)
				{
				case 1:
					printf("1를%d만큼 할당합니다.\n", size);
					a = myalloc_best(size);
					if (a.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n");
					break;
				case 2:
					printf("2를%d만큼 할당합니다.\n", size);
					b = myalloc_best(size);
					if (b.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n");
					break;
				case 3:
					printf("3를%d만큼 할당합니다.\n", size);
					c = myalloc_best(size);
					if (c.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n");
					break;
				case 4:
					printf("4를%d만큼 할당합니다.\n", size);
					d = myalloc_best(size);
					if (d.start == -1)
						printf("가용공간을 넘는 공간을 할당하려 하셨습니다.\n");
					break;
				}
				continue;
			}

			else if (menu_1 == 2)
			{

				printf("해제할 번호(1~4)\n");
				scanf("%d ", &name);
				switch (name)
				{
				case 1:printf("1을 해제합니다.\n");
					myfree(a);
					break;
				case 2:printf("2을 해제합니다.\n");
					myfree(b);
					break;
				case 3:printf("3을 해제합니다.\n");
					myfree(c);
					break;
				case 4:printf("4을 해제합니다.\n");
					myfree(d);
					break;
				}
				continue;
			}
		}


	}
}

void print_(Chunk *a) //시험용 함수
{
	printf("\n");
	Chunk * temp = a;
	printf("available ->");
	while (temp != NULL)
	{
		printf("%d %d->", temp->start, temp->size);
		temp = temp->link;
	}
	printf("NULL");
	printf("\n--------------------------------------------------------------------------------------\n");
}
void init(Chunk *space)
{
	available = space;
	available->start = 0;
	available->size = Max_bytes;
	available->link = NULL;
}
//베스트핏 마이얼록 함수도 설계
Addr myalloc_best(int request_size)
{
	Addr result;
	int count = 0;
	int smallest = 0;
	result.start = -1; //가용공간을 못찾으면 당연히 못넣음
	if (available == NULL)
		return result;
	Chunk *temp = available, *pre = temp, *haldang = available, *pre_ = temp;
	while (temp != NULL)
	{
		if ((temp->size) >= request_size)
		{
			if (count ==0)
			{
				count++;
				pre_ = pre;
				haldang = temp;
				smallest = temp->size;
			}
			else if (smallest > temp->size)
			{
				smallest = temp->size;
				pre_ = pre;
				haldang = temp;
			}
		}
			pre = temp;
			temp = temp->link;
	}
	if (count != 0)
	{
		result.start = haldang->start;
		result.size = request_size;
		haldang->start += request_size;
		haldang->size -= request_size;
		if (haldang->size == 0)
		{
			if (pre_ != haldang)
			{
				pre_->link = haldang->link;
				haldang->link = NULL;
				free(haldang);
			}
			else
			{
				available = NULL;
				free(haldang);
			}

		}
	}
	//처음에 가용공간 찾는 알고리즘 필요
	print_(available);
	myrenew(available);
	return result;
}
Addr myalloc(int request_size)
{
	Addr result;
	int flag = 1;
	result.start = -1; //가용공간을 못찾으면 당연히 못넣음
	if (available == NULL)
		return result;
	Chunk *temp = available, *pre = temp;
	while (temp != NULL  && flag)
	{
		if ((temp->size ) >= request_size)
		{
			flag = 0;
			result.start = temp->start;
			result.size = request_size;
			temp->start += request_size;
			temp->size -= request_size;
			if (temp->size == 0)
			{
				if (pre != temp)
				{
					pre->link = temp->link;
					temp->link = NULL;
					free(temp);
				}
				else
				{

					available = NULL;
					free(temp);
				}

			}
		}
		else
		{
			pre = temp;
			temp = temp->link;
		}
	}
	//처음에 가용공간 찾는 알고리즘 필요
	print_(available);
	myrenew(available);
	return result;
}
void myfree(Addr start_address)
{
	if (start_address.size == 0)
		return;
	Chunk * temp = available; 
	int flag = 1;
	Chunk * good = (Chunk*)malloc(sizeof(Chunk));
	good->start = start_address.start;
	good->size = start_address.size;
	if (available == NULL)
	{
		available = good;
		good->link = NULL;
	}
	while ( temp != NULL && flag)
	{
		if (temp == available && good->start + good->size <= temp->start)
		{
			flag = 0;
			good->link = temp;
			available = good;
		}
		else if (temp->start + temp->size <= good->start)
		{
			flag = 0;
			Chunk * temp_ = temp->link;
			temp -> link = good;
			good->link = temp_;
		}
		else
		{
			temp = temp->link;
		}
	}
	myrenew(available);
	print_(available);
	//빈공간을 리스트에 끼워넣음
}
void myrenew(Chunk * s)
{
	Chunk * temp = available;
	int flag = 1;
	while (temp != NULL && flag && temp->link !=NULL)
	{
		if ((temp->size+temp->start == temp->link->start))
		{
			temp->size += temp->link->size;
			temp->link = temp->link->link;
			flag = 0;
			//free();
		}
		else
		{
			temp = temp->link;
		}
	}
}

