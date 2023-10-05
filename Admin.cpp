#include "dangNhap.cpp"
/**
 * Nhan vien
 */
class Admin : public DangNhap {
private:
  string name;
public:
  Admin() {}
  ~Admin() {}
  void AdminDangNhap(vector<DangNhap> acc) {
    string u, p;
    // ifstream fi;
    // fi.open("./db/user.txt", ios::in | ios::out);
    cout << "\n=========================== DANG NHAP ===========================\n";
    cout << setw(30) << right << "Username: ";
    getline(cin, u);
    cout << setw(30) << right << "Password: ";
    getline(cin, p);

    bool run = true;

    for (int i = 0;i < acc.size();i++) {
      if (strcmp(acc.at(i).getUsername().c_str(), u.c_str()) == 0 && strcmp(acc.at(i).getPassword().c_str(), p.c_str()) == 0) {
        run = false;
        cout << "true" << endl;
      }
    }
    while (run) {
      for (int i = 0;i < acc.size();i++) {
        if (strcmp(acc.at(i).getUsername().c_str(), u.c_str()) == 0 && strcmp(acc.at(i).getPassword().c_str(), p.c_str()) == 0) {
          run = false;
          break;
        }
      }
      if (!run) break;
      cout << "Ban da nhap sai Username hoac Password" << endl;
      system("pause");
      system("cls");
      cout << "Xin moi nhap lai" << endl;
      system("pause");
      system("cls");
      cout << "\n" << "=========================== DANG NHAP =========================== " << "\n";
      cout << setw(30) << right << "Username: ";
      getline(cin, u);
      cout << setw(30) << right << "Password: ";
      getline(cin, p);
    }
    this->setUsername(u);
    this->setPassword(p);
    cout << "Dang nhap thanh cong" << endl;
    system("pause");
    system("cls");
  }

  void layThongTinSach() {

  }
  void themSach() {

  }
};
