#ifndef MENU_H
#define MENU_H
#include <iostream>
#include<string>
#include "SinhVien.h"
class Menu
{
    private:
        int choiceMenu;
        static const string baotri;
        static const string nhapsai;
    public:
        Menu();
        ~Menu();
        void hienThi();
        void InDanhSach();
        void newDanhSach();

        void ReadFile();

        void sapXep();
        int algoSapXep();

        void timKiem();				
		int algoTimKiem();
        
        int chonKhoa();
        void thongKe();

        void thoat();
};
#endif //MENU_H