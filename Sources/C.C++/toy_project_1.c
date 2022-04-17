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
	printf("ó�� ���� \n");
	print_(available);
	// �޴� ���� gui ����Լ� ����
	printf("a�� 30�Ҵ�\n");
	a = myalloc(30);
	printf("b�� 10�Ҵ�\n");
	b = myalloc(10);
	printf("c�� 10�Ҵ�\n");
	c = myalloc(10);
	printf("a�� ����\n");
	myfree(a);
	printf("a�� 40�Ҵ�\n");
	a = myalloc(40);
	printf("c�� ����\n");
	myfree(c);
	printf("c�� 10�Ҵ�\n");
	c = myalloc(10);
	printf("d�� 30�Ҵ�\n");
	d = myalloc(30);
	printf("b�� ����\n");
	myfree(b);	
	//�ϳ��ϳ� ���� �Ҵ���ϴ��� Ȯ���Ϸ��� �ſ� ��ȿ������
}
void best_scene_1(void)
{
	Addr a, b, c, d;
	printf("ó�� ���� \n");
	print_(available);
	// �޴� ���� gui ����Լ� ����
	printf("a�� 30�Ҵ�\n");
	a = myalloc_best(30);
	printf("b�� 10�Ҵ�\n");
	b = myalloc_best(10);
	printf("c�� 10�Ҵ�\n");
	c = myalloc_best(10);
	printf("a�� ����\n");
	myfree(a);
	printf("a�� 40�Ҵ�\n");
	a = myalloc_best(40);
	printf("c�� ����\n");
	myfree(c);
	printf("c�� 10�Ҵ�\n");
	c = myalloc_best(10);
	printf("d�� 30�Ҵ�\n");
	d = myalloc_best(30);
	printf("b�� ����\n");
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
	printf("1.�ó�����\n");
	printf("2.������Է�\n");
	printf("----------------------------------------------------------------------------------------------\n");
	scanf("%d", &menu);
	if (me==1 &&menu == 1)
	{
		printf("�̸� ����� �ó������� �����մϴ�.\n");
		scene_1();
	}
	else if (me == 2 && menu == 1)
	{
		printf("�̸� ����� �ó������� �����մϴ�.\n");
		best_scene_1();
	}
	else if (me ==1 && menu == 2)
	{
		while (menu_1 != -1)
		{
			printf("����� �Է��� �����̽��ϴ�. -1�� �Է��Ͻø� �����մϴ�.\n");
			printf(" 1 . �Ҵ� \n2. ���� \n");
			scanf("%d", &menu_1);




			if (menu_1 == 1)
			{

				printf("�Ҵ��� ��ȣ(1~4)�� �޸� ũ�⸦ �����ʽÿ� (4������ �Ҵ��Ͻ� �� �ֽ��ϴ�.)\n");
				scanf("%d %d", &name, &size);
				switch (name)
				{
				case 1:
					printf("1��%d��ŭ �Ҵ��մϴ�.\n", size);
					a = myalloc(size);
					if (a.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n"); 
					break;
				case 2:
					printf("2��%d��ŭ �Ҵ��մϴ�.\n", size);
					b = myalloc(size);
					if (b.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n"); 
					break;
				case 3:
					printf("3��%d��ŭ �Ҵ��մϴ�.\n", size);
					c = myalloc(size); 
					if (c.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n"); 
					break;
				case 4:
					printf("4��%d��ŭ �Ҵ��մϴ�.\n", size);
					d = myalloc(size);
					if (d.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n"); 
					break;
				}
				continue;
			}

			else if (menu_1 == 2)
			{

				printf("������ ��ȣ(1~4)\n");
				scanf("%d ", &name);
				switch (name)
				{
					//�ι� �����Ϸ� �õ��ϴ°͵� �����ϸ� ���� �� �־����
				case 1:
					/*if (a.size == 0)
						printf("�ȵ˴ϴ�. �ƹ� ��ȣ�� �ٽô����ʽÿ�\n"); continue;*/
					printf("1�� �����մϴ�.\n");
					myfree(a);
					break;
				case 2:
					printf("2�� �����մϴ�.\n");
					myfree(b);
					break;
				case 3:
					printf("3�� �����մϴ�.\n");
					myfree(c);
					break;
				case 4:
					printf("4�� �����մϴ�.\n");
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
			printf("����� �Է��� �����̽��ϴ�. -1�� �Է��Ͻø� �����մϴ�. �Ȱ��� �޸� �ι� �Ҵ��� �Ͻø� �ȵ˴ϴ�.\n");
			printf(" 1 . �Ҵ� \n2. ���� \n");
			scanf("%d", &menu_1);


			if (menu_1 == 1)
			{

				printf("�Ҵ��� ��ȣ(1~4)�� �޸� ũ�⸦ �����ʽÿ� (4������ �Ҵ��Ͻ� �� �ֽ��ϴ�.)\n");
				scanf("%d %d", &name, &size);
				switch (name)
				{
				case 1:
					printf("1��%d��ŭ �Ҵ��մϴ�.\n", size);
					a = myalloc_best(size);
					if (a.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n");
					break;
				case 2:
					printf("2��%d��ŭ �Ҵ��մϴ�.\n", size);
					b = myalloc_best(size);
					if (b.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n");
					break;
				case 3:
					printf("3��%d��ŭ �Ҵ��մϴ�.\n", size);
					c = myalloc_best(size);
					if (c.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n");
					break;
				case 4:
					printf("4��%d��ŭ �Ҵ��մϴ�.\n", size);
					d = myalloc_best(size);
					if (d.start == -1)
						printf("��������� �Ѵ� ������ �Ҵ��Ϸ� �ϼ̽��ϴ�.\n");
					break;
				}
				continue;
			}

			else if (menu_1 == 2)
			{

				printf("������ ��ȣ(1~4)\n");
				scanf("%d ", &name);
				switch (name)
				{
				case 1:printf("1�� �����մϴ�.\n");
					myfree(a);
					break;
				case 2:printf("2�� �����մϴ�.\n");
					myfree(b);
					break;
				case 3:printf("3�� �����մϴ�.\n");
					myfree(c);
					break;
				case 4:printf("4�� �����մϴ�.\n");
					myfree(d);
					break;
				}
				continue;
			}
		}


	}
}

void print_(Chunk *a) //����� �Լ�
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
//����Ʈ�� ���̾�� �Լ��� ����
Addr myalloc_best(int request_size)
{
	Addr result;
	int count = 0;
	int smallest = 0;
	result.start = -1; //��������� ��ã���� �翬�� ������
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
	//ó���� ������� ã�� �˰��� �ʿ�
	print_(available);
	myrenew(available);
	return result;
}
Addr myalloc(int request_size)
{
	Addr result;
	int flag = 1;
	result.start = -1; //��������� ��ã���� �翬�� ������
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
	//ó���� ������� ã�� �˰��� �ʿ�
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
	//������� ����Ʈ�� ��������
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

