#include "Class.h"
#include "IsValid.h"

// Hàm khởi tạo mặc định
Lop::Lop() : MALOP(""), TENLOP(""), danhSachSinhVien(nullptr) {}

// Hàm khởi tạo có tham số
Lop::Lop(const std::string &malop, const std::string &tenlop) : MALOP(malop), TENLOP(tenlop), danhSachSinhVien(nullptr) {}

// Hàm lấy mã lớp
std::string Lop::getCode()
{
    return MALOP;
}

// Phương thức để nhập thông tin lớp
void Lop::nhapThongTin()
{
    std::cout << "Nhập mã lớp: ";
    std::cin >> MALOP;
    if (!isValidCode(MALOP))
    {
        std::cout << "Mã lớp không hợp lệ, vui lòng nhập lại!" << std::endl;
        return;
    }
    std::cout << "Nhập tên lớp: ";
    std::cin.ignore();              // Xóa bỏ ký tự newline còn lại trong bộ đệm
    std::getline(std::cin, TENLOP); // Đọc toàn bộ dòng văn bản, bao gồm cả khoảng trắng
}

// Phương thức để thêm sinh viên vào danh sách
void Lop::addStudent(const SinhVien &student)
{
    SinhVienNode *newNode = new SinhVienNode(student); // Tạo node mới chứa sinh viên
    if (danhSachSinhVien == nullptr)
    {
        danhSachSinhVien = newNode; // Nếu danh sách rỗng, đặt node mới làm đầu danh sách
    }
    else
    {
        SinhVienNode *current = danhSachSinhVien;
        while (current->next != nullptr)
        {
            current = current->next; // Tìm đến node cuối cùng
        }
        current->next = newNode; // Đặt node mới vào cuối danh sách
    }
}

// Phương thức để in thông tin lớp
void Lop::printClassInfo() const
{
    std::cout << "Mã lớp: " << MALOP << ", Tên lớp: " << TENLOP << std::endl;
    std::cout << "Danh sách sinh viên: " << std::endl;

    SinhVienNode *current = danhSachSinhVien;
    while (current != nullptr)
    {
        current->student.inThongTin(); // In thông tin sinh viên
        current = current->next;       // Di chuyển đến sinh viên kế tiếp
    }
}

// Getter cho MALOP và TENLOP
std::string Lop::getClassID() const
{
    return MALOP;
}

std::string Lop::getClassName() const
{
    return TENLOP;
}

// Phương thức xóa sinh viên theo mã sinh viên
bool Lop::removeStudent(const std::string &maSV)
{
    SinhVienNode *current = danhSachSinhVien;
    SinhVienNode *previous = nullptr;

    while (current != nullptr)
    {
        if (current->student.getMASV() == maSV)
        {
            if (previous == nullptr)
            { // Nếu sinh viên cần xóa là sinh viên đầu tiên
                danhSachSinhVien = current->next;
            }
            else
            {
                previous->next = current->next; // Bỏ qua node cần xóa
            }
            delete current; // Xóa node
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false; // Không tìm thấy sinh viên
}

// Phương thức tìm sinh viên theo mã sinh viên
SinhVien *Lop::findStudent(const std::string &maSV)
{
    SinhVienNode *current = danhSachSinhVien;
    while (current != nullptr)
    {
        if (current->student.getMASV() == maSV)
        {
            return &current->student; // Trả về con trỏ đến sinh viên
        }
        current = current->next;
    }
    return nullptr; // Không tìm thấy sinh viên
}
