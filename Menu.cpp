#include "Menu.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Date.h"
#include "Searching.h"
using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
}


const string Menu::nhapsai = "Loi! Nhap lai: ";
const string Menu::baotri = "Tinh nang dang duoc nang cap!\nVui long quay lai sau";
vector<SinhVien> DSSV;

void Menu::hienThi()
{
    bool stat=true;
	SinhVien sinhVienTemp;
	char Choose;
	
	cout << "\n****************************************************" << endl
		 << "Chuong trinh quan li sinh vien.					   " << endl
		 << "	1. Them ho so								   " << endl
		 << "	2. In danh sach								   " << endl
		 << "	3. Sap xep									   " << endl
		 << "	4. Tim kiem									   " << endl
		 << "	5. Thong ke									   " << endl
		 << "	6. Thoat									   " << endl
		 << "Chon: ";
	while (stat == true)
	{
        cin >> choiceMenu;
        switch (choiceMenu) {
            case 1:
                sinhVienTemp.ThemHoSo();
                break;
            case 2:
                cout << "\nIn danh sach: " << endl;
                InDanhSach();
                break;
            case 3:
                cout << "\nSap xep: " << endl;
                sapXep();
                break;
            case 4: {
                cout << "\nTim kiem: " << endl;
                Searching menuTimKiem(DSSV);

                menuTimKiem.SearchMenu();
                break;
            }
            case 5:
                cout << "\nThong ke: " << endl;
                thongKe();
                break;
            case 6:
                thoat();
                break;
            default:
                cout << nhapsai;
                break;
        }
        if (choiceMenu != 6)
        {
            cout << "Tiep tuc chuong trinh? (y/n): ";
            cin >> Choose;
            if (Choose == 'n') {
                stat = false;
                thoat();
            }
            else {
                cout << "\n****************************************************" << endl
                     << "Chuong trinh quan li sinh vien.					   " << endl
                     << "	1. Them ho so								   " << endl
                     << "	2. In danh sach								   " << endl
                     << "	3. Sap xep									   " << endl
                     << "	4. Tim kiem									   " << endl
                     << "	5. Thong ke									   " << endl
                     << "	6. Thoat									   " << endl
                     << "Chon: ";
            }
        }
    }
}

void Menu::InDanhSach()
{
    char Confirm;
    if (DSSV.empty())
        ReadFile();

    for (int i=0;i<DSSV.size();i++){
        cout<<DSSV.at(i).toString_SinhVien();
    }
    cout<<"\nLam moi danh sach? (y/n): ";
    cin>>Confirm;
    if (Confirm == 'y')
        newDanhSach();

}
void Menu::newDanhSach() {
    fstream f;
    f.open("SinhVien.txt",ios::out);
    f.close();
}

void Menu::ReadFile() {
    fstream f;
    string MaLop,HoTen,MaSVbuff;
    int MaSV,month,day,year;
    float DiemTB;
    Date NgaySinh;

    f.open("SinhVien.txt",ios::in);
    while (!f.eof()){

        getline(f,HoTen,'|');

        getline(f,MaLop,'|');


        getline(f,MaSVbuff,'|');
        MaSV = stoi(MaSVbuff);


        f>>month;
        f.seekg(1,ios::cur);
        f>>day;
        f.seekg(1,ios::cur);
        f>>year;
        f.seekg(1,ios::cur);
        NgaySinh.setDate(month,day,year);

        f>>DiemTB;

        DSSV.push_back(SinhVien(MaLop,MaSV,NgaySinh,HoTen,DiemTB));
    }

    f.close();
}

void Menu::ExportFile() {
    fstream f;
    f.open("SinhVien.txt",ios::out);
    for (int i=0; i<DSSV.size(); i++){
        f<<"\n"<<DSSV.at(i).toString_SinhVien();
    }
    f.close();
}

int Menu::chonKhoa()
{
	int keyType;
	bool check = false;

	cout << "\nChon loai khoa: " << endl
		 << "1. Ma sinh vien"	 << endl
		 << "2. Ho ten"			 << endl
		 << "3. Ngay sinh"		 << endl
		 << "4. Diem trung binh" << endl
		 << "5. Ma lop"          << endl;
	
	cout << "Chon: ";
	do {
		cin >> keyType;
		
		switch (keyType) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
                check = true;
                return keyType;
			default:
				cout << nhapsai;
				break;
		}
	} while (!check);
}

void Menu::sapXep()
{
    if (DSSV.empty()){
        ReadFile();
    }

	int keyType = chonKhoa();
	cout << "\nDa chon loai: " << keyType << endl;
	int algoType = algoSapXep();
	switch (algoType){
	    case 1:
	        SelectionSort(keyType);
	        break;
	    case 2:
	        InsertSort(keyType);
	        break;
	    case 3:
	        QuickSort(keyType,0,DSSV.size()-1);
	        break;
	    case 4:
	        MergeSort(keyType, 0, DSSV.size()-1);
	        break;
	}

    ExportFile();

	cout<<"Đã sắp xếp xong, vui lòng in danh sách để xem lại kết quả!"<<endl;

//	for (int i=0; i<DSSV.size(); i++)
//	    cout<<DSSV.at(i).toString_SinhVien()<<endl;
}


int Menu::algoSapXep()
{
	int algoType;
	cout << "\nChon thuat toan sap xep: " << endl
		 << "1. Selection sort" 		  << endl
		 << "2. Insert sort"			  << endl
		 << "3. Quick sort"				  << endl
		 << "4. Merge sort"				  << endl
		 << "Chon: ";
	
	do {
		cin >> algoType;
		switch (algoType) {
			case 1:
				cout << "Selection sort dang chay!" << endl;
				return algoType;
			case 2:
				cout << "Insert sort dang chay!" << endl;
				return algoType;
			case 3:
				cout << "Quick sort dang chay!" << endl;
				return algoType;
			case 4:
				cout << "Merge sort dang chay!" << endl;
				return algoType;
			default:
				cout << nhapsai;
				break;
		}
	} while (algoType < 1 || algoType > 4);
}

bool Menu::Comparison(int a, int b) {
    if (a<b)
        return false;
    return true;
}
bool Menu::Comparison(float a, float b) {
    if (a<b)
        return false;
    return true;
}
bool Menu::Comparison(string a, string b) {
    if (a.compare(b) < 0)
        return false;
    return true;
}

void Menu::SelectionSort(int keyType) {
    int i,j,min_idx;
    for(i = 0; i<DSSV.size()-1;i++){
        min_idx=i;
        for (j = i; j<DSSV.size(); j++){
            switch(keyType){
                case 1:
                    if (Comparison(DSSV.at(j).getMaSV(), DSSV.at(min_idx).getMaSV()) == false)
                        min_idx = j;
                    break;
                case 2:
                    if (Comparison(DSSV.at(j).getHoTen(), DSSV.at(min_idx).getHoTen())== false)
                        min_idx = j;
                    break;
                case 3:
                    if (Comparison(DSSV.at(j).getDateString(), DSSV.at(min_idx).getDateString()) == false)
                        min_idx = j;
                    break;
                case 4:
                    if (Comparison(DSSV.at(j).getDiemTB(), DSSV.at(min_idx).getDiemTB()) == false)
                        min_idx = j;
                    break;
                case 5:
                    if (Comparison(DSSV.at(j).getMaLop(), DSSV.at(min_idx).getMaLop()) == false)
                        min_idx = j;
                    break;
            }
            swap(DSSV.at(i),DSSV.at(min_idx));
        }
    }
}

void Menu::InsertSort(int keyType) {
    int i,j;
    SinhVien key;
    for (i = 1; i<DSSV.size();i++){
        key = DSSV.at(i);
        j = i-1;
        while (j >= 0){
            switch(keyType){
                case 1:
                    if (Comparison(DSSV.at(j).getMaSV(), key.getMaSV()) == true){
                        DSSV.at(j+1) = DSSV.at(j);
                        j--;
                    }
                    break;
                case 2:
                    if (Comparison(DSSV.at(j).getHoTen(), key.getHoTen()) == true){
                        DSSV.at(j+1) = DSSV.at(j);
                        j--;
                    }
                    break;
                case 3:
                    if (Comparison(DSSV.at(j).getDateString(), key.getDateString()) == true){
                        DSSV.at(j+1) = DSSV.at(j);
                        j--;
                    }
                    break;
                case 4:
                    if (Comparison(DSSV.at(j).getDiemTB(), key.getDiemTB()) == true){
                        DSSV.at(j+1) = DSSV.at(j);
                        j--;
                    }
                    break;
                case 5:
                    if (Comparison(DSSV.at(j).getMaLop(), key.getMaLop()) == true){
                        DSSV.at(j+1) = DSSV.at(j);
                        j--;
                    }
                    break;
            }
            DSSV.at(j+1) = key;
        }
    }
}

void Menu::QuickSort(int keyType,int low,int high) {
    if (low < high){
        int pi = Partition(keyType,low,high);
        QuickSort(keyType,low,pi-1);
        QuickSort(keyType,pi+1,high);
    }
}
int Menu::Partition(int keyType, int low, int high) {
    int i,j;
    i = low - 1;
    for(j=low; j<=high-1; j++){
        switch(keyType) {
            case 1:
                if (Comparison(DSSV.at(j).getMaSV(), DSSV.at(high).getMaSV()) == false) {
                    i++;
                    swap(DSSV.at(j), DSSV.at(i));
                }
                break;
            case 2:
                if (Comparison(DSSV.at(j).getHoTen(), DSSV.at(high).getHoTen()) == false) {
                    i++;
                    swap(DSSV.at(j), DSSV.at(i));
                }
                break;
            case 3:
                if (Comparison(DSSV.at(j).getDateString(), DSSV.at(high).getDateString()) == false) {
                    i++;
                    swap(DSSV.at(j), DSSV.at(i));
                }
                break;
            case 4:
                if (Comparison(DSSV.at(j).getDiemTB(), DSSV.at(high).getDiemTB()) == false) {
                    i++;
                    swap(DSSV.at(j), DSSV.at(i));
                }
                break;
            case 5:
                if (Comparison(DSSV.at(j).getMaLop(), DSSV.at(high).getMaLop()) == false) {
                    i++;
                    swap(DSSV.at(j), DSSV.at(i));
                }
                break;
        }
    }
    swap(DSSV.at(i+1), DSSV.at(high));
    return (i+1);
}

void Menu::MergeSort(int keyType, int l, int r) {
    if (l < r){
        int m = l + (r-l)/2;

        MergeSort(keyType, l, m);
        MergeSort(keyType, m+1, r);
        Merge(keyType, l, m, r);
    }
}
void Menu::Merge(int keyType, int l, int m, int r) {
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    vector<SinhVien> L,R;

    for (i=0; i<n1; i++)
        L.push_back(DSSV.at(l+i));
    for (j=0; j<n2; j++)
        R.push_back(DSSV.at(m+1+j));

    i = j = 0;
    k = l;

    while(i<n1 && j<n2){
        switch(keyType) {
            case 1:
                if (Comparison(L.at(i).getMaSV(), R.at(j).getMaSV()) == false) {
                    DSSV.at(k) = L.at(i);
                    i++;
                }
                else{
                    DSSV.at(k) = R.at(j);
                    j++;
                }
                k++;
                break;
            case 2:
                if (Comparison(L.at(i).getHoTen(), R.at(j).getHoTen()) == false) {
                    DSSV.at(k) = L.at(i);
                    i++;
                }
                else{
                    DSSV.at(k) = R.at(j);
                    j++;
                }
                k++;
                break;
            case 3:
                if (Comparison(L.at(i).getDateString(), R.at(j).getDateString()) == false) {
                    DSSV.at(k) = L.at(i);
                    i++;
                }
                else{
                    DSSV.at(k) = R.at(j);
                    j++;
                }
                k++;
                break;
            case 4:
                if (Comparison(L.at(i).getDiemTB(), R.at(j).getDiemTB()) == false) {
                    DSSV.at(k) = L.at(i);
                    i++;
                }
                else{
                    DSSV.at(k) = R.at(j);
                    j++;
                }
                k++;
                break;
            case 5:
                if (Comparison(L.at(i).getMaLop(), R.at(j).getMaLop()) == false) {
                    DSSV.at(k) = L.at(i);
                    i++;
                }
                else{
                    DSSV.at(k) = R.at(j);
                    j++;
                }
                k++;
                break;
        }
    }
    while (i < n1){
        DSSV.at(k) = L.at(i);
        i++;
        k++;
    }
    while (j < n2){
        DSSV.at(k) = R.at(j);
        j++;
        k++;
    }
}

void Menu::timKiem()
{
	Searching menuTimKiem;
	menuTimKiem.SearchMenu();
}
void Menu::thongKe()
{
	int choice;
	cout << "\nLoai thong ke: 					   " << endl
		 << "1. Bao cao so luong sinh vien theo lop" << endl
		 << "2. Ti le phan loai KQHT			   " << endl;
	
	do {
		cin >> choice;
		switch (choice) {
			case 1:
			case 2:
				cout << baotri << endl;
			default:
				cout << nhapsai;
		}
	} while (choice < 1 || choice > 2);
}

void Menu::thoat()
{
	cout << "Chuong trinh ket thuc. Hen gap lai." << endl;
	cin.get();
	return ;
}