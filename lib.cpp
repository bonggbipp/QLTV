#pragma once
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

void reset(fstream* f[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    f[i]->seekg(0, ios::beg);
  }
}
bool operator==(const string& str, const string& sub_str) {
  return str.find(sub_str) != std::string::npos;
}
/**
 * @brief so sách 2 chuỗi
 *
 * @param str chuỗi thứ nhất
 * @param sub_str chuỗi thứ 2
 * @return true nếu 2 str trùng với sub_str |
 * @return false nếu 2  str khác nhau sub_str
 */
bool contains(const string& str, const string& sub_str) {
  return str == sub_str;
}

/**
 * @brief convert 1 chuỗi thành 1 số int
 */
int convertToInt(string str) {
  int res;
  stringstream ss(str);
  ss >> res;
  return res;
}

/**
 * @brief class quản lý ngày tháng
 *
 */
class Date {
private:
  int d, m, y;
public:
  Date() {}
  Date(int d, int m, int y) { this->d = d;this->m = m;this->y = y; }
  ~Date() {}
  void setNgay(int d, int m, int y) {
    this->d = d;
    this->m = m;
    this->y = y;
  }
  string xuat() const {
    string res = "";
    res += to_string(d);
    res += "/";
    res += to_string(m);
    res += "/";
    res += to_string(y);
    return res;
  }

  void nhapNgay() {
    cout << setw(30) << right << "Nhap Ngay: ";
    cin >> this->d;
    cout << setw(30) << right << "Nhap Thang: ";
    cin >> this->m;
    cout << setw(30) << right << "Nhap nam: ";
    cin >> this->y;
  }
  void setNgay(int val) { this->d = val; }
  void setThang(int val) { this->m = val; }
  void setNam(int val) { this->y = val; }

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
  friend ostream& operator<<(ostream& os, const Date& d) {
    os << d.xuat();
    return os;
  }

  friend istream& operator>>(istream& is, Date& d) {
    string tem;
    getline(is, tem);
    stringstream ss(tem);
    int n;
    char c;
    ss >> n >> c;
    d.setNgay(n);
    ss >> n >> c;
    d.setThang(n);
    ss >> n >> c;
    d.setNam(n);
    return is;
  }
};
