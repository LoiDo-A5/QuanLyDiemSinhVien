#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include <string>

class CreditClassList
{
private:
    CreditClass creditClasses[10000]; // Mảng các lớp tín chỉ, cố định kích thước
    int count;                        // Số lượng lớp tín chỉ hiện có

public:
    CreditClassList();

    // Thêm lớp tín chỉ
    void addCreditClass(CreditClass *creditClass);

    // Xóa lớp tín chỉ
    void removeCreditClass(int malopTC);

    // Tìm lớp tín chỉ theo mã
    CreditClass *findCreditClassByMALOPTC(int malopTC);

    // Hiển thị danh sách lớp tín chỉ
    void displayCreditClasses();

    // Xóa các lớp tín chỉ không đủ sinh viên
    void cancelCreditClasses();

    // Tìm lớp tín chỉ theo tham số
    CreditClass *findClassesByParams(const std::string &nienKhoa, int hocKy);

    // Tìm lớp tín chỉ theo mã môn học, học kỳ, nhóm, niên khóa
    CreditClass *findClass(const std::string &nienKhoa, int hocKy, int nhom, const std::string &maMH);

    // Đăng ký sinh viên vào lớp tín chỉ
    bool registerStudent(const std::string &maMH, const SinhVien &sinhVien);

    // Lưu thông tin lớp tín chỉ vào file
    void saveToFile(const std::string &filename);

    // Đọc thông tin lớp tín chỉ từ file
    void readFromFile(const std::string &filename);

    // Tìm lớp theo mã sinh viên
    CreditClass *findClassesByMsv(const std::string &msv);
};

#endif // CREDIT_CLASS_LIST_H
