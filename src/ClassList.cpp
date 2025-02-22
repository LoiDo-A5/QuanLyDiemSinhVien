#include "ClassList.h"
#include "Node.h"
#include <iostream>
#include <fstream> // Để sử dụng ofstream
#include <sstream>
using namespace std;

ClassList::ClassList() : classCount(0) {}

int ClassList::getClassCount()
{
    return classCount;
}

void ClassList::addClass(const Lop &newClass)
{
    if (classCount < 1000)
    {
        // Thêm lớp vào danh sách
        classes[classCount++] = newClass; // Không cần new vì đối tượng đã có sẵn trong tham số
    }
    else
    {
        cout << "Danh sách lớp đã đầy!" << endl;
    }
}

void ClassList::printClasses()
{
    for (int i = 0; i < classCount; i++)
    {
        classes[i].printClassInfo(); // Không cần dùng con trỏ vì lớp đã được tạo sẵn
    }
}

void ClassList::updateClass(const string &malop, Lop updatedClass)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i].getClassID() == malop)
        {
            // Giữ lại sinh viên của lớp cũ bằng cách duyệt qua danh sách sinh viên
            const SinhVienNode *current = classes[i].getStudents(); // Lấy danh sách sinh viên của lớp hiện tại
            while (current != nullptr)
            {
                updatedClass.addStudent(current->student); // Thêm sinh viên vào lớp mới
                current = current->next;                   // Di chuyển đến sinh viên tiếp theo
            }

            // Cập nhật lớp mới vào danh sách lớp
            classes[i] = updatedClass;
            cout << "Cập nhật lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

void ClassList::addStudentToClass(const string &malop, const SinhVien &newStudent)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i].getClassID() == malop)
        {
            classes[i].addStudent(newStudent); // Thêm sinh viên vào lớp
            cout << "Thêm sinh viên " << newStudent.getMASV() << " vào lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

Lop *ClassList::findClassByCode(const string &malop)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i].getClassID() == malop)
        {
            return &classes[i]; // Trả về con trỏ đến lớp tìm được
        }
    }
    return nullptr; // Không tìm thấy lớp
}

bool ClassList::removeStudent(const string &malop, const string &maSV)
{
    Lop *lop = findClassByCode(malop); // Tìm lớp

    if (lop == nullptr)
    {
        cout << "Lớp không tồn tại!" << endl;
        return false;
    }

    bool removed = lop->removeStudent(maSV); // Xóa sinh viên trong lớp

    if (removed)
    {
        cout << "Xóa sinh viên thành công!" << endl;
        return true;
    }
    else
    {
        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
        return false;
    }
}

bool ClassList::removeClassByCode(const string &malop)
{
    for (int i = 0; i < classCount; ++i)
    {
        if (classes[i].getClassID() == malop)
        {
            // Xóa lớp bằng mã lớp
            for (int j = i; j < classCount - 1; ++j)
            {
                classes[j] = classes[j + 1]; // Dịch chuyển lớp còn lại
            }
            --classCount; // Giảm số lượng lớp
            return true;  // Thành công
        }
    }
    return false; // Không tìm thấy lớp
}

SinhVien *ClassList::findSinhVienById(const string &maSV)
{
    for (int i = 0; i < classCount; ++i)
    {
        SinhVien *found = classes[i].findStudent(maSV); // Tìm sinh viên trong lớp
        if (found != nullptr)
        {
            return found;
        }
    }
    return nullptr; // Không tìm thấy sinh viên
}

void ClassList::saveToFile(const string &filename)
{
    ofstream outFile(filename); // Mở file để lưu dữ liệu

    if (!outFile)
    {
        cerr << "Không thể mở file để lưu!" << endl;
        return;
    }

    // Lưu danh sách lớp
    for (int i = 0; i < classCount; ++i)
    {
        outFile << classes[i].getClassID() << " " << classes[i].getClassName() << endl;

        // Lưu sinh viên trong lớp bằng cách duyệt qua danh sách liên kết
        const SinhVienNode *current = classes[i].getStudents(); // Sử dụng const vì danh sách là không thay đổi
        while (current != nullptr)
        {
            outFile << current->student.toString() << endl; // Gọi phương thức toString() của sinh viên
            current = current->next;                        // Di chuyển đến sinh viên tiếp theo
        }

        outFile << endl; // Đánh dấu kết thúc lớp
    }

    outFile.close(); // Đóng file
}

void ClassList::readFromFile(const string &filename)
{
    ifstream inFile(filename); // Mở file để đọc

    if (!inFile)
    {
        cerr << "Không thể mở file để đọc!" << endl;
        return;
    }

    classCount = 0;
    string line;

    while (getline(inFile, line))
    {
        istringstream classStream(line);
        string classID, className;
        classStream >> classID >> ws; // Đọc mã lớp và tên lớp
        getline(classStream, className);

        Lop classItem(classID, className);

        // Đọc sinh viên cho lớp
        while (getline(inFile, line) && !line.empty())
        {
            SinhVien student;
            student.fromString(line); // Giả sử phương thức fromString() để parse thông tin sinh viên
            classItem.addStudent(student);
        }

        addClass(classItem); // Thêm lớp vào danh sách
    }

    inFile.close(); // Đóng file
}
