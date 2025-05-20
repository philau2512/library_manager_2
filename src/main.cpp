#include <iostream>
#include "menu.h"
#include "user.h"
#include "book.h"
#include "borrow.h"
#include "return.h"
#include "statistics.h"
using namespace std;

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "===== QUAN LY DOC GIA =====" << endl;
                quanLyDocGia();
                break;
            case 2:
                cout << "===== QUAN LY SACH =====" << endl;
                quanLySach();
                break;
            case 3:
                cout << "===== LAP PHIEU MUON SACH =====" << endl;
                quanLyMuonSach();
                break;
            case 4:
                cout << "===== LAP PHIEU TRA SACH =====" << endl;
                quanLyTraSach();
                break;
            case 5:
                cout << "===== THONG KE =====" << endl;
                quanLyThongKe();
                break;
            case 0:
                cout << "===== THOAT CHUONG TRINH =====" << endl;
                exit(0);
            default:
                cout << "Invalid Choice, Try Again ..." << endl;
                break;
        }
    }
}
