#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void XuatMang(int *a, int n)
{
	for(int i = 0; i < n; ++i)
		printf("\ni = %d: %d", i, a[i]);
}

void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int *a, int n)
{
	for(int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Min bắt đầu từ i
	{
		int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i

		for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
		{
			if(a[j] < a[vitriMin]) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
			{
				vitriMin = j; // cập nhật lại vị trí Min
			}
		}
		HoanVi(a[i], a[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
	}
}

void InterchangeSort(int *a, int n) 
{
	for(int i = 0; i < n - 1; ++i) // Xét qua các phần tử từ đầu đến áp cuối
	{
		for(int j = i + 1; j < n; ++j) // Với mỗi phần tử thì xét tất cả các phần tử đằng sau nó
		{
			if(a[j] < a[i]) // Nếu phần tử nào nhỏ hơn => đổi chỗ phần tử nhỏ hơn đó về vị trí đầu dãy (i)
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
}

// n là số lượng các số được Random
// số sẽ random trong đoạn [a, b]
void PhatSinhDaySo(int n, int a, int b, char* tentaptin, char* mode) 
{
	FILE *f = fopen(tentaptin, mode); // Mở tập tin để ghi

	srand(time(0)); // Nếu để trong vòng lặp là sẽ bị cac số giống nhau
	for(int i = 1; i <= n; ++i)
	{
		int x = a + rand() % (b - a + 1); // 0 -> 100
		fprintf(f, "%d\n", x);
	}

	printf("Du lieu da duoc ghi vao tap tin %s", tentaptin);
	fclose(f); // Đóng tập tin khi đã dùng xong để giải phóng bộ nhớ
}

// true: Nếu mở được tập tin và đọc dữ liệu thành công
// false: Nếu không mở được tập tin
bool DocDuLieuTuTapTin(char* tentaptin, char* mode, int *&a, int n)
{
	FILE *f = fopen(tentaptin, mode);

	if(f != NULL)
	{
		a = new int[n];

		for(int i = 0; i < n; ++i)
		{
			fscanf(f, "%d", &a[i]);
		}

		fclose(f);
		return true;
	}

	printf("\nKhong tim thay tap tin %s", tentaptin);
	return false;
}

int main()
{
	// PhatSinhDaySo(80000, -100, 100, "80.000.txt", "a");
	
	FILE *f = fopen("DoThoiGianCacThuatToanSapXep.txt", "a");

	//fprintf(f, "\n\n\t\t\t\tSelection Sort");
	//fprintf(f, "\nTap Du Lieu\tLan Chay 1\tLan Chay 2\tLan Chay 3\tTrung Binh");

	fprintf(f, "\n80.000\t\t");

	double tong = 0;

	for(int i = 1; i <= 3; ++i)
	{
		int *a;
		int n = 80000;

		bool KiemTraTapTin = DocDuLieuTuTapTin("80.000.txt", "r", a, n);

		if(KiemTraTapTin == true)
		{
			// Xử lý sắp xếp và đo thời gian
		
			clock_t start = clock();
			SelectionSort(a, n);
			//InterchangeSort(a, n);
			clock_t end = clock();

			double thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;

			// Dữ liệu được ghi ra file
			fprintf(f, "%.3lfs\t\t", thoigianchay);

			tong += thoigianchay;

			//printf("\nVoi n = %d => Selection Sort chay mat %.3lfs", n, thoigianchay);

			delete[] a;
		}
	}
	fprintf(f, "%.3lfs", tong / 3);

	printf("\nDu lieu thoi gian chay da duoc ghi vao tap tin");

	fclose(f);
	getch();
	return 0;
}