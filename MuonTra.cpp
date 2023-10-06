#pragma once
#include "lib.cpp"
#include "Sach.cpp"
#include "DocGia.cpp"
/**
 * @brief bản ghi: thẻ mượn
 *
 */
class Record {
private:
  int stt;
  string ngMuon;
  string tenSach;
  Date ngayMuon;
  Date ngayTra;
  bool daTra;

public:

  void setStt(int stt) { this->stt = stt; }
  void setNgMuon(string ngMuon) { this->ngMuon = ngMuon; }
  void setNgTra(string tenSach) { this->tenSach = tenSach; }
  void setNgayMuon(Date ngayMuon) { this->ngayMuon = ngayMuon; }
  void setNgayTra(Date ngayTra) { this->ngayTra = ngayTra; }
  void setTT()
    void setUp(int stt, string ngMuon, string tenSach, Date ngayMuon, Date ngayTra, bool daTra) {
    this->ngayMuon = ngayMuon;
    this->ngayTra = ngayTra;
    this->ngMuon = ngMuon;
    this->tenSach = tenSach;
    this->stt = stt;
    this->daTra = daTra;

  }

  void setUp(Sach sach, DocGia dg, Date ngayMuon, Date ngayTra) {
    setUp(0, dg.GetTen(), sach.getTenSach(), ngayMuon, ngayTra, false);
  }

  void getInfo(fstream& f) {

  }

  void updateTrangThai(fstream& f, int stt, bool daTra) {

  }

  void xuat(int stt) {
    cout << stt << " | " << this->tenSach << " | " << this->ngMuon << " | " << this->ngayMuon.xuat() << " | " << this->ngayTra.xuat() << " | " << this->daTra ? "da Tra" : "chua tra" << endl;
  }
  void xuat() {
    cout << this->tenSach << " | " << this->ngMuon << " | " << this->ngayMuon.xuat() << " | " << this->ngayTra.xuat() << " | " << this->daTra ? "da Tra" : "chua tra" << endl;
  }
};


class MuonTra {
private:
  Record muonTra;
  int maxRecord;
  fstream f;

  vector<Record> dsMT;
public:
  MuonTra() {
    maxRecord = 0;
    // fstream f;
    f.open("./db/borrow.txt", ios::in | ios::out);
    while (!f.eof())
    {
      maxRecord++;
      string t;
      getline(f, t);
    }
    maxRecord /= 6;

  }
  ~MuonTra() { f.close(); }

  void muon(Sach sach, DocGia dg) {
    cout << "Nhap Ngay muon:\n";
    Date ngayMuon, ngayTra;
    ngayMuon.nhapNgay();
    cout << "Nhap Ngay Tra";
    ngayTra.nhapNgay();
    muonTra.setUp(sach, dg, ngayMuon, ngayTra);
  }

};

