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
void BubbleSort(T a[], int n, bool kieusapxep = true) 
{
	//int dem = 0;
	// Nếu chạy theo chiều từ phải qua trái
	for(int i = 1; i < n; ++i)
	{
		bool Check = true; // cờ hiệu để kiểm tra xem trong 1 lần so sánh các cặp thì có sự đổi chỗ nào không? Nếu không có thì thuật toán có thể kết thúc mà không cần xét qua các lần chạy tiếp theo
		for(int j = n - 1; j >= i; --j)
		{
			//dem++;
			// so sánh các cặp: a[j] và a[j - 1]
			// a[j - 1] là thằng đứng trước
			// a[j] là thằng đứng sau
			// Nếu sắp tăng dần thì thằng đứng trước phải < thằng đứng sau, nếu thằng đứng trước mà > thằng đứng sau thì phải đổi chỗ lại
			// Nếu sắp giảm dần thì thằng đứng trước phải > thằng đứng sau, nếu thằng đứng trước mà < thằng đứng sau thì phải đổi chỗ lại
			if(a[j - 1] > a[j] == kieusapxep)
			{
				HoanVi(a[j], a[j - 1]);
				Check = false; // cập nhật lại cờ hiệu
			}
		}

		// Sau quá trình xét các cặp thì ta đi kiểm tra cờ hiệu để biết được có ít nhất 1 cặp số nào đã đổi chỗ hay không?
		if(Check == true) // tức là không có trường hợp cặp số nào đổi chỗ hết => thuật toán dừng lại tại đây
		{
			break; // thoát khỏi vòng lặp for i (cha)
		}
	}
	//cout << "so luong cac cap so phai di so sanh: " << dem << "\n\n";

	/*
	//int dem = 0;
	// Nếu chạy theo chiều từ trái qua phải
	for(int i = n - 2; i >= 0; --i) // Nếu chạy i theo giá trị cuối cùng mà j hướng đến
	//for(int i = 1; i < n; ++i) // Nếu chạy i theo số lần chạy bắt đầu từ 1
	{
		bool Check = true; // cờ hiệu để kiểm tra xem trong 1 lần so sánh các cặp thì có sự đổi chỗ nào không? Nếu không có thì thuật toán có thể kết thúc mà không cần xét qua các lần chạy tiếp theo
		for(int j = 0; j <= i; ++j)
		//for(int j = 0; j <= n - 1 - i; ++j)
		{
			//dem++;
			// so sánh các cặp: a[j] và a[j + 1]
			// a[j] là thằng đứng trước
			// a[j + 1] là thằng đứng sau
			// Nếu sắp tăng dần thì thằng đứng trước phải < thằng đứng sau, nếu thằng đứng trước mà > thằng đứng sau thì phải đổi chỗ lại
			// Nếu sắp giảm dần thì thằng đứng trước phải > thằng đứng sau, nếu thằng đứng trước mà < thằng đứng sau thì phải đổi chỗ lại
			if(a[j] > a[j + 1] == kieusapxep)
			{
				HoanVi(a[j], a[j + 1]);
				Check = false; // cập nhật lại cờ hiệu
			}
		}
		// Sau quá trình xét các cặp thì ta đi kiểm tra cờ hiệu để biết được có ít nhất 1 cặp số nào đã đổi chỗ hay không?
		if(Check == true) // tức là không có trường hợp cặp số nào đổi chỗ hết => thuật toán dừng lại tại đây
		{
			break; // thoát khỏi vòng lặp for i (cha)
		}
	}
	//cout << "so luong cac cap so phai di so sanh: " << dem << "\n\n";
	*/
}

int main()
{
	//char a[] = {'b', 'a', 'c', 'e', 'd'};
	int a[] = {5, 1, 3, 2, 4, 9, 6, 10, 8, 7};
	//int a[] = {15, 2, 8, 7, 3, 6, 9, 17};
	//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	/*int a[10000];
	int n = 10000;
	
	for(int i = 0; i < n; ++i)
	{
		a[i] = i + 1;
	}*/

	int n = sizeof(a)/sizeof(a[0]);

	printf("\nMang truoc khi sap xep: ");
	XuatMang(a, n);

	printf("\nMang sau khi sap xep tang dan: ");
	BubbleSort(a, n);
	XuatMang(a, n);

	printf("\nMang sau khi sap xep giam dan: ");
	BubbleSort(a, n, false);
	XuatMang(a, n);
	
	getch();
	return 0;
}