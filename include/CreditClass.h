#ifndef CREDIT_CLASS_H
#define CREDIT_CLASS_H

#include <string>
#include "Student.h"

// Định nghĩa SinhVienNode (dùng cho danh sách liên kết đơn)
struct SinhVienNode
{
    SinhVien student;   // Thông tin sinh viên
    SinhVienNode *next; // Con trỏ đến phần tử tiếp theo trong danh sách

    // Constructor cho node
    SinhVienNode(const SinhVien &sv) : student(sv), next(nullptr) {}
};

class CreditClass
{
private:
    int MALOPTC;          // Mã lớp tín chỉ
    std::string MAMH;     // Mã môn học
    std::string tenLop;   // Tên lớp
    std::string nienKhoa; // Niên khóa
    int hocKy;            // Học kỳ
    int nhom;             // Nhóm
    int soSvMin;          // Số sinh viên tối thiểu
    int soSvMax;          // Số sinh viên tối đa
    bool huyLop;          // Trạng thái hủy lớp
    SinhVienNode *dssvdk; // Danh sách sinh viên đăng ký lớp tín chỉ (danh sách liên kết đơn)

public:
    // Constructor
    CreditClass(int MALOPTC, const std::string &MAMH, const std::string &tenLop,
                const std::string &nienKhoa, int hocKy, int nhom,
                int soSvMin, int soSvMax);

    // Nếu bạn cần constructor mặc định
    CreditClass();

    // Getter và Setter
    void addStudent(const SinhVien &student); // Thêm sinh viên vào danh sách đăng ký
    void capNhatDSSV(SinhVienNode *dssv);     // Cập nhật danh sách sinh viên
    void inDSSV() const;                      // In danh sách sinh viên đăng ký

    // Getter các thông tin khác
    int getMALOPTC() const;
    std::string getMAMH() const;
    std::string getTenLop() const;
    std::string getNienKhoa() const;
    int getHocKy() const;
    int getNhom() const;
    int getSoSvMin() const;
    int getSoSvMax() const;
    bool isHuyLop() const;

    // Setters cho các trường
    void setMAMH(const std::string &maMH);
    void setTenLop(const std::string &tenLop);
    void setNienKhoa(const std::string &nienKhoa);
    void setHocKy(int hocKy);
    void setNhom(int nhom);
    void setSoSvMin(int soSvMin);
    void setSoSvMax(int soSvMax);
    void setHuyLop(bool huy);

    // Getter cho danh sách sinh viên đăng ký
    SinhVienNode *getDSSVDK() const; // Trả về con trỏ đến danh sách sinh viên
};

#endif // CREDIT_CLASS_H
