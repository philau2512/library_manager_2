#include <iostream>
#include <string.h>
using namespace std;
#include "statistics.h"
#include "user.h"
#include "book.h"
#include "borrow.h"
#include "return.h"
#include "utils.h"

void showMenuThongKe() {
    cout << "1. Thong ke so luong sach trong thu vien" << endl;
    cout << "2. Thong ke so luong sach theo the loai" << endl;
    cout << "3. Thong ke so luong doc gia" << endl;
    cout << "4. Thong ke so luong doc gia theo gioi tinh" << endl;
    cout << "5. Thong ke so sach dang duoc muon" << endl;
    cout << "6. Thong ke danh sach doc gia bi tre han" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void quanLyThongKe() {
    int choice;
    docDuLieuDocGia();
    docDuLieuSach();
    docDuLieuPhieuMuon();
    docDuLieuPhieuTra();
    do {
        showMenuThongKe();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                thongKeSoLuongSach();
                break;
            case 2:
                thongKeSoLuongSachTheoTheLoai();
                break;
            case 3:
                thongKeSoLuongDocGia();
                break;
            case 4:
                thongKeSoLuongDocGiaTheoGioiTinh();
                break;
            case 5:
                thongKeSoSachDangDuocMuon();
                break;
            case 6:
                thongKeDanhSachDocGiaBiTreHan();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Nhap sai, vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

void thongKeSoLuongSach() {

}

void thongKeSoLuongSachTheoTheLoai() {

}

void thongKeSoLuongDocGia() {

}

void thongKeSoLuongDocGiaTheoGioiTinh() {

}

void thongKeSoSachDangDuocMuon() {
}

void thongKeDanhSachDocGiaBiTreHan() {

}
