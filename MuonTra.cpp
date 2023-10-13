#pragma once
#include "lib.cpp"
#include "Sach.cpp"
#include "DocGia.cpp"
/**
 * @brief bản ghi: thẻ mượn
 */
class Record {
private:
  int id, idSach, idNguoiMuon;
  string nguoiMuon;
  string tenSach;
  Date ngayMuon;
  Date ngayTra;
  bool daTra;
public:
  Record() {
    id = idNguoiMuon = idSach = 0;
    nguoiMuon = tenSach = "";
    daTra = false;
  }
  void setId(int id) { this->id = id; }
  void setIdSach(int id) { this->idSach = id; }
  void setIdNguoiMuon(int id) { this->idNguoiMuon = id; }
  void setNguoiMuon(string nguoiMuon) { this->nguoiMuon = nguoiMuon; }
  void setTenSach(string tenSach) { this->tenSach = tenSach; }
  void setNgayMuon(Date ngayMuon) { this->ngayMuon = ngayMuon; }
  void setNgayTra(Date ngayTra) { this->ngayTra = ngayTra; }
  void update(bool val) { this->daTra = val; }

  int getId() const { return this->id; }
  int getIdNguoiMuon() const { return this->idNguoiMuon; }
  int getIdSach() const { return this->idSach; }
  string getNguoiMuon() const { return this->nguoiMuon; }
  string getTenSach() const { return this->tenSach; }
  Date getNgayMuon() const { return this->ngayMuon; }
  Date getNgayTra() const { return this->ngayTra; }
  bool getDaTra() const { return this->daTra; }

  void luu(fstream& f) {
    f << this->id << endl;
    f << this->tenSach << endl;
    f << this->idSach << endl;
    f << this->nguoiMuon << endl;
    f << this->idNguoiMuon << endl;
    f << this->ngayMuon << endl;
    f << this->ngayTra << endl;
    f << (this->getDaTra() ? 1 : 0);
  }

  friend istream& operator>>(istream& is, Record& r) {
    string tem;
    Date tg1, tg2;

    getline(is, tem);
    r.setId(convertToInt(tem));
    getline(is, tem);
    r.setTenSach(tem);
    getline(is, tem);
    r.setIdSach(convertToInt(tem));
    getline(is, tem);
    r.setNguoiMuon(tem);
    getline(is, tem);
    r.setIdNguoiMuon(convertToInt(tem));
    is >> tg1 >> tg2;
    r.setNgayMuon(tg1);
    r.setNgayTra(tg2);
    getline(is, tem);
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

  void xuat() {
    cout << this->tenSach << " | " << this->nguoiMuon << " | " << this->ngayMuon.xuat() << " | " << this->ngayTra.xuat() << " | " << (this->daTra ? "da Tra" : "chua tra") << endl;
  }
};


class MuonTra {
private:
  // vector<Record> dsMT;
public:

  MuonTra() {}

  static vector<Record> dsMT(fstream& f) {
    vector<Record> res;
    while (!f.eof()) {
      Record tg;
      f >> tg;
      res.push_back(tg);
    }
    return res;
  }

  static int muon(Sach sach, DocGia& dg, vector<Record>& dsMT) {
    cout << "Nhap Ngay muon:\n";
    Date ngayMuon, ngayTra;
    ngayMuon.nhapNgay();
    Record r;
    r.setId(dsMT.size() - 1);
    r.setIdSach(sach.getMSS());
    r.setNgayMuon(ngayMuon);
    r.setTenSach(sach.getTenSach());
    r.setNguoiMuon(dg.getTen());
    r.setIdNguoiMuon(dg.getId());
    r.update(false);
    dsMT.push_back(r);
    return r.getId();
  }

  static bool tra(int id, vector<Record>& dsMT) {
    for (Record& r : dsMT) {
      if (r.getId() == id) {
        cout << "Nhap ngay tra: \n";
        Date ngayTra;
        ngayTra.nhapNgay();
        r.setNgayTra(ngayTra);
        r.update(true);
        return true;
      }
    }
    return false;
  }

  static void luu(fstream& f, const vector<Record>& ds) {
    f << ds[0];
    for (int i = 1;i < ds.size();i++) {
      f << endl << ds[i];
    }
  }

  static void hienThiDSTheMuon(const vector<Record>& dsMT) {
    system("cls");
    cout << "\n----------------------------DANH SACH CAC THE MUON-----------------------------\n";
    cout << " | " << setw(10) << left << "id";
    cout << " | " << setw(25) << left << "Ten sach";
    cout << " | " << setw(25) << left << "Nguoi muon";
    cout << " | " << setw(10) << left << "Ngay muon";
    cout << " | " << setw(10) << left << "Ngay tra";
    cout << " | " << setw(10) << left << "Trang thai";
    cout << " | " << endl;
    for (Record r : dsMT) {
      cout << " | " << setw(10) << left << r.getId();
      cout << " | " << setw(25) << left << r.getTenSach();
      cout << " | " << setw(25) << left << r.getNguoiMuon();
      cout << " | " << setw(10) << left << r.getNgayMuon().xuat();
      cout << " | " << setw(10) << left << r.getNgayTra().xuat();
      cout << " | " << setw(10) << left << (r.getDaTra() ? "da tra" : "chua tra");
      cout << " | " << endl;
    }
    cout << "\n-----------------------------------------------------------------------------\n";
    system("pause");
    system("cls");
    return;
  }


};