#pragma once
#include "lib.cpp"
#include "Sach.cpp"
#include "DocGia.cpp"
/**
 * @brief bản ghi: thẻ mượn
 */
class Record {
private:
  int id;
  string nguoiMuon;
  string tenSach;
  Date ngayMuon;
  Date ngayTra;
  bool daTra;

public:
  Record() {
    id = 0;
    nguoiMuon = tenSach = "";
    daTra = false;
  }
  void setId(int id) { this->id = id; }
  void setNguoiMuon(string nguoiMuon) { this->nguoiMuon = nguoiMuon; }
  void setTenSach(string tenSach) { this->tenSach = tenSach; }
  void setNgayMuon(Date ngayMuon) { this->ngayMuon = ngayMuon; }
  void setNgayTra(Date ngayTra) { this->ngayTra = ngayTra; }
  void update(bool val) { this->daTra = val; }

  int getId() const { return this->id; }
  string getNguoiMuon() const { return this->nguoiMuon; }
  string getTenSach() const { return this->tenSach; }
  Date getNgayMuon() const { return this->ngayMuon; }
  Date getNgayTra() const { return this->ngayTra; }
  bool getDaTra() const { return this->daTra; }

  // void setTT()
  void setUp(int stt, string nguoiMuon, string tenSach, Date ngayMuon, Date ngayTra, bool daTra) {
    this->ngayMuon = ngayMuon;
    this->ngayTra = ngayTra;
    this->nguoiMuon = nguoiMuon;
    this->tenSach = tenSach;
    this->id = stt;
    this->daTra = daTra;

  }

  void setUp(Sach sach, DocGia dg, Date ngayMuon, Date ngayTra) {
    setUp(0, dg.GetTen(), sach.getTenSach(), ngayMuon, ngayTra, false);
  }

  void luu(fstream& f) {
    f << this->id << endl;
    f << this->tenSach << endl;
    f << this->nguoiMuon << endl;
    f << this->ngayMuon << endl;
    f << this->ngayTra << endl;
    f << (this->getDaTra() ? 1 : 0);
  }

  friend istream& operator>>(istream& is, Record& r) {
    // cout << "resrs";
    string tem;
    Date tg1, tg2;
    getline(is, tem);
    r.setId(convertToInt(tem));
    getline(is, tem);
    r.setTenSach(tem);
    getline(is, tem);
    r.setNguoiMuon(tem);
    is >> tg1 >> tg2;
    r.setNgayMuon(tg1);
    // is >> tg;
    r.setNgayTra(tg2);
    getline(is, tem);
    cout << "tem:: " << tem << endl;
    r.update(tem.find("1") != string::npos);
    return is;
  }



  friend ostream& operator<<(ostream& os, const Record& r) {
    os << r.getId() << endl;
    os << r.getTenSach() << endl;
    os << r.getNguoiMuon() << endl;
    os << r.getNgayMuon() << endl;
    os << r.getNgayTra() << endl;
    os << (r.getDaTra() ? 1 : 0);
    return os;
  }

  bool updateTrangThai(vector<Record>& ds, int id, bool daTra) {
    if (id < 0 && id >= ds.size()) return false;
    // ds[id].set
  }

  void xuat(int id) {
    cout << id << " | " << this->tenSach << " | " << this->nguoiMuon << " | " << this->ngayMuon.xuat() << " | " << this->ngayTra.xuat() << " | " << (this->daTra ? "da Tra" : "chua tra") << endl;
  }
  void xuat() {
    cout << this->tenSach << " | " << this->nguoiMuon << " | " << this->ngayMuon.xuat() << " | " << this->ngayTra.xuat() << " | " << (this->daTra ? "da Tra" : "chua tra") << endl;
  }
};


class MuonTra {
private:
  fstream f;
  vector<Record> dsMT;
public:
  MuonTra() {
    f.open("./db/muon.txt", ios::out | ios::in);
    while (!f.eof()) {
      Record tg;
      f >> tg;
      dsMT.push_back(tg);
    }
  }
  ~MuonTra() { f.close(); }

  void muon(Sach sach, DocGia dg) {

    cout << "Nhap Ngay muon:\n";
    Date ngayMuon, ngayTra;
    ngayMuon.nhapNgay();
  }

  void tra(DocGia dg) {

  }
};

