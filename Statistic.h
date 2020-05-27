//
// Created by quocanh on 23/05/2020.
//

#ifndef CHAPTER1_STATISTIC_H
#define CHAPTER1_STATISTIC_H

#include "SinhVien.h"
#include "Searching.h"
#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include <iomanip>
using namespace std;

class Statistic{
private:
    vector<SinhVien> DSSV;
public:
    Statistic();
    Statistic(vector<SinhVien> & _DSSV);

    void addClasses();
    void uniqueClasses();
    void addQuantity();


    void QuantityStat();
    void QualityStat();
};
class Classes{
private:
    string MaLop;
public:
    int getXuatSac() const;

    void setXuatSac(int xuatSac);

    int getGioi() const;

    void setGioi(int gioi);

    int getKha() const;

    void setKha(int kha);

    int getTrungBinh() const;

    void setTrungBinh(int trungBinh);

    int getYeu() const;

    void setYeu(int yeu);

private:
    int XuatSac,Gioi,Kha,TrungBinh,Yeu;
public:
    const string &getMaLop() const;

    void setMaLop(const string &maLop);

    void setSoLuong(int soLuong);

    int getSoLuong() const;

    void upSoLuong();
    void upXuatSac();
    void upGioi();
    void upKha();
    void upTrungBinh();
    void upYeu();

private:
    int SoLuong;
public:
    Classes();
    Classes(string MaLop, int SoLuong);
};
#endif //CHAPTER1_STATISTIC_H
