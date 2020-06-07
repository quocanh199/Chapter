//
// Created by quocanh on 23/05/2020.
//
#include "Statistic.h"

Classes::Classes() {
    MaLop = "";
    SoLuong = 0;
    XuatSac = Gioi = TrungBinh = Kha = Yeu = 0;
}

Classes::Classes(string MaLop, int SoLuong) {
    this->MaLop = MaLop;
    this->SoLuong = SoLuong;
    XuatSac = Gioi = TrungBinh = Kha = Yeu = 0;
}

const string &Classes::getMaLop() const {
    return MaLop;
}

int Classes::getSoLuong() const {
    return SoLuong;
}

void Classes::setMaLop(const string &maLop) {
    MaLop = maLop;
}

void Classes::setSoLuong(int soLuong) {
    SoLuong = soLuong;
}

void Classes::upSoLuong() {
    SoLuong++;
}

void Classes::upXuatSac() {
    XuatSac++;
}

void Classes::upGioi() {
    Gioi++;
}

void Classes::upKha() {
    Kha++;
}

void Classes::upTrungBinh() {
    TrungBinh++;
}

void Classes::upYeu() {
    Yeu++;
}

int Classes::getXuatSac() const {
    return XuatSac;
}

void Classes::setXuatSac(int xuatSac) {
    XuatSac = xuatSac;
}

int Classes::getGioi() const {
    return Gioi;
}

void Classes::setGioi(int gioi) {
    Gioi = gioi;
}

int Classes::getKha() const {
    return Kha;
}

void Classes::setKha(int kha) {
    Kha = kha;
}

int Classes::getTrungBinh() const {
    return TrungBinh;
}

void Classes::setTrungBinh(int trungBinh) {
    TrungBinh = trungBinh;
}

int Classes::getYeu() const {
    return Yeu;
}

void Classes::setYeu(int yeu) {
    Yeu = yeu;
}

vector<Classes> classList;

Statistic::Statistic() {
    Menu _menu;
    _menu.ReadFile();
}

Statistic::Statistic(vector<SinhVien> &_DSSV) {
    DSSV = _DSSV;
}

void Statistic::addClasses() {
    for (int i = 0; i < DSSV.size(); i++) {
        classList.push_back(Classes(DSSV.at(i).getMaLop(), 0));
    }
    uniqueClasses();
}

void Statistic::uniqueClasses() {
    for (int i = 0; i < classList.size() - 1; i++) {
        for (int j = i + 1; j < classList.size(); j++) {
            if (classList.at(j).getMaLop() == classList.at(i).getMaLop())
                classList.erase(classList.begin() + j);
        }
    }
}

void Statistic::addQuantity() {
    for (int i = 0; i < classList.size(); i++) {
        for (int j = 0; j < DSSV.size(); j++) {
            if (classList.at(i).getMaLop() == DSSV.at(j).getMaLop())
                classList.at(i).upSoLuong();
        }
    }

    for (int i = 0; i < classList.size(); i++) {
        for (int j = 0; j < DSSV.size(); j++) {
            if (DSSV.at(j).getMaLop() == classList.at(i).getMaLop()) {
                if (DSSV.at(j).getDiemTB() >= 9.0)
                    classList.at(i).upXuatSac();
                else if (DSSV.at(j).getDiemTB() >= 8.0)
                    classList.at(i).upGioi();
                else if (DSSV.at(j).getDiemTB() >= 6.5)
                    classList.at(i).upKha();
                else if (DSSV.at(j).getDiemTB() >= 4.0)
                    classList.at(i).upTrungBinh();
                else classList.at(i).upYeu();
            }
        }
    }
}

void Statistic::QuantityStat() {
    addClasses();
    addQuantity();
    cout << setw(3) << left << '|';
    cout << setw(12) << left << "Mã lớp";
    cout << setw(10) << '|';
    cout << setw(18) << "Tên lớp";
    cout << setw(2) << '|';
    cout << setw(16) << "Số sinh viên";
    cout << '|' << endl;

    for (int i = 0; i < classList.size(); i++) {
        cout << setw(3) << left << '|';
        cout << setw(9) << left << classList.at(i).getMaLop();
        cout << setw(12) << '|';
        cout << setw(13) << classList.at(i).getMaLop();
        cout << setw(8) << '|';
        cout << setw(7) << classList.at(i).getSoLuong();
        cout << '|' << endl;
    }
}

void Statistic::QualityStat() {
    float TongXS, TongGioi, TongKha, TongTB, TongYeu;
    TongXS = TongGioi = TongKha = TongTB = TongYeu = 0;
    for (int i = 0; i < classList.size(); i++) {
        TongXS += float(classList.at(i).getXuatSac());
        TongGioi += float(classList.at(i).getGioi());
        TongKha += float(classList.at(i).getKha());
        TongTB += float(classList.at(i).getTrungBinh());
        TongYeu += float(classList.at(i).getYeu());
    }
    cout << setw(2) << left << "|" << setw(10) << left << "Mã lớp" << setw(5) << left << "|"
         << setw(16) << left << "Xuất sắc" << setw(7) << left << "|"
         << setw(12) << left << "Giỏi" << setw(8) << left << "|"
         << setw(10) << left << "Khá" << setw(4) << left << "|"
         << setw(14) << left << "Trung Bình" << setw(8) << left << "|"
         << setw(11) << left << "Yếu" << "|" << endl;

    cout << setw(2) << left << "|" << setw(7) << left << " " << setw(4) << left << "|"
         << setw(5) << left << "SL" << setw(4) << left << "|" << setw(4) << left << "%" << setw(4) << left << "|"
         << setw(5) << left << "SL" << setw(4) << left << "|" << setw(4) << left << "%" << setw(4) << left << "|"
         << setw(5) << left << "SL" << setw(4) << left << "|" << setw(4) << left << "%" << setw(4) << left << "|"
         << setw(5) << left << "SL" << setw(4) << left << "|" << setw(4) << left << "%" << setw(4) << left << "|"
         << setw(5) << left << "SL" << setw(4) << left << "|" << setw(4) << left << "%" << setw(4) << left << "|"
         << endl;
    for (int i = 0; i < classList.size(); i++) {
        cout << setw(4) << left << "|" << setw(5) << classList.at(i).getMaLop() << setw(4) << left << "|";

        cout << setw(5) << left << classList.at(i).getXuatSac() << setw(4) << left << "|" << setw(4) << left;
        if (TongXS != 0)
            cout << (classList.at(i).getXuatSac() / TongXS) * 100;
        else cout << 0;

        cout << setw(4) << left << "|"
             << setw(5) << left << classList.at(i).getGioi() << setw(4) << left << "|" << setw(4) << left;
        if (TongGioi != 0)
            cout << (classList.at(i).getGioi() / TongGioi) * 100;
        else cout << 0;

        cout << setw(4) << left << "|"
             << setw(5) << left << classList.at(i).getKha() << setw(4) << left << "|" << setw(4) << left;
        if (TongKha != 0)
            cout << (classList.at(i).getKha() / TongKha) * 100;
        else cout << 0;

        cout << setw(4) << left << "|"
             << setw(5) << left << classList.at(i).getTrungBinh() << setw(4) << left << "|" << setw(4) << left;
        if (TongTB != 0)
            cout << (classList.at(i).getTrungBinh() / TongTB) * 100 << setw(4) << left << "|";
        else cout << 0;

        cout << setw(5) << left << classList.at(i).getYeu() << setw(4) << left << "|" << setw(4) << left;
        if (TongYeu != 0)
            cout << (classList.at(i).getYeu() / TongYeu) * 100;
        else cout << 0;

        cout << setw(4) << left << "|"
             << endl;
    }
    cout << setw(3) << left << "|" << setw(8) << "Tổng" << setw(4) << left << "|"
         << setw(5) << left << TongXS << setw(4) << left << "|" << setprecision(2) << setw(4) << left
         << (TongXS / DSSV.size()) * 100 << setw(4) << left << "|"
         << setw(5) << left << TongGioi << setw(4) << left << "|" << setprecision(2) << setw(4) << left
         << (TongGioi / DSSV.size()) * 100 << setw(4) << left << "|"
         << setw(5) << left << TongKha << setw(4) << left << "|" << setprecision(2) << setw(4) << left
         << (TongKha / DSSV.size()) * 100 << setw(4) << left << "|"
         << setw(5) << left << TongTB << setw(4) << left << "|" << setprecision(2) << setw(4) << left
         << (TongTB / DSSV.size()) * 100 << setw(4) << left << "|"
         << setw(5) << left << TongYeu << setw(4) << left << "|" << setprecision(2) << setw(4) << left
         << (TongYeu / DSSV.size()) * 100 << setw(4) << left << "|"
         << endl;
}
