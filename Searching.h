//
// Created by quocanh on 03/05/2020.
//

#ifndef CHAPTER1_SEARCHING_H
#define CHAPTER1_SEARCHING_H

#include <iostream>
#include "SinhVien.h"
#include "Menu.h"
#include <string>
#include <vector>
using namespace std;

class Searching{
private:
    vector<SinhVien> DSSV;
public:
    Searching();
    Searching(vector<SinhVien> &_DSSV);

    int SearchField();
    int SearchAlgo();

    int * BinarySearch(string FindingString);
    int * BinarySearch(int SearchField, string FindingString);
    int BinarySearch1(int SearchField,string FindingString);

    void SearchMenu();

};
#endif //CHAPTER1_SEARCHING_H
