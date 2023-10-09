#pragma once
#include "lib.cpp"
/**
 * Class kiem soat dang nhap.
 * luu cac thong tin dang nhap co ban
 */
class DangNhap
{
private:
  int id;
  string username;
  string password;
public:
  DangNhap() {
    this->password = "";
    this->username = "";
    // this->id = "";
  }
  ~DangNhap() {}
  /* setter/getter */
  void setId(int id) { this->id = id; }
  void setUsername(string username) { this->username = username; }
  void setPassword(string password) { this->password = password; }

  int GetId() const { return this->id; }
  string getUsername() const { return this->username; }
  string getPassword() const { return this->password; }

  /**
   * @brief lấy danh sách các account có trong hệ thống.
   *
   * @param file luồng đọc ghi của user.txt
   * @return vector<DangNhap> danh sách động các users có trong hệ thống.
   */
  static vector<DangNhap> dsTaiKhoan(fstream& file) {
    vector<DangNhap> res;
    while (!file.eof()) {
      DangNhap tem;
      string u, p, m;
      getline(file, m);
      getline(file, u);
      getline(file, p);
      tem.setId(convertToInt(m));
      tem.setUsername(u);
      tem.setPassword(p);
      res.push_back(tem);
    }
    return res;
  }

  /**
   * @brief lưu account hiện tại vô hệ thống.
   *
   * @param f luồng đọc ghi của user.txt
   */
  void luu(fstream& f) {
    f << this->id << endl << this->username << endl << this->password;
  }

  /* huong dan cho code de cos the hien thi no ra console */
  /* chat GPT */
  friend std::ostream& operator<<(std::ostream& os, const DangNhap& o) {
    // Code to write the object to the output stream
    os << "account: " << o.GetId() << " | " << o.getUsername() << " | " << o.getPassword() << endl;
    return os;
  }
};
