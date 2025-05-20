#ifndef DATA_H
#define DATA_H

// Khai báo số lượng tối đa độc giả
const int MAX_USERS = 100;

// Khai báo số lượng sách tối đa
const int MAX_BOOKS = 100;

// Giới hạn độ dài các mảng = biến
const int MAX_BORROW_RECORDS = 100;
const int MAX_RETURN_RECORDS = 100;
const int MAX_BOOKS_PER_RECORD = 5; // Giới hạn số sách mượn/trả tối đa
const int MAX_DOC_GIA_ID_LENGTH = 10;
const int MAX_ISBN_LENGTH = 10;
const int MAX_DATE_LENGTH = 15; // dd/mm/yyyy
const int MAX_TEXT_LENGTH = 100;
const int MAX_GENDER_LENGTH = 10;

// Định nghĩa cấu trúc cho độc giả
struct User {
    char maDocGia[MAX_DOC_GIA_ID_LENGTH];
    char hoTen[MAX_TEXT_LENGTH];
    char cmnd[MAX_TEXT_LENGTH];
    char birth[MAX_DATE_LENGTH];
    char gioiTinh[MAX_GENDER_LENGTH];
    char email[MAX_TEXT_LENGTH];
    char diaChi[MAX_TEXT_LENGTH];
    char ngayLapThe[MAX_DATE_LENGTH];
    char ngayHetHan[MAX_DATE_LENGTH];
};

// Định nghĩa cấu trúc cho sách
struct Book {
    char maSach[MAX_ISBN_LENGTH];
    char tenSach[MAX_TEXT_LENGTH];
    char tacGia[MAX_TEXT_LENGTH];
    char theLoai[MAX_TEXT_LENGTH];
    char nhaXuatBan[MAX_TEXT_LENGTH];
    int namXuatBan;
    int soLuong;
};

// Định nghĩa cấu trúc cho phiếu mượn
struct BorrowRecord {
    char maDocGiaMuon[MAX_DOC_GIA_ID_LENGTH];
    char ngayMuon[MAX_DATE_LENGTH];
    char ngayTraDuKien[MAX_DATE_LENGTH];
    char danhSachISBNMuon[MAX_BOOKS_PER_RECORD][MAX_ISBN_LENGTH];
    int soLuongSachMuon;
};

// Định nghĩa cấu trúc cho một phiếu trả
struct ReturnRecord {
    char maDocGiaTra[MAX_DOC_GIA_ID_LENGTH];
    char ngayTraThucTe[MAX_DATE_LENGTH];
    char danhSachISBNTra[MAX_BOOKS_PER_RECORD][MAX_ISBN_LENGTH];
    int soLuongSachTra;
};

// Khai báo mảng các struct và biến đếm
extern User danhSachDocGia[MAX_USERS];
extern int soLuongDocGia;

extern Book danhSachSach[MAX_BOOKS];
extern int soLuongSach;

extern BorrowRecord danhSachPhieuMuon[MAX_BORROW_RECORDS];
extern int soLuongPhieuMuon;

extern ReturnRecord danhSachPhieuTra[MAX_RETURN_RECORDS];
extern int soLuongPhieuTra;

#endif //DATA_H
