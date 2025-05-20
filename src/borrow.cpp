#include <iostream>
#include <string.h>
#include "borrow.h"
#include "utils.h"
#include "user.h"
#include "book.h"
using namespace std;

BorrowRecord danhSachPhieuMuon[MAX_BORROW_RECORDS];
int soLuongPhieuMuon = 0;


void showMenuMuonSach() {
    cout << "1. Lap phieu muon" << endl;
    cout << "2. Hien thi phieu muon" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

void quanLyMuonSach() {
    int choice;
    docDuLieuDocGia();
    docDuLieuSach();
    docDuLieuPhieuMuon(); // Đọc dữ liệu khi vào menu quản lý mượn sách
    do {
        showMenuMuonSach();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                lapPhieuMuonSach();
                break;
            case 2:
                hienThiPhieuMuon();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Nhap sai, vui long nhap lai." << endl;
        }
    } while (choice != 0);
}

void lapPhieuMuonSach() {
    if (soLuongPhieuMuon >= MAX_BORROW_RECORDS) {
        cout << "So luong phieu muon da dat gioi han!\n";
        return;
    }

    BorrowRecord phieuMuonMoi;

    cout << "Nhap ma doc gia muon: ";
    cin.getline(phieuMuonMoi.maDocGiaMuon, MAX_DOC_GIA_ID_LENGTH);

    if (!tonTaiMaDocGia(phieuMuonMoi.maDocGiaMuon)) {
        cout << "[X] Ma doc gia - " << phieuMuonMoi.maDocGiaMuon << " khong ton tai, hay kiem tra lai." << endl;
        return;
    }
    cout << "Nhap ngay muon (dd/mm/yyyy): ";
    cin.getline(phieuMuonMoi.ngayMuon, MAX_DATE_LENGTH);

    tinhNgayTraSachDuKien(phieuMuonMoi.ngayMuon, phieuMuonMoi.ngayTraDuKien);

    cout << "So luong sach muon muon (toi da " << MAX_BOOKS_PER_RECORD << "):";
    cin >> phieuMuonMoi.soLuongSachMuon;

    if (phieuMuonMoi.soLuongSachMuon > MAX_BOOKS_PER_RECORD) {
        cout << "[X] So luong sach muon khong duoc qua " << MAX_BOOKS_PER_RECORD << "." << endl;
        return;
    }

    cin.ignore();

    cout << "Nhap danh sach ISBN muon: " << endl;
    for (int i = 0; i < phieuMuonMoi.soLuongSachMuon; i++) {
        cout << "Nhap ma IBSN thu " << i + 1 << ": ";
        cin.getline(phieuMuonMoi.danhSachISBNMuon[i], MAX_ISBN_LENGTH);

        // kiểm tra mã sách có tồn tại
        if (tonTaiMaSach(phieuMuonMoi.danhSachISBNMuon[i])) {
            // kiểm tra số lượng sách đó > 0
            if (coTheMuonSach(phieuMuonMoi.danhSachISBNMuon[i])) {
                bool status = giamSoLuongSach(phieuMuonMoi.danhSachISBNMuon[i]); // giảm 1 cuốn đã cho mượn
                if (!status) {
                    cout << "[X] Loi khi them sach - " << phieuMuonMoi.danhSachISBNMuon[i] << endl;
                    return;
                }
            } else {
                cout << "[X] Sach - " << phieuMuonMoi.danhSachISBNMuon[i] << " da het, khong the muon." << endl;
                return;
            }
        } else {
            cout << "[X] Ma ISBN - " << phieuMuonMoi.danhSachISBNMuon[i] << " khong ton tai, hay kiem tra lai." <<
                    endl;
            return;
        }
    }
    danhSachPhieuMuon[soLuongPhieuMuon++] = phieuMuonMoi;
    luuDuLieuPhieuMuon();
    cout << "[OK] Lap phieu muon sach thanh cong." << endl;
}

void hienThiPhieuMuon() {
    if (soLuongPhieuMuon == 0) {
        cout << "Khong co phieu muon nao." << endl;
        return;
    }

    cout << "\nDANH SACH PHIEU MUON:\n";

    for (int i = 0; i < soLuongPhieuMuon; i++) {
        cout << "Phieu muon thu " << i + 1 << ":" << endl;
        cout << "Ma doc gia: " << danhSachPhieuMuon[i].maDocGiaMuon << endl;
        cout << "Ngay muon: " << danhSachPhieuMuon[i].ngayMuon << endl;
        cout << "Ngay tra du kien: " << danhSachPhieuMuon[i].ngayTraDuKien << endl;
        cout << "Danh sach ISBN muon:" << endl;
        for (int j = 0; j < MAX_BOOKS_PER_RECORD; j++) {
            if (danhSachPhieuMuon[i].danhSachISBNMuon[j][0] != '\0') {
                cout << danhSachPhieuMuon[i].danhSachISBNMuon[j] << "\t";
            } else {
                break;
            }
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
}

int timViTriPhieuMuon(const char *maDocGia) {
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (stricmp(danhSachPhieuMuon[i].maDocGiaMuon, maDocGia) == 0) {
            return i;
        }
    }
    return -1;
}

bool tonTaiPhieuMuon(const char *maDocGia) {
    return timViTriPhieuMuon(maDocGia) != -1;
}

void luuDuLieuPhieuMuon() {
    FILE *file = fopen("../data/borrow.txt", "w");
    if (!file) {
        cout << "Loi: Khong the mo file borrow.txt de ghi!\n";
        return;
    }

    fprintf(file, "%d\n", soLuongPhieuMuon);
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        fprintf(file, "%s\n", danhSachPhieuMuon[i].maDocGiaMuon);
        fprintf(file, "%s\n", danhSachPhieuMuon[i].ngayMuon);
        fprintf(file, "%s\n", danhSachPhieuMuon[i].ngayTraDuKien);
        fprintf(file, "%d\n", danhSachPhieuMuon[i].soLuongSachMuon);

        for (int j = 0; j < danhSachPhieuMuon[i].soLuongSachMuon; j++) {
            fprintf(file, "%s\n", danhSachPhieuMuon[i].danhSachISBNMuon[j]);
        }
    }
    fclose(file);
}

void docDuLieuPhieuMuon() {
    FILE *file = fopen("../data/borrow.txt", "r");
    if (!file) {
        cout << "Chua co du lieu phieu muon!\n";
        return;
    }

    fscanf(file, "%d\n", &soLuongPhieuMuon);
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        fgets(danhSachPhieuMuon[i].maDocGiaMuon, MAX_DOC_GIA_ID_LENGTH, file);
        fgets(danhSachPhieuMuon[i].ngayMuon, MAX_DATE_LENGTH, file);
        fgets(danhSachPhieuMuon[i].ngayTraDuKien, MAX_DATE_LENGTH, file);
        fscanf(file, "%d\n", &danhSachPhieuMuon[i].soLuongSachMuon);

        for (int j = 0; j < danhSachPhieuMuon[i].soLuongSachMuon; j++) {
            fscanf(file, "%s\n", danhSachPhieuMuon[i].danhSachISBNMuon[j]);
        }

        // Xóa ký tự xuống dòng ở cuối chuỗi
        danhSachPhieuMuon[i].maDocGiaMuon[strcspn(danhSachPhieuMuon[i].maDocGiaMuon, "\n")] = '\0';
        danhSachPhieuMuon[i].ngayMuon[strcspn(danhSachPhieuMuon[i].ngayMuon, "\n")] = '\0';
        danhSachPhieuMuon[i].ngayTraDuKien[strcspn(danhSachPhieuMuon[i].ngayTraDuKien, "\n")] = '\0';
        for (int j = 0; j < danhSachPhieuMuon[i].soLuongSachMuon; j++) {
            danhSachPhieuMuon[i].danhSachISBNMuon[j][strcspn(danhSachPhieuMuon[i].danhSachISBNMuon[j], "\n")] = '\0';
        }
    }
    fclose(file);
}
