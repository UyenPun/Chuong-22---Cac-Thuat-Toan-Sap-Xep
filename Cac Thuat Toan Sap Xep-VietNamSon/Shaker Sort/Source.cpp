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
void ShakerSort(T a[], int n, bool kieusapxep = true) 
{
	int left = 0; // Biên trái
	int right = n - 1; // Biên phải
	
	// k là vị trí index cuối cùng đổi chỗ trong 1 lần duyệt để nhờ đó cập nhật lại giá trị biên left, right để thu hẹp phạm vi xét dữ liệu lại
	// Lưu ý: giá trị k khởi tạo này nên là 1 giá trị nằm ngoài phạm vi index của mảng để tránh bị lỗi trong trường hợp nếu như sau lần duyệt đầu tiên vị trí đổi chỗ cuối cùng có index trùng với index k khởi tạo ngoài này thì chương trình nó kết thúc luôn mà không xét vòng lặp ở bên dưới
	int k = -1; 

	// Điều kiện lặp của các lần duyệt
	while(left < right)
	{
		int temp_k = k; // Biến phụ để lưu giá trị k vào mục đích để kiểm tra xem sau vòng lặp đầu tiên thì giá trị k có bị thay đổi không? Nếu không thay đổi thì nghĩa là không có cặp số nào hoán vị => thuật toán có thể kết thúc ngay mà không cần phải xét đến vòng lặp thứ 2

		// Lần duyệt đầu tiên từ biên phải về biên trái
		for(int i = right; i > left; --i)
		{
			// a[i] & a[i - 1]
			if(a[i] < a[i - 1] == kieusapxep)
			{
				swap(a[i], a[i - 1]);
				k = i - 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được nổi bọt lên
			}
		}
		// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
		if(temp_k == k)
			break;

		left = k + 1; // Cập nhật lại biên trái

		// Lần duyệt tiếp theo sẽ là từ biên trái về biên phải
		for(int i = left; i < right; ++i)
		{
			// a[i] & a[i + 1]
			if(a[i + 1] < a[i] == kieusapxep)
			{
				swap(a[i + 1], a[i]);
				k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
			}
		}
		right = k - 1; // Cập nhật lại biên phải
	}
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
	ShakerSort(a, n);
	XuatMang(a, n);

	printf("\nMang sau khi sap xep giam dan: ");
	ShakerSort(a, n, false);
	XuatMang(a, n);
	
	getch();
	return 0;
}