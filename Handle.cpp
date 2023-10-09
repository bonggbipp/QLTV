#pragma once
#include "Admin.cpp"
#include "DocGia.cpp"
#include "Sach.cpp"
#include "MuonTra.cpp"
#include "lib.cpp"

class Handle {
private:
  fstream userFile;
  fstream bookFile;
  fstream muonFile;
  fstream dgFile;
  fstream adminFile;

  vector<Sach> books;
  vector<DangNhap> users;
  vector<DocGia> docGias;
  vector<Admin> admins;
public:
  /**
   * khởi tạo các biến cần thiết
   * khởi tạo trạng thái ban đầu của ứng dụng
   *
   */
  Handle() {
    this->userFile.open("./db/user.txt", ios::in | ios::out);
    this->bookFile.open("./db/book.txt", ios::in | ios::out);
    this->adminFile.open("./db/admin.txt", ios::in | ios::out);
    this->dgFile.open("./db/docGia.txt", ios::in | ios::out);
    this->muonFile.open("./db/muon.txt", ios::in | ios::out);

    this->users = DangNhap::dsTaiKhoan(this->userFile);
    this->books = Sach::dsSach(this->bookFile);

  }

  ~Handle() {
    userFile.close();
    bookFile.close();
    adminFile.close();
    dgFile.close();
    muonFile.close();
  }
  void reset() {
    userFile.seekg(0, std::ios::beg);
    bookFile.seekg(0, std::ios::beg);
    adminFile.seekg(0, std::ios::beg);
    dgFile.seekg(0, std::ios::beg);
    muonFile.seekg(0, std::ios::beg);

  }
  void run() {
    Record r1;
    r1.setId(1);
    r1.setTenSach("test 123 123");
    r1.setNguoiMuon("cuong 2342 23 424 2");
    r1.setNgayMuon(Date(1, 12, 2222));
    r1.setNgayTra(Date(1, 12, 2244));
    r1.update(true);
    r1.luu(muonFile);
    r1.luu(muonFile);
    r1.luu(muonFile);
    r1.luu(muonFile);
    cout << "\n=====================\n";
    cout << r1;
    cout << "\n=====================\n";
    Record r;
    reset();
    while (!muonFile.eof()) {
      muonFile >> r;
      cout << r << endl;
    }

  }
};