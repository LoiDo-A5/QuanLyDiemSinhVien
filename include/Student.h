#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <map>
#include <sstream> // Để sử dụng std::istringstream

using namespace std;

class SinhVien
{
private:
    string MASV;
    string HO;
    string TEN;
    string GIOITINH;
    string CMND;
    string SODT;
    map<string, float> DIEM;

    struct DangKy
    {
        string MASV;
        float DIEM;
        bool huyDangKy;
        DangKy *next;

        DangKy(string masv, float diem, bool huy)
            : MASV(masv), DIEM(diem), huyDangKy(huy), next(nullptr) {}
    };
    DangKy *dsdangky;

public:
    SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), CMND(""), SODT("") {}

    SinhVien(const string &masv, const string &ho, const string &ten,
             const string &gioitinh, const string &cmnd, const string &sodt)
        : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioitinh), CMND(cmnd), SODT(sodt), dsdangky(nullptr) {}

    // Getter methods
    string getMASV() const { return MASV; }
    string getHO() const { return HO; }
    string getTEN() const { return TEN; }
    string getGIOITINH() const { return GIOITINH; }
    string getCMND() const { return CMND; }
    string getSODT() const { return SODT; }

    // Setter methods
    void setMASV(const string &masv) { MASV = masv; }
    void setHO(const string &ho) { HO = ho; }
    void setTEN(const string &ten) { TEN = ten; }
    void setGIOITINH(const string &gioitinh) { GIOITINH = gioitinh; }
    void setCMND(const string &cmnd) { CMND = cmnd; }
    void setSODT(const string &sodt) { SODT = sodt; }

    // Cập nhật điểm
    void capNhatDiem(const string &maMH, float diemMoi);

    // Lấy điểm của môn học
    float getDiem(const string &maMH) const;

    // In thông tin sinh viên
    void inThongTin() const;

    // In điểm các môn học
    void inDiem() const;

    // Thêm đăng ký môn học
    void themDangKy(float diem, bool huy);

    // In danh sách đăng ký môn học
    void inDanhSachDangKy() const;

    // Destructor để giải phóng bộ nhớ
    ~SinhVien();

    std::string toString() const
    {
        // Chuyển thông tin sinh viên thành chuỗi
        return "Mã SV: " + MASV + ", Họ: " + HO + ", Tên: " + TEN +
               ", Giới tính: " + GIOITINH + ", CMND: " + CMND + ", Số điện thoại: " + SODT;
    }

    void SinhVien::fromString(const std::string& str) {
        std::istringstream ss(str);
        
        std::getline(ss, MASV, ' ');   // Đọc mã sinh viên
        std::getline(ss, HO, ' ');      // Đọc họ sinh viên
        std::getline(ss, TEN, ' ');     // Đọc tên sinh viên
        std::getline(ss, GIOITINH, ' ');// Đọc giới tính sinh viên
        std::getline(ss, CMND, ' ');    // Đọc CMND sinh viên
        std::getline(ss, SODT, ' ');    // Đọc số điện thoại sinh viên
    }
    
    
};

#endif // STUDENT_H
