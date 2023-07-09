#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <algorithm>
//#include <Sort.h>
#include <iostream>
using namespace std;

template <class abc> // abc là tên bất kỳ ta đặt đại diện cho kiểu dữ liệu
void XuatMang(abc a[], int n)
{
	for(int i = 0; i < n; ++i)
		//printf("%4d", a[i]);
		cout << a[i] << " ";
		//printf("%d(%d) ", a[i], i);
		//cout << a[i] << "(" << i << ") ";
}

/*
template <class T>
void HoanVi(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}*/

// kieusapxep là true: tăng - false: giảm
template <class T>
void InsertionSort(T a[], int n, bool saptang = true) 
{
	//printf("\nDang chay vao ham InsertionSort\n");
	for(int i = 1; i < n; ++i) // vế phải
	{
		T x = a[i];

		bool Check = false;

		// đi so sánh a[i] với tất cả giá trị của a[j]
		for(int j = i - 1; j >= 0; --j) // vế trái
		{
			if(saptang == true ? x < a[j] : x > a[j])
			{
				// a[j] sẽ nhích qua bên phải 1 ô
				a[j + 1] = a[j];
			}
			else
			{
				a[j + 1] = x;
				Check = true;
				break;
			}
		}
		if(Check == false)
		{
			a[0] = x;
		}
	}
}

// kieusapxep là true: tăng - false: giảm
template <class T>
void InsertionSort_2(T a[], int n, bool saptang = true) 
{
	//printf("\nDang chay vao ham InsertionSort_2\n");
	for(int i = 1; i < n; ++i) // vế phải
	{
		T x = a[i];

		// đi so sánh a[i] với tất cả giá trị của a[j]
		int j = i - 1;
		while(j >= 0 && (saptang == true ? x < a[j] : x > a[j]))
		{
			// a[j] sẽ nhích qua bên phải 1 ô
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

// kieusapxep là true: tăng - false: giảm
template <class T>
void InsertionSort_3(T a[], int n, bool saptang = true) 
{
	//printf("\nDang chay vao ham InsertionSort_3\n");
	for(int i = 1; i < n; ++i) // vế phải
	{
		T x = a[i];

		// đi so sánh a[i] với tất cả giá trị của a[j]
		int j = i - 1;
		while(j >= 0 && (saptang == true ? x < a[j] : x > a[j]))
		{
			j--;
		}
		
		// x phải đứng ở vị trí a[j + 1] => bắt đầu quá trình di dời phần tử từ index i - 1 đến index j + 1 mỗi lần nhích lên 1 đơn vị rồi sau đó thêm x vào vị trí j + 1
		for(int m = i - 1; m >= j + 1; --m)
		{
			a[m + 1] = a[m];
		}
		a[j + 1] = x;
	}
}

// kieusapxep là true: tăng - false: giảm
template <class T>
void InsertionSort_3_Sentinel(T a[], int n, bool saptang = true) 
{
	//printf("\nDang chay vao ham InsertionSort_3\n");
	for(int i = 1; i < n; ++i) // vế phải
	{
		T x = a[i];

		// đi so sánh a[i] với tất cả giá trị của a[j]
		int j = 0;
		while(saptang == true ? x > a[j] : x < a[j])
		{
			j++;
		}

		if(j == i)
			continue;
		
		// x phải đứng ở vị trí a[j + 1] => bắt đầu quá trình di dời phần tử từ index i - 1 đến index j + 1 mỗi lần nhích lên 1 đơn vị rồi sau đó thêm x vào vị trí j + 1
		for(int m = i - 1; m >= j; --m)
		{
			a[m + 1] = a[m];
		}
		a[j] = x;
	}
}

template <class T>
void InsertionSortWithSentinel(T a[], int n, bool saptang = true) 
{
	//printf("\nDang chay vao ham InsertionSortWithSentinel\n");
	for(int i = 2; i < n; ++i) // vế phải
	{
		T x = a[i];
		a[0] = x; // lính canh (sentinel)

		// đi so sánh a[i] với tất cả giá trị của a[j]
		int j = i - 1;
		while(saptang == true ? x < a[j] : x > a[j])
		{
			// a[j] sẽ nhích qua bên phải 1 ô
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

// [n_A, n_B]: Giá trị n (số lượng phần tử của mảng) sẽ được random ngẫu nhiên trong đoạn từ n_A --> n_B
// [ai_A, ai_B]: Giá trị ai (giá trị từng phần trong mảng) sẽ được random ngẫu nhiên trong đoạn từ ai_A --> ai_B
template <class T>
void TestSortWithSentinel(void (*ThuatToanSapXep)(T*, int, bool), int SoTestCase, int n_A, int n_B, int ai_A, int ai_B)
{
	// Tool test tự động thuật toán sắp xếp
	// số lượng phần tử của mảng
	// Sinh ngẫu nhiên 1 giá trị nằm trong đoạn [a, b] => a + rand() % (b - a + 1)
	// ví dụ: Muốn sinh ngẫu nhiên giá trị nằm trong đoạn từ 1 tới 10 => 1 + rand() % 10;
	srand(time(0));
	for(int k = 1; k <= SoTestCase; ++k)
	{
		printf("Test case %d: ", k);
		int n = n_A + rand() % (n_B - n_A + 1); // n_A --> n_B
		T *a = new T[n + 1];
		//printf("n = %d\n", n);
		for(int i = 1; i <= n; ++i)
		{
			a[i] = ai_A + rand() % (ai_B - ai_A + 1); // ai_A --> ai_B
			//a[i] = a[i] / 10.0;
			//printf("a[%d] = %d\n", i, a[i]);
		}
		printf("(n = %d): ", n);
		//XuatMang(a, n);

		T *KetQuaChinhXac = new T[n + 1];
		for(int i = 1; i <= n; ++i)
			KetQuaChinhXac[i] = a[i];

		ThuatToanSapXep(a, n + 1, true);

		sort(KetQuaChinhXac + 1, KetQuaChinhXac + n + 1);

		//printf("\nSap tang\n");
		bool Check = true;
		for(int i = 1; i <= n; ++i)
		{
			//printf("KetQuaChinhXac[%d] = %d\n", i, KetQuaChinhXac[i]);
			if(a[i] != KetQuaChinhXac[i])
			{
				Check = false;
				printf("\nSap tang co test case sai o vi tri index: %d\n", i);
				break;
			}
		}
		if(Check == false)
		{
			printf("a = ");
			XuatMang(a, n);
			printf("\n\nKetQuaChinhXac = ");
			XuatMang(KetQuaChinhXac, n);
			break;
		}

		//printf("\nSap giam\n");
		ThuatToanSapXep(a, n + 1, false);
		
		int j = 1;
		Check = true;
		for(int i = n; i >= 1; --i)
		{
			//printf("KetQuaChinhXac[%d] = %d\n", i, KetQuaChinhXac[i]);
			if(a[j] != KetQuaChinhXac[i])
			{
				Check = false;
				printf("\nSap giam co test case sai o vi tri index: %d\n", j);
				break;
			}
			j++;
		}
		if(Check == false)
		{
			printf("a = ");
			XuatMang(a, n);
			printf("\n\nKetQuaChinhXac = ");
			
			for(int i = n - 1; i >= 0; --i)
				printf("%d(%d) ", KetQuaChinhXac[i], n - 1 - i);

			break;

		}
		else
		{
			printf(" => Pass Test Case\n");
		}

		// Nhớ phải có 2 dòng này để giải phóng bộ nhớ nếu không có nó bảo đảm bộ nhớ ram sẽ tăng đột biến và có thể tắt máy tính luôn
		delete[] a;
		delete[] KetQuaChinhXac;
	}
}

// [n_A, n_B]: Giá trị n (số lượng phần tử của mảng) sẽ được random ngẫu nhiên trong đoạn từ n_A --> n_B
// [ai_A, ai_B]: Giá trị ai (giá trị từng phần trong mảng) sẽ được random ngẫu nhiên trong đoạn từ ai_A --> ai_B
template <class T>
void TestSort(void (*ThuatToanSapXep)(T*, int, bool), int SoTestCase, int n_A, int n_B, int ai_A, int ai_B)
{
	// Tool test tự động thuật toán sắp xếp
	// số lượng phần tử của mảng
	// Sinh ngẫu nhiên 1 giá trị nằm trong đoạn [a, b] => a + rand() % (b - a + 1)
	// ví dụ: Muốn sinh ngẫu nhiên giá trị nằm trong đoạn từ 1 tới 10 => 1 + rand() % 10;
	srand(time(0));
	for(int k = 1; k <= SoTestCase; ++k)
	{
		printf("Test case %d: ", k);
		int n = n_A + rand() % (n_B - n_A + 1); // n_A --> n_B
		T *a = new T[n];
		//printf("n = %d\n", n);
		for(int i = 0; i < n; ++i)
		{
			a[i] = ai_A + rand() % (ai_B - ai_A + 1); // ai_A --> ai_B
			//a[i] = a[i] / 10.0;
			//printf("a[%d] = %d\n", i, a[i]);
		}
		printf("(n = %d): ", n);
		//XuatMang(a, n);

		T *KetQuaChinhXac = new T[n];
		for(int i = 0; i < n; ++i)
			KetQuaChinhXac[i] = a[i];

		ThuatToanSapXep(a, n, true);

		sort(KetQuaChinhXac, KetQuaChinhXac + n);

		//printf("\nSap tang\n");
		bool Check = true;
		for(int i = 0; i < n; ++i)
		{
			//printf("KetQuaChinhXac[%d] = %d\n", i, KetQuaChinhXac[i]);
			if(a[i] != KetQuaChinhXac[i])
			{
				Check = false;
				printf("\nSap tang co test case sai o vi tri index: %d\n", i);
				break;
			}
		}
		if(Check == false)
		{
			printf("a = ");
			XuatMang(a, n);
			printf("\n\nKetQuaChinhXac = ");
			XuatMang(KetQuaChinhXac, n);
			break;
		}

		//printf("\nSap giam\n");
		ThuatToanSapXep(a, n + 1, false);
		
		int j = 0;
		Check = true;
		for(int i = n - 1; i >= 0; --i)
		{
			//printf("KetQuaChinhXac[%d] = %d\n", i, KetQuaChinhXac[i]);
			if(a[j] != KetQuaChinhXac[i])
			{
				Check = false;
				printf("\nSap giam co test case sai o vi tri index: %d\n", j);
				break;
			}
			j++;
		}
		if(Check == false)
		{
			printf("a = ");
			XuatMang(a, n);
			printf("\n\nKetQuaChinhXac = ");
			
			for(int i = n - 1; i >= 0; --i)
				printf("%d(%d) ", KetQuaChinhXac[i], n - 1 - i);

			break;

		}
		else
		{
			printf(" => Pass Test Case\n");
		}

		// Nhớ phải có 2 dòng này để giải phóng bộ nhớ nếu không có nó bảo đảm bộ nhớ ram sẽ tăng đột biến và có thể tắt máy tính luôn
		delete[] a;
		delete[] KetQuaChinhXac;
	}
}

int main()
{
	int n = 30000;
	int n_a = n;
	int *a = new int[n_a];
	for(int i = 0; i < n_a; ++i)
	{
		//a[i] = n_a - i;
		a[i] = i + 1;
	}

	int n_b = n + 1;
	int *b = new int[n_b];
	for(int i = 1; i < n_b; ++i)
	{
		//b[i] = n_b - i;
		b[i] = i;
	}

	time_t start1 = clock();
	InsertionSort_3(a, n_a, true);
	time_t end1 = clock();
	double thoigianchay1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

	time_t start2 = clock();
	InsertionSort_3_Sentinel(b, n_b, true);
	time_t end2 = clock();
	double thoigianchay2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	cout << "\nInsertionSort_3 chay mat: " << thoigianchay1;
	cout << "\nInsertionSort_3_Sentinel chay mat: " << thoigianchay2;

	////char a[] = {'b', 'a', 'c', 'e', 'd'};
	//int a[] = {5, 1, 3, 2, 4, 9, 6, 10, 8, 7};
	////float a[] = {1.5, 0.5, 4.5, 3.5, 5};
	////int a[] = {15, 2, 8, 7, 3, 6, 9, 17};
	////int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//
	///*int a[10000];
	//int n = 10000;
	//
	//for(int i = 0; i < n; ++i)
	//{
	//	a[i] = i + 1;
	//}*/

	//int n = sizeof(a)/sizeof(a[0]);

	//printf("\nMang truoc khi sap xep: ");
	//XuatMang(a, n);

	//printf("\nMang sau khi sap xep tang dan: ");
	////InsertionSort_3(a, n);
	//InsertionSort_3_Sentinel(a, n, true);
	//XuatMang(a, n);

	//printf("\nMang sau khi sap xep giam dan: ");
	////InsertionSort_3(a, n, false);
	//InsertionSort_3_Sentinel(a, n, false);
	//XuatMang(a, n);

	//TestSort<int>(InsertionSort_3_Sentinel, 100, 300, 500, -100, 200);
	
	

	

	getch();
	return 0;
}