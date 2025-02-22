#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

struct MonHoc
{
    string MAMH;   // Mã môn học
    string TENMH;  // Tên môn học
    int STCLT;     // Số tín chỉ lý thuyết
    int STCTH;     // Số tín chỉ thực hành

    MonHoc() : MAMH(""), TENMH(""), STCLT(0), STCTH(0) {}

    MonHoc(const string &maMH, const string &tenMH, int stclt, int stcth)
        : MAMH(maMH), TENMH(tenMH), STCLT(stclt), STCTH(stcth) {}
};

#endif // COURSE_H
