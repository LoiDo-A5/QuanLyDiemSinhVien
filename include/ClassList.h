#ifndef CLASSLIST_H
#define CLASSLIST_H

#include "Class.h"
#include "Student.h"

class ClassList
{
private:
    Lop classes[1000]; // Danh sách lớp (không dùng vector hay mảng con trỏ)
    int classCount;

public:
    ClassList();
    int getClassCount();
    void addClass(const Lop &newClass);                                           // Thêm lớp
    void printClasses();                                                          // In danh sách lớp
    void addStudentToClass(const std::string &malop, const SinhVien &newStudent); // Thêm sinh viên vào lớp
    void updateClass(const std::string &malop, Lop updatedClass);                 // Cập nhật lớp
    bool removeStudent(const std::string &malop, const std::string &maSV);        // Xóa sinh viên khỏi lớp
    Lop *findClassByCode(const std::string &malop);                               // Tìm lớp theo mã lớp
    bool removeClassByCode(const std::string &malop);                             // Xóa lớp bằng mã lớp
    SinhVien *findSinhVienById(const std::string &maSV);                          // Lấy thông tin sinh viên bằng mã sinh viên
    void saveToFile(const std::string &filename);
    void readFromFile(const std::string &filename);
};

#endif // CLASSLIST_H
