#include <iostream>
#include <string.h>
#include "user.h"
#include "utils.h"
using namespace std;

User danhSachDocGia[MAX_USERS];
int soLuongDocGia = 0;

// Hàm hiển thị menu quản lý độc giả
void showMenuDocGia() {
    cout << "1. Xem danh sach doc gia\n";
    cout << "2. Them doc gia moi\n";
    cout << "3. Chinh sua thong tin doc gia\n";
    cout << "4. Xoa thong tin doc gia\n";
    cout << "5. Tim kiem doc gia theo CMND\n";
    cout << "6. Tim kiem doc gia theo ho ten\n";
    cout << "0. Quay lai menu chinh\n";
    cout << "--> Nhap lua chon: ";
}

// Hàm quản lý độc giả
void quanLyDocGia() {
    int choice;
    docDuLieuDocGia(); // Đọc dữ liệu khi vào menu quản lý độc giả

    do {
        showMenuDocGia();
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự '\n' còn lại trong buffer
        switch (choice) {
            case 1:
                xemDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3:
                chinhSuaDocGia();
                break;
            case 4:
                xoaDocGia();
                break;
            case 5:
                timDocGiaTheoCmnd();
                break;
            case 6:
                timDocGiaTheoHoTen();
                break;
            case 0:
                cout << "Quay lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);
}

void xemDanhSachDocGia() {
    if (soLuongDocGia == 0) {
        cout << "Danh sach doc gia rong.\n";
        return;
    }
    cout << "Danh sach doc gia:\n";
    cout << "Ma doc gia | Ho ten | CMND | Birthday | Gioi tinh | Email | Dia chi | Ngay lap the | Ngay het han\n";
    for (int i = 0; i < soLuongDocGia; i++) {
        inThongTinDocGia(danhSachDocGia[i]);
    }
    cout << endl;
};

void themDocGia() {
    if (soLuongDocGia >= MAX_USERS) {
        cout << "[X] Danh sach doc gia da day. Khong the them moi.\n";
        return;
    }
    User docGiaMoi;
    cout << "Nhap thong tin doc gia moi:\n";

    cout << "Nhap ma doc gia: ";
    cin.getline(docGiaMoi.maDocGia, MAX_DOC_GIA_ID_LENGTH);

    if (tonTaiMaDocGia(docGiaMoi.maDocGia)) {
        cout << "[X] Ma doc gia da ton tai. Khong the them moi.\n";
        return;
    }

    cout << "Nhap ho ten: ";
    cin.getline(docGiaMoi.hoTen, MAX_TEXT_LENGTH);

    cout << "Nhap CMND: ";
    cin.getline(docGiaMoi.cmnd, MAX_TEXT_LENGTH);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(docGiaMoi.birth, MAX_DATE_LENGTH);

    cout << "Nhap gioi tinh (Nam/Nu): ";
    cin.getline(docGiaMoi.gioiTinh, MAX_GENDER_LENGTH);

    cout << "Nhap email: ";
    cin.getline(docGiaMoi.email, MAX_TEXT_LENGTH);

    cout << "Nhap dia chi: ";
    cin.getline(docGiaMoi.diaChi, MAX_TEXT_LENGTH);

    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    cin.getline(docGiaMoi.ngayLapThe, MAX_DATE_LENGTH);

    calculateExpiryDate(docGiaMoi.ngayLapThe, docGiaMoi.ngayHetHan);
    cout << "Ngay het han (dd/mm/yyyy): " << docGiaMoi.ngayHetHan << endl;

    danhSachDocGia[soLuongDocGia++] = docGiaMoi;
    luuDuLieuDocGia();
    cout << "[OK] Them doc gia thanh cong!\n";
};

void chinhSuaDocGia() {
    char maDocGiaCanSua[MAX_DOC_GIA_ID_LENGTH];
    cout << "Nhap ma doc gia can chinh sua: ";
    cin.getline(maDocGiaCanSua, MAX_DOC_GIA_ID_LENGTH);

    // Tìm vị trí độc giả cần chỉnh sửa
    int viTri = timViTriDocGia(maDocGiaCanSua);
    if (viTri == -1) {
        cout << "Khong tim thay doc gia!\n";
        return;
    }

    cout << "Nhap thong tin doc gia " << maDocGiaCanSua << " can chinh sua:" << endl;

    cout << "Nhap ho ten: ";
    cin.getline(danhSachDocGia[viTri].hoTen, MAX_TEXT_LENGTH);

    cout << "Nhap CMND: ";
    cin.getline(danhSachDocGia[viTri].cmnd, MAX_TEXT_LENGTH);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin.getline(danhSachDocGia[viTri].birth, MAX_DATE_LENGTH);

    cout << "Nhap gioi tinh (Nam/Nu): ";
    cin.getline(danhSachDocGia[viTri].gioiTinh, MAX_GENDER_LENGTH);

    cout << "Nhap email: ";
    cin.getline(danhSachDocGia[viTri].email, MAX_TEXT_LENGTH);

    cout << "Nhap dia chi: ";
    cin.getline(danhSachDocGia[viTri].diaChi, MAX_TEXT_LENGTH);

    cout << "Nhap ngay lap the (dd/mm/yyyy): ";
    cin.getline(danhSachDocGia[viTri].ngayLapThe, MAX_DATE_LENGTH);

    calculateExpiryDate(danhSachDocGia[viTri].ngayLapThe, danhSachDocGia[viTri].ngayHetHan);
    cout << "Ngay het han (dd/mm/yyyy): " << danhSachDocGia[viTri].ngayHetHan << endl;

    luuDuLieuDocGia();
    cout << "[OK] Chinh sua doc gia thanh cong!" << endl;
};

void xoaDocGia() {
    char maDocGiaCanXoa[MAX_DOC_GIA_ID_LENGTH];
    cout << "Nhap ma doc gia can xoa: ";
    cin.getline(maDocGiaCanXoa, MAX_DOC_GIA_ID_LENGTH);

    int viTri = timViTriDocGia(maDocGiaCanXoa);
    if (viTri == -1) {
        cout << "Khong tim thay doc gia!\n";
        return;
    }

    for (int i = viTri; i < soLuongDocGia - 1; i++) {
        danhSachDocGia[i] = danhSachDocGia[i + 1];
    }

    soLuongDocGia--;
    luuDuLieuDocGia();

    cout << "[OK] Xoa doc gia thanh cong!" << endl;
};

void timDocGiaTheoCmnd() {
    char cmndCanTim[MAX_TEXT_LENGTH];
    cout << "Nhap CMND cua doc gia can tim: ";
    cin.getline(cmndCanTim, MAX_TEXT_LENGTH);

    bool found = false;
    cout << "Danh sach doc gia co CMND " << cmndCanTim << ":" << endl;
    cout << "STT | Ma doc gia | Ho ten | CMND | Birthday | Gioi tinh | Email | Dia chi | Ngay lap the | Ngay het han\n";
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(danhSachDocGia[i].cmnd, cmndCanTim) == 0) {
            inThongTinDocGia(danhSachDocGia[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay doc gia co CMND " << cmndCanTim << endl;
    }
    cout << endl;
};

void timDocGiaTheoHoTen() {
    char hoTenCanTim[MAX_TEXT_LENGTH];
    cout << "Nhap ho ten cua doc gia can tim: ";
    cin.getline(hoTenCanTim, MAX_TEXT_LENGTH);

    bool found = false;
    cout << "Danh sach doc gia co ten - " << hoTenCanTim << endl;
    cout << "Ma doc gia | Ho ten | CMND | Birthday | Gioi tinh | Email | Dia chi | Ngay lap the | Ngay het han\n";

    // dùng strstr để lấy tên gần đúng || dùng strcmp để tìm chính xác tên
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strstr(danhSachDocGia[i].hoTen, hoTenCanTim) != NULL) {
            inThongTinDocGia(danhSachDocGia[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay doc gia co ten " << hoTenCanTim << endl;
    }
    cout << endl;
};

int timViTriDocGia(const char *maDocGia) {
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(danhSachDocGia[i].maDocGia, maDocGia) == 0) {
            return i;
        }
    }
    return -1;
}

bool tonTaiMaDocGia(const char *maDocGia) {
    return timViTriDocGia(maDocGia) != -1;
}

void inThongTinDocGia(const User &docGia) {
    cout << docGia.maDocGia << " | "
            << docGia.hoTen << " | "
            << docGia.cmnd << " | "
            << docGia.birth << " | "
            << docGia.gioiTinh << " | "
            << docGia.email << " | "
            << docGia.diaChi << " | "
            << docGia.ngayLapThe << " | "
            << docGia.ngayHetHan << endl;
}

void luuDuLieuDocGia() {
    FILE *file = fopen("../data/users.txt", "w");
    if (file == NULL) {
        cout << "Khong the mo file users.txt de ghi !" << endl;
        return;
    }
    fprintf(file, "%d\n", soLuongDocGia);
    for (int i = 0; i < soLuongDocGia; i++) {
        fprintf(file, "%s\n", danhSachDocGia[i].maDocGia);
        fprintf(file, "%s\n", danhSachDocGia[i].hoTen);
        fprintf(file, "%s\n", danhSachDocGia[i].cmnd);
        fprintf(file, "%s\n", danhSachDocGia[i].birth);
        fprintf(file, "%s\n", danhSachDocGia[i].gioiTinh);
        fprintf(file, "%s\n", danhSachDocGia[i].email);
        fprintf(file, "%s\n", danhSachDocGia[i].diaChi);
        fprintf(file, "%s\n", danhSachDocGia[i].ngayLapThe);
        fprintf(file, "%s\n", danhSachDocGia[i].ngayHetHan);
    }
    fclose(file);
}

void docDuLieuDocGia() {
    FILE *file = fopen("../data/users.txt", "r");
    if (file == NULL) {
        cout << "Khong the mo file users.txt de doc !" << endl;
        return;
    }
    fscanf(file, "%d\n", &soLuongDocGia);
    for (int i = 0; i < soLuongDocGia; i++) {
        fgets(danhSachDocGia[i].maDocGia, sizeof(danhSachDocGia[i].maDocGia), file);
        fgets(danhSachDocGia[i].hoTen, sizeof(danhSachDocGia[i].hoTen), file);
        fgets(danhSachDocGia[i].cmnd, sizeof(danhSachDocGia[i].cmnd), file);
        fgets(danhSachDocGia[i].birth, sizeof(danhSachDocGia[i].birth), file);
        fgets(danhSachDocGia[i].gioiTinh, sizeof(danhSachDocGia[i].gioiTinh), file);
        fgets(danhSachDocGia[i].email, sizeof(danhSachDocGia[i].email), file);
        fgets(danhSachDocGia[i].diaChi, sizeof(danhSachDocGia[i].diaChi), file);
        fgets(danhSachDocGia[i].ngayLapThe, sizeof(danhSachDocGia[i].ngayLapThe), file);
        fgets(danhSachDocGia[i].ngayHetHan, sizeof(danhSachDocGia[i].ngayHetHan), file);

        // Xóa ký tự '\n' nếu có
        danhSachDocGia[i].maDocGia[strcspn(danhSachDocGia[i].maDocGia, "\n")] = '\0';
        danhSachDocGia[i].hoTen[strcspn(danhSachDocGia[i].hoTen, "\n")] = '\0';
        danhSachDocGia[i].cmnd[strcspn(danhSachDocGia[i].cmnd, "\n")] = '\0';
        danhSachDocGia[i].birth[strcspn(danhSachDocGia[i].birth, "\n")] = '\0';
        danhSachDocGia[i].gioiTinh[strcspn(danhSachDocGia[i].gioiTinh, "\n")] = '\0';
        danhSachDocGia[i].email[strcspn(danhSachDocGia[i].email, "\n")] = '\0';
        danhSachDocGia[i].diaChi[strcspn(danhSachDocGia[i].diaChi, "\n")] = '\0';
        danhSachDocGia[i].ngayLapThe[strcspn(danhSachDocGia[i].ngayLapThe, "\n")] = '\0';
        danhSachDocGia[i].ngayHetHan[strcspn(danhSachDocGia[i].ngayHetHan, "\n")] = '\0';
    }

    fclose(file);
}
