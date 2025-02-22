#include "CreditClassList.h"
#include "CreditClass.h"
#include <iostream>
#include <fstream> // Để sử dụng ofstream
#include <sstream>

// Constructor
CreditClassList::CreditClassList() : count(0) {}

void CreditClassList::addCreditClass(CreditClass *creditClass)
{
    if (count < 10000) // Kiểm tra nếu chưa vượt quá giới hạn mảng
    {
        creditClasses[count++] = *creditClass; // Thêm lớp tín chỉ vào mảng
    }
    else
    {
        std::cerr << "Đã vượt quá giới hạn lớp tín chỉ." << std::endl;
    }
}

void CreditClassList::displayCreditClasses()
{
    if (count == 0)
    {
        std::cout << "Danh sách lớp tín chỉ rỗng." << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        std::cout << "Mã lớp tín chỉ: " << creditClasses[i].getMALOPTC()
                  << ", Mã môn học: " << creditClasses[i].getMAMH()
                  << ", Tên lớp: " << creditClasses[i].getTenLop()
                  << ", Niên khóa: " << creditClasses[i].getNienKhoa()
                  << ", Học kỳ: " << creditClasses[i].getHocKy()
                  << ", Nhóm: " << creditClasses[i].getNhom()
                  << ", Số sinh viên tối thiểu: " << creditClasses[i].getSoSvMin()
                  << ", Số sinh viên tối đa: " << creditClasses[i].getSoSvMax()
                  << ", Trạng thái hủy lớp: " << (creditClasses[i].isHuyLop() ? "Có" : "Không")
                  << std::endl;
    }
}

void CreditClassList::removeCreditClass(int malopTC)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getMALOPTC() == malopTC)
        {
            // Di chuyển các lớp còn lại lên để "xóa" lớp
            for (int j = i; j < count - 1; ++j)
            {
                creditClasses[j] = creditClasses[j + 1];
            }
            --count; // Giảm số lượng lớp
            std::cout << "Lớp tín chỉ với mã " << malopTC << " đã được xóa." << std::endl;
            return;
        }
    }
    std::cerr << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << std::endl;
}

CreditClass *CreditClassList::findCreditClassByMALOPTC(int malopTC)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getMALOPTC() == malopTC)
        {
            return &creditClasses[i];
        }
    }
    return nullptr; // Return nullptr if not found
}

void CreditClassList::cancelCreditClasses()
{
    int soLopHuy = 0;
    for (int i = 0; i < count; ++i)
    {
        // Lấy danh sách sinh viên đăng ký
        SinhVienNode *dssvdk = creditClasses[i].getDSSVDK();

        // Đếm số lượng sinh viên đăng ký
        int soSinhVien = 0;
        while (dssvdk != nullptr)
        {
            soSinhVien++;
            dssvdk = dssvdk->next;
        }

        // Kiểm tra nếu số sinh viên ít hơn số sinh viên tối thiểu
        if (soSinhVien < creditClasses[i].getSoSvMin())
        {
            std::string luaChon;
            do
            {
                std::cout << "Đồng ý hủy lớp " << creditClasses[i].getMALOPTC() << "?(Y/N)" << std::endl;
                std::cin >> luaChon;
                if (luaChon == "Y")
                {
                    soLopHuy++;
                    creditClasses[i].setHuyLop(true); // Đặt trạng thái hủy
                    std::cout << "Lớp tín chỉ với mã " << creditClasses[i].getMALOPTC() << " đã được hủy." << std::endl;
                }
            } while (luaChon != "Y" && luaChon != "N");
        }
    }
    if (soLopHuy == 0)
    {
        std::cout << "Không tìm được lớp không đủ điều kiện để hủy!" << std::endl;
    }
}

CreditClass *CreditClassList::findClassesByParams(const std::string &nienKhoa, int hocKy)
{
    for (int i = 0; i < count; ++i)
    {
        if ((nienKhoa.empty() || creditClasses[i].getNienKhoa() == nienKhoa) &&
            (hocKy == 0 || creditClasses[i].getHocKy() == hocKy))
        {
            return &creditClasses[i];
        }
    }
    return nullptr; // Return nullptr if not found
}

CreditClass *CreditClassList::findClass(const std::string &nienKhoa,
                                        int hocKy, int nhom, const std::string &maMH)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getNienKhoa() == nienKhoa && creditClasses[i].getHocKy() == hocKy &&
            creditClasses[i].getNhom() == nhom && creditClasses[i].getMAMH() == maMH)
        {
            return &creditClasses[i];
        }
    }
    return nullptr;
}

bool CreditClassList::registerStudent(const std::string &maMH, const SinhVien &sinhVien)
{
    bool daDangKy = false;
    for (int i = 0; i < count; ++i)
    {
        if (maMH == creditClasses[i].getMAMH())
        {
            creditClasses[i].addStudent(sinhVien);
            daDangKy = true;
        }
    }
    return daDangKy;
}

void CreditClassList::saveToFile(const std::string &filename)
{
    std::ofstream outFile(filename); // Open file to save data

    if (!outFile)
    {
        return;
    }

    // Save credit classes
    for (int i = 0; i < count; ++i)
    {
        outFile << creditClasses[i].getMALOPTC() << " "
                << creditClasses[i].getMAMH() << " "
                << creditClasses[i].getTenLop() << " "
                << creditClasses[i].getNienKhoa() << " "
                << creditClasses[i].getHocKy() << " "
                << creditClasses[i].getNhom() << " "
                << creditClasses[i].getSoSvMin() << " "
                << creditClasses[i].getSoSvMax() << " "
                << creditClasses[i].isHuyLop() << std::endl;

        // Write student details
        SinhVienNode *current = creditClasses[i].getDSSVDK(); // Bắt đầu từ phần tử đầu tiên của danh sách
        while (current != nullptr)
        {
            outFile << current->student.toString() << std::endl; // Lưu thông tin sinh viên
            current = current->next;                             // Di chuyển đến sinh viên kế tiếp trong danh sách
        }

        outFile << std::endl; // Đánh dấu kết thúc của lớp
    }

    outFile.close(); // Đóng file
}

void CreditClassList::readFromFile(const std::string &filename)
{
    std::ifstream inFile(filename); // Open file to read data

    if (!inFile)
    {
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        if (line.empty())
            continue;

        std::istringstream classStream(line);

        // Read class details
        int MALOPTC, hocKy, nhom, soSvMin, soSvMax;
        std::string MAMH, tenLop, nienKhoa;
        bool huyLop;

        classStream >> MALOPTC >> MAMH >> tenLop >> nienKhoa >> hocKy >> nhom >> soSvMin >> soSvMax >> huyLop;

        // Create CreditClass instance
        CreditClass creditClass(MALOPTC, MAMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);

        // Read student details
        while (std::getline(inFile, line) && !line.empty())
        {
            SinhVien student;
            student.fromString(line);              // Parse student details
            creditClass.addStudent(student); // Add student to class
        }

        // Add class to the array
        addCreditClass(&creditClass); // Add class to array
    }

    inFile.close(); // Close file
}

CreditClass *CreditClassList::findClassesByMsv(const std::string &msv)
{
    for (int i = 0; i < count; ++i)
    {
        SinhVienNode *current = creditClasses[i].getDSSVDK(); // Bắt đầu từ phần tử đầu tiên trong danh sách
        while (current != nullptr)
        {
            if (current->student.getMASV() == msv)
            {
                return &creditClasses[i]; // Nếu tìm thấy sinh viên, trả về lớp tín chỉ
            }
            current = current->next; // Di chuyển đến sinh viên tiếp theo
        }
    }
    return nullptr; // Không tìm thấy sinh viên
}
