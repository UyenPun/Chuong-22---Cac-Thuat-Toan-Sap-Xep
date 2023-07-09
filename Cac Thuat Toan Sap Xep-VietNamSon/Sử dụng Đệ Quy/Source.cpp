#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Cách làm này là đưa điều kiện dừng lên đầu chương trình để mỗi lần chạy lại hàm thì đầu tiên sẽ xét xem có bị vi phạm điều kiện dừng không để từ đó hợp lệ rồi thì mới đi thực hiện những xử lý ở bên trong và lặp sang lần mới
// Xuất theo chiều ngược từ phải qua trái
void XuatMang_DeQuy_1(int a[], int n)
{
	if(n == 0)
		return;

	cout << a[n - 1] << " ";
	XuatMang_DeQuy_1(a, n - 1);
}

// Cách làm này khác cách làm trên ở chỗ thay vì đưa điều kiện để kết thúc thì ta sẽ đưa điều kiện để được lặp
// Xuất theo chiều ngược từ phải qua trái
/*
Chạy tay hàm này như sau:
vd: với n = 5
XuatMang_DeQuy_2(a, 5) => in ra a[n - 1] tức là in ra a[4] sau đó gọi đệ quy: XuatMang_DeQuy_2(a, 4)
XuatMang_DeQuy_2(a, 4) => in ra a[n - 1] tức là in ra a[3] sau đó gọi đệ quy: XuatMang_DeQuy_2(a, 3)
XuatMang_DeQuy_2(a, 3) => in ra a[n - 1] tức là in ra a[2] sau đó gọi đệ quy: XuatMang_DeQuy_2(a, 2)
XuatMang_DeQuy_2(a, 2) => in ra a[n - 1] tức là in ra a[1] sau đó gọi đệ quy: XuatMang_DeQuy_2(a, 1)
XuatMang_DeQuy_2(a, 1) => in ra a[n - 1] tức là in ra a[0] và lúc này không thỏa điều kiện cho nên không chạy đệ quy nữa và nghĩa là kết thúc tại đây
*/
void XuatMang_DeQuy_2(int a[], int n)
{
	cout << a[n - 1] << " ";
	
	if(n > 1)
		XuatMang_DeQuy_2(a, n - 1);
}

// Xuất theo chiều xuôi từ trái qua phải
/*
quá trình chạy tay hàm này như sau:
vd: với n = 5
XuatMang_DeQuy_3(a, 5) => gọi lại XuatMang_DeQuy_3(a, 4) và nợ lại dòng code xuất ra a[n - 1] => trả nợ: in ra a[n - 1] với n = 5 tức là in ra a[4]
XuatMang_DeQuy_3(a, 4) => gọi lại XuatMang_DeQuy_3(a, 3) và nợ lại dòng code xuất ra a[n - 1] => trả nợ: in ra a[n - 1] với n = 4 tức là in ra a[3]
XuatMang_DeQuy_3(a, 3) => gọi lại XuatMang_DeQuy_3(a, 2) và nợ lại dòng code xuất ra a[n - 1] => trả nợ: in ra a[n - 1] với n = 3 tức là in ra a[2]
XuatMang_DeQuy_3(a, 2) => gọi lại XuatMang_DeQuy_3(a, 1) và nợ lại dòng code xuất ra a[n - 1] => trả nợ: in ra a[n - 1] với n = 2 tức là in ra a[1]
XuatMang_DeQuy_3(a, 1) => bị vi phạm điều kiện để được đệ quy => không có gọi đệ quy gì nữa => chạy xuống in ra a[n - 1] với n = 1 tức là in ra a[0]
*/
void XuatMang_DeQuy_3(int a[], int n)
{
	if(n == 0)
		return;

	//if(n > 1) // Chỉ mở comment ra khi comment 2 dòng ở trên tức là trong 1 trường hợp chỉ chạy 1 trong 2
		XuatMang_DeQuy_3(a, n - 1);

	cout << a[n - 1] << " ";
}

// Hàm này sẽ chỉ chạy 1 lần giống như hàm đệ quy 2 tuy nhiên nó vẫn in ra được các phần tử theo chiều từ trái qua phải
void XuatMang_DeQuyDuoi(int a[], int n, int i = 0)
{
	if(i == n)
		return;

	cout << a[i] << " ";
	
	//if(i < n - 1)
		XuatMang_DeQuyDuoi(a, n, i + 1);
}

void SelectionSort_DeQuy_1(int a[], int n, int i = 0)
{
	if(i == n - 1)
		return;

	int vitriMin = i;
	for(int j = i + 1; j < n; ++j)
	{
		if(a[j] < a[vitriMin])
		{
			vitriMin = j;
		}
	}
	if(vitriMin != i)
		swap(a[i], a[vitriMin]);

	//if(i < n - 2) 
		SelectionSort_DeQuy_1(a, n, i + 1);
}

void SelectionSort_DeQuy_2(int a[], int n)
{
	if(n == 1)
		return;

	int vitriMax = 0;
	for(int j = 1; j < n; ++j)
	{
		if(a[j] > a[vitriMax])
		{
			vitriMax = j;
		}
	}
	swap(a[vitriMax], a[n - 1]);

	//if(n > 2)
		SelectionSort_DeQuy_2(a, n - 1);
}

void TimViTriIndexPhanTuNhoNhatCuaMangTrongDoanTuXDenY(int a[], int x, int y, int &vitriMin)
{
	//if(x > y)
		//return;

	if(a[x] < a[vitriMin])
		vitriMin = x;

	if(x < y)
		TimViTriIndexPhanTuNhoNhatCuaMangTrongDoanTuXDenY(a, x + 1, y, vitriMin);
}

// Không dùng vòng lặp ở bên trong hàm này nữa
void SelectionSort_DeQuy_3(int a[], int n, int i = 0)
{
	if(i == n - 1)
		return;

	int vitriMin = i;
	TimViTriIndexPhanTuNhoNhatCuaMangTrongDoanTuXDenY(a, i + 1, n - 1, vitriMin);
	if(vitriMin != i)
		swap(a[i], a[vitriMin]);

	//if(i < n - 2) 
		SelectionSort_DeQuy_3(a, n, i + 1);
}

void TimViTriIndexPhanTuLonNhatCuaMangTrongDoanTuXDenY(int a[], int x, int y, int &vitriMax)
{
	//if(x > y)
		//return;

	if(a[x] > a[vitriMax])
		vitriMax = x;

	if(x < y)
		TimViTriIndexPhanTuLonNhatCuaMangTrongDoanTuXDenY(a, x + 1, y, vitriMax);
}

void SelectionSort_DeQuy_4(int a[], int n)
{
	if(n == 1)
		return;

	int vitriMax = 0;
	TimViTriIndexPhanTuLonNhatCuaMangTrongDoanTuXDenY(a, 1, n - 1, vitriMax);
	swap(a[vitriMax], a[n - 1]);

	//if(n > 2)
		SelectionSort_DeQuy_4(a, n - 1);
}

void SelectionSort_DeQuy_5(int a[], int n, int i = 0, int j = 1, int vitriMin = 0)
{
	//if(i == n - 1)
		//return;

	if(j < n)
	{
		if(a[j] < a[vitriMin])
		{
			vitriMin = j;
		}
		SelectionSort_DeQuy_5(a, n, i, j + 1, vitriMin);
	}
	else // điều kiện dừng của vòng lặp for j
	{
		swap(a[i], a[vitriMin]);

		if(i < n - 2)
			SelectionSort_DeQuy_5(a, n, i + 1, i + 2, i + 1);
	}
}

void SelectionSort_DeQuy_6(int a[], int n, int j = 0, int vitriMax = 0)
{
	//if(n == 1)
		//return;

	if(j < n)
	{
		if(a[j] > a[vitriMax])
		{
			vitriMax = j;
		}
		SelectionSort_DeQuy_6(a, n, j + 1, vitriMax);
	}
	else
	{
		swap(a[vitriMax], a[n - 1]);

		if(n > 2)
			SelectionSort_DeQuy_6(a, n - 1, 1, 0);
	}
}

int i_select_7 = 0;
int j_select_7 = 1;
int vitriMin_select_7 = 0;
void SelectionSort_DeQuy_7(int a[], int n)//, int i = 0, int j = 1, int vitriMin = 0)
{
	//if(i == n - 1)
		//return;

	if(j_select_7 < n)
	{
		if(a[j_select_7] < a[vitriMin_select_7])
		{
			vitriMin_select_7 = j_select_7;
		}
		j_select_7++;
		SelectionSort_DeQuy_7(a, n);//, i, j + 1, vitriMin);
	}
	else // điều kiện dừng của vòng lặp for j
	{
		swap(a[i_select_7], a[vitriMin_select_7]);

		if(i_select_7 < n - 2)
		{
			i_select_7++;
			j_select_7 = i_select_7 + 1;
			vitriMin_select_7 = i_select_7;

			SelectionSort_DeQuy_7(a, n);//, i + 1, i + 2, i + 1);
		}
	}
}

int j_select_8 = 0;
int vitriMax_select_8 = 0;
void SelectionSort_DeQuy_8(int a[], int n)//, int j = 0, int vitriMax = 0)
{
	//if(n == 1)
		//return;

	if(j_select_8 < n)
	{
		if(a[j_select_8] > a[vitriMax_select_8])
		{
			vitriMax_select_8 = j_select_8;
		}
		j_select_8++;
		SelectionSort_DeQuy_8(a, n);//, j + 1, vitriMax);
	}
	else
	{
		swap(a[vitriMax_select_8], a[n - 1]);

		if(n > 2)
		{
			j_select_8 = 1;
			vitriMax_select_8 = 0;
			SelectionSort_DeQuy_8(a, n - 1);//, 1, 0);
		}
	}
}


void SelectionSort_DeQuy_9(int a[], int n)//, int i = 0, int j = 1, int vitriMin = 0)
{
	static int i_select_9 = 0;
	static int j_select_9 = 1;
	static int vitriMin_select_9 = 0;

	//if(i == n - 1)
		//return;

	if(j_select_9 < n)
	{
		if(a[j_select_9] < a[vitriMin_select_9])
		{
			vitriMin_select_9 = j_select_9;
		}
		j_select_9++;
		SelectionSort_DeQuy_9(a, n);//, i, j + 1, vitriMin);
	}
	else // điều kiện dừng của vòng lặp for j
	{
		swap(a[i_select_9], a[vitriMin_select_9]);

		if(i_select_9 < n - 2)
		{
			i_select_9++;
			j_select_9 = i_select_9 + 1;
			vitriMin_select_9 = i_select_9;

			SelectionSort_DeQuy_9(a, n);//, i + 1, i + 2, i + 1);
		}
	}
}


void SelectionSort_DeQuy_10(int a[], int n)//, int j = 0, int vitriMax = 0)
{
	static int j_select_10 = 0;
	static int vitriMax_select_10 = 0;

	//if(n == 1)
		//return;

	if(j_select_10 < n)
	{
		if(a[j_select_10] > a[vitriMax_select_10])
		{
			vitriMax_select_10 = j_select_10;
		}
		j_select_10++;
		SelectionSort_DeQuy_10(a, n);//, j + 1, vitriMax);
	}
	else
	{
		swap(a[vitriMax_select_10], a[n - 1]);

		if(n > 2)
		{
			j_select_10 = 1;
			vitriMax_select_10 = 0;
			SelectionSort_DeQuy_10(a, n - 1);//, 1, 0);
		}
	}
}

void InterchangeSort_DeQuy_1(int a[], int n, int i = 0)
{
	if(i == n - 1)
		return;

	for(int j = i + 1; j < n; ++j)
	{
		if(a[j] < a[i])
		{
			swap(a[i], a[j]);
		}
	}

	//if(i < n - 2) 
		InterchangeSort_DeQuy_1(a, n, i + 1);
}

void InterchangeSort_DeQuy_2(int a[], int n)
{
	if(n == 1)
		return;

	for(int j = 0; j < n - 1; ++j)
	{
		if(a[j] > a[n - 1])
		{
			swap(a[j], a[n - 1]);
		}
	}
	
	//if(n > 2)
		InterchangeSort_DeQuy_2(a, n - 1);
}

void XetTrongDoanTuXDenYDoiChoPhanTuNhoNhatVeDauCuaMang(int a[], int x, int y, int indexDauMang)
{
	if(x > y)
		return;
	
	if(a[x] < a[indexDauMang])
		swap(a[x], a[indexDauMang]);

	//if(x < y)
		XetTrongDoanTuXDenYDoiChoPhanTuNhoNhatVeDauCuaMang(a, x + 1, y, indexDauMang);
}

void InterchangeSort_DeQuy_3(int a[], int n, int i = 0)
{
	if(i == n - 1)
		return;

	XetTrongDoanTuXDenYDoiChoPhanTuNhoNhatVeDauCuaMang(a, i + 1, n - 1, i);

	//if(i < n - 2) 
		InterchangeSort_DeQuy_3(a, n, i + 1);
}


void XetTrongDoanTuXDenYDoiChoPhanTuLonNhatVeCuoiCuaMang(int a[], int x, int y, int n)
{
	if(x > y)
		return;
	
	if(a[x] > a[n - 1])
		swap(a[x], a[n - 1]);

	//if(x < y)
		XetTrongDoanTuXDenYDoiChoPhanTuLonNhatVeCuoiCuaMang(a, x + 1, y, n);
}

void InterchangeSort_DeQuy_4(int a[], int n)
{
	if(n == 1)
		return;

	XetTrongDoanTuXDenYDoiChoPhanTuLonNhatVeCuoiCuaMang(a, 0, n - 2, n); 
	
	//if(n > 2)
		InterchangeSort_DeQuy_4(a, n - 1);
}

// check = true là sắp tăng => mặc định là true
// check = false là sắp giảm
void InterchangeSort_DeQuy_5(int a[], int n, int i = 0, int j = 1)
{
	//if(i == n - 1)
		//return;

	if(j < n)
	{
		if(a[j] < a[i])
		{
			swap(a[i], a[j]);
		}
		InterchangeSort_DeQuy_5(a, n, i, j + 1);
	}
	else
	{
		if(i < n - 2)
			InterchangeSort_DeQuy_5(a, n, i + 1, i + 2);
	}
}

void InterchangeSort_DeQuy_6(int a[], int n, int j = 0)
{
	//if(n == 1)
		//return;

	if(j < n - 1)
	{
		if(a[j] > a[n - 1])
		{
			swap(a[j], a[n - 1]);
		}
		InterchangeSort_DeQuy_6(a, n, j + 1);
	}
	else
	{
		if(n > 2)
			InterchangeSort_DeQuy_6(a, n - 1, 0);
	}
}

int i = 0;
int j = 1;
void InterchangeSort_DeQuy_7(int a[], int n)//, int i = 0, int j = 1)
{
	//if(i == n - 1)
		//return;

	if(j < n)
	{
		if(a[j] < a[i])
		{
			swap(a[i], a[j]);
		}
		j++;
		InterchangeSort_DeQuy_7(a, n);//, i, j + 1);
	}
	else
	{
		if(i < n - 2)
		{
			i++;
			j = i + 1;
			InterchangeSort_DeQuy_7(a, n);//, i + 1, i + 2);
		}
	}
}

int j_inter_8 = 0;
void InterchangeSort_DeQuy_8(int a[], int n)//, int j = 0)
{
	//if(n == 1)
		//return;

	if(j_inter_8 < n - 1)
	{
		if(a[j_inter_8] > a[n - 1])
		{
			swap(a[j_inter_8], a[n - 1]);
		}
		j_inter_8++;
		InterchangeSort_DeQuy_8(a, n);//, j + 1);
	}
	else
	{
		if(n > 2)
		{
			j_inter_8 = 0;
			InterchangeSort_DeQuy_8(a, n - 1);//, 0);
		}
	}
}


void InterchangeSort_DeQuy_9(int a[], int n)//, int i = 0, int j = 1)
{
	static int i_inter_9 = 0;
	static int j_inter_9 = 1;

	//if(i == n - 1)
		//return;

	if(j_inter_9 < n)
	{
		if(a[j_inter_9] < a[i_inter_9])
		{
			swap(a[i_inter_9], a[j_inter_9]);
		}
		j_inter_9++;
		InterchangeSort_DeQuy_9(a, n);//, i, j + 1);
	}
	else
	{
		if(i_inter_9 < n - 2)
		{
			i_inter_9++;
			j_inter_9 = i_inter_9 + 1;
			InterchangeSort_DeQuy_9(a, n);//, i + 1, i + 2);
		}
	}
}


void InterchangeSort_DeQuy_10(int a[], int n)//, int j = 0)
{
	static int j_inter_10 = 0;

	//if(n == 1)
		//return;

	if(j_inter_10 < n - 1)
	{
		if(a[j_inter_10] > a[n - 1])
		{
			swap(a[j_inter_10], a[n - 1]);
		}
		j_inter_10++;
		InterchangeSort_DeQuy_10(a, n);//, j + 1);
	}
	else
	{
		if(n > 2)
		{
			j_inter_10 = 0;
			InterchangeSort_DeQuy_10(a, n - 1);//, 0);
		}
	}
}

// 1 2 3 4 5
void BubbleSort_DeQuy_1(int a[], int n, int i = 0)
{
	//if(i == n - 1)
		//return;

	bool Check = true;
	for(int j = n - 1; j > i; --j)
	{
		// xét a[j] & a[j - 1]
		if(a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			Check = false;
		}
	}

	if(i < n - 2  && Check == false)
		BubbleSort_DeQuy_1(a, n, i + 1);
}

void BubbleSort_DeQuy_2(int a[], int n)
{
	//if(n == 1)
		//return;

	bool Check = true;
	for(int i = 0; i < n - 1; ++i)
	{
		// xét cặp a[i] & a[i + 1]
		if(a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
			Check = false;
		}
	}

	if(n > 2 && Check == false)
		BubbleSort_DeQuy_2(a, n - 1);
}

void XetCacCapSoTrongDoanTuYVeXDeDuaPhanTuNhoNhatVeDau(int a[], int y, int x, bool &Check)
{
	if(y < x)
		return;

	if(a[y - 1] > a[y])
	{
		swap(a[y - 1], a[y]);
		Check = false;
	}

	XetCacCapSoTrongDoanTuYVeXDeDuaPhanTuNhoNhatVeDau(a, y - 1, x, Check);
}

void BubbleSort_DeQuy_3(int a[], int n, int i = 0)
{
	//if(i == n - 1)
		//return;

	bool Check = true;
	XetCacCapSoTrongDoanTuYVeXDeDuaPhanTuNhoNhatVeDau(a, n - 1, i + 1, Check);

	if(i < n - 2 && Check == false)
		BubbleSort_DeQuy_3(a, n, i + 1);
}

void XetCacCapSoTrongDoanTuXDenYDeDuaPhanTuLonNhatVeCuoi(int a[], int x, int y, bool &Check)
{
	if(x > y)
		return;

	if(a[x] > a[x + 1])
	{
		swap(a[x], a[x + 1]);
		Check = false;
	}

	XetCacCapSoTrongDoanTuXDenYDeDuaPhanTuLonNhatVeCuoi(a, x + 1, y, Check);
}

void BubbleSort_DeQuy_4(int a[], int n)
{
	//if(n == 1)
		//return;

	bool Check = true;
	XetCacCapSoTrongDoanTuXDenYDeDuaPhanTuLonNhatVeCuoi(a, 0, n - 2, Check);

	if(n > 2 && Check == false)
		BubbleSort_DeQuy_4(a, n - 1);
}

void BubbleSort_DeQuy_5(int a[], int n, int i = 0, int j = -1, bool Check = true)
{
	if(j == -1)
		j = n - 1;

	if(j > i)
	{
		// xét a[j] & a[j - 1]
		if(a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			Check = false;
		}
		BubbleSort_DeQuy_5(a, n, i, j - 1, Check);
	}
	else
	{
		if(i < n - 2  && Check == false)
			BubbleSort_DeQuy_5(a, n, i + 1, n - 1, true);
	}
}

void BubbleSort_DeQuy_5_Ver2(int a[], int n, int j, int i = 0, bool Check = true)
{
	if(j > i)
	{
		// xét a[j] & a[j - 1]
		if(a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			Check = false;
		}
		BubbleSort_DeQuy_5_Ver2(a, n, j - 1, i, Check);
	}
	else
	{
		if(i < n - 2  && Check == false)
			BubbleSort_DeQuy_5_Ver2(a, n, n - 1, i + 1, true);
	}
}

//int dem = 0;
void BubbleSort_DeQuy_6(int a[], int n, int i = 0, bool Check = true)
{
	if(i < n - 1)
	{
		// xét cặp a[i] & a[i + 1]
		if(a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
			Check = false;
		}
		BubbleSort_DeQuy_6(a, n, i + 1, Check);
	}
	else
	{
		//dem++;

		if(n > 2 && Check == false)
			BubbleSort_DeQuy_6(a, n - 1, 0, true);
	}
}

int i_bubble_7 = 0;
int j_bubble_7 = -1;
bool Check_bubble_7 = true;
void BubbleSort_DeQuy_7(int a[], int n)//, int i = 0, int j = -1, bool Check = true)
{
	if(j_bubble_7 == -1)
		j_bubble_7 = n - 1;

	if(j_bubble_7 > i_bubble_7)
	{
		// xét a[j] & a[j - 1]
		if(a[j_bubble_7 - 1] > a[j_bubble_7])
		{
			swap(a[j_bubble_7 - 1], a[j_bubble_7]);
			Check_bubble_7 = false;
		}
		j_bubble_7--;
		BubbleSort_DeQuy_7(a, n);//, i, j - 1, Check);
	}
	else
	{
		if(i_bubble_7 < n - 2  && Check_bubble_7 == false)
		{
			i_bubble_7++;
			j_bubble_7 = n - 1;
			Check_bubble_7 = true;
			BubbleSort_DeQuy_7(a, n);//, i + 1, n - 1, true);
		}
	}
}

int i_bubble_8 = 0;
bool Check_bubble_8 = true;
void BubbleSort_DeQuy_8(int a[], int n)//, int i = 0, bool Check = true)
{
	if(i_bubble_8 < n - 1)
	{
		// xét cặp a[i] & a[i + 1]
		if(a[i_bubble_8] > a[i_bubble_8 + 1])
		{
			swap(a[i_bubble_8], a[i_bubble_8 + 1]);
			Check_bubble_8 = false;
		}
		i_bubble_8++;
		BubbleSort_DeQuy_8(a, n);//, i + 1, Check);
	}
	else
	{
		//dem++;

		if(n > 2 && Check_bubble_8 == false)
		{
			i_bubble_8 = 0;
			Check_bubble_8 = true;
			BubbleSort_DeQuy_8(a, n - 1);//, 0, true);
		}
	}
}

void BubbleSort_DeQuy_9(int a[], int n)//, int i = 0, int j = -1, bool Check = true)
{
	static int i_bubble_9 = 0;
	static int j_bubble_9 = -1;
	static bool Check_bubble_9 = true;

	if(j_bubble_9 == -1)
		j_bubble_9 = n - 1;

	if(j_bubble_9 > i_bubble_9)
	{
		// xét a[j] & a[j - 1]
		if(a[j_bubble_9 - 1] > a[j_bubble_9])
		{
			swap(a[j_bubble_9 - 1], a[j_bubble_9]);
			Check_bubble_9 = false;
		}
		j_bubble_9--;
		BubbleSort_DeQuy_9(a, n);//, i, j - 1, Check);
	}
	else
	{
		if(i_bubble_9 < n - 2  && Check_bubble_9 == false)
		{
			i_bubble_9++;
			j_bubble_9 = n - 1;
			Check_bubble_9 = true;
			BubbleSort_DeQuy_9(a, n);//, i + 1, n - 1, true);
		}
	}
}


void BubbleSort_DeQuy_10(int a[], int n)//, int i = 0, bool Check = true)
{
	static int i_bubble_10 = 0;
	static bool Check_bubble_10 = true;

	if(i_bubble_10 < n - 1)
	{
		// xét cặp a[i] & a[i + 1]
		if(a[i_bubble_10] > a[i_bubble_10 + 1])
		{
			swap(a[i_bubble_10], a[i_bubble_10 + 1]);
			Check_bubble_10 = false;
		}
		i_bubble_10++;
		BubbleSort_DeQuy_10(a, n);//, i + 1, Check);
	}
	else
	{
		//dem++;

		if(n > 2 && Check_bubble_10 == false)
		{
			i_bubble_10 = 0;
			Check_bubble_10 = true;
			BubbleSort_DeQuy_10(a, n - 1);//, 0, true);
		}
	}
}

void ShakerSort_DeQuy_1(int a[], int n, int left, int right, int k = -1) 
{
	if(left >= right)
		return;

	int temp_k = k; // Biến phụ để lưu giá trị k vào mục đích để kiểm tra xem sau vòng lặp đầu tiên thì giá trị k có bị thay đổi không? Nếu không thay đổi thì nghĩa là không có cặp số nào hoán vị => thuật toán có thể kết thúc ngay mà không cần phải xét đến vòng lặp thứ 2

	// Lần duyệt đầu tiên từ biên phải về biên trái
	for(int i = right; i > left; --i)
	{
		// a[i] & a[i - 1]
		if(a[i] < a[i - 1])
		{
			swap(a[i], a[i - 1]);
			k = i - 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được nổi bọt lên
		}
	}

	// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
	if(temp_k == k)
		return;

	left = k + 1; // Cập nhật lại biên trái

	// Lần duyệt tiếp theo sẽ là từ biên trái về biên phải
	for(int i = left; i < right; ++i)
	{
		// a[i] & a[i + 1]
		if(a[i + 1] < a[i])
		{
			swap(a[i + 1], a[i]);
			k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
		}
	}

	right = k - 1; // Cập nhật lại biên phải

	ShakerSort_DeQuy_1(a, n, left, right, k);
}

void ShakerSort_DeQuy_2(int a[], int n, int left, int right, int k, int temp_k, int i, int j) 
{
	if(i > left)
	{
		// a[i] & a[i - 1]
		if(a[i] < a[i - 1])
		{
			swap(a[i], a[i - 1]);
			k = i - 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được nổi bọt lên
		}

		if(i == left + 1)
		{
			// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
			if(temp_k == k)
				return;

			left = k + 1; // Cập nhật lại biên trái

			j = left;
		}

		ShakerSort_DeQuy_2(a, n, left, right, k, temp_k, i - 1, j);
	}
	else
	{
		if(j < right)
		{
			// a[i] & a[i + 1]
			if(a[j + 1] < a[j])
			{
				swap(a[j + 1], a[j]);
				k = j + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
			}
			ShakerSort_DeQuy_2(a, n, left, right, k, temp_k, i, j + 1);
		}
		else
		{
			right = k - 1; // Cập nhật lại biên phải
			temp_k = k;
			i = right;
			
			if(left < right)
			{
				ShakerSort_DeQuy_2(a, n, left, right, k, temp_k, i, j);
			}
		}
	}
}

void ShakerSort_DeQuy_3(int a[], int n)//, int left, int right, int k, int temp_k, int i, int j) 
{
	static int left = 0;
	static int right = n - 1;
	static int k = -1;
	static int temp_k = k;
	static int i = right;
	static int j = left;

	if(i > left)
	{
		// a[i] & a[i - 1]
		if(a[i] < a[i - 1])
		{
			swap(a[i], a[i - 1]);
			k = i - 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được nổi bọt lên
		}

		if(i == left + 1)
		{
			// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
			if(temp_k == k)
				return;

			left = k + 1; // Cập nhật lại biên trái

			j = left;
		}

		i--;
		ShakerSort_DeQuy_3(a, n);//, left, right, k, temp_k, i - 1, j);
	}
	else
	{
		if(j < right)
		{
			// a[i] & a[i + 1]
			if(a[j + 1] < a[j])
			{
				swap(a[j + 1], a[j]);
				k = j + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
			}

			j++;
			ShakerSort_DeQuy_3(a, n);//, left, right, k, temp_k, i, j + 1);
		}
		else
		{
			right = k - 1; // Cập nhật lại biên phải
			temp_k = k;
			i = right;
			
			if(left < right)
			{
				ShakerSort_DeQuy_3(a, n);//, left, right, k, temp_k, i, j);
			}
		}
	}
}

int main()
{
	int a[] = {5, 2, 1, 4, 3, 9, 7, 8, 10, 6, 15, 20, 16, 13, 11, 12, 19, 18, 17, 14};
	//int a[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a) / sizeof(a[0]);

	/*int a[10000];
	int n = 10000;
	for(int i = n - 1; i >= 0; --i)
		a[i] = i;*/

	/*int a[2000];
	int n = 2000;
	for(int i = 0; i < n; ++i)
		a[i] = i + 1;*/

	
	/*clock_t start1 = clock();
	XuatMang_DeQuy_2(a, n);
	clock_t end1 = clock();

	clock_t start2 = clock();
	XuatMang_DeQuy_3(a, n);
	clock_t end2 = clock();

	clock_t start3 = clock();
	XuatMang_DeQuyDuoi(a, n);
	clock_t end3 = clock();

	cout << "\nXuatMang_DeQuy_2 chay mat: " << (double)(end1 - start1) / CLOCKS_PER_SEC;
	cout << "\nXuatMang_DeQuy_3 chay mat: " << (double)(end2 - start2) / CLOCKS_PER_SEC;
	cout << "\nXuatMang_DeQuyDuoi chay mat: " << (double)(end3 - start3) / CLOCKS_PER_SEC;*/

	//XuatMang_DeQuy_1(a, n);
	//XuatMang_DeQuy_2(a, n);
	//XuatMang_DeQuy_3(a, n);

	//SelectionSort_DeQuy_1(a, n);
	//SelectionSort_DeQuy_2(a, n);
	//SelectionSort_DeQuy_3(a, n);
	//SelectionSort_DeQuy_4(a, n);
	//SelectionSort_DeQuy_5(a, n);
	//SelectionSort_DeQuy_6(a, n);
	//SelectionSort_DeQuy_7(a, n);
	//SelectionSort_DeQuy_8(a, n);
	//SelectionSort_DeQuy_9(a, n);
	//SelectionSort_DeQuy_10(a, n);
	//InterchangeSort_DeQuy_1(a, n);
	//InterchangeSort_DeQuy_2(a, n);
	//InterchangeSort_DeQuy_3(a, n);
	//InterchangeSort_DeQuy_4(a, n);
	//InterchangeSort_DeQuy_5(a, n);
	//InterchangeSort_DeQuy_6(a, n);
	//InterchangeSort_DeQuy_7(a, n);
	//InterchangeSort_DeQuy_8(a, n);
	//InterchangeSort_DeQuy_9(a, n);
	//InterchangeSort_DeQuy_10(a, n);
	//BubbleSort_DeQuy_1(a, n);
	//BubbleSort_DeQuy_2(a, n);
	//BubbleSort_DeQuy_3(a, n);
	//BubbleSort_DeQuy_4(a, n);
	//BubbleSort_DeQuy_5(a, n);
	//BubbleSort_DeQuy_5_Ver2(a, n, n - 1);
	//BubbleSort_DeQuy_6(a, n);
	//BubbleSort_DeQuy_7(a, n);
	//BubbleSort_DeQuy_8(a, n);
	//BubbleSort_DeQuy_9(a, n);
	//BubbleSort_DeQuy_10(a, n);
	//ShakerSort_DeQuy_1(a, n, 0, n - 1);
	ShakerSort_DeQuy_2(a, n, 0, n - 1, -1, -1, n - 1, 0);
	//ShakerSort_DeQuy_3(a, n);

	XuatMang_DeQuyDuoi(a, n);

	//cout << "\n\ndem = " << dem;

	system("pause");
	return 0;
}