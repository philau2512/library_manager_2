#ifndef BOOK_H
#define BOOK_H

#include "data.h"

void quanLySach(); // Hàm quản lý sách
void showMenuQuanLySach(); // hàm hiển thị menu chức năng
void xemSach(); // Xem tất cả sách
void themSach(); // Thêm sách mới
void chinhSuaSach(); // Chỉnh sửa sách
void xoaSach(); // Xóa sách
void timSachTheoISBN(); // Tìm sách theo mã sách
void timSachTheoTen(); // Tìm sách theo tên sách

int timViTriSach(const char* maSach); // Tìm vị trí sách trong mảng, trả về -1 nếu không tìm thấy
bool tonTaiMaSach(const char *maSach); // kiểm tra sự tồn tại của mã sách ( true/false )
bool coTheMuonSach(const char *maSach); // Kiểm tra nếu số lượng sách > 0 thì cho mượn !
bool giamSoLuongSach(const char *maSach); // Giảm số lượng sách khi mượn
bool tangSoLuongSach(const char *maSach); // Tăng số lượng sách khi trả

void inThongTinSach(const Book& sach); // Hàm in thông tin sách
void luuDuLieuSach(); // Lưu dữ liệu sách xuống file
void docDuLieuSach(); // Đọc dữ liệu sách từ file

#endif // BOOK_H
