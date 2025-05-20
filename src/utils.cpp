#include <stdio.h>
#include "utils.h"
using namespace std;

// hàm kiểm tra năm nhuận
inline bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

// hàm tự động tính ngày hết hạn thẻ đọc giả (48 tháng)
void calculateExpiryDate(const char *startDate, char *expiryDate) {
    int day, month, year;
    sscanf(startDate, "%d/%d/%d", &day, &month, &year);

    month += 48; // Cộng 48 tháng (4 năm)

    // Kiểm tra nếu tháng > 12 thì cộng thêm năm và làm lại tháng
    if (month > 12) {
        year += month / 12; // Cộng thêm năm
        month = month % 12; // Lấy tháng còn lại (từ 1 đến 12)
    }

    // Nếu tháng = 0, thì chỉnh lại tháng thành 12 và giảm năm đi 1
    if (month == 0) {
        month = 12;
        year--;
    }

    // Lưu ngày hết hạn vào mảng expiryDate
    sprintf(expiryDate, "%02d/%02d/%d", day, month, year);
}

// tính ngày trả dự kiến dựa vào ngày mượn ( +7 ngày )
void tinhNgayTraSachDuKien(const char *startDate, char *expiryDate) {
    int day, month, year;
    sscanf(startDate, "%d/%d/%d", &day, &month, &year);

    // Số ngày trong các tháng
    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    day += 7;

    // Kiểm tra nếu ngày vượt quá số ngày trong tháng thì cộng thêm tháng
    while (day > daysInMonth[month - 1]) {
        day = day - daysInMonth[month - 1]; // Giảm số ngày đi theo tháng
        month++; // Thêm tháng
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // Lưu ngày trả sách dự kiện vào mảng expiryDate
    sprintf(expiryDate, "%02d/%02d/%d", day, month, year);
}

int countExpiredDay(const char *ngayMuon, const char *ngayTraThucTe) {
    int dayMuon, monthMuon, yearMuon;
    int dayTra, monthTra, yearTra;
    sscanf(ngayMuon, "%d/%d/%d", &dayMuon, &monthMuon, &yearMuon);
    sscanf(ngayTraThucTe, "%d/%d/%d", &dayTra, &monthTra, &yearTra);

    // Tính tổng số ngày kể từ ngày đầu năm
    int daysMuon = 0;
    for (int i = 1; i < monthMuon; i++) {
        if (i == 2) {
            daysMuon += isLeapYear(yearMuon) ? 29 : 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            daysMuon += 30;
        } else {
            daysMuon += 31;
        }
    }
    daysMuon += dayMuon;

    int daysTra = 0;
    for (int i = 1; i < monthTra; i++) {
        if (i == 2) {
            daysTra += isLeapYear(yearTra) ? 29 : 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            daysTra += 30;
        } else {
            daysTra += 31;
        }
    }
    daysTra += dayTra;

    // Tính số ngày chênh lệch giữa các năm
    int daysDiff = 0;
    for (int i = yearMuon; i < yearTra; i++) {
        daysDiff += isLeapYear(i) ? 366 : 365;
    }

    // Tính tổng số ngày chênh lệch
    daysDiff = daysDiff + daysTra - daysMuon;

    // Trả về số ngày quá hạn (trễ hạn)
    return daysDiff - 7;
}