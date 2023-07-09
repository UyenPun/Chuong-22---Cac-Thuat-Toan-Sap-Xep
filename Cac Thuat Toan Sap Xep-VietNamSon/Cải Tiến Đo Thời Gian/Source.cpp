/*
Cải tiến lại Project đo thời gian để chỉ cần chạy trong 1 lần duy nhất sẽ đo được tất cả các tập dữ liệu 
chỉ định (10.000, 50.000, 80.000, 100.000) với các thuật toán chỉ định (Selection Sort, Interchange Sort ...) 
và tạo ra bảng thống kê chi tiết sau cùng giống như thế này:

				Interchange Sort
Tap Du Lieu	Lan Chay 1	Lan Chay 2	Lan Chay 3	Trung Binh
10.000		0.327s		0.329s		0.220s		0.292s
50.000		4.045s		3.749s		3.740s		3.845s
80.000		9.729s		9.485s		9.342s		9.519s
100.000		15.768s		15.333s		14.575s		15.225s

				Selection Sort
Tap Du Lieu	Lan Chay 1	Lan Chay 2	Lan Chay 3	Trung Binh
10.000		0.145s		0.148s		0.145s		0.146s
50.000		3.594s		3.506s		3.580s		3.560s
80.000		10.065s		9.626s		9.618s		9.770s
100.000		14.676s		14.260s		14.637s		14.524s

				Tong Ket
Tap Du Lieu	Interchange Sort	Selection Sort
10.000		0.292s				0.146s
50.000		3.845s				3.560s
80.000		9.519s				9.770s
100.000		15.225s				14.524s
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>      // std::setprecision
using namespace std;

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
		//if(vitriMin != i)
		{
			HoanVi(a[i], a[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
		}
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

void BubbleSort(int *a, int n) 
{
	for(int i = 1; i < n; ++i)
	{
		bool Check = true; 
		for(int j = n - 1; j >= i; --j)
		{
			if(a[j - 1] > a[j])
			{
				HoanVi(a[j], a[j - 1]);
				Check = false; // cập nhật lại cờ hiệu
			}
		}
		if(Check == true)
		{
			break;
		}
	}
}

void ShakerSort(int *a, int n) 
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
			if(a[i] < a[i - 1])
			{
				HoanVi(a[i], a[i - 1]);
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
			if(a[i + 1] < a[i])
			{
				HoanVi(a[i + 1], a[i]);
				k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
			}
		}
		right = k - 1; // Cập nhật lại biên phải
	}
}

// true: Nếu mở được tập tin và đọc dữ liệu thành công
// false: Nếu không mở được tập tin
bool DocDuLieuTuTapTin(string tentaptin, int *&a, int &n)
{
	//FILE *f = fopen(tentaptin, mode);
	ifstream FileIn;
	FileIn.open(tentaptin, ios_base::in);

	if(FileIn != NULL)
	{
		FileIn >> n;

		a = new int[n];

		for(int i = 0; i < n; ++i)
		{
			//fscanf(f, "%d", &a[i]);
			FileIn >> a[i];
		}

		//fclose(f);
		FileIn.close();
		return true;
	}

	//printf("\nKhong tim thay tap tin %s", tentaptin);
	cout << "\nKhong tim thay tap tin " << tentaptin;
	return false;
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

int main()
{
	vector<string> DanhSachCacThuatToanSapXepCanTaoBangThongKe;
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("Interchange Sort");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("Selection Sort");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("Bubble Sort");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("Shaker Sort");
	DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort");
	DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_2");
	DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_3");
	DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_3_Sentinel");
	int size_DanhSachCacThuatToanSapXepCanTaoBangThongKe = DanhSachCacThuatToanSapXepCanTaoBangThongKe.size();

	vector<string> DanhSachCacTapDuLieuCanTaoBangThongKe;
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("10.000.txt");
	DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("50.000.txt");
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("80.000.txt");
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("100.000.txt");
	int size_DanhSachCacTapDuLieuCanTaoBangThongKe = DanhSachCacTapDuLieuCanTaoBangThongKe.size();

	int SoLanChayDoThoiGianVoiMoiTapDuLieu = 3;


	ofstream FileOut;
	FileOut.open("BangThongKeDoThoiGianChayCuaCacThuatToanSapXep.txt", ios_base::out);

	vector<double> MangLuuThoiGianChayTrungBinh;

	for(int i = 0; i < size_DanhSachCacThuatToanSapXepCanTaoBangThongKe; ++i)
	{
		if(i != 0)
			FileOut << "\n\n";

		FileOut << "\t\t\t\t" << DanhSachCacThuatToanSapXepCanTaoBangThongKe[i];
		FileOut << "\nTap Du Lieu";
		for(int m = 1; m <= SoLanChayDoThoiGianVoiMoiTapDuLieu; ++m)
		{
			FileOut << "\t" << ("Lan Chay " + to_string(m));
		}
		FileOut << "\tTrung Binh";

		for(int j = 0; j < size_DanhSachCacTapDuLieuCanTaoBangThongKe; ++j)
		{
			// 10.000.txt => chỉ muốn lấy 10.000??? substr(0, 6)
			// 1.000.000.txt => chỉ muốn lấy 1.000.000??? substr(0, 9)
			FileOut << "\n" << DanhSachCacTapDuLieuCanTaoBangThongKe[j].substr(0, DanhSachCacTapDuLieuCanTaoBangThongKe[j].length() - 4) << "\t\t";

			double TongThoiGianChayCuaTatCaCacLan = 0;

			for(int k = 0; k < SoLanChayDoThoiGianVoiMoiTapDuLieu; ++k)
			{
				int *a;
				int n = 0;
				
				/*int n = 50000;
				int *a = new int[n];
				for(int l = 0; l < n; ++l)
				{
					a[l] = n - l;
				}*/

				bool KiemTraDocDuLieu = DocDuLieuTuTapTin(DanhSachCacTapDuLieuCanTaoBangThongKe[j], a, n);

				if(KiemTraDocDuLieu == true)
				{
					clock_t start = clock();

					if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "Selection Sort")
					{
						SelectionSort(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "Interchange Sort")
					{
						InterchangeSort(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "Bubble Sort")
					{
						BubbleSort(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "Shaker Sort")
					{
						ShakerSort(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort")
					{
						InsertionSort(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_2")
					{
						InsertionSort_2(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_3")
					{
						InsertionSort_3(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_3_Sentinel")
					{
						InsertionSort_3_Sentinel(a, n);
					}

					clock_t end = clock();

					double thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;

					TongThoiGianChayCuaTatCaCacLan += thoigianchay;

					FileOut << fixed << setprecision(3) << thoigianchay << "s\t\t";
				}
				delete[] a;
			}
			double ThoiGianChayTrungBinh = TongThoiGianChayCuaTatCaCacLan / SoLanChayDoThoiGianVoiMoiTapDuLieu;

			FileOut << fixed << setprecision(3) << ThoiGianChayTrungBinh << "s";

			MangLuuThoiGianChayTrungBinh.push_back(ThoiGianChayTrungBinh);
			
		}
	}

	FileOut << "\n\n\t\t\t\tTong Ket";
	FileOut << "\nTap Du Lieu";
	
	for(int i = 0; i < size_DanhSachCacThuatToanSapXepCanTaoBangThongKe; ++i)
	{
		FileOut << "\t" << DanhSachCacThuatToanSapXepCanTaoBangThongKe[i];
	}

	for(int j = 0; j < size_DanhSachCacTapDuLieuCanTaoBangThongKe; ++j)
	{
		FileOut << "\n" << DanhSachCacTapDuLieuCanTaoBangThongKe[j].substr(0, DanhSachCacTapDuLieuCanTaoBangThongKe[j].length() - 4);

		FileOut << "\t\t" << MangLuuThoiGianChayTrungBinh[j] << "s";

		for(int k = 1; k < size_DanhSachCacThuatToanSapXepCanTaoBangThongKe; ++k)
		{
			FileOut << "\t\t" << MangLuuThoiGianChayTrungBinh[j + size_DanhSachCacTapDuLieuCanTaoBangThongKe * k] << "s";
		}
	}


	FileOut.close();
	cout << "Du lieu da duoc ghi thanh cong vao tap tin";

	system("pause");
	return 0;
}