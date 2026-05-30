Tên môn: Cấu trúc dữ liệu và giải thuật

Thời gian học: Học kì 2 / 2025-2026

Họ và tên sinh viên:

Trần Duy Tuấn – MSSV: 25120463

Võ Nguyên Oánh – MSSV: 25120407

I. Thuật toán cài đặt tốt nhất ở lần chạy thứ nhất
1. Bài A:
- Thuật toán sử dụng Radix Sort.
- Các phương thức tối ưu:
	+ Lật bit dấu để tránh hiện tượng số âm (1) lớn hơn số dương (0).
	+ Mỗi lần sort theo 8 bit sẽ nhanh hơn radix sort theo hệ thập phân hoặc từng bit.
- Lí do tối ưu nhất: Radix Sort có độ phức tạp thuật toán O(n.k) tối ưu hơn các thuật toán Sort có so sánh, việc làm việc với bit sẽ giúp CPU xử lí nhanh hơn với hệ thập phân.
2. Bài B:
- Thuật toán sử dụng: Radix Sort, Insertion Sort.
- Các phương thức tối ưu:
	+ Tối ưu I/O: Dùng mảng buffer lớn và fread để lưu hết tất cả chuỗi vào, cắt chuỗi bằng ‘\0’ và lưu con trỏ đến chuỗi lại, sau đó sort dựa theo các con trỏ đó.
	+ Dùng Radix Sort MSD: Sắp xếp các kí tự từ trái qua phải, sau đó dùng đệ quy để xử lí các kí tự trùng nhau.
	+ Khi số phần tử nhỏ (<= 32) xử dụng Insertion Sort để tối ưu.
- Lí do tối ưu nhất: Khi dùng Radix Sort theo MSD sau mỗi lần chạy thì vị trí tương đối của các chuỗi sẽ không thay đổi (bắt đầu bằng a thì chỉ di chuyển trong pool ‘a’) nên sẽ tối ưu hơn Radix Sort thường, tối ưu I/O giúp hạn chế việc swap chuỗi có kích thước lớn.
3. Bài C:
- Thuật toán sử dụng: Radix Sort.
- Các phương thức tối ưu:
	+ Phân loại chuỗi theo độ dài: Chia chuỗi có độ dài l vào bucket[l].
	+ Tối ưu I/O: Dùng mảng buffer lớn và fread để lưu hết tất cả chuỗi vào, cắt chuỗi bằng ‘\0’ và lưu con trỏ đến chuỗi lại, sau đó sort dựa theo các con trỏ đó.
	+ Dùng Radix Sort: Sắp xếp các kí tự từ phải qua trái trong từng bucket.
- Lí do tối ưu nhất: Phân loại chuỗi theo độ dài để có thể sử dụng Radix Sort giúp tăng tốc độ sắp xếp.
II. Cách thức sinh test case:
1. Bài A:
- Test 1: 
	+ Cách sinh test: Ngẫu nhiên hoàn toàn.
+ Thuật toán mục tiêu: Tất cả.
+ Lý do: Kiểm tra khả năng hoạt động tổng quát của thuật toán.
- Test 2:
	+ Cách sinh test: Bộ số tăng dần.
	+ Thuật toán mục tiêu: QuickSort với pivot đầu/cuối.
	+ Lý do: Làm tăng độ phức tạp lên O(n²).
- Test 3:
	+ Cách sinh test: Bộ số giảm dần.
	+ Thuật toán mục tiêu: QuickSort với pivot đầu/cuối, InsertionSort, BubbleSort,...
	+ Lý do: Làm tăng độ số phép swap tối đa.
- Test 4:
	+ Cách sinh test: Bộ số trùng nhau.
	+ Thuật toán mục tiêu: QuickSort với mọi cách chọn pivot.
	+ Lý do: Khiến QuickSort chỉ phân hoạch về 1 phía.
- Test 5:
	+ Cách sinh test: Bộ số dao động giữa MIN và MAX.
	+ Thuật toán mục tiêu: Các thuật toán liên quan đến đếm như Counting Sort
	+ Lý do: Tăng kích thích count array lên rất lơn khiến MLE hoặc TLE khi duyệt ngược lại.
2. Bài B
- Test 1: 
	+ Cách sinh test: Ngẫu nhiên hoàn toàn.
+ Thuật toán mục tiêu: Tất cả.
+ Lý do: Kiểm tra khả năng hoạt động tổng quát của thuật toán.
- Test 2:
+ Cách sinh test: Bộ chuỗi được sắp xếp tăng dần theo từ điển.
+ Thuật toán mục tiêu: QuickSort (áp dụng chọn pivot ở đầu hoặc cuối mảng).
+ Lý do: Việc lấy trúng cực tiểu hoặc cực đại làm pivot sẽ khiến mảng luôn bị phân hoạch về một phía, độ phức tạp suy biến thành O(n²)
- Test 3:
+ Cách sinh test: Bộ chuỗi được sắp xếp giảm dần.
+ Thuật toán mục tiêu: Insertion Sort, QuickSort.
+ Lý do: Bắt buộc Insertion Sort phải thực hiện dời chỗ qua tất cả các phần tử trước đó ở khoảng cách xa nhất, khiến tổng số phép gán tăng vọt thành O(n²)
- Test 4:
+ Cách sinh test: Các chuỗi có phần tiền tố (prefix) giống nhau rất dài.
+ Thuật toán mục tiêu: QuickSort, Merge Sort (sử dụng hàm strcmp).
+ Lý do: Làm tăng chi phí mỗi lần so sánh hai chuỗi lên mức O(L) (với L là độ dài tiền tố chung). Tích lũy lại, tổng thời gian so sánh sẽ tăng lên rất nhiều
- Test 5:
+ Cách sinh test: Chuỗi trùng nhau hoàn toàn.
+ Thuật toán mục tiêu: QuickSort.
+ Lý do: QuickSort thường không thể chia tách mảng chứa các phần tử giống nhau, làm thuật toán suy biến thành O(n²)

3. Bài C
- Test 1: 
	+ Cách sinh test: Ngẫu nhiên hoàn toàn.
+ Thuật toán mục tiêu: Tất cả.
+ Lý do: Kiểm tra khả năng hoạt động tổng quát của thuật toán.
- Test 2:
+ Cách sinh test: Bộ chuỗi được sắp xếp tăng dần theo từ điển.
+ Thuật toán mục tiêu: QuickSort (áp dụng chọn pivot ở đầu hoặc cuối mảng).
+ Lý do: Việc lấy trúng cực tiểu hoặc cực đại làm pivot sẽ khiến mảng luôn bị phân hoạch về một phía, độ phức tạp suy biến thành O(n²)
- Test 3:
+ Cách sinh test: Bộ chuỗi được sắp xếp ngược (theo từ điển giảm dần).
+ Thuật toán mục tiêu: Insertion Sort.
+ Lý do: Tối đa hóa số lần hoán đổi vị trí của các chuỗi, tạo tình huống xấu nhất với O(n²)
- Test 4:
+ Cách sinh test: Tập chuỗi chung tiền tố dài nhưng chỉ khác biệt ở các ký tự cuối cùng.
+ Thuật toán mục tiêu: Thuật toán so sánh tuần tự và MSD Radix Sort.
+ Lý do: MSD Radix Sort sẽ phải thực hiện đệ quy rất sâu vào trong để duyệt đến tận chữ cái cuối cùng mới phân biệt được, làm gia tăng nghiêm trọng chi phí gọi đệ quy (overhead)
- Test 5:
+ Cách sinh test: Chuỗi trùng nhau hoàn toàn.
+ Thuật toán mục tiêu: QuickSort.
+ Lý do: QuickSort thường không thể chia tách mảng chứa các phần tử giống nhau, làm thuật toán suy biến thành O(n²)
III. Thuật toán cài đặt tốt nhất ở lần chạy thứ hai
1. Bài A
- Thuật toán sử dụng: Radix Sort.
- Các phương thức tối ưu:
+ Lật bit dấu để tránh hiện tượng số âm lớn hơn số dương.
+ Mỗi lần sort theo 8 bit sẽ nhanh hơn radix sort hệ thập phân.
- Để tiếp tục tối ưu so với lần 1: Tối ưu hóa trực tiếp trên CPU và bộ nhớ đệm (Cache L1) bằng việc áp dụng kỹ thuật Loop Unrolling (trải vòng lặp) để giảm chi phí kiểm tra điều kiện. Sử dụng con trỏ (pointer) thay vì biến chỉ số (index) a[i] để tăng tốc độ truy cập mảng nguyên thủy.
2. Bài B:
- Thuật toán sử dụng: Radix Sort, Insertion Sort.
- Các phương thức tối ưu:
	+ Tối ưu I/O: Dùng mảng buffer lớn và fread để lưu hết tất cả chuỗi vào, cắt chuỗi bằng ‘\0’ và lưu con trỏ đến chuỗi lại, sau đó sort dựa theo các con trỏ đó.
	+ Dùng Radix Sort MSD: Sắp xếp các kí tự từ trái qua phải, sau đó dùng đệ quy để xử lí các kí tự trùng nhau.
	+ Khi số phần tử nhỏ (<= 32) sử dụng Insertion Sort để tối ưu.
- Sử dụng cùng thuật toán so với lần 1.
3. Bài C:
- Thuật toán sử dụng: Radix Sort.
- Các phương thức tối ưu:
+ Phân loại chuỗi theo độ dài vào bucket[l], tối ưu I/O với buffer cắt chuỗi ‘\0’.
+ Dùng Radix Sort sắp xếp ký tự phải qua trái trong bucket.
- Để tiếp tục tối ưu so với lần 1: Thay vì khởi tạo các bucket linh động sau mỗi lần gọi sắp xếp, tối ưu bằng cách phân bổ (pre-allocate) một vùng nhớ cố định cho các mảng bucket[l] ngay từ đầu nhằm tránh quá tải bộ nhớ và tái sử dụng chúng cho n = 10000 phần tử nhanh gọn nhất.

