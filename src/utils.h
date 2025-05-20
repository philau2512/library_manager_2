#ifndef UTILS_H
#define UTILS_H
// hàm kiểm tra năm nhuận
inline bool isLeapYear(int year);

// hàm tự động tính ngày hết hạn thẻ đọc giả (48 tháng)
void calculateExpiryDate(const char *startDate, char *expiryDate);

// tính ngày trả dự kiến dựa vào ngày mượn ( +7 ngày )
void tinhNgayTraSachDuKien(const char *startDate, char *expiryDate);

// Hàm tính xem ngày trả thực tế - ngày mượn xem có > 7 không, trả về số ngày quá hạn
int countExpiredDay(const char *ngayMuon, const char* ngayTraThucTe);

#endif //UTILS_H
