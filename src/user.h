#ifndef USER_H
#define USER_H

#include "data.h"

void quanLyDocGia(); // Quản lý độc giả
void showMenuDocGia(); // Hiển thị menu quản lý độc giả

void xemDanhSachDocGia(); // Xem danh sách độc giả
void themDocGia(); // Thêm độc giả mới
void chinhSuaDocGia(); // Chỉnh sửa thông tin độc giả
void xoaDocGia(); // Xóa thông tin độc giả
void timDocGiaTheoCmnd(); // Tìm độc giả theo CMND
void timDocGiaTheoHoTen(); // Tìm độc giả theo họ tên

// Các hàm tiện ích
int timViTriDocGia(const char *maDocGia); // Trả về vị trí độc giả, -1 nếu không tìm thấy
bool tonTaiMaDocGia(const char *maDocGia);
void inThongTinDocGia(const User &docGia);
void luuDuLieuDocGia(); // Lưu dữ liệu độc giả xuống file
void docDuLieuDocGia(); // Đọc dữ liệu độc giả từ file

#endif //USER_H
