#include <stdio.h>
#include <conio.h>
//#include <Sort.h>
#include <iostream>
using namespace std;

template <class abc> // abc là tên bất kỳ ta đặt đại diện cho kiểu dữ liệu
void XuatMang(abc a[], int n)
{
	for(int i = 0; i < n; ++i)
		//printf("%4d", a[i]);
		cout << a[i] << " ";
}

template <class T>
void HoanVi(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// kieusapxep là true: tăng - false: giảm
template <class T>
void InterchangeSort(T a[], int n, bool kieusapxep = true) 
{
	for(int i = 0; i < n - 1; ++i) // Xét qua các phần tử từ đầu đến áp cuối
	{
		for(int j = i + 1; j < n; ++j) // Với mỗi phần tử thì xét tất cả các phần tử đằng sau nó
		{
			if(a[j] < a[i] == kieusapxep) // Nếu phần tử nào nhỏ hơn => đổi chỗ phần tử nhỏ hơn đó về vị trí đầu dãy (i)
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}

int main()
{
	char a[] = {'b', 'a', 'c', 'e', 'd'};
	int n = sizeof(a)/sizeof(a[0]);

	printf("\nMang truoc khi sap xep: ");
	XuatMang(a, n);

	printf("\nMang sau khi sap xep tang dan: ");
	InterchangeSort(a, n);
	XuatMang(a, n);

	printf("\nMang sau khi sap xep giam dan: ");
	InterchangeSort(a, n, false);
	XuatMang(a, n);
	
	getch();
	return 0;
}