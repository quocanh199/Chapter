#include "Searching.h"

//
// Created by quocanh on 05/05/2020.
//
Searching::Searching(){
    Menu _menu;
    _menu.ReadFile();
}
Searching::Searching(vector<SinhVien> &_DSSV) {
    DSSV = _DSSV;
}

int Searching::SearchField() {
   int key;
   bool check = false;
   cout<<"\nChọn trường thông tin tìm kiếm: "<<endl
        <<"1. Họ tên"<<endl
        <<"2. Mã lớp"<<endl
        <<"3. Mã sinh viên"<<endl
        <<"4. Ngày sinh"<<endl
        <<"5. Điểm TB"<<endl
        <<"Chọn: ";
        cin>>key;

    do {
        switch (key) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                check = true;
                return key;
            default:
                cout << Menu::nhapsai;
                break;
        }
    } while(!check);
}

int Searching::SearchAlgo() {
    int key;
    bool check = false;
    cout<<"1. Tìm kiếm duy nhất"<<endl
        <<"2. Tìm kiếm nhiều sinh viên"<<endl
        <<"3. Tìm kiếm không theo trường"<<endl
        <<"Chọn: ";
    do {
        cin>>key;
        switch (key) {
            case 1:
            case 2:
            case 3:
                return key;
            default:
                cout << Menu::nhapsai;
                break;
        }
    } while(key > 0 && key < 4);
}

void Searching::SearchMenu() {
    string FindingString;
    int *p;
    int i;

    cout<<"Nhập chuỗi cần tìm: ";
    cin.ignore();
    getline(cin,FindingString);
    int Algo = SearchAlgo();
    int Field;
    cout<<"Đã chọn: "<<Algo<<endl;

    switch (Algo){
        case 1:
            Field = SearchField();
            BinarySearch1(Field,FindingString);
            break;
        case 2:
            Field = SearchField();
            p = BinarySearch(Field, FindingString);
            break;
        case 3:
            p = BinarySearch(FindingString);
            break;
        default:
            cout<<Menu::nhapsai<<endl;
    }
}

int Searching::BinarySearch1(int SearchField, string FindingString) {
    int i;

    for (i = 0; i < DSSV.size(); i++) {
        switch (SearchField) {
            case 1:
                if (DSSV.at(i).getHoTen().compare(FindingString) == 0) {
                    cout << DSSV.at(i).toString_SinhVien() << endl;
                    return 1;
                }
                break;
            case 2:
                if (DSSV.at(i).getMaLop().compare(FindingString) == 0) {
                    cout << DSSV.at(i).toString_SinhVien()<<endl;
                    return 1;
                }
                break;
            case 3:
                if (to_string(DSSV.at(i).getMaSV()).compare(FindingString) == 0) {
                    cout << DSSV.at(i).toString_SinhVien()<<endl;
                    return 1;
                }
                break;
            case 4:
                if (DSSV.at(i).getNgaySinh().asString().compare(FindingString) == 0) {
                    cout << DSSV.at(i).toString_SinhVien()<<endl;
                    return 1;
                }
                break;
            case 5:
                if (to_string(DSSV.at(i).getDiemTB()).compare(FindingString) == 0) {
                    cout << DSSV.at(i).toString_SinhVien()<<endl;
                    return 1;
                }
                break;
        }
    }
}
int * Searching::BinarySearch(int SearchField, string FindingString) {
    int Position[DSSV.size()];
    int i;
    int pos = 0;
    int k = -1;

    for (i = 0; i < DSSV.size(); i++) {
        switch (SearchField) {
            case 1:
                if (DSSV.at(i).getHoTen().find(FindingString, pos) != string::npos) {
                    Position[++k] = i;
                    cout<<DSSV.at(i).toString_SinhVien()<<endl;
                }
                break;
            case 2:
                if (DSSV.at(i).getMaLop().find(FindingString, pos) != string::npos) {
                    Position[++k] = i;
                    cout<<DSSV.at(i).toString_SinhVien()<<endl;
                }
                break;
            case 3:
                if (to_string(DSSV.at(i).getMaSV()).find(FindingString, pos) != string::npos) {
                    Position[++k] = i;
                    cout<<DSSV.at(i).toString_SinhVien()<<endl;
                }
                break;
            case 4:
                if (DSSV.at(i).getNgaySinh().asString().find(FindingString, pos) != string::npos) {
                    Position[++k] = i;
                    cout<<DSSV.at(i).toString_SinhVien()<<endl;
                }
                break;
            case 5:
                if (to_string(DSSV.at(i).getDiemTB()).find(FindingString, pos) != string::npos) {
                    Position[++k] = i;
                    cout<<DSSV.at(i).toString_SinhVien()<<endl;
                }
                break;
        }
    }
    return Position;
}
int * Searching::BinarySearch(string FindingString){
    int i;
    int pos = 0;
    int k = -1;
    int Position[DSSV.size()];

    for (i = 0; i < DSSV.size(); i++){
        if (DSSV.at(i).getHoTen().find(FindingString, pos) != string::npos)
            cout<<DSSV.at(i).toString_SinhVien()<<endl;

        if (DSSV.at(i).getMaLop().find(FindingString, pos) != string::npos)
            cout<<DSSV.at(i).toString_SinhVien()<<endl;

        if (to_string(DSSV.at(i).getMaSV()).find(FindingString, pos) != string::npos)
            cout<<DSSV.at(i).toString_SinhVien()<<endl;

        if (DSSV.at(i).getNgaySinh().asString().find(FindingString, pos) != string::npos)
            cout<<DSSV.at(i).toString_SinhVien()<<endl;

        if (to_string(DSSV.at(i).getDiemTB()).find(FindingString, pos) != string::npos)
            cout<<DSSV.at(i).toString_SinhVien()<<endl;
    }
    return Position;
}