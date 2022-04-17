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
	printf("20160636 손수민\n\n");
	printf("값의 개수 : ");
	scanf("%d", &size);  size++; // 인덱스 0은 사용하지 않음
	sMax = size;
	tMax = (int *)malloc(sizeof(int) * size);
	for (int i = 1; i < size; i++)   { // 인덱스 0 사용하지 않음 
		int item; 
		scanf("%d", &item); 
		InsertIntoMaxHeapTree(tMax, i, item);
	}// 입력 값을 힙 트리에 삽입 
		PrintHeapTreeWidthFirst(tMax, sMax); // 힙 트리를 출력
		while (sMax > 1) { printf("%d ", RemoveFromMaxHeapTree(tMax, &sMax)); } printf("\n");
		return 0;




	
}