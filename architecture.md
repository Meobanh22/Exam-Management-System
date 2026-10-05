# HỆ THỐNG QUẢN LÝ KỲ THI (EXAM MANAGEMENT SYSTEM)

## 1. Workflow
- Mỗi người làm việc độc lập trên module và cấu trúc dữ liệu được phân công. Tự viết file test cục bộ để đảm bảo code biên dịch thành công và chạy đúng trước khi push code lên branch của mình.
- Mạnh pull code từ branch của các thành viên, ghép nối vào hệ thống chung, quản lý mã nguồn Git, xây dựng kịch bản sinh dữ liệu thử nghiệm và UI.

## 2. Phân chia công việc chi tiết

- Mạnh:
  + Giai đoạn 1: Graph (Đồ thị)
  + Giai đoạn 2: Lập lịch thi (Mô hình hóa xung đột và thuật toán xếp ca thi), Tích hợp hệ thống (Ghép nối các module C++), Python Scripts (Sinh dữ liệu & Giao diện Rich UI)

- Thành viên 1:
  + Giai đoạn 1: Dynamic Array (Mảng động), Hash Table (Bảng băm)
  + Giai đoạn 2: Quản lý thí sinh (Thêm, sửa, tìm kiếm thí sinh theo SBD), Phân chia phòng thi (Sắp xếp danh sách và chia phòng thi)

- Thành viên 2:
  + Giai đoạn 1: Tree (Cây), Doubly Linked List (DSLK đôi)
  + Giai đoạn 2: Ngân hàng câu hỏi (Lưu trữ, phân loại câu hỏi), Tổ chức đề thi (Trộn đề, sinh mã đề và điều hướng câu hỏi)

- Thành viên 3:
  + Giai đoạn 1: Min/Max Heap, Queue (Hàng đợi FIFO)
  + Giai đoạn 2: Xếp hạng (Sắp xếp kết quả theo nhiều tiêu chí, trích xuất Top-K), Tra cứu điểm (Tìm kiếm kết quả thi), Hàng đợi phúc khảo (Tiếp nhận và xử lý đơn phúc khảo)

## 3. Cấu trúc thư mục dự án
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
