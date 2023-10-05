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
    return "";
  }
};

class Record {
private:
  int stt;
  string ngMuon;
  string tenSach;
  Date ngayMuon;
  Date ngayTra;
public:
  void setUp(int stt, string ngMuon, string tenSach, Date ngayMuon, Date ngayTra) {
    this->ngayMuon = ngayMuon;
    this->ngayTra = ngayTra;
    this->ngMuon = ngMuon;
    this->tenSach = tenSach;
    this->stt = stt;
  }
  void xuat(int stt) {

  }
};
