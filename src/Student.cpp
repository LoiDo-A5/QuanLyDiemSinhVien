#include "Student.h"

// Constructor
SinhVien::SinhVien(const string &masv, const string &ho, const string &ten, 
                   const string &gioitinh, const string &cmnd, const string &sodt)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioitinh), CMND(cmnd), SODT(sodt), dsdangky(nullptr) {}

// Getter methods
string SinhVien::getMASV() const { return MASV; }
string SinhVien::getHO() const { return HO; }
string SinhVien::getTEN() const { return TEN; }
string SinhVien::getGIOITINH() const { return GIOITINH; }
string SinhVien::getCMND() const { return CMND; }
string SinhVien::getSODT() const { return SODT; }

// Setter methods
void SinhVien::setMASV(const string &masv) { MASV = masv; }
void SinhVien::setHO(const string &ho) { HO = ho; }
void SinhVien::setTEN(const string &ten) { TEN = ten; }
void SinhVien::setGIOITINH(const string &gioitinh) { GIOITINH = gioitinh; }
void SinhVien::setCMND(const string &cmnd) { CMND = cmnd; }
void SinhVien::setSODT(const string &sodt) { SODT = sodt; }

// Method to update grades
void SinhVien::capNhatDiem(const string &maMH, float diemMoi) {
    DIEM[maMH] = diemMoi;
}

// Method to get grades for a subject
float SinhVien::getDiem(const string &maMH) const {
    auto it = DIEM.find(maMH);
    if (it != DIEM.end()) {
        return it->second;
    }
    return -1.0f; // If not found, return -1.0 as invalid grade
}

// Method to display grades
void SinhVien::inDiem() const {
    for (const auto &entry : DIEM) {
        cout << "Môn học: " << entry.first << " - Điểm: " << entry.second << endl;
    }
}

// Method to add a registration (DangKy)
void SinhVien::themDangKy(float diem, bool huy) {
    DangKy* newDangKy = new DangKy(MASV, diem, huy);
    newDangKy->next = dsdangky;  // Add to the front of the linked list
    dsdangky = newDangKy;
}

// Method to display the registration list
void SinhVien::inDanhSachDangKy() const {
    DangKy* temp = dsdangky;
    while (temp != nullptr) {
        cout << "Mã SV: " << temp->MASV << ", Điểm: " << temp->DIEM 
             << ", Hủy đăng ký: " << (temp->huyDangKy ? "Có" : "Không") << endl;
        temp = temp->next;
    }
}

// Destructor to clean up the DangKy linked list
SinhVien::~SinhVien() {
    while (dsdangky != nullptr) {
        DangKy* temp = dsdangky;
        dsdangky = dsdangky->next;
        delete temp;  // Delete each DangKy node
    }
}

// Method to display student info
void SinhVien::inThongTin() const {
    cout << "Mã sinh viên: " << MASV << ", Họ tên: " << HO << " " << TEN 
         << ", Giới tính: " << GIOITINH << ", CMND: " << CMND 
         << ", Số điện thoại: " << SODT << endl;
}
