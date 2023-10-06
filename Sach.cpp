#pragma once
#include "lib.cpp"

class Sach
{
private:
  string mss;
  string tenSach;
  string tenTacGia;
  int soTrang;
  int namXuatBan;

  Sach clone() {
    Sach book;
    book.setMSS(this->getMSS());
    book.setTenSach(this->getTenSach());
    book.setTenTacGia(this->getTenTacGia());
    book.setSoTrang(this->getSoTrang());
    book.setNamXuatBan(this->getNamXuatBan());
    return book;
  }

public:
  Sach() {
    this->mss = this->tenSach = this->tenTacGia = "";
    this->soTrang = this->namXuatBan = 0;
  };
  ~Sach() {};

  void setTenSach(string tenSach) { this->tenSach = tenSach; }
  void setMSS(string mss) { this->mss = mss; }
  void setTenTacGia(string tenTacGia) { this->tenTacGia = tenTacGia; }
  void setSoTrang(int soTrang) { this->soTrang = soTrang; }
  void setNamXuatBan(int namXuatBan) { this->namXuatBan = namXuatBan; }

  string getTenSach() { return this->tenSach; }
  string getTenTacGia() { return this->tenTacGia; }
  string getMSS() { return this->mss; }
  int getSoTrang() { return this->soTrang; }
  int getNamXuatBan() { return this->namXuatBan; }

  void luu(fstream& file) {
    file << mss << '\n' << tenSach << '\n' << tenTacGia << '\n' << soTrang << '\n' << namXuatBan << '\n';
  }


  vector<Sach> dsSach(fstream& file) {
    vector<Sach> res;
    while (!file.eof()) {
      string st, nxb;
      getline(file, this->mss);
      getline(file, this->tenSach);
      getline(file, this->tenTacGia);
      getline(file, st);
      getline(file, nxb);
      std::stringstream ss1(st), ss2(nxb);
      ss1 >> this->soTrang;
      ss2 >> this->namXuatBan;
      res.push_back(this->clone());
    }

    return res;
  }
};