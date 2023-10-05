#include "lib.cpp"
/**
 * dang nhap
 *
 */
class DangNhap
{
private:
  string username;
  string password;
public:
  DangNhap() {
    this->password = "";
    this->username = "";
  }
  ~DangNhap() {}

  void setUsername(string username)
  {
    this->username = username;
  }
  string getUsername()
  {
    return this->username;
  }
  void setPassword(string password)
  {
    this->password = password;
  }
  string getPassword()
  {
    return this->password;
  }

  vector<DangNhap> dsTaiKhoan(fstream& file) {
    vector<DangNhap> res;
    while (!file.eof()) {
      DangNhap tem;
      string u, p;
      getline(file, u);
      getline(file, p);
      tem.setUsername(u);
      tem.setPassword(p);
      res.push_back(tem);
    }

    return res;
  }
};
