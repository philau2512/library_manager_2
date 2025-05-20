#ifndef BORROW_H
#define BORROW_H
#include "data.h"

void quanLyMuonSach(); // Hàm quản lý mượn sách
void showMenuMuonSach(); // show menu chuc nang

void lapPhieuMuonSach(); // Hàm lập phiếu mượn sách
void hienThiPhieuMuon(); // Hiển thị tất cả phiếu mượn

int timViTriPhieuMuon(const char *maDocGia); // hàm tìm index phiếu mượn theo Mã Độc Giả
bool tonTaiPhieuMuon(const char *maDocGia); // kiểm tra sự tồn tại của phiếu mượn ( true/false )
void luuDuLieuPhieuMuon(); // lưu dữ liệu phiếu mượn xuống file
void docDuLieuPhieuMuon(); // đọc dữ liệu phiếu mượn từ file
#endif //BORROW_H