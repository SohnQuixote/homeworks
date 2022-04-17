#include <stdio.h>
#define Swap( a,  b, t)((t) = (a),(a) = (b) ,(b) = (t) )
int InsertIntoMaxHeapTree(int *tree, int index, int value)
{
	int p; 
	tree[index] = value;
	if (index == 1 || tree[(index / 2)] > tree[index])
		return index;
	else if (index != 1 && tree[index] > tree[(index/2)])
	{
		p = tree[(index / 2)];
		tree[(index / 2)] = tree[index];
		tree[index] = p;
	}
	return InsertIntoMaxHeapTree(tree, (index / 2), value);
}
int RemoveFromMaxHeapTree(int*tree, int *size)
{
	int item = tree[1];
	tree[1] = tree[(*size) - 1];
	*size -= 1;
	ArrangeMaxHeapTree(tree, *size, 1);
	return item;
}
int ArrangeMaxHeapTree(int*tree, int size, int index)
{
	int temp;
	int next = index;

	if ((2 * index) <= size && tree[index] < tree[(2 * index)]) next = index * 2;
	if ((2 * index + 1) <= size && tree[next] < tree[(2 * index + 1)]) next = index * 2 + 1;

	if (index != next)
	{
		Swap(tree[index], tree[next], temp);
		ArrangeMaxHeapTree(tree, size, next);
	}
}
void PrintHeapTreeWidthFirst(int *tree, int size)
{
	for (int i = 1; i < size; i++)
		printf("%d ", tree[i]);
	printf("\n");
}
int main(void)
{
	int *tMax, sMax, size, value;
	printf("20160636 �ռ���\n\n");
	printf("���� ���� : ");
	scanf("%d", &size);  size++; // �ε��� 0�� ������� ����
	sMax = size;
	tMax = (int *)malloc(sizeof(int) * size);
	for (int i = 1; i < size; i++)   { // �ε��� 0 ������� ���� 
		int item; 
		scanf("%d", &item); 
		InsertIntoMaxHeapTree(tMax, i, item);
	}// �Է� ���� �� Ʈ���� ���� 
		PrintHeapTreeWidthFirst(tMax, sMax); // �� Ʈ���� ���
		while (sMax > 1) { printf("%d ", RemoveFromMaxHeapTree(tMax, &sMax)); } printf("\n");
		return 0;




	
}