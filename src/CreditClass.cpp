#include "CreditClass.h"
#include <iostream>

// Constructor với ID lớp tự động
CreditClass::CreditClass(int maLopTC, const std::string &maMH, const std::string &tenLop,
                         const std::string &nienKhoa, int hocKy, int nhom, int minSv, int maxSv)
    : MALOPTC(maLopTC), MAMH(maMH), tenLop(tenLop), nienKhoa(nienKhoa),
      hocKy(hocKy), nhom(nhom), soSvMin(minSv), soSvMax(maxSv), huyLop(false)
{
    // Khởi tạo DSSVDK dưới dạng danh sách sinh viên rỗng
}

// Getter cho DSSVDK (danh sách sinh viên đã đăng ký)
std::vector<SinhVien> &CreditClass::getDSSVDK()
{
    return DSSVDK;
}

// Thêm môn học vào danh sách
void CreditClass::addMonHoc(const std::string &monHoc)
{
    danhSachMonHoc.push_back(monHoc);
}

// Phương thức trả về danh sách môn học
std::vector<std::string> CreditClass::getDanhSachMonHoc() const
{
    return danhSachMonHoc;
}

// Các phương thức getter và setter khác

int CreditClass::getMALOPTC() const
{
    return MALOPTC;
}

std::string CreditClass::getMAMH() const
{
    return MAMH;
}

std::string CreditClass::getTenLop() const
{
    return tenLop;
}

std::string CreditClass::getNienKhoa() const
{
    return nienKhoa;
}

int CreditClass::getHocKy() const
{
    return hocKy;
}

int CreditClass::getNhom() const
{
    return nhom;
}

int CreditClass::getSoSvMin() const
{
    return soSvMin;
}

int CreditClass::getSoSvMax() const
{
    return soSvMax;
}

bool CreditClass::isHuyLop() const
{
    return huyLop;
}

// Setters
void CreditClass::setMAMH(const std::string &maMH)
{
    MAMH = maMH;
}

void CreditClass::setTenLop(const std::string &tenLop)
{
    this->tenLop = tenLop;
}

void CreditClass::setNienKhoa(const std::string &nienKhoa)
{
    this->nienKhoa = nienKhoa;
}

void CreditClass::setHocKy(int hocKy)
{
    this->hocKy = hocKy;
}

void CreditClass::setNhom(int nhom)
{
    this->nhom = nhom;
}

void CreditClass::setSoSvMin(int soSvMin)
{
    this->soSvMin = soSvMin;
}

void CreditClass::setSoSvMax(int soSvMax)
{
    this->soSvMax = soSvMax;
}

void CreditClass::setHuyLop(bool huy)
{
    huyLop = huy;
}

// Thêm sinh viên vào lớp tín chỉ
void CreditClass::addStudent(const SinhVien &student, bool docFile)
{
    if (DSSVDK.size() < soSvMax)
    {
        DSSVDK.push_back(student); // Thêm sinh viên vào danh sách
        if (!docFile)
            std::cout << "Sinh viên " << student.getHo() << " " << student.getTen() << " đã được thêm vào lớp tín chỉ." << std::endl;
    }
    else
    {
        if (!docFile)
            std::cout << "Lớp tín chỉ đã đầy sinh viên." << std::endl;
    }
}

// Phương thức cập nhật danh sách sinh viên
void CreditClass::capNhatDSSV(const std::vector<SinhVien> &dssv)
{
    DSSVDK = dssv; // Cập nhật danh sách sinh viên
}
