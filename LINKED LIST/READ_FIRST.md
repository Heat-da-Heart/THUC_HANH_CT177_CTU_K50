# KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT
```c
typedef struct Node
{
  int Data;
  struct Node* Next;
} Node;

typedef struct Node* Position;

typedef Position List;
```
________________________________________________________________________________________________________
## PHẦN BÀI TẬP

*Câu 1: Viết hàm nhập và hiển thị một danh sách các số nguyên từ bàn phím.*
*Câu 2: Viết hàm xoá phần tử x xuất hiện đầu tiên trong danh sách.*
*Câu 3: Viết hàm sắp xếp danh sách tăng dần.*
*Câu 4: Viết hàm liệt kê các số lẻ và số chẵn có trong danh sách.*
*Câu 5: Viết hàm tính trung bình cộng các phần tử trong danh sách.*
*Câu 6: Viết hàm cho phép liệt kê các số chẵn và tính trung bình cộng các phần tử là số chẵn trong danh sách.*
*Câu 7: Viết hàm xóa tất cả phần tử x xuất hiện trong danh sách.*
*Câu 8: Viết hàm cho phép tìm tập hợp giao của 2 danh sách biểu diễn tập hợp.*
*Câu 9: Viết hàm cho phép tìm tập hợp hợp của 2 danh sách biểu diễn tập hợp.*
*Câu 10: Viết hàm cho phép tìm hiệu của 2 danh sách biểu diễn tập hợp.*

LƯU Ý:
// Ở TRƯỜNG HỢP NÀY, MỘT DANH SÁCH BIỂU DIỄN TẬP HỢP ĐƯỢC HIỂU LÀ MỘT DANH SÁCH MÀ Ở ĐÓ KHÔNG CÓ HAI PHẦN TỬ NÀO TRÙNG NHAU.
// TA CÓ THỂ BIỂU DIỄN MỘT TẬP HỢP BẰNG MỘT DANH SÁCH VÀ XỬ LÍ NHỮNG PHẦN TỬ TRÙNG NHAU BẰNG HÀM Ở CÂU 7.
// GỢI Ý: NÊN TẠO MỘT HÀM ĐỂ KIỂM TRA MỘT PHẦN TỬ X CÓ NẰM TRONG MỘT DANH SÁCH L HAY KHÔNG. TỪ VIỆC SỬ DỤNG HÀM TRÊN RÚT RA CÁCH GIẢI QUYẾT CÂU 8, 9, 10.

-> CODE XEM FILE LINKED_LIST.c VÀ TÌM THEO TÊN CÁC HÀM SAU:

Câu 1: Input(List* pL), Output(List L).

Câu 2: Hàm deleteList(Position p, List* pL) cho phép xoá phần tử vị trí P (vị trí ở đây là một Node) trong danh sách kết hợp với hàm Locate(ElementType x, List L) cho phép tìm phần tử x xuất hiện đầu tiên trong danh sách và hàm Locate trả về một Node là Node mà ở đó chứa Data == X. 
=> Ta gọi deleteList(Locate(x, L), &L).

Câu 3: Sort(List *pL) // Ở ĐÂY KHÔNG DÙNG ĐƯỢC INSERTION SORT VÌ TA LÀM VIỆC TRÊN MỘT DANH SÁCH LIÊN KẾT ĐƠN, KHÔNG THỂ DUYỆT NGƯỢC, NẾU MUỐN DUYỆT NGƯỢC, SỬ DỤNG DANH SÁCH LIÊN KẾT KÉP.

Câu 4: Odd(List L), Even(List L).

Câu 5: Averange(List L).

Câu 6: EvenAverage(List L).

Câu 7: deleteAll(ElementType x, List* pL).

GỢI Ý: XEM HÀM Member(ElementType X, List L).
Câu 8: Intersection(List L1, List L2).

Câu 9: Union(List L1, List L2).

Câu 10: Difference(List L1, List L2).


Tảng Mạn:

CẤU TRÚC DANH SÁCH LIÊN KẾT LÀ MỘT CẤU TRÚC KHÓ VÌ KHI CÀI ĐẶT TA CẦN HIỂU RẤT RÕ VỀ CON TRỎ VÀ CON TRỎ CẤP HAI, CỤ THỂ LÀ HÀM INSERTLIST VÀ CÁC HÀM CÓ THAM SỐ BIẾN KIỂU List* (CON TRỎ LIST, BẢN THÂN LIST ĐƯỢC TA ĐỊNH NGHĨA LÀ struct Node*, VẬY LIST* = struct Node**, CON TRỎ struct Node*).

Ở HÀM INSERTLIST TA CẦN NẮM ĐƯỢC ĐỊA CHỈ CỦA MỘT NODE X NÀO ĐÓ LÀ CÓ THỂ CHÈN ĐƯỢC, VÀ NẾU NODE ĐÓ NẰM TRONG LIST L THÌ TA ĐÃ CHÈN VÀO SAU NODE X TRONG LIST L.

CÁC HÀM CÓ THAM SỐ List* THỰC CHẤT LÀ TA ĐANG MUỐN TRUYỀN ĐỊA CHỈ CỦA MỘT CON TRỎ VỚI MỤC ĐÍCH LÀ THAY ĐỔI ĐƯỢC CON TRỎ ĐÓ.
// TA XEM NHƯ CON TRỎ NHƯ MỘT ĐỐI TƯỢNG, MUỐN THAY ĐỔI ĐỐI TƯỢNG ĐÓ TRONG HÀM THÌ TA PHẢI TRUYỀN THAM CHIẾU CỦA NÓ.

Có thể những nhận xét trên của tôi có những sai sót hoặc không đúng, tôi rất cảm kích những ý kiến đóng góp từ người xem qua mail: natney444@gmail.com
