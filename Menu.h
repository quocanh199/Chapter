#ifndef MENU_H
#define MENU_H
#include <iostream>
#include<string>
#include "SinhVien.h"
class Menu
{
    private:
        int choiceMenu;
    public:
        static const string baotri;
        static const string nhapsai;
        Menu();
        ~Menu();
        void hienThi();
        void InDanhSach();
        void newDanhSach();

        void ReadFile();
        string ChuanHoaTen(string HoTen);
        void ExportFile();

        bool Comparison(int a,int b);
        bool Comparison(string a,string b);
        bool Comparison(float a,float b);

        void SelectionSort(int keyType);
        void InsertSort(int keyType);
        void QuickSort(int keyType, int low, int high);
        int Partition(int keyType, int low, int high);
        void MergeSort(int keyType, int l, int r);
        void Merge(int keyType, int l, int m, int r);

        void sapXep();
        int algoSapXep();

        void timKiem();
        
        int chonKhoa();
        void thongKe();

        void thoat();
};
#endif //MENU_H