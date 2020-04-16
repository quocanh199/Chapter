#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class SinhVien
{
    private:
        string MaLop;
        int MaSV;
        Date NgaySinh;
        string HoTen;
        float DiemTB;
    public:
        SinhVien();
        SinhVien(string MaLop,int MaSV,Date NgaySinh,string HoTen,float diemTB);

        void ThemHoSo();

        void setMaLop(string MaLop);
        string getMaLop();

        void setMaSV(int MaSV);
        int getMaSV();

        void setNgaySinh(int month,int day,int year);
        Date getNgaySinh();
        string getDateString();

        void setHoTen(string HoTen);
        string getHoTen();

        void setDiemTB(float DiemTB);
        float getDiemTB();

        string toString_SinhVien();
        void ReName();
};

#endif //SINHVIEN_H