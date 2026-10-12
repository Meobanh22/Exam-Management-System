# HỆ THỐNG TỔ CHỨC, QUẢN LÝ KỲ THI

## 1. Phân chia công việc chi tiết

- Mạnh:
  + Data structure: Graph (Đồ thị)
  + Algorihm: Lập lịch thi (Mô hình hóa xung đột và thuật toán xếp ca thi), Tích hợp hệ thống (Ghép nối các module C++), Python Scripts (Sinh dữ liệu & Giao diện Rich UI)

- Lộc:
  + Data stucture: Dynamic Array (Mảng động), Hash Table (Bảng băm)
  + Algorihm: Quản lý thí sinh (Thêm, sửa, tìm kiếm thí sinh theo SBD), Phân chia phòng thi (Sắp xếp danh sách và chia phòng thi)

- Khoa:
  + Data structre: Tree (Cây), Doubly Linked List (DSLK đôi)
  + ALgorihm: Ngân hàng câu hỏi (Lưu trữ, phân loại câu hỏi), Tổ chức đề thi (Trộn đề, sinh mã đề và điều hướng câu hỏi)

- Lâm:
  + Data stucture: Min/Max Heap, Queue (Hàng đợi FIFO)
  + Algorihm: Xếp hạng (Sắp xếp kết quả theo nhiều tiêu chí, trích xuất Top-K), Tra cứu điểm (Tìm kiếm kết quả thi), Hàng đợi phúc khảo (Tiếp nhận và xử lý đơn phúc khảo)

## 2. Cấu trúc thư mục dự án
```text
├── include/
│   ├── ds.h
│   └── module.h
├── ds/
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


