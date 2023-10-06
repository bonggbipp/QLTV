#pragma once
#include "dangNhap.cpp"
/**
 * doc gia
 */
class DocGia : public DangNhap
{
private:
  string ten;
  string diaChi;
  int tuoi;
public:
  DocGia() {};
  ~DocGia() {};

  void setTen(string ten) { this->ten = ten; }
  void setDiaChi(string diaChi) { this->diaChi = diaChi; }
  void setTuoi(int tuoi) { this->tuoi = tuoi; }

  int GetTuoi() { return this->tuoi; }
  string GetTen() { return this->ten; }
  string GetDiaChi() { return this->diaChi; }

  void docGiaDangNhap(vector<DangNhap> acc) {
    string u, p;
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

  void updateThongTin() {
    int chon;
    do {
      system("cls");
      cout << "\n=========================== CAP NHAT THONG TIN ===========================\n";
      cout << "1. Thay doi ten\n";
      cout << "2. Thay doi tuoi\n";
      cout << "3. Thay doi dia chi\n";
      cout << "Lua chon cua ban la: ";
      cin >> chon;
      if (chon < 1 || chon > 3) {
        cout << "vui long chon lai chuc nang.\n";
        system("pause");
      }
    } while (chon < 1 || chon > 3);
    system("cls");
    switch (chon) {
    case 1:
      cout << "\n=========================== CAP NHAT TEN ===========================\n";
      cout << "Ten cua ban: " << this->ten << endl;
      cout << "Nhap Ten moi: ";
      cin.ignore();
      getline(cin, this->ten);
      break;
    case 2:
      cout << "\n=========================== CAP NHAT TUOI ===========================\n";
      cout << "Tuoi cua ban: " << this->tuoi << endl;
      cout << "Nhap Tuoi moi: ";
      cin >> this->tuoi;
      break;
    case 3:
      cout << "\n=========================== CAP NHAT DIA CHI ===========================\n";
      cout << "Dia chi cua ban: " << this->diaChi << endl;
      cout << "Nhap dia chi moi: ";
      cin.ignore();
      getline(cin, this->diaChi);
      break;
    }
    cout << "Ban da thay doi thanh cong";
    system("pause");
    system("cls");
  }

  void luu(fstream& f) {
    f << DangNhap::GetId() << endl << this->ten << endl << this->diaChi << endl << this->tuoi << endl;
  }
};
