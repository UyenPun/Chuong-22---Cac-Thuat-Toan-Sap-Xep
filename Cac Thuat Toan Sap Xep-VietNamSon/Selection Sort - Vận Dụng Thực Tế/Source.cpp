#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include "Sort.h"
//#include <Sort.h>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

void NhapChuoi(char [], char [], int);
void KhoangCach(int); // n là số khoảng cách
int MaxHoTen = 0, MaxMaSo = 0;

struct SinhVien
{
	char HoTen[31];
	char MaSo[31];
	float DiemToan, DiemLy, DiemHoa;
};
typedef struct SinhVien SINHVIEN;

int DoDaiHoTenLonNhat(SINHVIEN sv[], int n)
{
	int Max = strlen(sv[0].HoTen);

	for(int i = 1; i < n; ++i)
	{
		int DoDai = strlen(sv[i].HoTen);

		if(DoDai > Max)
			Max = DoDai;
	}
	return Max;
}

int DoDaiMaSoLonNhat(SINHVIEN sv[], int n)
{
	int Max = strlen(sv[0].MaSo);

	for(int i = 1; i < n; ++i)
	{
		int DoDai = strlen(sv[i].MaSo);

		if(DoDai > Max)
			Max = DoDai;
	}
	return Max;
}

char arr[6][30] = {"Ho Ten", "Ma So", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem Trung Binh"};
int khoangcach[6] = {10, 10, 10, 10, 10, 10};

void NhapSinhVien(SINHVIEN &sv)
{
	NhapChuoi(sv.HoTen, "Ho Ten", sizeof(sv.HoTen));

	int DoDaiHoTen = strlen(sv.HoTen);

	if(DoDaiHoTen > MaxHoTen)
		MaxHoTen = DoDaiHoTen;

	NhapChuoi(sv.MaSo, "Ma So", sizeof(sv.MaSo));

	int DoDaiMaSo = strlen(sv.MaSo);

	if(DoDaiMaSo > MaxMaSo)
		MaxMaSo = DoDaiMaSo;

	do{
		printf("\nNhap diem toan: ");
		scanf("%f", &sv.DiemToan);

		if(sv.DiemToan < 0 || sv.DiemToan > 10)
			printf("\nDiem phai nam trong doan [0, 10]. Xin kiem tra lai!");
	}while(sv.DiemToan < 0 || sv.DiemToan > 10);

	do{
		printf("\nNhap diem ly: ");
		scanf("%f", &sv.DiemLy);

		if(sv.DiemLy < 0 || sv.DiemLy > 10)
			printf("\nDiem phai nam trong doan [0, 10]. Xin kiem tra lai!");
	}while(sv.DiemLy < 0 || sv.DiemLy > 10);

	do{
		printf("\nNhap diem hoa: ");
		scanf("%f", &sv.DiemHoa);

		if(sv.DiemHoa < 0 || sv.DiemHoa > 10)
			printf("\nDiem phai nam trong doan [0, 10]. Xin kiem tra lai!");
	}while(sv.DiemHoa < 0 || sv.DiemHoa > 10);
}

float TinhDiemTrungBinh(SINHVIEN sv)
{
	return (sv.DiemToan + sv.DiemLy + sv.DiemHoa) / 3;
}

void XuatSinhVien(SINHVIEN sv)
{
	printf("\n%s", sv.HoTen);
	KhoangCach(khoangcach[0] - (strlen(sv.HoTen) - strlen(arr[0])));
	printf("%s", sv.MaSo);
	KhoangCach(khoangcach[1] - (strlen(sv.MaSo) - strlen(arr[1])));
	printf("%.2f", sv.DiemToan);
	KhoangCach(khoangcach[2] - (4 - strlen(arr[2])));
	printf("%.2f", sv.DiemLy);
	KhoangCach(khoangcach[3] - (4 - strlen(arr[3])));
	printf("%.2f", sv.DiemHoa);
	KhoangCach(khoangcach[4] - (4 - strlen(arr[4])));
	printf("%.2f", TinhDiemTrungBinh(sv));
}

void NhapDanhSachSinhVien(SINHVIEN *&sv, int &n)
{
	do{
		printf("\nNhap vao so luong cac sinh vien trong lop hoc: ");
		scanf("%d", &n);

		if(n < 0)
			printf("\nSo luong phai >= 0. Xin kiem tra lai!");
	}while(n < 0);

	sv = new SINHVIEN[n];

	// Nhập danh sách các sinh viên trong lớp
	for(int i = 0; i < n; ++i)
	{
		printf("\n===========> Nhap Thong Tin Sinh Vien Thu %d <===========\n", i + 1);
		NhapSinhVien(sv[i]);
	}
}

// Xuất danh sách các sinh viên trong lớp
void XuatDanhSachSinhVien(SINHVIEN *sv, int n)
{
	// Xuất ra các cột
	for(int i = 0; i < 6; ++i)
	{
		printf("%s", arr[i]);
		KhoangCach(khoangcach[i]);
	}
	
	// Xuất ra từng sinh viên
	for(int i = 0; i < n; ++i)
	{
		XuatSinhVien(sv[i]);
	}
}

//void HoanVi(SINHVIEN &a, SINHVIEN &b)
//{
//	SINHVIEN temp = a;
//	a = b;
//	b = temp;
//}
//
//void SelectionSort(SINHVIEN a[], int n)
//{
//	for(int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Max bắt đầu từ i
//	{
//		int vitriMax = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i
//
//		for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Max
//		{
//			if(TinhDiemTrungBinh(a[j]) > TinhDiemTrungBinh(a[vitriMax])) // Nếu phần tử nào lớn hơn => cập nhật lại vị trí Max
//			{
//				vitriMax = j; // cập nhật lại vị trí Max
//			}
//		}
//		HoanVi(a[i], a[vitriMax]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
//	}
//}


bool operator < (SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) < TinhDiemTrungBinh(b);
}

bool operator <= (SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) <= TinhDiemTrungBinh(b);
}

bool operator > (SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) > TinhDiemTrungBinh(b);
}

bool operator >= (SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) >= TinhDiemTrungBinh(b);
}

bool operator == (SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) == TinhDiemTrungBinh(b);
}

bool operator != (SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) != TinhDiemTrungBinh(b);
}


template <class T>
void HoanVi(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//// saptang là true: tăng - false: giảm
template <class T>
void SelectionSort(T a[], int n, bool saptang = true) 
{
	for(int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Min bắt đầu từ i
	{
		int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i
		
		for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
		{
			if(a[j] < a[vitriMin] == saptang) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
			//if(TinhDiemTrungBinh(a[j]) < TinhDiemTrungBinh(a[vitriMin]) == kieusapxep)
			{
				vitriMin = j; // cập nhật lại vị trí Min
			}
		}
		HoanVi(a[i], a[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
	}
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
			//if(TinhDiemTrungBinh(a[j]) < TinhDiemTrungBinh(a[i]) == kieusapxep)
			{
				HoanVi(a[i], a[j]);
				//swap(a[i], a[j]);
			}
		}
	}
}

void NhapChuoi(char chuoi[], char tengoi[], int size)
{
	printf("\nNhap vao %s (toi da %d ky tu): ", tengoi, size - 1);
	int dem = 0;
	char c;
	while (true)
	{
		c = getch();
		if(c == 13)	// 13 là mã ascii của phím Enter
			break; // thoát khỏi vòng lặp

		else if(c == 8) // 8 là mã ascii của phím BackSpce (xóa) trên bàn phím
		{
			if(dem != 0)
				dem--;

			chuoi[dem] = '\0'; // Xóa ký tự cuối cùng hiện tại
			system("cls"); // xóa toàn bộ màn hình hiện tại đi
			printf("\nNhap vao %s (toi da %d ky tu): ", tengoi, size - 1);
			printf("%s", chuoi);
		}
		else // Khác Enter và Khác BackSpace
		{
			if(dem < size - 1)
			{
				printf("%c", c);
				chuoi[dem] = c;
				dem++;
			}
			else // dem == sizeof(HoTen) - 1
				printf("\nBan khong duoc phep nhap them do da toi ky tu cuoi cung duoc phep. Xac nhan nhap xong nhan phim Enter");
		}
	}
	chuoi[dem] = '\0'; // Kết thúc chuỗi
}

void KhoangCach(int n) // n là số khoảng cách
{
	for(int i = 1; i <= n; ++i)
		printf(" ");
}

void KhoangCachSetw(int n, char *chuoi)
{
	cout << setw(n + strlen(chuoi));
	cout << chuoi;
}

int main()
{
	SINHVIEN *sv;
	int n; // số lượng các sinh viên

	NhapDanhSachSinhVien(sv, n);
	
	khoangcach[0] += MaxHoTen;
	khoangcach[1] += MaxMaSo;

	// Tự test nhé
	//clock_t start = clock();
	//for(int i = 1; i <= 100; ++i)
	//{
	//	//khoangcach[0] += MaxHoTen;
	//	//khoangcach[1] += MaxMaSo;
	//	khoangcach[0] += DoDaiHoTenLonNhat(sv, n);
	//	khoangcach[1] += DoDaiMaSoLonNhat(sv, n);
	//	XuatDanhSachSinhVien(sv, n);
	//}
	//clock_t end = clock();
	//printf("\nChay mat %.2lf", (double)(end - start) / CLOCKS_PER_SEC);

	XuatDanhSachSinhVien(sv, n);
	printf("\n\n===========> SAP XEP GIAM DAN THEO DIEM TRUNG BINH <========\n\n");
	//SelectionSort(sv, n, false);
	InterchangeSort(sv, n, false);
	XuatDanhSachSinhVien(sv, n);

	delete[] sv;

	/*cout << "abc";
	KhoangCachSetw(10, "xyz");

	printf("\n\n");
	printf("abc");
	KhoangCach(10);
	printf("xyz");*/


	/*char hoten[100];
	char maso[100];
	float toan, ly, hoa, trungbinh;

	char arr[6][30] = {"Ho Ten", "Ma So", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem Trung Binh"};

	strcpy(hoten, "Nguyen Viet Nam Son rat la dep thanh lich vo dich vu tru ha ha ha ha ha");
	strcpy(maso, "123456789123456789123456789123456789123456789123456789");
	toan = 7.5;
	ly = 8.5;
	hoa = 9.5;
	trungbinh = (toan + ly + hoa) / 3;

	int khoangcach[6] = {strlen(hoten) + 10, strlen(maso) + 10, 10, 10, 10, 10};

	for(int i = 0; i < 6; ++i)
	{
		printf("%s", arr[i]);
		KhoangCach(khoangcach[i]);
	}

	printf("\n%s", hoten);
	KhoangCach(khoangcach[0] - (strlen(hoten) - strlen(arr[0])));
	printf("%s", maso);
	KhoangCach(khoangcach[1] - (strlen(maso) - strlen(arr[1])));
	printf("%.2f", toan);
	KhoangCach(khoangcach[2] - (4 - strlen(arr[2])));
	printf("%.2f", ly);
	KhoangCach(khoangcach[3] - (4 - strlen(arr[3])));
	printf("%.2f", hoa);
	KhoangCach(khoangcach[4] - (4 - strlen(arr[4])));
	printf("%.2f", trungbinh);*/

	getch();
	return 0;
}