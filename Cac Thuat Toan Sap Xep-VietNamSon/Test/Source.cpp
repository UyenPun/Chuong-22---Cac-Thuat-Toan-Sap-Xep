#include <Sort.h>

int main()
{
	printf("Test Selection Sort\n\n");
	TestSort<int>(SelectionSort, 500, 100, 500, -999, 999);

	printf("Test Interchange Sort\n\n");
	TestSort<int>(InterchangeSort, 500, 100, 500, -999, 999);

	printf("Test Bubble Sort\n\n");
	TestSort<int>(BubbleSort, 500, 100, 500, -999, 999);

	printf("Test Shaker Sort\n\n");
	TestSort<int>(ShakerSort, 500, 100, 500, -999, 999);

	printf("Test Insertion Sort\n\n");
	TestSort<int>(InsertionSort, 500, 100, 500, -999, 999);

	system("pause");
	return 0;
}