# HỆ THỐNG QUẢN LÝ KỲ THI (EXAM MANAGEMENT SYSTEM)

## 1. Workflow
- Mỗi người làm việc độc lập trên module và cấu trúc dữ liệu được phân công. Tự viết file test cục bộ để đảm bảo code biên dịch thành công và chạy đúng trước khi push code lên branch của mình.
- Mạnh pull code từ branch của các thành viên, ghép nối vào hệ thống chung, quản lý mã nguồn Git, xây dựng kịch bản sinh dữ liệu thử nghiệm và UI.

## 2. Phân chia công việc chi tiết

- Mạnh:
  + Data structure: Graph (Đồ thị)
  + Algorihm: Lập lịch thi (Mô hình hóa xung đột và thuật toán xếp ca thi), Tích hợp hệ thống (Ghép nối các module C++), Python Scripts (Sinh dữ liệu & Giao diện Rich UI)

- Thành viên 1:
  + Data stucture: Dynamic Array (Mảng động), Hash Table (Bảng băm)
  + Algorihm: Quản lý thí sinh (Thêm, sửa, tìm kiếm thí sinh theo SBD), Phân chia phòng thi (Sắp xếp danh sách và chia phòng thi)

- Thành viên 2:
  + Data structre: Tree (Cây), Doubly Linked List (DSLK đôi)
  + ALgorihm: Ngân hàng câu hỏi (Lưu trữ, phân loại câu hỏi), Tổ chức đề thi (Trộn đề, sinh mã đề và điều hướng câu hỏi)

- Thành viên 3:
  + Data stucture: Min/Max Heap, Queue (Hàng đợi FIFO)
  + Algorihm: Xếp hạng (Sắp xếp kết quả theo nhiều tiêu chí, trích xuất Top-K), Tra cứu điểm (Tìm kiếm kết quả thi), Hàng đợi phúc khảo (Tiếp nhận và xử lý đơn phúc khảo)

## 3. Cấu trúc thư mục dự án
```text
├── include/
│   ├── models.h
│   └── module.h
├── dsa/
│   ├── graph.h
│   ├── vector.h
│   ├── hashtable.h
│   ├── tree.h
│   ├── linked_list.h
│   ├── heap.h
│   └── queue.h
├── modules/
│   ├── scheduler.cpp
│   ├── student_mgr.cpp
│   ├── exam_bank.cpp
│   └── ranking.cpp
├── python/
│   ├── generate_data.py
│   ├── app.py
│   └── requirements.txt
├── .gitignore
└── README.md
```


