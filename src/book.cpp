#include <iostream>
#include <string.h>
#include "book.h"
using namespace std;

Book danhSachSach[MAX_BOOKS];
int soLuongSach = 0;

void showMenuQuanLySach() {
    cout << "1. Xem danh sach 'Sach'\n";
    cout << "2. Them sach moi\n";
    cout << "3. Chinh sua sach\n";
    cout << "4. Xoa sach\n";
    cout << "5. Tim kiem sach theo ISBN ( maSach )\n";
    cout << "6. Tim kiem sach theo ten\n";
    cout << "0. Quay lai menu chinh\n";
    cout << "Chon chuc nang: ";
}

void quanLySach() {
    int choice;
    docDuLieuSach(); // Đọc dữ liệu khi vào menu quản lý sách

    do {
        showMenuQuanLySach();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                xemSach();
                break;
            case 2:
                themSach();
                break;
            case 3:
                chinhSuaSach();
                break;
            case 4:
                xoaSach();
                break;
            case 5:
                timSachTheoISBN();
                break;
            case 6:
                timSachTheoTen();
                break;
            case 0:
                cout << "Quay lai menu chinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);
}

void xemSach() {
    if (soLuongSach == 0) {
        cout << "Danh sach sach rong." << endl;
        return;
    }
    cout << "Danh sach sach:" << endl;
    cout << "Ma Sach | Ten Sach | Tac Gia | Nha Xuat Ban | Nam Xuat Ban | The Loai | Gia Sach | So Luong" << endl;
    for (int i = 0; i < soLuongSach; i++) {
        inThongTinSach(danhSachSach[i]);
    }
    cout << endl;
}

void themSach() {
    if (soLuongSach >= MAX_BOOKS) {
        cout << "[X] Danh sach sach day. Khong the them moi." << endl;
        return;
    }
    Book sachMoi;
    cout << "Nhap thong tin sach moi:" << endl;

    cout << "Ma Sach (ISBN): ";
    cin.getline(sachMoi.maSach, MAX_ISBN_LENGTH);

    if (tonTaiMaSach(sachMoi.maSach)) {
        cout << "[X] Ma sach da ton tai. Khong the them moi." << endl;
        return;
    }

    cout << "Ten Sach: ";
    cin.getline(sachMoi.tenSach, MAX_TEXT_LENGTH);

    cout << "Tac gia: ";
    cin.getline(sachMoi.tacGia, MAX_TEXT_LENGTH);

    cout << "Nha xuat ban: ";
    cin.getline(sachMoi.nhaXuatBan, MAX_TEXT_LENGTH);

    cout << "Nam xuat ban: ";
    cin >> sachMoi.namXuatBan;
    cin.ignore();

    cout << "The loai: ";
    cin.getline(sachMoi.theLoai, MAX_TEXT_LENGTH);

    cout << "Gia sach: ";
    cin >> sachMoi.giaSach;
    cin.ignore();

    cout << "So luong: ";
    cin >> sachMoi.soLuong;
    cin.ignore();

    danhSachSach[soLuongSach++] = sachMoi;
    luuDuLieuSach();

    soLuongSach++;
    cout << "[OK] Them sach moi thanh cong!" << endl;
}

void chinhSuaSach() {
    char maSachCanSua[MAX_ISBN_LENGTH];
    cout << "Nhap ISBN sach can sua: ";
    cin.getline(maSachCanSua, MAX_ISBN_LENGTH);

    int viTri = timViTriSach(maSachCanSua);
    if (viTri == -1) {
        cout << "Khong tim thay sach!\n";
        return;
    }

    cout << "\nNHAP THONG TIN MOI:\n";
    cout << "Ten sach: ";
    cin.getline(danhSachSach[viTri].tenSach, MAX_TEXT_LENGTH);

    cout << "Tac gia: ";
    cin.getline(danhSachSach[viTri].tacGia, MAX_TEXT_LENGTH);

    cout << "Nha xuat ban: ";
    cin.getline(danhSachSach[viTri].nhaXuatBan, MAX_TEXT_LENGTH);

    cout << "Nam xuat ban: ";
    cin >> danhSachSach[viTri].namXuatBan;
    cin.ignore();

    cout << "The loai: ";
    cin.getline(danhSachSach[viTri].theLoai, MAX_TEXT_LENGTH);

    cout << "Gia sach: ";
    cin >> danhSachSach[viTri].giaSach;
    cin.ignore();

    cout << "So luong: ";
    cin >> danhSachSach[viTri].soLuong;
    cin.ignore();

    luuDuLieuSach();
    cout << "Cap nhat thong tin sach thanh cong!\n";
}

void xoaSach() {
    char maSachCanXoa[MAX_ISBN_LENGTH];
    cout << "Nhap ISBN sach can xoa: ";
    cin.getline(maSachCanXoa, MAX_ISBN_LENGTH);

    int viTri = timViTriSach(maSachCanXoa);
    if (viTri == -1) {
        cout << "Khong tim thay sach!\n";
        return;
    }

    // Dịch chuyển các phần tử
    for (int i = viTri; i < soLuongSach - 1; i++) {
        danhSachSach[i] = danhSachSach[i + 1];
    }
    soLuongSach--;

    luuDuLieuSach();
    cout << "Xoa sach thanh cong!\n";
}

void timSachTheoISBN() {
    char maSachCanTim[MAX_ISBN_LENGTH];
    cout << "Nhap ISBN can tim: ";
    cin.getline(maSachCanTim, MAX_ISBN_LENGTH);

    int viTri = timViTriSach(maSachCanTim);
    if (viTri == -1) {
        cout << "Khong tim thay sach!\n";
        return;
    }

    cout << "\nTHONG TIN SACH TIM THAY:\n";
    inThongTinSach(danhSachSach[viTri]);
}

void timSachTheoTen() {
    char tenCanTim[MAX_TEXT_LENGTH];
    cout << "Nhap ten sach can tim: ";
    cin.getline(tenCanTim, MAX_TEXT_LENGTH);

    bool timThay = false;
    cout << "\nKET QUA TIM KIEM:\n";

    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(danhSachSach[i].tenSach, tenCanTim) != NULL) {
            inThongTinSach(danhSachSach[i]);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sach nao!\n";
    }
}

int timViTriSach(const char *maSach) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSachSach[i].maSach, maSach) == 0) {
            return i;
        }
    }
    return -1;
}

bool tonTaiMaSach(const char *maSach) {
    return timViTriSach(maSach) != -1;
}

bool coTheMuonSach(const char *maSach) {
    int viTri = timViTriSach(maSach);
    return viTri != -1 && danhSachSach[viTri].soLuong > 0;
}

bool giamSoLuongSach(const char *maSach) {
    int viTri = timViTriSach(maSach);
    if (viTri != -1 && danhSachSach[viTri].soLuong > 0) {
        danhSachSach[viTri].soLuong--;
        luuDuLieuSach();
        return true;
    }
    return false;
}

bool tangSoLuongSach(const char *maSach) {
    int viTri = timViTriSach(maSach);
    if (viTri != -1) {
        danhSachSach[viTri].soLuong++;
        luuDuLieuSach();
        return true;
    }
    return false;
}

void inThongTinSach(const Book &sach) {
    cout << sach.maSach << " | "
            << sach.tenSach << " | "
            << sach.tacGia << " | "
            << sach.nhaXuatBan << " | "
            << sach.namXuatBan << " | "
            << sach.theLoai << " | "
            << sach.giaSach << " | "
            << sach.soLuong << endl;
    cout << endl;
}

void luuDuLieuSach() {
    FILE *file = fopen("../data/books.txt", "w");
    if (file == NULL) {
        cout << "Loi: Khong the mo file books.txt de ghi!\n";
        return;
    }

    fprintf(file, "%d\n", soLuongSach);
    for (int i = 0; i < soLuongSach; i++) {
        fprintf(file, "%s\n", danhSachSach[i].maSach);
        fprintf(file, "%s\n", danhSachSach[i].tenSach);
        fprintf(file, "%s\n", danhSachSach[i].tacGia);
        fprintf(file, "%s\n", danhSachSach[i].nhaXuatBan);
        fprintf(file, "%d\n", danhSachSach[i].namXuatBan);
        fprintf(file, "%s\n", danhSachSach[i].theLoai);
        fprintf(file, "%lf\n", danhSachSach[i].giaSach);
        fprintf(file, "%d\n", danhSachSach[i].soLuong);
    }
    fclose(file);
}

void docDuLieuSach() {
    FILE *file = fopen("../data/books.txt", "r");
    if (file == NULL) {
        cout << "Loi: Khong the mo file books.txt de doc!\n";
        return;
    }

    fscanf(file, "%d\n", &soLuongSach);
    for (int i = 0; i < soLuongSach; i++) {
        fgets(danhSachSach[i].maSach, MAX_ISBN_LENGTH, file);
        fgets(danhSachSach[i].tenSach, MAX_TEXT_LENGTH, file);
        fgets(danhSachSach[i].tacGia, MAX_TEXT_LENGTH, file);
        fgets(danhSachSach[i].nhaXuatBan, MAX_TEXT_LENGTH, file);
        fscanf(file, "%d\n", &danhSachSach[i].namXuatBan);
        fgets(danhSachSach[i].theLoai, MAX_TEXT_LENGTH, file);
        fscanf(file, "%lf\n", &danhSachSach[i].giaSach);
        fscanf(file, "%d\n", &danhSachSach[i].soLuong);

        // Xóa ký tự '\n' ở cuối chuỗi
        danhSachSach[i].maSach[strcspn(danhSachSach[i].maSach, "\n")] = '\0';
        danhSachSach[i].tenSach[strcspn(danhSachSach[i].tenSach, "\n")] = '\0';
        danhSachSach[i].tacGia[strcspn(danhSachSach[i].tacGia, "\n")] = '\0';
        danhSachSach[i].theLoai[strcspn(danhSachSach[i].theLoai, "\n")] = '\0';
        danhSachSach[i].nhaXuatBan[strcspn(danhSachSach[i].nhaXuatBan, "\n")] = '\0';
    }
    fclose(file);
}
