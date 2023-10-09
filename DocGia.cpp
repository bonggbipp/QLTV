#pragma once
#include "dangNhap.cpp"
/**
 * doc gia
 * class kiem soat doc gia.
 * thuc hien cac chuc nang maf doc gia co the lam.
 */
class DocGia : public DangNhap {
private:
  string ten;
  string diaChi;
  int tuoi;
  int idTheMuon;
public:
  DocGia() {};
  ~DocGia() {};
  /* setter/getter */
  void setTen(string ten) { this->ten = ten; }
  void setDiaChi(string diaChi) { this->diaChi = diaChi; }
  void setTuoi(int tuoi) { this->tuoi = tuoi; }
  void setIdTheMuon(int idTheMuon) { this->idTheMuon = idTheMuon; }

  int GetTuoi() const { return this->tuoi; }
  string GetTen() const { return this->ten; }
  string GetDiaChi() const { return this->diaChi; }
  int GetIdTheMuon() const { return this->idTheMuon; }

  /**
   * @brief đăng nhâp của độc giả.
   *
   * @param acc danh sách các account có trong hệ thống.
   * @return int id của độc giả đã đăng nhập.
   */
  int docGiaDangNhap(vector<DangNhap> acc) {
    cin.ignore();
    string u, p, m;
    cout << "\n=========================== DANG NHAP ===========================\n";
    cout << setw(30) << right << "Username: ";
    getline(cin, u);
    cout << setw(30) << right << "Password: ";
    getline(cin, p);

    bool run = true;

    for (int i = 0;i < acc.size();i++) {
      if (strcmp(acc.at(i).getUsername().c_str(), u.c_str()) == 0 && strcmp(acc.at(i).getPassword().c_str(), p.c_str()) == 0) {
        m = acc.at(i).GetId();
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
    this->setId(convertToInt(m));
    cout << "Dang nhap thanh cong" << endl;
    system("pause");
    system("cls");
    return this->GetId();
  }
  /**
   * @brief cập nhật thông tin cho độc giả hiện tại.
   *
   */
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
  /**
   * @brief lưu độc giả hiện tại ra file.
   *
   * @param f luồng đọc ghi của file docGia.txt
   */
  void luu(fstream& f) {
    f << DangNhap::GetId() << endl << this->ten << endl << this->diaChi << endl << this->tuoi << endl << this->idTheMuon << endl;
  }

  friend std::ostream& operator<<(std::ostream& os, const DocGia& o) {
    // Code to write the object to the output stream
    os << o.GetId() << " | " << o.getUsername() << " | " << o.getPassword() << " | " << o.GetTen() << " | " << o.GetTuoi() << " | " << o.GetDiaChi() << endl;
    return os;
  }

  /**
   * @brief lấy danh sách các độc giả có trong hệ thống.
   *
   * @param f luồng đọc ghi của file docGia.txt
   * @return vector<DocGia> danh sách động các độc giả có trong hệ thống.
   */
  static vector<DocGia> dsDocGia(fstream& f) {
    vector<DocGia> res;
    while (!f.eof()) {
      DocGia tg;
      string tem;
      getline(f, tem);
      tg.setId(convertToInt(tem));
      getline(f, tem);
      tg.setTen(tem);
      getline(f, tem);
      tg.setDiaChi(tem);
      getline(f, tem);
      tg.setTuoi(convertToInt(tem));
      getline(f, tem);
      tg.setIdTheMuon(convertToInt(tem));
      res.push_back(tg);
    }
    return res;
  }
};
