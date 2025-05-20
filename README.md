# Quản Lý Thư Viện

## Giới Thiệu
Chương trình quản lý thư viện trên nền console, dành cho việc quản lý độc giả, sách và các phiếu mượn/trả sách tại Thư viện.

## Yêu Cầu Kỹ Thuật
- Chương trình sử dụng giao diện menu để người dùng chọn và thực hiện chức năng.
- Chỉ sử dụng các kiểu dữ liệu cơ bản và mảng một chiều.
- Lưu trữ dữ liệu xuống tập tin.
- Sử dụng `struct`.
- Mã nguồn chương trình phải được tổ chức thành các file và các hàm rõ ràng.
- Trước mỗi hàm, phải có comment mô tả chức năng và tham số truyền vào, giá trị trả về.

## Các Chức Năng Chính

### 1. Quản Lý Độc Giả
- Xem danh sách độc giả trong thư viện.
- Thêm độc giả mới.
- Chỉnh sửa thông tin một độc giả.
- Xóa thông tin một độc giả.
- Tìm kiếm độc giả theo CMND.
- Tìm kiếm độc giả theo họ tên.

### 2. Quản Lý Sách
- Xem danh sách các sách trong thư viện.
- Thêm sách mới.
- Chỉnh sửa thông tin một quyển sách.
- Xóa thông tin sách.
- Tìm kiếm sách theo ISBN.
- Tìm kiếm sách theo tên sách.

### 3. Lập Phiếu Mượn Sách
- Lập phiếu mượn sách cho độc giả.

### 4. Lập Phiếu Trả Sách
- Lập phiếu trả sách cho độc giả.

### 5. Các Thống Kê Cơ Bản
- Thống kê số lượng sách trong thư viện.
- Thống kê số lượng sách theo thể loại.
- Thống kê số lượng độc giả.
- Thống kê số lượng độc giả theo giới tính.
- Thống kê số sách đang được mượn.
- Thống kê danh sách độc giả bị trễ hạn.

## Chi Tiết Quản Lý Dữ Liệu

### 1. Thông Tin Độc Giả
Mỗi độc giả sẽ có các thông tin như sau:
- Mã độc giả
- Họ tên
- CMND
- Ngày tháng năm sinh
- Giới tính
- Email
- Địa chỉ
- Ngày lập thẻ và ngày hết hạn của thẻ (48 tháng kể từ ngày lập thẻ)

### 2. Thông Tin Sách
Mỗi sách sẽ có các thông tin như sau:
- ISBN (Mã sách)
- Tên sách
- Tác giả
- Nhà xuất bản
- Năm xuất bản
- Thể loại
- Giá sách
- Số lượng quyển sách

### 3. Phiếu Mượn/Trả
#### Phiếu mượn:
- Mã độc giả
- Ngày mượn
- Ngày trả dự kiến
- Danh sách ISBN mượn
#### Phiếu trả:
- Mã độc giả
- Ngày mượn
- Ngày trả thực tế
- Danh sách ISBN trả

## Các Quy Định
- Mỗi sách có thể được mượn tối đa 7 ngày. Nếu quá hạn, sẽ bị phạt tiền 5.000 đồng mỗi ngày.
- Nếu sách bị mất, độc giả sẽ bị phạt 200% giá trị của sách.

## Cài Đặt và Sử Dụng
1. **Cài Đặt**:  
   Không cần cài đặt phức tạp. Chương trình có thể được biên dịch và chạy trực tiếp trên môi trường console.

2. **Sử Dụng**:
   - Chạy chương trình và sử dụng các lựa chọn trong menu để quản lý thư viện.
   - Lựa chọn các chức năng như quản lý độc giả, sách, lập phiếu mượn/trả và thống kê.

## Cấu Trúc Dự Án
```
/src
├── main.cpp               # Menu chính
├── menu.cpp / .h          # Hiển thị menu
├── user.cpp / .h          # Quản lý độc giả
├── book.cpp / .h          # Quản lý sách
├── borrow.cpp / .h        # Quản lý phiếu mượn/trả
├── statistics.cpp / .h    # Thống kê
├── utils.cpp / .h         # Hàm tiện ích
```