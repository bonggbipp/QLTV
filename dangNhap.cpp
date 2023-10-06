#pragma once
#include "lib.cpp"
/**
 * dang nhap
 *
 */
class DangNhap
{
private:
  string id;
  string username;
  string password;
public:
  DangNhap() {
    this->password = "";
    this->username = "";
    this->id = "";
  }
  ~DangNhap() {}
  void setId(string id) { this->id = id; }
  void setUsername(string username) { this->username = username; }
  void setPassword(string password) { this->password = password; }
  string GetId() { return this->id; }
  string getUsername() { return this->username; }
  string getPassword() { return this->password; }

  vector<DangNhap> dsTaiKhoan(fstream& file) {
    vector<DangNhap> res;
    while (!file.eof()) {
      DangNhap tem;
      string u, p, m;
      getline(file, m);
      getline(file, u);
      getline(file, p);
      tem.setId(m);
      tem.setUsername(u);
      tem.setPassword(p);
      res.push_back(tem);
    }
    return res;
  }

  void luu(fstream& f) {
    f << this->id << endl << this->username << endl << this->password << endl;
  }
};
