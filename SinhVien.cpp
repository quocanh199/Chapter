#include "SinhVien.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
SinhVien::SinhVien()
{
    this->MaLop="";
    this->HoTen="";
    this->MaSV=1;
    this->DiemTB=0;
    // this->NgaySinh = Date::Date(8,12,2000);
}
SinhVien::SinhVien(string MaLop,int MaSV,Date NgaySinh,string HoTen,float DiemTB)
{
    this->MaLop=MaLop;
    this->MaSV=MaSV;
    this->NgaySinh=NgaySinh;
    this->HoTen=HoTen;
    this->DiemTB=DiemTB;
}
void SinhVien::ThemHoSo()
{
    char Confirm;
    cout<<"Nhap thong tin sinh vien: "<<endl;
    
    cin.ignore();
    cout<<"Ho ten: ";
    getline(cin,HoTen);
    
//    cin.ignore();
    cout<<"Ma sinh vien: ";
    cin>>MaSV;

    cin.ignore();
    cout<<"Ma lop: ";
    getline(cin,MaLop);

//    cin.ignore();
    cout<<"Ngay sinh (thang,ngay,nam): ";
    NgaySinh.userInput();

    cin.ignore();
    cout<<"Diem trung binh: ";
    cin>>DiemTB;
    if (DiemTB < 0.0 || DiemTB > 10.0)
    {
        do
        {
            cin.clear();
            cin.ignore();
            cout<<"Diem trung binh khong hop le!\nVui long nhap lai: ";
            cin>>DiemTB;
        }
        while (DiemTB < 0.0 || DiemTB > 10.0);
    }
    cout<<"Xac nhan thong tin sinh vien? (y/n): ";
    cin>>Confirm;
    if (Confirm == 'y'){
        fstream f;
        f.open("SinhVien.txt",ios::app);
        f<<HoTen<<"\n"<<MaLop<<" "<<MaSV<<" "<<NgaySinh.asString()<<" "<<DiemTB<<endl;

        f.close();
    }
}

void SinhVien::setMaLop(string MaLop)
{
	this->MaLop = MaLop;
}

string SinhVien::getMaLop()
{
	return MaLop;
}

void SinhVien::setMaSV(int MaSV)
{
	this->MaSV = MaSV;
}
int SinhVien::getMaSV()
{
	return MaSV;
}

void SinhVien::setHoTen(string HoTen)
{
	this->HoTen = HoTen;
}

string SinhVien::getHoTen()
{
	return HoTen;
}

void SinhVien::setNgaySinh(int month, int day, int year)
{
	NgaySinh.setDate(month, day, year);
}

Date SinhVien::getNgaySinh()
{
	return NgaySinh;
}

void SinhVien::setDiemTB(float DiemTB)
{
	this->DiemTB = DiemTB;
}

float SinhVien::getDiemTB()
{
	return DiemTB;
}

string SinhVien::toString_SinhVien()
{
	ostringstream _SinhVien;
	_SinhVien << MaLop << "|" << MaSV  << "|" << HoTen << "|" << NgaySinh.asString() << "|" << DiemTB;

	return _SinhVien.str();
}