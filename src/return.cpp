#include <iostream>
#include <string.h>
using namespace std;
#include "return.h"
#include "borrow.h"
#include "book.h"
#include "utils.h"

ReturnRecord danhSachPhieuTra[MAX_RETURN_RECORDS];
int soLuongPhieuTra = 0;

void showMenuTraSach() {
    cout << "1. Lap phieu tra" << endl;
    cout << "2. Hien thi phieu tra" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void quanLyTraSach() {
    int choice;
    docDuLieuPhieuTra(); // Đọc dữ liệu khi vào menu quản lý trả sách
    do {
        showMenuTraSach();
        cin >> choice;
        switch (choice) {
            case 1:
                lapPhieuTraSach();
                break;
            case 2:
                hienThiPhieuTra();
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Nhap sai. Vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

void lapPhieuTraSach() {
    if (soLuongPhieuTra >= MAX_RETURN_RECORDS) {
        cout << "Danh sach phieu tra day. Khong the them moi." << endl;
        return;
    }

    ReturnRecord phieuTraMoi;

    cout << "Nhap ma doc gia tra: ";
    cin.ignore();
    cin.getline(phieuTraMoi.maDocGiaTra, MAX_DOC_GIA_ID_LENGTH);

    int indexPhieuMuon = timViTriPhieuMuon(phieuTraMoi.maDocGiaTra);
    if (indexPhieuMuon == -1) {
        cout << "[X] Doc gia khong co phieu muon sach." << endl;
        return;
    }

    cout << "Nhap ngay tra thuc te (dd/mm/yyyy): ";
    cin.getline(phieuTraMoi.ngayTraThucTe, MAX_DATE_LENGTH);

    // Copy danh sách sách từ phiếu mượn
    phieuTraMoi.soLuongSachTra = danhSachPhieuMuon[indexPhieuMuon].soLuongSachMuon;
    for (int i = 0; i < phieuTraMoi.soLuongSachTra; i++) {
        strcpy(phieuTraMoi.danhSachISBNTra[i],
               danhSachPhieuMuon[indexPhieuMuon].danhSachISBNMuon[i]);
        // Tăng số lượng sách khi trả
        bool status = tangSoLuongSach(phieuTraMoi.danhSachISBNTra[i]);
        if (!status) {
            cout << "[X] Loi khi tra sach " << endl;
            return;
        }
    }

    danhSachPhieuTra[soLuongPhieuTra++] = phieuTraMoi;
    luuDuLieuPhieuTra();
    cout << "[OK] Lap phieu tra thanh cong !" << endl;

    int daysDiff = countExpiredDay(danhSachPhieuMuon[indexPhieuMuon].ngayMuon, phieuTraMoi.ngayTraThucTe);
    if (daysDiff > 0) {
        cout << "[X] Doc gia " << phieuTraMoi.maDocGiaTra << " da tre han " << daysDiff << " ngay." << endl;
        cout << "---> So tien phai tra: " << daysDiff * 5000 << " VND" << endl;
    }
}

void hienThiPhieuTra() {
    if (soLuongPhieuTra == 0) {
        cout << "Danh sach phieu tra rong." << endl;
        return;
    }

    cout << "Danh sach phieu tra:" << endl;

    for (int i = 0; i < soLuongPhieuTra; i++) {
        cout << "Phieu tra thu " << i + 1 << ":" << endl;
        cout << "Ma doc gia: " << danhSachPhieuTra[i].maDocGiaTra << endl;
        cout << "Ngay tra thuc te: " << danhSachPhieuTra[i].ngayTraThucTe << endl;
        cout << "Danh sach ISBN tra:" << endl;
        for (int j = 0; j < danhSachPhieuTra[i].soLuongSachTra; j++) {
            if (danhSachPhieuTra[i].danhSachISBNTra[j][0] != '\0') {
                cout << danhSachPhieuTra[i].danhSachISBNTra[j] << " ";
            } else {
                break;
            }
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
}

void luuDuLieuPhieuTra() {
    FILE *file = fopen("../data/return.txt", "w");
    if (file == NULL) {
        cout << "Loi: Khong the mo file return.txt de ghi!\n";
        return;
    }

    fprintf(file, "%d\n", soLuongPhieuTra);
    for (int i = 0; i < soLuongPhieuTra; i++) {
        fprintf(file, "%s|%s|%d\n",
                danhSachPhieuTra[i].maDocGiaTra,
                danhSachPhieuTra[i].ngayTraThucTe,
                danhSachPhieuTra[i].soLuongSachTra);
        for (int j = 0; j < danhSachPhieuTra[i].soLuongSachTra; j++) {
            fprintf(file, "%s ", danhSachPhieuTra[i].danhSachISBNTra[j]);
        }
    }
    fclose(file);
}

void docDuLieuPhieuTra() {
    FILE *file = fopen("../data/return.txt", "r");
    if (file == NULL) {
        cout << "Loi: Khong the mo file return.txt de doc!\n";
        return;
    }
    fscanf(file, "%d", &soLuongPhieuTra);
    for (int i = 0; i < soLuongPhieuTra; i++) {
        fscanf(file, "%s|%s|%d",
               danhSachPhieuTra[i].maDocGiaTra,
               danhSachPhieuTra[i].ngayTraThucTe,
               &danhSachPhieuTra[i].soLuongSachTra);
        for (int j = 0; j < danhSachPhieuTra[i].soLuongSachTra; j++) {
            fscanf(file, "%s", danhSachPhieuTra[i].danhSachISBNTra[j]);
        }
    }
    fclose(file);
}
