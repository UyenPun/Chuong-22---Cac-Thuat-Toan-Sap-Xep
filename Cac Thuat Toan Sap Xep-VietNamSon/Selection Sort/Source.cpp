#include <stdio.h>
#include <conio.h>
//#include <Sort.h>
#include <iostream>
using namespace std;
int sosanh = 0;
int gan = 0;



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
	gan += 3;
	//printf("\ngan trong ham HoanVi => gan = %d", gan);
}

// kieusapxep là true: tăng - false: giảm
template <class T>
void SelectionSort(T a[], int n, bool kieusapxep = true) 
{
	for(int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Min bắt đầu từ i
	{
		int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i
		gan++;
		//printf("\ngan vong lap i => i = %d => gan = %d", i, gan);

		for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
		{
			sosanh++;

			if(a[j] < a[vitriMin] == kieusapxep) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
			{
				vitriMin = j; // cập nhật lại vị trí Min
				gan++;
				//printf("\ngan vong lap j => j = %d => gan = %d", j, gan);
			}
		}
		HoanVi(a[i], a[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
	}
}

int main()
{
	char a[] = {'b', 'a', 'c', 'e', 'd'};
	int n = sizeof(a)/sizeof(a[0]);

	printf("\nMang truoc khi sap xep");
	XuatMang(a, n);

	printf("\nMang sau khi sap xep tang dan");
	SelectionSort(a, n);
	XuatMang(a, n);

	printf("\nMang sau khi sap xep giam dan");
	SelectionSort(a, n, false);
	XuatMang(a, n);

	//printf("\nSo lan so sanh = %d", sosanh);
	//printf("\nSo lan gan = %d", gan);
	
	getch();
	return 0;
}