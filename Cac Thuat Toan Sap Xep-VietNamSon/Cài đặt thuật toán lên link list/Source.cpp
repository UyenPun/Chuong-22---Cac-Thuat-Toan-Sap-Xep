#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Bước 1: Khai báo cấu trúc danh sách liên kết đơn các số nguyên
struct Node
{
	int Data;
	struct Node *pNext; // con trỏ pNext để dẫn đường qua Node tiếp theo
	struct Node *pPrev; // con trỏ pPrev để dẫn đường về lại Node trước đó
};
typedef struct Node NODE;

struct List
{
	NODE *pHead, *pTail;
};
typedef struct List LIST;

// Bước 2: Khởi tạo danh sách liên kết đơn các số nguyên
void INit(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node
NODE* GetNode(int x) // x chính là Data trong Node
{
	NODE *p = new NODE;

	if(p == NULL)
		return NULL;

	p->Data = x;
	p->pNext = NULL;
	p->pPrev = NULL;

	return p;
}

// Bước 4: Thêm Node vào đầu/cuối danh sách
void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
		l.pHead->pPrev = NULL;
	}
}

void AddTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
		l.pTail->pNext = NULL;
	}
}

// Bước 5: Hàm nhập xuất danh sách
void InPut(LIST &l, int &n)
{
	//int n;
	cout << "\nNhap vao so luong cac phan tu cua danh sach: ";
	cin >> n;

	srand(time(0));
	for(int i = 1; i <= n; ++i)
	{
		// [a, b] => a + rand() % (b - a + 1)
		// [-100, 100] => -100 + rand() % (100 - -100 + 1) => -100 + rand() % 201;
		
		
		int x = -100 + rand() % 201;
		//int x;
		//cout << "\nNhap vao phan tu thu " << i << ": ";
		//cin >> x;

		NODE *p = GetNode(x);
		AddTail(l, p);
	}
}

void OutPut(LIST l)
{
	//cout << "\nDanh sach la: ";
	for(NODE *p = l.pHead; p != NULL; p = p->pNext)
	//for(NODE *p = l.pTail; p != NULL; p = p->pPrev)
	{
		cout << p->Data << " ";
	}
}

/*
Ví dụ nhập vào danh sách có 5 phần tử lần lượt là 1, 2, 3, 4, 5 thì quy trình như sau:
Đầu tiên gọi hàm DeQuy(1) => DeQuy(2) và nợ lại dòng lệnh xuất ra dữ liệu của Node 1
Gọi hàm DeQuy(2) => DeQuy(3) và nợ lại dòng lệnh xuất ra dữ liệu của Node 2
Gọi hàm DeQuy(3) => DeQuy(4) và nợ lại dòng lệnh xuất ra dữ liệu của Node 3
Gọi hàm DeQuy(4) => DeQuy(5) và nợ lại dòng lệnh xuất ra dữ liệu của Node 4
Gọi hàm DeQuy(5) => DeQuy(NULL) và nợ lại dòng lệnh xuất ra dữ liệu của Node 5
Gọi hàm DeQuy(NULL) => gặp điều kiện dừng => kết thúc
*/
void XuatDanhSach_DeQuy(NODE *Head)
{
	if(Head == NULL)
		return;

	cout << Head->Data << " ";

	XuatDanhSach_DeQuy(Head->pNext);	
}

// Bước 6: Những yêu cầu xử lý trên danh sách
// Thử thách 2: Triển khai thuật toán Selection Sort đã được học lên cấu trúc danh sách liên kết đơn các số nguyên

void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(LIST l, bool saptang = true)
{
  //for(int i = 0; i < n - 1; ++i)
	for(NODE *i = l.pHead; i != l.pTail; i = i->pNext)
	{
	  //int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i
		NODE *Min = i;

	  //for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
		for(NODE *j = i->pNext; j != NULL; j = j->pNext)
		{
		  //if(a[j] < a[vitriMin]) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
			if(saptang == true ? j->Data < Min->Data : j->Data > Min->Data)
			{
			  //vitriMin = j; // cập nhật lại vị trí Min
				Min = j;
			}
		}
	  //HoanVi(a[i], a[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
		HoanVi(i->Data, Min->Data);
	}
}

/*
// Cách viết ngắn gọn nhất của Interchange Sort dùng trong phòng thi khi cần nhanh chóng giải quyết vấn đề mà không cần quan tâm đến hiệu suất hay khả năng mở rộng
void InterchangeSort(LIST l)
{
	for(NODE *i = l.pHead; i != l.pTail; i = i->pNext)
		for(NODE *j = i->pNext; j != NULL; j = j->pNext)
			if(j->Data < i->Data)
				swap(i->Data, j->Data);
}*/

void InterchangeSort(LIST l, bool saptang = true)
{
  //for(int i = 0; i < n - 1; ++i)
	for(NODE *i = l.pHead; i != l.pTail; i = i->pNext)
	{
	  //for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
		for(NODE *j = i->pNext; j != NULL; j = j->pNext)
		{
		  //if(a[j] < a[i]) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
			if(saptang == true ? j->Data < i->Data : j->Data > i->Data)
			{
				//HoanVi(a[i], a[j]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
				HoanVi(i->Data, j->Data);
			}
		}
	}
}

void InterchangeSort_DeQuy_1(NODE *Head)
{
	if(Head == NULL)
		return;

	for(NODE *j = Head->pNext; j != NULL; j = j->pNext)
	{
		if(j->Data < Head->Data)
		{
			HoanVi(Head->Data, j->Data);
		}
	}

	InterchangeSort_DeQuy_1(Head->pNext);
}

void InterchangeSort_DeQuy_2(NODE *Head, NODE *j)
{
	if(Head == NULL)
		return;

	if(j != NULL)
	{
		if(j->Data < Head->Data)
		{
			HoanVi(Head->Data, j->Data);
		}
		InterchangeSort_DeQuy_2(Head, j->pNext);
	}
	else
	{
		InterchangeSort_DeQuy_2(Head->pNext, Head->pNext);
	}
}

void InterchangeSort_DeQuy_3(NODE *Head)
{
	static NODE *j = Head;

	if(Head == NULL)
		return;

	if(j != NULL)
	{
		if(j->Data < Head->Data)
		{
			HoanVi(Head->Data, j->Data);
		}
		j = j->pNext;
		InterchangeSort_DeQuy_3(Head);//, j->pNext);
	}
	else
	{
		j = Head->pNext;
		InterchangeSort_DeQuy_3(Head->pNext);//, Head->pNext);
	}
}

void SelectionSort_DeQuy_1(NODE *Head)
{
	if(Head == NULL)
		return;

	NODE *Min = Head;
	for(NODE *j = Head->pNext; j != NULL; j = j->pNext)
	{
		if(j->Data < Min->Data)
		{
			Min = j;
		}
	}
	if(Min != Head)
		HoanVi(Head->Data, Min->Data);

	SelectionSort_DeQuy_1(Head->pNext);
}

void SelectionSort_DeQuy_2(NODE *Head, NODE *j, NODE *Min)
{
	if(Head == NULL)
		return;

	if(j != NULL)
	{
		if(j->Data < Min->Data)
		{
			Min = j;
		}
		SelectionSort_DeQuy_2(Head, j->pNext, Min);
	}
	else
	{
		HoanVi(Min->Data, Head->Data);
		SelectionSort_DeQuy_2(Head->pNext, Head->pNext, Head->pNext);
	}
}

// Hàm 3 này là chuyển thể lại y chang từ hàm 2 tức là khi Head = A thì j sẽ xét từ A đến E tức là sẽ xét 1 lần trùng lặp chính Head. Chấp nhận làm như vậy để không bị lỗi
void SelectionSort_DeQuy_3(NODE *Head)//, NODE *j, NODE *Min)
{
	static NODE *j = Head;
	static NODE *Min = Head;

	if(Head == NULL)
		return;

	if(j != NULL)
	{
		if(j->Data < Min->Data)
		{
			Min = j;
		}
		j = j->pNext;
		SelectionSort_DeQuy_3(Head);//, j->pNext, Min);
	}
	else
	{
		HoanVi(Min->Data, Head->Data);
		j = Head->pNext;
		Min = Head->pNext;
		SelectionSort_DeQuy_3(Head->pNext);//, Head->pNext, Head->pNext);
	}
}

// Hàm số 4 này là cải tiến lại từ hàm số 3, khi Head = A thì J không bắt đầu từ A mà sẽ bắt đầu từ B cho đến cuối => đúng chuẩn y như nếu chúng ta làm bằng vòng lặp mà vẫn yên tâm không sợ bị lỗi
void SelectionSort_DeQuy_4(NODE *Head)//, NODE *j, NODE *Min)
{
	if(Head == NULL)
		return;

	static NODE *j = Head;
	static NODE *Min = Head;

	j = j->pNext;

	if(j != NULL)
	{
		if(j->Data < Min->Data)
		{
			Min = j;
		}
		//j = j->pNext;
		SelectionSort_DeQuy_4(Head);//, j->pNext, Min);
	}
	else
	{
		HoanVi(Min->Data, Head->Data);
		j = Head->pNext;
		Min = Head->pNext;
		SelectionSort_DeQuy_4(Head->pNext);//, Head->pNext, Head->pNext);
	}
}

// Đi theo đúng tư tưởng của thuật toán Bubble Sort theo chiều từ trái qua phải nhưng phải có xác định được giá trị số lượng phần tử mà danh sách liên kết đang chứa
void BubbleSort(LIST l, int n)
{
	// Nếu chạy theo chiều từ trái qua phải
	for(int i = n - 2; i >= 0; --i)
	{
		bool Check = true; // cờ hiệu để kiểm tra xem trong 1 lần so sánh các cặp thì có sự đổi chỗ nào không? Nếu không có thì thuật toán có thể kết thúc mà không cần xét qua các lần chạy tiếp theo
		NODE *a = l.pHead;
		for(int j = 0; j <= i; ++j)
		{
			NODE *b = a->pNext;

			if(a->Data > b->Data)
			{
				HoanVi(a->Data, b->Data);
				Check = false; // cập nhật lại cờ hiệu
			}
			a = b; // Cuối cùng của 1 lần lặp thì cho con trỏ Node a nhảy đến địa chỉ của con trỏ Node b để xét tiếp cặp phần tử kế cận
		}
		// Sau quá trình xét các cặp thì ta đi kiểm tra cờ hiệu để biết được có ít nhất 1 cặp số nào đã đổi chỗ hay không?
		if(Check == true) // tức là không có trường hợp cặp số nào đổi chỗ hết => thuật toán dừng lại tại đây
		{
			break; // thoát khỏi vòng lặp for i (cha)
		}
	}
	

	// Nếu chạy theo chiều từ phải qua trái
	/*for(int i = n - 2; i >= 0; --i)
	{
		bool Check = true; // cờ hiệu để kiểm tra xem trong 1 lần so sánh các cặp thì có sự đổi chỗ nào không? Nếu không có thì thuật toán có thể kết thúc mà không cần xét qua các lần chạy tiếp theo
		NODE *b = l.pTail;
		for(int j = 0; j <= i; ++j)
		{
			NODE *a = b->pPrev;
			if(a->Data > b->Data)
			{
				HoanVi(a->Data, b->Data);
				Check = false; // cập nhật lại cờ hiệu
			}
			b = a;
		}

		// Sau quá trình xét các cặp thì ta đi kiểm tra cờ hiệu để biết được có ít nhất 1 cặp số nào đã đổi chỗ hay không?
		if(Check == true) // tức là không có trường hợp cặp số nào đổi chỗ hết => thuật toán dừng lại tại đây
		{
			break; // thoát khỏi vòng lặp for i (cha)
		}
	}*/
}

// Đi theo đúng tư tưởng của thuật toán Bubble Sort theo chiều từ trái qua phải nhưng phải có xác định được giá trị số lượng phần tử mà danh sách liên kết đang chứa
void BubbleSort_DeQuy_1(NODE *Head, int n, int i)
{
	// Nếu chạy theo chiều từ trái qua phải
	bool Check = true; // cờ hiệu để kiểm tra xem trong 1 lần so sánh các cặp thì có sự đổi chỗ nào không? Nếu không có thì thuật toán có thể kết thúc mà không cần xét qua các lần chạy tiếp theo
	NODE *a = Head;
	for(int j = 0; j <= i; ++j)
	{
		NODE *b = a->pNext;

		if(a->Data > b->Data)
		{
			HoanVi(a->Data, b->Data);
			Check = false; // cập nhật lại cờ hiệu
		}
		a = b; // Cuối cùng của 1 lần lặp thì cho con trỏ Node a nhảy đến địa chỉ của con trỏ Node b để xét tiếp cặp phần tử kế cận
	}

	if(i > 0 && Check == false)
		BubbleSort_DeQuy_1(Head, n, i - 1);
}

// Đi theo đúng tư tưởng của thuật toán Bubble Sort theo chiều từ trái qua phải nhưng phải có xác định được giá trị số lượng phần tử mà danh sách liên kết đang chứa
void BubbleSort_DeQuy_2(NODE *Head, int n, int i, NODE *a, NODE *b, int j = 0, bool Check = true)
{
	// Nếu chạy theo chiều từ trái qua phải
	if(j <= i)
	{
		if(a->Data > b->Data)
		{
			HoanVi(a->Data, b->Data);
			Check = false; // cập nhật lại cờ hiệu
		}
		BubbleSort_DeQuy_2(Head, n, i, b, b->pNext, j + 1, Check);
	}
	else
	{
		if(i > 0 && Check == false)
			BubbleSort_DeQuy_2(Head, n, i - 1, Head, Head->pNext);
	}
}

// Đi theo đúng tư tưởng của thuật toán Bubble Sort theo chiều từ trái qua phải nhưng phải có xác định được giá trị số lượng phần tử mà danh sách liên kết đang chứa
void BubbleSort_DeQuy_3(NODE *Head, int n)//, int i, NODE *a, NODE *b, int j = 0, bool Check = true)
{
	static int i = n - 2;
	static NODE *a = Head;
	static NODE *b = Head->pNext;
	static int j = 0;
	static bool Check = true;

	// Nếu chạy theo chiều từ trái qua phải
	if(j <= i)
	{
		if(a->Data > b->Data)
		{
			HoanVi(a->Data, b->Data);
			Check = false; // cập nhật lại cờ hiệu
		}
		a = b;
		b = b->pNext;
		j++;
		BubbleSort_DeQuy_3(Head, n);//, i, b, b->pNext, j + 1, Check);
	}
	else
	{
		if(i > 0 && Check == false)
		{
			i--;
			a = Head;
			b = Head->pNext;
			j = 0;
			Check = true;
			BubbleSort_DeQuy_3(Head, n);//, i - 1, Head, Head->pNext);
		}
	}
}

// Đi theo đúng tư tưởng của thuật toán Bubble Sort theo chiều từ trái qua phải nhưng không cần xác định số lượng phần tử của danh sách liên kết đang có
void BubbleSort_2(LIST l)
{
	NODE *end = l.pTail;
	NODE *temp;
	NODE *p;
	do{
		for(p = l.pHead; p != end; p = p->pNext)
		{
			if(p->Data > p->pNext->Data)
			{
				HoanVi(p->Data, p->pNext->Data);
			}
			temp = p;
		}
		end = temp;
	}while(end != p);
}

void BubbleSort_2_DeQuy_1(NODE *Head, NODE *End)
{
	if(End == Head)
		return;

	NODE *temp;
	for(NODE *p = Head; p != End; p = p->pNext)
	{
		if(p->Data > p->pNext->Data)
		{
			HoanVi(p->Data, p->pNext->Data);
		}
		temp = p;
	}

	//if(temp != Head)
	//if(End != Head->pNext)
		BubbleSort_2_DeQuy_1(Head, temp);
}

void BubbleSort_2_DeQuy_2(NODE *Head, NODE *End, NODE *p, NODE *temp)
{
	if(End == Head) 
		return;

	if(p != End)
	{
		if(p->Data > p->pNext->Data)
		{
			HoanVi(p->Data, p->pNext->Data);
		}
		BubbleSort_2_DeQuy_2(Head, End, p->pNext, p);
	}
	else
	{
		BubbleSort_2_DeQuy_2(Head, temp, Head, Head);
	}
}

void BubbleSort_2_DeQuy_3(LIST l)//, NODE *End, NODE *p, NODE *temp)
{
	static NODE *End = l.pTail;
	static NODE *p = l.pHead;
	static NODE *temp = l.pHead;

	if(End == l.pHead) 
		return;

	if(p != End)
	{
		if(p->Data > p->pNext->Data)
		{
			HoanVi(p->Data, p->pNext->Data);
		}
		temp = p;
		p = p->pNext;
		
		BubbleSort_2_DeQuy_3(l);
	}
	else
	{
		End = temp;
		temp = p = l.pHead;
		BubbleSort_2_DeQuy_3(l);
	}
}

/*
Mảng 1 chiều có n phần tử thì index sẽ hợp lệ trong đoạn từ 0 --> n - 1

a[x - 1] => 0 <= x - 1 <= n - 1 <=> 1 <= x <= n

for(int x = 1; x <= n; ++x)
	a[x - 1]

if(x >= 1 && x <= n)
	a[x - 1]

int x;

x += 2; <=> x = x + 2
x++; <=> x = x + 1

int *a;

a 


*/

void ShakerSort_DoubleLinkList(LIST l)
{
	//int left = 0; // Biên trái
	NODE* left = l.pHead;

	//int right = n - 1; // Biên phải
	NODE* right = l.pTail;

	// k là vị trí index cuối cùng đổi chỗ trong 1 lần duyệt để nhờ đó cập nhật lại giá trị biên left, right để thu hẹp phạm vi xét dữ liệu lại
	// Lưu ý: giá trị k khởi tạo này nên là 1 giá trị nằm ngoài phạm vi index của mảng để tránh bị lỗi trong trường hợp nếu như sau lần duyệt đầu tiên vị trí đổi chỗ cuối cùng có index trùng với index k khởi tạo ngoài này thì chương trình nó kết thúc luôn mà không xét vòng lặp ở bên dưới
	//int k = -1; 
	NODE* k = NULL;
	
	// Phải dùng vòng lặp do while để cho nó lặp ít nhất 1 lần rồi sau đó có dữ kiện mới đi xét được chứ nếu để vòng lặp while xét điều kiện trước thì sẽ bị lỗi ngay từ đầu
	do
	{
		//int temp_k = k; // Biến phụ để lưu giá trị k vào mục đích để kiểm tra xem sau vòng lặp đầu tiên thì giá trị k có bị thay đổi không? Nếu không thay đổi thì nghĩa là không có cặp số nào hoán vị => thuật toán có thể kết thúc ngay mà không cần phải xét đến vòng lặp thứ 2
		NODE* temp_k = k;

		// Lần duyệt đầu tiên từ biên phải về biên trái
		//for(int i = right; i > left; --i)
		for(NODE *i = right; i != left; i = i->pPrev)
		{
			// a[i] & a[i - 1]
			//if(a[i] < a[i - 1])
			if(i->Data < i->pPrev->Data)
			{
				//swap(a[i], a[i - 1]);
				swap(i->Data, i->pPrev->Data);

				//k = i - 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được nổi bọt lên
				k = i->pPrev;
			}
		}

		// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
		// Phải để điều kiện dừng này lên trước dòng lệnh left = k->pNext để nếu như trường hợp dãy số đã có thứ tự sẵn từ đầu thì k vẫn là NULL thì làm sao có thể -> pNext được => phải dừng nó luôn từ trước
		if(temp_k == k)
			break;
		
		// left = k + 1; // Cập nhật lại biên trái
		left = k->pNext;

		// Lần duyệt tiếp theo sẽ là từ biên trái về biên phải
		//for(int i = left; i < right; ++i)
		for(NODE *i = left; i != right; i = i->pNext)
		{
			// a[i] & a[i + 1]
			//if(a[i + 1] < a[i])
			if(i->pNext->Data < i->Data)
			{
				//swap(a[i + 1], a[i]);
				swap(i->pNext->Data, i->Data);

				//k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
				k = i->pNext;
			}
		}

		// right = k - 1; // Cập nhật lại biên phải
		right = k->pPrev;

	}while(left != NULL ? left->pPrev->pPrev != right : right->pNext->pNext != left); // Điều kiện này để tránh trường hợp sẽ có lúc left = NULL hay Right = NULL (vd: Nhập dữ liệu 2 số theo thứ tự 2, 1)
}

void ShakerSort_DoubleLinkList_DeQuy_1(LIST l, NODE *left, NODE *right)
{
	// Phải dùng điều kiện để được đệ quy để cho nó lặp ít nhất 1 lần rồi sau đó có dữ kiện mới đi xét được chứ nếu để điều kiện dừng xét điều kiện trước thì sẽ bị lỗi ngay từ đầu
	NODE *k = NULL;	
	NODE* temp_k = k;

	// Lần duyệt đầu tiên từ biên phải về biên trái
	for(NODE *i = right; i != left; i = i->pPrev)
	{
		if(i->Data < i->pPrev->Data)
		{
			swap(i->Data, i->pPrev->Data);
			k = i->pPrev;
		}
	}

	// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
	// Phải để điều kiện dừng này lên trước dòng lệnh left = k->pNext để nếu như trường hợp dãy số đã có thứ tự sẵn từ đầu thì k vẫn là NULL thì làm sao có thể -> pNext được => phải dừng nó luôn từ trước
	if(temp_k == k)
		return;

	left = k->pNext;

	// Lần duyệt tiếp theo sẽ là từ biên trái về biên phải
	for(NODE *i = left; i != right; i = i->pNext)
	{
		if(i->pNext->Data < i->Data)
		{
			swap(i->pNext->Data, i->Data);
			k = i->pNext;
		}
	}

	right = k->pPrev;

	if(left != NULL ? left->pPrev->pPrev != right : right->pNext->pNext != left)
		ShakerSort_DoubleLinkList_DeQuy_1(l, left, right);
}

void ShakerSort_DoubleLinkList_DeQuy_2(LIST l, NODE *left, NODE *right, NODE *k, NODE *temp_k, NODE *i, NODE *j)
{
	// -18 -26
	if(i != left)
	{
		if(i->Data < i->pPrev->Data)
		{
			swap(i->Data, i->pPrev->Data);
			k = i->pPrev;
		}

		NODE *temp_i = i->pPrev;

		if(i->pPrev == left)
		{
			// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
			// Phải để điều kiện dừng này lên trước dòng lệnh left = k->pNext để nếu như trường hợp dãy số đã có thứ tự sẵn từ đầu thì k vẫn là NULL thì làm sao có thể -> pNext được => phải dừng nó luôn từ trước
			if(temp_k == k)
				return;

			left = k->pNext;

			temp_i = left; // Dòng này phải để ở bên dưới dòng left = k->pNext để cập nhật lại left trước sau đó lấy left đã được cập nhật đó gán qua cho temp_i

			j = left;

			//ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, k, temp_k, left, j); // Chỗ này điền tham số i chính là left để sang lần đệ quy tiếp theo đó nó không thỏa cái if đầu tiên mà sẽ rơi vào cái else để làm bước đệ quy thứ 2
		}
		//else
			//ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, k, temp_k, i->pPrev, j);

		ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, k, temp_k, temp_i, j);
	}
	else // điều kiện dừng của vòng lặp for con thứ nhất
	{
		if(j != right)
		{
			if(j->pNext->Data < j->Data)
			{
				swap(j->pNext->Data, j->Data);
				k = j->pNext;
			}

			ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, k, temp_k, i, j->pNext);
		}
		else
		{
			// Để như thế này để tránh tình huống khi Left và Right ở lần cuối bị trùng nhau thì điều kiện để được đệ quy vẫn cho rằng hợp lệ và như thế sẽ lặp lại, và khi lặp lại thì sẽ không có quá trình đệ quy nào được thực hiện thành ra k và temp_k vẫn là NULL nhưng vì quá trình đệ quy con 1 không thực hiện được cho nên cái if(temp_k == k) return không chạy vô được => chương trình không dừng lại mà vẫn tiếp tục làm xuống dưới => mình phải xét tiếp điều kiện dừng cho nó ở đây
			//if(temp_k == k)
				//return;

			right = k->pPrev;

			// Hoặc nếu phát hiện left & right trùng nhau thì cũng không cần phải gọi đệ quy nữa => dừng lại
			if(left == right)
				return;

			if(left != NULL ? left->pPrev->pPrev != right : right->pNext->pNext != left)
				ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, NULL, NULL, right, left);
		}
	}
}

void ShakerSort_DoubleLinkList_DeQuy_3(LIST l)//, NODE *left, NODE *right, NODE *k, NODE *temp_k, NODE *i, NODE *j)
{
	static NODE *left = l.pHead;
	static NODE *right = l.pTail;
	static NODE *k = NULL;
	static NODE *temp_k = k;
	static NODE *i = right;
	static NODE *j = left;

	// -18 -26
	if(i != left)
	{
		if(i->Data < i->pPrev->Data)
		{
			swap(i->Data, i->pPrev->Data);
			k = i->pPrev;
		}

		NODE *temp_i = i->pPrev;

		if(i->pPrev == left)
		{
			// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
			// Phải để điều kiện dừng này lên trước dòng lệnh left = k->pNext để nếu như trường hợp dãy số đã có thứ tự sẵn từ đầu thì k vẫn là NULL thì làm sao có thể -> pNext được => phải dừng nó luôn từ trước
			if(temp_k == k)
				return;

			left = k->pNext;

			temp_i = left; // Dòng này phải để ở bên dưới dòng left = k->pNext để cập nhật lại left trước sau đó lấy left đã được cập nhật đó gán qua cho temp_i

			j = left;

			//ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, k, temp_k, left, j); // Chỗ này điền tham số i chính là left để sang lần đệ quy tiếp theo đó nó không thỏa cái if đầu tiên mà sẽ rơi vào cái else để làm bước đệ quy thứ 2
		}
		//else
			//ShakerSort_DoubleLinkList_DeQuy_2(l, left, right, k, temp_k, i->pPrev, j);

		i = temp_i;
		ShakerSort_DoubleLinkList_DeQuy_3(l);//, left, right, k, temp_k, temp_i, j);
	}
	else // điều kiện dừng của vòng lặp for con thứ nhất
	{
		if(j != right)
		{
			if(j->pNext->Data < j->Data)
			{
				swap(j->pNext->Data, j->Data);
				k = j->pNext;
			}

			j = j->pNext;
			ShakerSort_DoubleLinkList_DeQuy_3(l);//, left, right, k, temp_k, i, j->pNext);
		}
		else
		{
			// Để như thế này để tránh tình huống khi Left và Right ở lần cuối bị trùng nhau thì điều kiện để được đệ quy vẫn cho rằng hợp lệ và như thế sẽ lặp lại, và khi lặp lại thì sẽ không có quá trình đệ quy nào được thực hiện thành ra k và temp_k vẫn là NULL nhưng vì quá trình đệ quy con 1 không thực hiện được cho nên cái if(temp_k == k) return không chạy vô được => chương trình không dừng lại mà vẫn tiếp tục làm xuống dưới => mình phải xét tiếp điều kiện dừng cho nó ở đây
			//if(temp_k == k)
				//return;

			right = k->pPrev;

			// Hoặc nếu phát hiện left & right trùng nhau thì cũng không cần phải gọi đệ quy nữa => dừng lại
			if(left == right)
				return;

			if(left != NULL ? left->pPrev->pPrev != right : right->pNext->pNext != left)
			{
				k = temp_k = NULL;
				i = right;
				j = left;
				ShakerSort_DoubleLinkList_DeQuy_3(l);//, left, right, NULL, NULL, right, left);
			}
		}
	}
}

NODE* GetNodePre(LIST l, NODE *x)
{
	if(x == l.pHead || x == NULL)
		return NULL;

	NODE *p = l.pHead;
	while(p->pNext != x)
		p = p->pNext;

	return p;
}

void ShakerSort_SingleLinkList(LIST l)
{
	//int left = 0; // Biên trái
	NODE* left = l.pHead;

	//int right = n - 1; // Biên phải
	NODE* right = l.pTail;

	// k là vị trí index cuối cùng đổi chỗ trong 1 lần duyệt để nhờ đó cập nhật lại giá trị biên left, right để thu hẹp phạm vi xét dữ liệu lại
	// Lưu ý: giá trị k khởi tạo này nên là 1 giá trị nằm ngoài phạm vi index của mảng để tránh bị lỗi trong trường hợp nếu như sau lần duyệt đầu tiên vị trí đổi chỗ cuối cùng có index trùng với index k khởi tạo ngoài này thì chương trình nó kết thúc luôn mà không xét vòng lặp ở bên dưới
	//int k = -1; 
	NODE* k = NULL;
	
	// Phải dùng vòng lặp do while để cho nó lặp ít nhất 1 lần rồi sau đó có dữ kiện mới đi xét được chứ nếu để vòng lặp while xét điều kiện trước thì sẽ bị lỗi ngay từ đầu
	do
	{
		//int temp_k = k; // Biến phụ để lưu giá trị k vào mục đích để kiểm tra xem sau vòng lặp đầu tiên thì giá trị k có bị thay đổi không? Nếu không thay đổi thì nghĩa là không có cặp số nào hoán vị => thuật toán có thể kết thúc ngay mà không cần phải xét đến vòng lặp thứ 2
		NODE* temp_k = k;

		// Lần duyệt đầu tiên từ biên phải về biên trái
		//for(int i = right; i > left; --i)
		NODE *pre_i;
		for(NODE *i = right; i != left; i = pre_i)
		{
			pre_i = GetNodePre(l, i);
			// a[i] & a[i - 1]
			//if(a[i] < a[i - 1])
			if(i->Data < pre_i->Data)
			{
				//swap(a[i], a[i - 1]);
				swap(i->Data, pre_i->Data);

				//k = i - 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được nổi bọt lên
				k = pre_i;
			}
		}
		
		// Kiểm tra điều kiện dừng nếu sau 1 lượt duyệt mà không có cặp số nào bị đổi chỗ
		// Phải để điều kiện dừng này lên trước dòng lệnh left = k->pNext để nếu như trường hợp dãy số đã có thứ tự sẵn từ đầu thì k vẫn là NULL thì làm sao có thể -> pNext được => phải dừng nó luôn từ trước
		if(temp_k == k)
			break;

		// left = k + 1; // Cập nhật lại biên trái
		left = k->pNext;

		// Lần duyệt tiếp theo sẽ là từ biên trái về biên phải
		//for(int i = left; i < right; ++i)
		for(NODE *i = left; i != right; i = i->pNext)
		{
			// a[i] & a[i + 1]
			//if(a[i + 1] < a[i])
			if(i->pNext->Data < i->Data)
			{
				//swap(a[i + 1], a[i]);
				swap(i->pNext->Data, i->Data);

				//k = i + 1; // mỗi lần có hoán vị cặp số thì biến k được cập nhật là index của phần tử được chìm xuống
				k = i->pNext;
			}
		}
		// right = k - 1; // Cập nhật lại biên phải
		right = GetNodePre(l, k);

	}while(left != NULL ? left->pPrev->pPrev != right : right->pNext->pNext != left); // Điều kiện này để tránh trường hợp sẽ có lúc left = NULL hay Right = NULL (vd: Nhập dữ liệu 2 số theo thứ tự 2, 1)
}

// Bước 7: Giải phóng danh sách
void GiaiPhongDanhSach(LIST &l)
{
	while(l.pHead != NULL)
	{
		NODE *p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
	l.pHead = l.pTail = NULL; // Sau quá trình giải phóng thì cập nhật lại con trỏ pHead, pTail là NULL để có nhu cầu gì so sánh giá trị với NULL thì còn so sánh được
}

// [n_A, n_B]: Giá trị n (số lượng phần tử của mảng) sẽ được random ngẫu nhiên trong đoạn từ n_A --> n_B
// [ai_A, ai_B]: Giá trị ai (giá trị từng phần trong mảng) sẽ được random ngẫu nhiên trong đoạn từ ai_A --> ai_B
void TestSort(void (*ThuatToanSapXep)(LIST &, bool), int SoTestCase, int n_A, int n_B, int ai_A, int ai_B)
{
	// Tool test tự động thuật toán sắp xếp
	// số lượng phần tử của mảng
	// Sinh ngẫu nhiên 1 giá trị nằm trong đoạn [a, b] => a + rand() % (b - a + 1)
	// ví dụ: Muốn sinh ngẫu nhiên giá trị nằm trong đoạn từ 1 tới 10 => 1 + rand() % 10;
	srand(time(0));
	for(int k = 1; k <= SoTestCase; ++k)
	{
		printf("\nTest case %d: ", k);
		int n = n_A + rand() % (n_B - n_A + 1); // n_A --> n_B
		
		LIST l;
		INit(l);
		for(int i = 1; i <= n; ++i)
		{
			int x = ai_A + rand() % (ai_B - ai_A + 1); // ai_A --> ai_B
			NODE *p = GetNode(x);
			AddTail(l, p);
		}

		printf("(n = %d): ", n);
		/*cout << "\nDanh sach lien ket cua minh: ";
		OutPut(l);*/
		
		list<int> KetQuaChinhXac;
		for(NODE *p = l.pHead; p != NULL; p = p->pNext)
			KetQuaChinhXac.push_back(p->Data);

		/*cout << "\nDanh sach lien ket cua may: ";
		for(list<int>::iterator it = KetQuaChinhXac.begin(); it != KetQuaChinhXac.end(); ++it)
			cout << *it << " ";*/

		ThuatToanSapXep(l, true);
		/*cout << "\nDanh sach lien ket cua minh sau khi sap xep tang dan: ";
		OutPut(l);*/

		KetQuaChinhXac.sort();
		/*cout << "\nDanh sach lien ket cua may sau khi sap xep tang dan: ";
		for(list<int>::iterator it = KetQuaChinhXac.begin(); it != KetQuaChinhXac.end(); ++it)
			cout << *it << " ";*/

		bool Check = true;
		list<int>::iterator it = KetQuaChinhXac.begin();
		for(NODE *p = l.pHead; p != NULL; p = p->pNext)
		{
			if(p->Data != *it)
			{
				Check = false;
				printf("\nSap tang sai o Node : %d trong danh sach lien ket cua minh\n", p->Data);
				break;
			}
			++it;
		}
		if(Check == false)
		{
			cout << "\nDanh sach lien ket cua minh: ";
			OutPut(l);
			cout << "\nDanh sach lien ket cua may: ";
			for(list<int>::iterator it = KetQuaChinhXac.begin(); it != KetQuaChinhXac.end(); ++it)
				cout << *it << " ";

			break;
		}
		
		ThuatToanSapXep(l, false);
		/*cout << "\nDanh sach lien ket cua minh sau khi sap xep giam dan: ";
		OutPut(l);*/

		/*cout << "\nDanh sach lien ket cua may sau khi sap xep giam dan: ";
		for(list<int>::reverse_iterator rit = KetQuaChinhXac.rbegin(); rit != KetQuaChinhXac.rend(); ++rit)
			cout << *rit << " ";*/

		Check = true;
		list<int>::reverse_iterator rit = KetQuaChinhXac.rbegin();
		for(NODE *p = l.pHead; p != NULL; p = p->pNext)
		{
			if(p->Data != *rit)
			{
				Check = false;
				printf("\nSap giam sai o Node : %d trong danh sach lien ket cua minh\n", p->Data);
				break;
			}
			++rit;
		}
		if(Check == false)
		{
			cout << "\nDanh sach lien ket cua minh: ";
			OutPut(l);
			cout << "\nDanh sach lien ket cua may: ";
			for(list<int>::reverse_iterator rit = KetQuaChinhXac.rbegin(); rit != KetQuaChinhXac.rend(); ++rit)
				cout << *rit << " ";

			break;
		}
		else
			printf(" => Pass Test Case");

		// Nhớ phải có 2 dòng này để giải phóng bộ nhớ nếu không có nó bảo đảm bộ nhớ ram sẽ tăng đột biến và có thể tắt máy tính luôn
		GiaiPhongDanhSach(l);
		KetQuaChinhXac.clear();
	}
}

void InsertionSort_DoubleLinkList_ChenNhuMang(LIST &l, bool saptang = true)
{
	//for(int i = 1; i < n; ++i) // vế phải
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext) // vế phải
	{
	//	T x = a[i];
		int x = i->Data;

	// đi so sánh a[i] với tất cả giá trị của a[j]
	//	int j = i - 1;
		NODE *j = i->pPrev;
	//	while(j >= 0 && (x < a[j] == kieusapxep))
		while(j != NULL && (saptang == true ? x < j->Data : x > j->Data))
		{
	//		// a[j] sẽ nhích qua bên phải 1 ô
	//		a[j + 1] = a[j];
			j->pNext->Data = j->Data;
	//		j--;
			j = j->pPrev;
		}
	//	a[j + 1] = x;

		// Lưu ý trường hợp này khác mảng ở chỗ nếu tận cùng của cách làm với mảng thì j = -1 thì a[j + 1] tức là a[-1 + 1] tức là a[0] là phần tử đầu tiên. Còn với danh sách liên kết thì j = j->pRev tận cùng thì j = NULL mà đã là NULL thì không thể trỏ đi đâu khác được => lỗi => khắc phục: Xét riêng trường hợp nếu j là NULL thì nghĩa là cập nhật trực tiếp vô Node đầu danh sách (pHead)
		if(j != NULL)
			j->pNext->Data = x;
		else
			l.pHead->Data = x;
	}
}

void DeleteHead(LIST &l)
{
	if(l.pHead != NULL)
	{
		NODE *p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

void InsertionSort_DoubleLinkList_ChenNhuMang_Sentinel(LIST &l, bool saptang = true)
{
	AddHead(l, GetNode(0));

	//for(int i = 1; i < n; ++i) // vế phải
	for(NODE *i = l.pHead->pNext->pNext; i != NULL; i = i->pNext) // vế phải
	{
	//	T x = a[i];
		int x = i->Data;
		l.pHead->Data = x;

	// đi so sánh a[i] với tất cả giá trị của a[j]
	//	int j = i - 1;
		NODE *j = i->pPrev;
	//	while(j >= 0 && (x < a[j] == kieusapxep))
		while(saptang == true ? x < j->Data : x > j->Data)
		{
	//		// a[j] sẽ nhích qua bên phải 1 ô
	//		a[j + 1] = a[j];
			j->pNext->Data = j->Data;
	//		j--;
			j = j->pPrev;
		}
	//	a[j + 1] = x;

		// Lưu ý trường hợp này khác mảng ở chỗ nếu tận cùng của cách làm với mảng thì j = -1 thì a[j + 1] tức là a[-1 + 1] tức là a[0] là phần tử đầu tiên. Còn với danh sách liên kết thì j = j->pRev tận cùng thì j = NULL mà đã là NULL thì không thể trỏ đi đâu khác được => lỗi => khắc phục: Xét riêng trường hợp nếu j là NULL thì nghĩa là cập nhật trực tiếp vô Node đầu danh sách (pHead)
		/*if(j != NULL)
			j->pNext->Data = x;
		else
			l.pHead->Data = x;*/
		j->pNext->Data = x;
	}

	DeleteHead(l);
}

void InsertionSort_SingleLinkList_ChenNhuMang_DungHamGetNodePre(LIST l, bool saptang = true)
{
	//for(int i = 1; i < n; ++i) // vế phải
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext) // vế phải
	{
	//	T x = a[i];
		int x = i->Data;

	// đi so sánh a[i] với tất cả giá trị của a[j]
	//	int j = i - 1;
		NODE *j = GetNodePre(l, i);
	//	while(j >= 0 && (x < a[j] == kieusapxep))
		while(j != NULL && (saptang == true ? x < j->Data : x > j->Data))
		{
	//		// a[j] sẽ nhích qua bên phải 1 ô
	//		a[j + 1] = a[j];
			j->pNext->Data = j->Data;
	//		j--;
			//j = j->pPrev;
			j = GetNodePre(l, j);
		}
	//	a[j + 1] = x;

		// Lưu ý trường hợp này khác mảng ở chỗ nếu tận cùng của cách làm với mảng thì j = -1 thì a[j + 1] tức là a[-1 + 1] tức là a[0] là phần tử đầu tiên. Còn với danh sách liên kết thì j = j->pRev tận cùng thì j = NULL mà đã là NULL thì không thể trỏ đi đâu khác được => lỗi => khắc phục: Xét riêng trường hợp nếu j là NULL thì nghĩa là cập nhật trực tiếp vô Node đầu danh sách (pHead)
		if(j != NULL)
			j->pNext->Data = x;
		else
			l.pHead->Data = x;
	}
}

void InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre(LIST &l, bool saptang = true)
{
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		int x = i->Data;

		for(NODE *j = l.pHead; j != i; j = j->pNext)
		{
			if(saptang == true ? x < j->Data : x > j->Data)
			{
				// Chèn giá trị x vào ngay vị trí Node j hiện tại thỏa
				int u, v;
				NODE *k = j;
				v = k->Data;
				for(; k != i; k = k->pNext)
				{
					u = v;
					v = k->pNext->Data;
					k->pNext->Data = u;
				}
				j->Data = x;
				break; // Phải nhớ break nếu không sẽ sai vì cứ liên tục thỏa mãn điều kiện chèn hoài
			}
		}
	}
}

void InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre_Sentinel(LIST &l, bool saptang = true)
{
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		int x = i->Data;

		Node *j = l.pHead;
		while(saptang == true ? x > j->Data : x < j->Data)
		{
			j = j->pNext;
		}

		if(j == i)
			continue;

		// Chèn giá trị x vào ngay vị trí Node j hiện tại thỏa
		int u, v;
		NODE *k = j;
		v = k->Data;
		for(; k != i; k = k->pNext)
		{
			u = v;
			v = k->pNext->Data;
			k->pNext->Data = u;
		}
		j->Data = x;
	}
}

// x là Node cần xóa trong danh sách (nghĩa là Node x này phải là Node nằm trong danh sách)
void XoaNode(LIST &l, NODE *x)
{
	// Danh sách rỗng thì không làm gì cả
	if(l.pHead == NULL)
		return;

	// Xóa node đầu
	if(l.pHead == x)
	{
		l.pHead = l.pHead->pNext;

		// Lỡ Node đầu đó cũng là Node duy nhất trong danh sách
		if(l.pHead == NULL)
		{
			l.pTail = NULL;
			return;
		}

		l.pHead->pPrev = NULL;
		return;
	}

	// Xóa Node cuối
	if(l.pTail == x)
	{
		l.pTail = l.pTail->pPrev;
		l.pTail->pNext = NULL;
		return;
	}

	// Xóa Node ở giữa: Điều kiện lý tưởng tức là có đủ Node đứng trước và Node đứng sau Node x cần xóa
	NODE *pre_x = x->pPrev;
	NODE *next_x = x->pNext;

	pre_x->pNext = next_x;
	next_x->pPrev = pre_x;

	//delete x; // do Node x còn cần phải chèn vào vị trí khác trong danh sách => không có giải phóng bộ nhớ cho x
}

// x là Node cần xóa trong danh sách (nghĩa là Node x này phải là Node nằm trong danh sách)
void XoaNode_SingleLinkList_DungGetNodePre(LIST &l, NODE *x)
{
	// Danh sách rỗng thì không làm gì cả
	if(l.pHead == NULL)
		return;

	// Xóa node đầu
	if(l.pHead == x)
	{
		l.pHead = l.pHead->pNext;

		// Lỡ Node đầu đó cũng là Node duy nhất trong danh sách
		if(l.pHead == NULL)
		{
			l.pTail = NULL;
			return;
		}

		//l.pHead->pPrev = NULL;
		return;
	}

	// Xóa Node cuối
	if(l.pTail == x)
	{
		l.pTail = GetNodePre(l, l.pTail);
		l.pTail->pNext = NULL;
		return;
	}

	// Xóa Node ở giữa: Điều kiện lý tưởng tức là có đủ Node đứng trước và Node đứng sau Node x cần xóa
	NODE *pre_x = GetNodePre(l, x);
	NODE *next_x = x->pNext;

	pre_x->pNext = next_x;
	//next_x->pPrev = pre_x;

	//delete x; // do Node x còn cần phải chèn vào vị trí khác trong danh sách => không có giải phóng bộ nhớ cho x
}

// x là Node cần xóa trong danh sách (nghĩa là Node x này phải là Node nằm trong danh sách)
void XoaNode_SingleLinkList_KhongDungGetNodePre(LIST &l, NODE *pre_x, NODE *x)
{
	// Danh sách rỗng thì không làm gì cả
	if(l.pHead == NULL)
		return;

	// Xóa node đầu
	if(l.pHead == x)
	{
		l.pHead = l.pHead->pNext;

		// Lỡ Node đầu đó cũng là Node duy nhất trong danh sách
		if(l.pHead == NULL)
		{
			l.pTail = NULL;
			return;
		}

		//l.pHead->pPrev = NULL;
		return;
	}

	// Xóa Node cuối
	if(l.pTail == x)
	{
		l.pTail = pre_x;
		l.pTail->pNext = NULL;
		return;
	}

	// Xóa Node ở giữa: Điều kiện lý tưởng tức là có đủ Node đứng trước và Node đứng sau Node x cần xóa
	NODE *next_x = x->pNext;

	pre_x->pNext = next_x;
	//next_x->pPrev = pre_x;

	//delete x; // do Node x còn cần phải chèn vào vị trí khác trong danh sách => không có giải phóng bộ nhớ cho x
}

void ThemNodeBVaoSauNodeA(LIST &l, NODE *a, NODE *b)
{
	if(a == NULL)
	{
		AddHead(l, b);
		return;
	}

	if(a == l.pTail)
	{
		AddTail(l, b);
		return;
	}

	// Điều kiện lý tưởng là Node a cần thêm vào sau nó có sẵn 1 Node đằng sau nó
	NODE *next_a = a->pNext;
	a->pNext = b;
	b->pNext = next_a;

	next_a->pPrev = b;
	b->pPrev = a;
}

void ThemNodeBVaoSauNodeA_SingleLinkList(LIST &l, NODE *a, NODE *b)
{
	if(a == NULL)
	{
		AddHead(l, b);
		return;
	}

	if(a == l.pTail)
	{
		AddTail(l, b);
		return;
	}

	// Điều kiện lý tưởng là Node a cần thêm vào sau nó có sẵn 1 Node đằng sau nó
	NODE *next_a = a->pNext;
	a->pNext = b;
	b->pNext = next_a;

	//next_a->pPrev = b;
	//b->pPrev = a;
}

void InsertionSort_DoubleLinkList_BeMoiLienKet_Ver1(LIST &l, bool saptang = true)
{
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		//cout << "\ni = " << i->Data << " : ";
		NODE *j = i->pPrev;
		while(j != NULL && (saptang == true ? i->Data < j->Data : i->Data > j->Data))
		{
			j = j->pPrev;
		}

		XoaNode(l, i);
		ThemNodeBVaoSauNodeA(l, j, i);
	}
}

void InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2(LIST &l, bool saptang = true)
{
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		//cout << "\ni = " << i->Data << " : ";
		NODE *j = i->pPrev;
		while(j != NULL && (saptang == true ? i->Data < j->Data : i->Data > j->Data))
		{
			j = j->pPrev;
		}

		// Nếu không có điều kiện này thì với những Node mà bị xóa và thêm lại ngay tại chính vị trí của nó ban đầu sẽ khiến chương trình bị lặp vô tận bởi vì pre_i = Node trước đó rồi sau đó lại cứ xét lại Node i tiếp theo (là chính nó vừa bị xóa) và cứ thế bị lặp lại ...
		if(i->pPrev == j)
			continue;

		// Phải lưu lại địa chỉ Node đứng trước i trước khi i bị xóa và thêm vào 1 vị trí khác để sau quá trình đó cập nhật lại địa chỉ cho Node i để vòng lặp khi lặp pNext tiếp theo của i sẽ xét tiếp từ vị trí ban đầu chứ không xét lại từ vị trí mới của i được thêm
		NODE *pre_i = i->pPrev;

		XoaNode(l, i);
		ThemNodeBVaoSauNodeA(l, j, i);

		i = pre_i; // Cập nhật lại địa chỉ của Node i là Node trước đó để vòng lặp tiếp theo lặp sang pNext của i sẽ được địa chỉ đúng

		//OutPut(l);
	}
}

void InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2_Sentinel(LIST &l, bool saptang = true)
{
	AddHead(l, GetNode(0));

	for(NODE *i = l.pHead->pNext->pNext; i != NULL; i = i->pNext)
	{
		//cout << "\ni = " << i->Data << " : ";
		l.pHead->Data = i->Data;

		NODE *j = i->pPrev;
		while(saptang == true ? i->Data < j->Data : i->Data > j->Data)
		{
			j = j->pPrev;
		}

		// Nếu không có điều kiện này thì với những Node mà bị xóa và thêm lại ngay tại chính vị trí của nó ban đầu sẽ khiến chương trình bị lặp vô tận bởi vì pre_i = Node trước đó rồi sau đó lại cứ xét lại Node i tiếp theo (là chính nó vừa bị xóa) và cứ thế bị lặp lại ...
		if(i->pPrev == j)
			continue;

		// Phải lưu lại địa chỉ Node đứng trước i trước khi i bị xóa và thêm vào 1 vị trí khác để sau quá trình đó cập nhật lại địa chỉ cho Node i để vòng lặp khi lặp pNext tiếp theo của i sẽ xét tiếp từ vị trí ban đầu chứ không xét lại từ vị trí mới của i được thêm
		NODE *pre_i = i->pPrev;

		XoaNode(l, i);
		ThemNodeBVaoSauNodeA(l, j, i);

		i = pre_i; // Cập nhật lại địa chỉ của Node i là Node trước đó để vòng lặp tiếp theo lặp sang pNext của i sẽ được địa chỉ đúng

		//OutPut(l);
	}

	DeleteHead(l);
}

void InsertionSort_SingleLinkList_BeMoiLienKet_DungGetNodePre(LIST &l, bool saptang = true)
{
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		//cout << "\ni = " << i->Data << " : ";
		NODE *j = GetNodePre(l, i);
		while(j != NULL && (saptang == true ? i->Data < j->Data : i->Data > j->Data))
		{
			j = GetNodePre(l, j);
		}

		// Nếu không có điều kiện này thì với những Node mà bị xóa và thêm lại ngay tại chính vị trí của nó ban đầu sẽ khiến chương trình bị lặp vô tận bởi vì pre_i = Node trước đó rồi sau đó lại cứ xét lại Node i tiếp theo (là chính nó vừa bị xóa) và cứ thế bị lặp lại ...
		if(GetNodePre(l, i) == j)
			continue;

		// Phải lưu lại địa chỉ Node đứng trước i trước khi i bị xóa và thêm vào 1 vị trí khác để sau quá trình đó cập nhật lại địa chỉ cho Node i để vòng lặp khi lặp pNext tiếp theo của i sẽ xét tiếp từ vị trí ban đầu chứ không xét lại từ vị trí mới của i được thêm
		NODE *pre_i = GetNodePre(l, i);

		XoaNode_SingleLinkList_DungGetNodePre(l, i);
		ThemNodeBVaoSauNodeA_SingleLinkList(l, j, i);

		i = pre_i; // Cập nhật lại địa chỉ của Node i là Node trước đó để vòng lặp tiếp theo lặp sang pNext của i sẽ được địa chỉ đúng

		//OutPut(l);
	}
}

void InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver1(LIST &l, bool saptang = true)
{
	NODE *pre_i = l.pHead;
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		NODE *pre_j = NULL;
		NODE *j = l.pHead;
		while(j != i && (saptang == true ? i->Data > j->Data : i->Data < j->Data))
		{
			pre_j = j;
			j = j->pNext;
		}
		if(j == i)
		{
			pre_i = i;
			continue;
		}

		XoaNode_SingleLinkList_KhongDungGetNodePre(l, pre_i, i);
		ThemNodeBVaoSauNodeA_SingleLinkList(l, pre_j, i);

		i = pre_i;
	}
}

void InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2(LIST &l, bool saptang = true)
{
	NODE *pre_i = l.pHead;
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		if(saptang == true ? i->Data < l.pHead->Data : i->Data > l.pHead->Data)
		{
			XoaNode_SingleLinkList_KhongDungGetNodePre(l, pre_i, i);
			AddHead(l, i);
			i = pre_i;
			continue;
		}

		NODE *j = l.pHead;
		while(j->pNext != i && (saptang == true ? i->Data > j->pNext->Data : i->Data < j->pNext->Data))
		{
			j = j->pNext;
		}
		if(j->pNext == i)
		{
			pre_i = i;
			continue;
		}

		XoaNode_SingleLinkList_KhongDungGetNodePre(l, pre_i, i);
		ThemNodeBVaoSauNodeA_SingleLinkList(l, j, i);

		i = pre_i;
	}
}

void InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2_Sentinel(LIST &l, bool saptang = true)
{
	NODE *pre_i = l.pHead;
	for(NODE *i = l.pHead->pNext; i != NULL; i = i->pNext)
	{
		if(saptang == true ? i->Data < l.pHead->Data : i->Data > l.pHead->Data)
		{
			XoaNode_SingleLinkList_KhongDungGetNodePre(l, pre_i, i);
			AddHead(l, i);
			i = pre_i;
			continue;
		}

		NODE *j = l.pHead;
		while(saptang == true ? i->Data > j->pNext->Data : i->Data < j->pNext->Data)
		{
			j = j->pNext;
		}
		if(j->pNext == i)
		{
			pre_i = i;
			continue;
		}

		XoaNode_SingleLinkList_KhongDungGetNodePre(l, pre_i, i);
		ThemNodeBVaoSauNodeA_SingleLinkList(l, j, i);

		i = pre_i;
	}
}

void InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3(LIST &l, bool saptang = true)
{
	NODE *i = l.pHead;
	while(i != l.pTail)
	{
		// 2 --> 1 --> NULL => xóa 1: 2 --> NULL
		if(saptang == true ? i->pNext->Data < l.pHead->Data : i->pNext->Data > l.pHead->Data)
		{
			NODE *next_i = i->pNext;
			XoaNode_SingleLinkList_KhongDungGetNodePre(l, i, next_i); // ở đây truyền vào i->pNext cũng được
			AddHead(l, next_i); // Lưu ý: Không được truyền i->pNext vào hàm thêm này bởi vì sau quá trình xóa ở trên thì i->pNext đã là 1 địa chỉ mới rồi (Node đằng sau Node cần xóa ban đầu) => SAI
			continue;
		}

		NODE *j = l.pHead;
		while(j != i && (saptang == true ? i->pNext->Data > j->pNext->Data : i->pNext->Data < j->pNext->Data))
		{
			j = j->pNext;
		}
		if(j == i)
		{
			i = i->pNext;
			continue;
		}

		NODE *next_i = i->pNext;
		XoaNode_SingleLinkList_KhongDungGetNodePre(l, i, next_i); // ở đây truyền vào i->pNext cũng được
		ThemNodeBVaoSauNodeA_SingleLinkList(l, j, next_i); // Lưu ý: Không được truyền i->pNext vào hàm thêm này bởi vì sau quá trình xóa ở trên thì i->pNext đã là 1 địa chỉ mới rồi (Node đằng sau Node cần xóa ban đầu) => SAI
	}
}

void InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3_Sentinel(LIST &l, bool saptang = true)
{
	NODE *i = l.pHead;
	while(i != l.pTail)
	{
		// 2 --> 1 --> NULL => xóa 1: 2 --> NULL
		if(saptang == true ? i->pNext->Data < l.pHead->Data : i->pNext->Data > l.pHead->Data)
		{
			NODE *next_i = i->pNext;
			XoaNode_SingleLinkList_KhongDungGetNodePre(l, i, next_i); // ở đây truyền vào i->pNext cũng được
			AddHead(l, next_i); // Lưu ý: Không được truyền i->pNext vào hàm thêm này bởi vì sau quá trình xóa ở trên thì i->pNext đã là 1 địa chỉ mới rồi (Node đằng sau Node cần xóa ban đầu) => SAI
			continue;
		}

		NODE *j = l.pHead;
		while(saptang == true ? i->pNext->Data > j->pNext->Data : i->pNext->Data < j->pNext->Data)
		{
			j = j->pNext;
		}
		if(j == i)
		{
			i = i->pNext;
			continue;
		}

		NODE *next_i = i->pNext;
		XoaNode_SingleLinkList_KhongDungGetNodePre(l, i, next_i); // ở đây truyền vào i->pNext cũng được
		ThemNodeBVaoSauNodeA_SingleLinkList(l, j, next_i); // Lưu ý: Không được truyền i->pNext vào hàm thêm này bởi vì sau quá trình xóa ở trên thì i->pNext đã là 1 địa chỉ mới rồi (Node đằng sau Node cần xóa ban đầu) => SAI
	}
}

// true: Nếu mở được tập tin và đọc dữ liệu thành công
// false: Nếu không mở được tập tin
bool DocDuLieuTuTapTin(string tentaptin, LIST &l)
{
	//FILE *f = fopen(tentaptin, mode);
	ifstream FileIn;
	FileIn.open(tentaptin, ios_base::in);

	if(FileIn != NULL)
	{
		int n;
		FileIn >> n;
		INit(l);

		for(int i = 0; i < n; ++i)
		{
			int x;
			FileIn >> x;
			NODE *p = GetNode(x);
			AddTail(l, p);
		}

		//fclose(f);
		FileIn.close();
		return true;
	}

	//printf("\nKhong tim thay tap tin %s", tentaptin);
	cout << "\nKhong tim thay tap tin " << tentaptin;
	return false;
}

void LapBangDoThoiGian()
{
	vector<string> DanhSachCacThuatToanSapXepCanTaoBangThongKe;
	
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2_Sentinel");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_DoubleLinkList_ChenNhuMang");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_ChenNhuMang_DungHamGetNodePre");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_DoubleLinkList_ChenNhuMang_Sentinel");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre_Sentinel");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_DoubleLinkList_BeMoiLienKet_Ver1");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_BeMoiLienKet_DungGetNodePre");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver1");
	DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2");
	DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2_Sentinel");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3");
	//DanhSachCacThuatToanSapXepCanTaoBangThongKe.push_back("InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3_Sentinel");


	int size_DanhSachCacThuatToanSapXepCanTaoBangThongKe = DanhSachCacThuatToanSapXepCanTaoBangThongKe.size();

	vector<string> DanhSachCacTapDuLieuCanTaoBangThongKe;
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("1000.txt");
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("10.000.txt");
	DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("50.000.txt");
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("80.000.txt");
	//DanhSachCacTapDuLieuCanTaoBangThongKe.push_back("100.000.txt");
	int size_DanhSachCacTapDuLieuCanTaoBangThongKe = DanhSachCacTapDuLieuCanTaoBangThongKe.size();

	int SoLanChayDoThoiGianVoiMoiTapDuLieu = 1;


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
				LIST l;

				bool KiemTraDocDuLieu = DocDuLieuTuTapTin(DanhSachCacTapDuLieuCanTaoBangThongKe[j], l);

				if(KiemTraDocDuLieu == true)
				{
					clock_t start = clock();

					if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_DoubleLinkList_ChenNhuMang")
					{
						InsertionSort_DoubleLinkList_ChenNhuMang(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_ChenNhuMang_DungHamGetNodePre")
					{
						InsertionSort_SingleLinkList_ChenNhuMang_DungHamGetNodePre(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre")
					{
						InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_DoubleLinkList_BeMoiLienKet_Ver1")
					{
						InsertionSort_DoubleLinkList_BeMoiLienKet_Ver1(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2")
					{
						InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2_Sentinel")
					{
						InsertionSort_DoubleLinkList_BeMoiLienKet_Ver2_Sentinel(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_BeMoiLienKet_DungGetNodePre")
					{
						InsertionSort_SingleLinkList_BeMoiLienKet_DungGetNodePre(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver1")
					{
						InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver1(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2")
					{
						InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2_Sentinel")
					{
						InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2_Sentinel(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3")
					{
						InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3_Sentinel")
					{
						InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3_Sentinel(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_DoubleLinkList_ChenNhuMang_Sentinel")
					{
						InsertionSort_DoubleLinkList_ChenNhuMang_Sentinel(l);
					}
					else if(DanhSachCacThuatToanSapXepCanTaoBangThongKe[i] == "InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre_Sentinel")
					{
						InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre_Sentinel(l);
					}

					clock_t end = clock();

					double thoigianchay = (double)(end - start) / CLOCKS_PER_SEC;

					TongThoiGianChayCuaTatCaCacLan += thoigianchay;

					FileOut << fixed << setprecision(3) << thoigianchay << "s\t\t";
				}
				GiaiPhongDanhSach(l);
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
}

void PhatSinhDaySo(int n, int a, int b, char* tentaptin, char* mode) 
{
	FILE *f = fopen(tentaptin, mode); // Mở tập tin để ghi

	srand(time(0)); // Nếu để trong vòng lặp là sẽ bị cac số giống nhau
	fprintf(f, "%d\n", n);
	for(int i = 1; i <= n; ++i)
	{
		int x = a + rand() % (b - a + 1); // 0 -> 100
		fprintf(f, "%d\n", x);
	}

	printf("Du lieu da duoc ghi vao tap tin %s", tentaptin);
	fclose(f); // Đóng tập tin khi đã dùng xong để giải phóng bộ nhớ
}

int main()
{
	LapBangDoThoiGian();

	//TestSort(InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver2_Sentinel, 500, 100, 200, -500, 500);

	//LIST l;
	//int n;
	//INit(l);

	////input(l, n);
	////int a[] = {4, 3, 2, 10, 12, 1, 5, 6};
	////int a[] = {2, 1};
	//int a[] = {10, 5, 7, 1, 3, 2, 4, 6, 8, 9};
	////int a[] = {1};
	//n = sizeof(a) / sizeof(a[0]);
	//
	//for(int i = 0; i < n; ++i)
	//{
	//	NODE *p = GetNode(a[i]);
	//	AddTail(l, p);
	//}

	//OutPut(l);

	// 1 --> 2 --> 3 --> NULL
	// 1 --> 2 --> 3 --> 4
	//int x = 4;
	//NODE *p = GetNode(x);

	//cout << "\nDanh sach sau khi them: ";
	//ThemNodeBVaoSauNodeA(l, l.pHead->pNext, p);
	//OutPut(l);

	//XuatDanhSach_DeQuy(l.pHead);

	//cout << "\nSap xep danh sach tang dan\n";
	//InterchangeSort_DeQuy_1(l.pHead);
	//InterchangeSort_DeQuy_2(l.pHead, l.pHead);
	//InterchangeSort_DeQuy_3(l.pHead);
	//SelectionSort_DeQuy_1(l.pHead);
	//SelectionSort_DeQuy_2(l.pHead, l.pHead, l.pHead);
	//SelectionSort_DeQuy_3(l.pHead);
	//BubbleSort_DeQuy_1(l.pHead, n, n - 2);

	//if(l.pHead != NULL)
	//{
		//BubbleSort_DeQuy_2(l.pHead, n, n - 2, l.pHead, l.pHead->pNext);
		//BubbleSort_DeQuy_3(l.pHead, n);
		//BubbleSort_2_DeQuy_1(l.pHead, l.pTail);
		//BubbleSort_2_DeQuy_2(l.pHead, l.pTail, l.pHead, l.pHead);
		//BubbleSort_2_DeQuy_3(l);
	//}

	//XuatDanhSach_DeQuy(l.pHead);

	//SelectionSort(l);
	////InterchangeSort(l);
	//BubbleSort(l, n);
	//BubbleSort_2(l);
	//ShakerSort_DoubleLinkList(l);
	//ShakerSort_SingleLinkList(l);
	//ShakerSort_DoubleLinkList_DeQuy_1(l, l.pHead, l.pTail);
	//ShakerSort_DoubleLinkList_DeQuy_2(l, l.pHead, l.pTail, NULL, NULL, l.pTail, l.pHead);
	//ShakerSort_DoubleLinkList_DeQuy_3(l);
	//cout << "\nDanh sach sau khi sap tang: ";
	////InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre(l, true);
	//InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3_Sentinel(l, true);
	//OutPut(l);

	//cout << "\nDanh sach sau khi sap giam: ";
	////InsertionSort_SingleLinkList_ChenNhuMang_KhongDungHamGetNodePre(l, false);
	//InsertionSort_SingleLinkList_BeMoiLienKet_KhongDungGetNodePre_Ver3_Sentinel(l, false);
	//OutPut(l);
	//

	//cout << "\nGiai phong danh sach\n";
	//GiaiPhongDanhSach(l);
	//OutPut(l);

	system("pause");
	return 0;
}