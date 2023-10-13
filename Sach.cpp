#pragma once
#include "lib.cpp"
/**
 * @brief class quản lý sách
 *
 */
class Sach
{
private:
  int mss;
  string tenSach;
  string tenTacGia;
  int soTrang;
  int namXuatBan;
  /**
   * @brief tạo bản sao sách mới
   *
   * @return Sach bản sao của sách hiện tại.
   */
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
    this->tenSach = this->tenTacGia = "";
    this->mss = this->soTrang = this->namXuatBan = 0;
  };
  ~Sach() {};
  /* setter */
  void setTenSach(string tenSach) { this->tenSach = tenSach; }
  void setMSS(int mss) { this->mss = mss; }
  void setTenTacGia(string tenTacGia) { this->tenTacGia = tenTacGia; }
  void setSoTrang(int soTrang) { this->soTrang = soTrang; }
  void setNamXuatBan(int namXuatBan) { this->namXuatBan = namXuatBan; }
  /* getter */
  string getTenSach() const { return this->tenSach; }
  string getTenTacGia() const { return this->tenTacGia; }
  int getMSS() const { return this->mss; }
  int getSoTrang() const { return this->soTrang; }
  int getNamXuatBan() const { return this->namXuatBan; }

  /**
   * @brief  dinh dang lai thong tin de dua ra console
   *
   * @return string sau khi định dạng lại thành dạng dễ đọc hơn.
   */
  string xuat() {
    return mss + " | " + tenSach + " | " + tenTacGia + " | " + to_string(soTrang) + " | " + to_string(namXuatBan) + "\n";
  }

  /**
   * @brief xuat file*/
  void luu(fstream& file) const {
    file << mss << '\n' << tenSach << '\n' << tenTacGia << '\n' << soTrang << '\n' << namXuatBan;
  }

  /**
   * @brief đọc danh sách các sách có trong hệ thống.
   *
   * @param file luồng đọc ghi của file sach.txt
   * @return vector<Sach> mảng động các sách có trong hệ thống
   */
  static vector<Sach> dsSach(fstream& file) {
    vector<Sach> res;
    res.clear();
    while (!file.eof()) {
      Sach t;
      string st, nxb, id;
      getline(file, id);
      getline(file, t.tenSach);
      getline(file, t.tenTacGia);
      getline(file, st);
      getline(file, nxb);
      std::stringstream ss1(st), ss2(nxb), ss3(id);
      ss3 >> t.mss;
      ss1 >> t.soTrang;
      ss2 >> t.namXuatBan;
      res.push_back(t);
    }
    return res;
  }

  /** truy van sach*/
  static int timKiem(vector<Sach>& sach) {
    cout << "\n--------------------------TRUY VAN SACH--------------------------\n";
    string tv;
    cout << "Nhap ten sach ban muon tim: ";
    getline(cin, tv);
    for (Sach s : sach) {
      if (contains(s.getTenSach(), tv)) {
        cout << "da tim thay sach co ten: " << tv << "\nSach co mss la: " << s.getMSS();
        system("pause");
        return s.getMSS();
      }
    }
    cout << "khong tim thay sach co ten nhu vay\n";
    system("pause");

    return -1;
  }

  friend istream& operator>>(istream& is, Sach& s) {
    cout << "Nhap ten sach: ";
    getline(is, s.tenSach);
    cout << "Nhap ten tac gia: ";
    getline(is, s.tenTacGia);
    cout << "Nhap So trang: ";
    cin >> s.soTrang;
    cout << "Nhap Nam xuat ban: ";
    is >> s.namXuatBan;
    return is;
  }
};