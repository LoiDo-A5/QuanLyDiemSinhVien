#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include "Student.h"

class SinhVienNode
{
public:
    SinhVien student;   // Sinh viên
    SinhVienNode *next; // Con trỏ đến sinh viên tiếp theo

    SinhVienNode(const SinhVien &student) : student(student), next(nullptr) {}
};

class Lop
{
private:
    std::string MALOP;              // Mã lớp
    std::string TENLOP;             // Tên lớp
    SinhVienNode *danhSachSinhVien; // Danh sách sinh viên trong lớp (danh sách liên kết đơn)

public:
    Lop();
    Lop(const std::string &malop, const std::string &tenlop);

    std::string getCode();
    void nhapThongTin();
    void addStudent(const SinhVien &student);
    void printClassInfo() const;
    std::string getClassID() const;
    std::string getClassName() const;
    bool removeStudent(const std::string &maSV);
    SinhVien *findStudent(const std::string &maSV);
    const SinhVienNode *getStudents() const
    {
        return danhSachSinhVien;
    }
};

#endif // CLASS_H
