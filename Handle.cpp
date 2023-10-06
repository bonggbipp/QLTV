#pragma once
#include "Admin.cpp"
#include "DocGia.cpp"
#include "Sach.cpp"

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
  Handle() {
    this->userFile.open("./db/user.txt", ios::in | ios::out);
    this->bookFile.open("./db/book.txt", ios::in | ios::out);
    this->adminFile.open("./db/admin.txt", ios::in | ios::out);
    this->dgFile.open("./db/docGia.txt", ios::in | ios::out);
    DangNhap tem;
    this->users = tem.dsTaiKhoan(this->userFile);
  }

  void run() {

  }

  ~Handle() {
    userFile.close();
    bookFile.close();
  }
};