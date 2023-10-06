#pragma once
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Date {
private:
  int d, m, y;
public:
  void setNgay(int d, int m, int y) {
    this->d = d;
    this->m = m;
    this->y = y;
  }
  string xuat() {
    string res = "";
    res += d;
    res += "/";
    res += m;
    res += "/";
    res += y;
    return res;
  }

  void nhapNgay() {
    cout << setw(30) << "Nhap Ngay: ";
    cin >> this->d;
    cout << setw(30) << "Nhap Thang: ";
    cin >> this->m;
    cout << setw(30) << "Nhap nam: ";
    cin >> this->y;
  }
  void nhapNgay(fstream& f) {
    string tem;
    char c;
    getline(f, tem);
    stringstream ss(tem);
    ss >> this->d;
    ss >> c;
    ss >> this->m;
    ss >> c;
    ss >> this->y;
  }
  void xuat(fstream& f) {
    f << this->xuat() << endl;
  }
};
