#include <iostream>
#include <string>
#include <time.h>
//#include <Sort.h>
using namespace std;

struct HocSinh
{
	string Ten;
	int Diem;
	int index;
};
typedef struct HocSinh HOCSINH;

struct HocSinh_2
{
	string Ten;
	int Diem;
};
typedef struct HocSinh_2 HOCSINH_2;

void PhatSinhDanhSachHocSinh(HOCSINH *&a, int &n)
{
	cout << "\nNhap vao so luong hoc sinh: ";
	cin >> n;

	a = new HOCSINH[n];

	// Duyệt qua từng học sinh để phát sinh dữ liệu tương ứng
	srand(time(0));
	for(int i = 0; i < n; ++i)
	{
		a[i].index = i; // Lưu vị trí index thuở ban đầu lúc mới được tạo ra để sau này chúng ta sẽ dùng nó để làm cho thuật toán sắp xếp có tính ổn định

		// [a, b] => a + rand() % (b - a + 1)
		a[i].Diem = rand() % 11; // Điểm số của từng học sinh được phát sinh trong đoạn từ 0 đến 10

		if((i + 1) % 26 == 0)
		{
			for(int j = 1; j <= (i + 1) / 26 - 1; ++j)
				a[i].Ten += 'A';

			a[i].Ten += 'Z';
		}
		else
		{
			int vetraiTen = (i + 1) / 26;
			int vePhaiTen = (i + 1) % 26;

			for(int j = 1; j <= vetraiTen; ++j)
				a[i].Ten += 'A';

			a[i].Ten += char(64 + vePhaiTen);
		}

		
	}
}

void XuatDanhSachHocSinh(HOCSINH *a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << a[i].Ten << "\t" << a[i].Diem << endl;
	}
}

void HoanVi(HOCSINH &a, HOCSINH &b)
{
	HOCSINH temp = a;
	a = b;
	b = temp;
}

void SelectionSort(HOCSINH *a, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		int vitriMax = i;

		for(int j = i + 1; j < n; ++j)
		{
			if(a[j].Diem > a[vitriMax].Diem)
			{
				vitriMax = j;
			}
		}
		//HoanVi(a[i], a[vitriMax]);
		// how to swap 2 item in c/c++/c#/java/python ...
		swap(a[i], a[vitriMax]); // Đây là hàm có sẵn mà C++ cung cấp cho chúng ta
	}
}

/*
a < b => -1
a == b => 0
a > b => 1
*/
int SoSanh2Ten(string a, string b)
{
	int length_a = a.length();
	int length_b = b.length();

	if(length_a > length_b)
		return 1;
	else if(length_a < length_b)
		return -1;

	// Xuống đây tức là 2 length bằng nhau thì xét ký tự ngoài cùng bên phải

	if(a[length_a - 1] > b[length_b - 1])
		return 1;
	else if(a[length_a - 1] < b[length_b - 1])
		return -1;

	// Xuống đây tức là 2 ký tự ngoài cùng bằng nhau luôn tức là 2 chuỗi giống nhau hoàn toàn
	return 0;
}

void SelectionSort_CaiTienDoOnDinh(HOCSINH *a, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		int vitriMax = i;

		for(int j = i + 1; j < n; ++j)
		{
			if(a[j].Diem > a[vitriMax].Diem)
			{
				vitriMax = j;
			}
			// Đây là điều mình làm thêm để cho thuật toán có tính ổn định với những học sinh có điểm bằng nhau thì sẽ đối chiếu theo chỉ số index để biết thằng nào đứng trước, thằng nào đứng sau
			else if(a[j].Diem == a[vitriMax].Diem) 
			{
				if(a[j].index < a[vitriMax].index)
				//if(SoSanh2Ten(a[j].Ten, a[vitriMax].Ten) < 0)
				{
					vitriMax = j;
				}
			}
		}
		swap(a[i], a[vitriMax]); // Đây là hàm có sẵn mà C++ cung cấp cho chúng ta
	}
}

void InterchangeSort(HOCSINH *a, int n) 
{
	for(int i = 0; i < n - 1; ++i) // Xét qua các phần tử từ đầu đến áp cuối
	{
		for(int j = i + 1; j < n; ++j) // Với mỗi phần tử thì xét tất cả các phần tử đằng sau nó
		{
			if(a[j].Diem > a[i].Diem) // Nếu phần tử nào nhỏ hơn => đổi chỗ phần tử nhỏ hơn đó về vị trí đầu dãy (i)
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void InterchangeSort_CaiTienDoOnDinh(HOCSINH *a, int n) 
{
	for(int i = 0; i < n - 1; ++i) // Xét qua các phần tử từ đầu đến áp cuối
	{
		for(int j = i + 1; j < n; ++j) // Với mỗi phần tử thì xét tất cả các phần tử đằng sau nó
		{
			if(a[j].Diem > a[i].Diem) // Nếu phần tử nào nhỏ hơn => đổi chỗ phần tử nhỏ hơn đó về vị trí đầu dãy (i)
			{
				swap(a[i], a[j]);
			}
			// Đây là điều mình làm thêm để cho thuật toán có tính ổn định với những học sinh có điểm bằng nhau thì sẽ đối chiếu theo chỉ số index để biết thằng nào đứng trước, thằng nào đứng sau
			else if(a[j].Diem == a[i].Diem) 
			{
				if(a[j].index < a[i].index)
				//if(SoSanh2Ten(a[j].Ten, a[i].Ten) < 0)
				{
					swap(a[i], a[j]);
				}
			}
		}
	}
}

void BubbleSort(HOCSINH_2 *a, int n) 
{
	for(int i = 1; i < n; ++i)
	{
		bool Check = true; 
		for(int j = n - 1; j >= i; --j)
		{
			if(a[j - 1].Diem < a[j].Diem)
			{
				swap(a[j], a[j - 1]);
				Check = false; // cập nhật lại cờ hiệu
			}
		}
		if(Check == true)
		{
			break;
		}
	}
}

void ShakerSort(HOCSINH *a, int n, bool sapgiamdan = true) 
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
			//if(a[i].Diem > a[i - 1].Diem == sapgiamdan) // sapgiamdan == false => a[i].Diem <= a[i - 1].Diem
			//if((sapgiamdan == true && a[i].Diem > a[i - 1].Diem) || (sapgiamdan == false && a[i].Diem < a[i - 1].Diem))
			if(sapgiamdan == true ? a[i].Diem > a[i - 1].Diem : a[i].Diem < a[i - 1].Diem)
			//if(a[i].Diem > a[i - 1].Diem == sapgiamdan && a[i].Diem != a[i - 1].Diem)
			
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
			//if(a[i + 1].Diem > a[i].Diem == sapgiamdan)
			//if((sapgiamdan == true && a[i + 1].Diem > a[i].Diem) || (sapgiamdan == false && a[i + 1].Diem < a[i].Diem))
			if(sapgiamdan == true ? a[i + 1].Diem > a[i].Diem : a[i + 1].Diem < a[i].Diem)
			//if(a[i + 1].Diem > a[i].Diem == sapgiamdan && a[i + 1].Diem != a[i].Diem)
			{
				swap(a[i + 1], a[i]);
				k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
			}
		}
		right = k - 1; // Cập nhật lại biên phải
	}
}

bool SoSanhLonHon(int a, int b)
{
	return a > b;
}

bool SoSanhNhoHon(int a, int b)
{
	return a < b;
}

void ShakerSort_FunctionPointer(HOCSINH *a, int n, bool (*SoSanh)(int, int)) 
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
			//if(a[i].Diem > a[i - 1].Diem == sapgiamdan) // sapgiamdan == false => a[i].Diem <= a[i - 1].Diem
			//if((sapgiamdan == true && a[i].Diem > a[i - 1].Diem) || (sapgiamdan == false && a[i].Diem < a[i - 1].Diem))
			//if(sapgiamdan == true ? a[i].Diem > a[i - 1].Diem : a[i].Diem < a[i - 1].Diem)
			if(SoSanh(a[i].Diem, a[i - 1].Diem))
			//if(a[i].Diem > a[i - 1].Diem == sapgiamdan && a[i].Diem != a[i - 1].Diem)
			
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
			//if(a[i + 1].Diem > a[i].Diem == sapgiamdan)
			//if((sapgiamdan == true && a[i + 1].Diem > a[i].Diem) || (sapgiamdan == false && a[i + 1].Diem < a[i].Diem))
			//if(sapgiamdan == true ? a[i + 1].Diem > a[i].Diem : a[i + 1].Diem < a[i].Diem)
			//if(a[i + 1].Diem > a[i].Diem == sapgiamdan && a[i + 1].Diem != a[i].Diem)
			if(SoSanh(a[i + 1].Diem, a[i].Diem))
			{
				swap(a[i + 1], a[i]);
				k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
			}
		}
		right = k - 1; // Cập nhật lại biên phải
	}
}


bool operator >(HOCSINH a, HOCSINH b)
{
	return a.Diem > b.Diem;
}

bool operator <(HOCSINH a, HOCSINH b)
{
	return a.Diem < b.Diem;
}

int main()
{
	/*string a = "AA";
	string b = "AA";

	int kq = SoSanh2Ten(a, b);

	if(kq > 0)
		cout << "a > b";
	else if(kq < 0)
		cout << "a < b";
	else
		cout << "a = b";*/

	HOCSINH *a;
	int n;

	PhatSinhDanhSachHocSinh(a, n);
	XuatDanhSachHocSinh(a, n);

	
	cout << "\n\nSap xep danh sach giam dan theo diem\n";
	/*
	HOCSINH_2 *b = new HOCSINH_2[n];

	for(int i = 0; i < n; ++i)
	{
		b[i].Ten = a[i].Ten;
		b[i].Diem = a[i].Diem;
	}
	
	clock_t start = clock();
	BubbleSort(b, n);
	clock_t end = clock();
	double thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nBubble Sort chay mat: " << thoigianchay;

	for(int i = 0; i < n; ++i)
	{
		b[i].Ten = a[i].Ten;
		b[i].Diem = a[i].Diem;
	}

	start = clock();
	ShakerSort(b, n);
	end = clock();
	thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nShaker Sort chay mat: " << thoigianchay;

	HOCSINH *c = new HOCSINH[n];

	for(int i = 0; i < n; ++i)
	{
		c[i] = a[i];
	}

	start = clock();
	SelectionSort_CaiTienDoOnDinh(c, n);
	end = clock();
	thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nSelectionSort_CaiTienDoOnDinh chay mat: " << thoigianchay;

	for(int i = 0; i < n; ++i)
	{
		c[i] = a[i];
	}

	start = clock();
	InterchangeSort_CaiTienDoOnDinh(c, n);
	end = clock();
	thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nInterchangeSort_CaiTienDoOnDinh chay mat: " << thoigianchay;

	*/

	//SelectionSort(a, n);
	//SelectionSort_CaiTienDoOnDinh(a, n);
	//BubbleSort(a, n, false);
	//InterchangeSort(a, n);
	//InterchangeSort_CaiTienDoOnDinh(a, n);
	ShakerSort(a, n, false);
	//ShakerSort_FunctionPointer(a, n, SoSanhNhoHon);
	XuatDanhSachHocSinh(a, n);

	//delete[] a;
	//delete[] b;
	//delete[] c;

	system("pause");
	return 0;
}