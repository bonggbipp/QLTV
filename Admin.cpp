#pragma once
#include "dangNhap.cpp"
#include "Sach.cpp"
#include "DocGia.cpp"
/**
 * Nhan vien
 * class ther hien nhan vien.
 * the hien nhung vc nhan vien co the lm.
 */
class Admin : public DangNhap {
private:
  string ten;

  void updateThongTinSach(vector<Sach> sachs, int id) {
    int chon;
    string tem;
    int tem2;
    do {
      cout << "\n=============== CAP NHAT THONG TIN CHO SACH ==================\n";
      cout << "Ten: " << sachs[id].getTenSach() << endl;
      cout << "Ten tac gia: " << sachs[id].getTenTacGia() << endl;
      cout << "So trang: " << sachs[id].getSoTrang() << endl;
      cout << "Nam xuat ban: " << sachs[id].getNamXuatBan() << endl;
      cout << "Lua chon pham minh muon sua:\n";
      cout << "1. Ten\n";
      cout << "2. Ten Tac Gia\n";
      cout << "3. So Trang\n";
      cout << "4. Nam xuat ban\n";
      cout << "Lua chon cua ban: ";
      cin >> chon;
    } while (chon > 4 || chon < 1);

    cin.ignore();

    switch (chon) {
    case 1:
      cout << "\n================= THAY TEN ===================\n";
      cout << "Ten hien tai: " << sachs[id].getTenSach() << endl;
      cout << "Ten moi: ";
      getline(cin, tem);
      sachs[id].setTenSach(tem);
      break;
    case 2:
      cout << "\n================= THAY TEN TAC GIA ===================\n";
      cout << "Ten tac gia hien tai: " << sachs[id].getTenTacGia() << endl;
      cout << "Ten tac gia  moi: ";
      getline(cin, tem);
      sachs[id].setTenTacGia(tem);
      break;
    case 3:
      cout << "\n================= THAY SO TRANG ===================\n";
      cout << "So trang hien tai: " << sachs[id].getSoTrang() << endl;
      cout << "So trang moi: ";
      // getline(cin, tem);
      cin >> tem2;
      sachs[id].setSoTrang(tem2);
      break;
    case 4:
      cout << "\n================= THAY NAM XUAT BAN ===================\n";
      cout << "Nam xuat ban: " << sachs[id].getNamXuatBan() << endl;
      cout << "Nam xuat ban moi: ";
      cin >> tem2;
      sachs[id].setNamXuatBan(tem2);
      break;
    }
    cout << "Ban da dang nhap thanh cong\n";
    system("pause");
  }

public:
  Admin() {}
  ~Admin() {}
  /* setter/getter */
  void setTen(string ten) { this->ten = ten; }
  string getTen() const { return this->ten; }
  /**
   * @brief luu du lieu ra file.
   *
   * @param f luong doc ghi cua file admin.txt
   */
  void luu(fstream& f) {
    f << DangNhap::GetId() << endl << this->ten;
  }
  /**
   * @brief hàm tĩnh để lấy danh sách các Admin có trong hệ thống.
   *
   * @param f luồng đọc ghi của file Admin.txt
   * @return vector<Admin> Danh sách động các Admin có trong hệ thống.
   */
  static vector<Admin> dsAdmin(fstream& f) {

    vector<Admin> res;
    while (!f.eof()) {
      Admin tg;
      string tem;
      getline(f, tem);
      tg.setId(convertToInt(tem));
      getline(f, tem);
      tg.setTen(tem);
      res.push_back(tg);
    }
    return res;
  }
  /**
   * @brief Admin đăng nhập
   *
   * @param acc danh sách các account có trong hệ thống
   * @param ads danh sách các account admin có trong hệ thống
   * @return int id của account đó nếu có | -1 nếu không đăng nhập thanh công.
   */
  int AdminDangNhap(const vector<DangNhap> acc, const vector<Admin> ads) {
    cin.ignore();
    string u, p;
    int m;
    cout << "\n=========================== DANG NHAP ===========================\n";
    cout << setw(30) << right << "Username: ";
    getline(cin, u);
    cout << setw(30) << right << "Password: ";
    getline(cin, p);

    bool run = true;

    for (int i = 0;i < acc.size();i++) {
      /**Hàm strcmp() là một hàm dùng để so sánh hai chuỗi. Hàm này sẽ so sánh từng ký tự của hai chuỗi từ đầu đến cuối. Nếu hai chuỗi giống nhau, hàm sẽ trả về giá trị 0. Nếu chuỗi đầu tiên lớn hơn chuỗi thứ hai, hàm sẽ trả về giá trị âm. Nếu chuỗi đầu tiên nhỏ hơn chuỗi thứ hai, hàm sẽ trả về giá trị dương. */
      if (strcmp(acc.at(i).getUsername().c_str(), u.c_str()) == 0 && strcmp(acc.at(i).getPassword().c_str(), p.c_str()) == 0) {
        for (Admin a : ads) {
          if (a.GetId() == acc[i].GetId()) {
            run = false;
            m = acc.at(i).GetId();
            this->setUsername(u);
            this->setPassword(p);
            this->setId(acc.at(i).GetId());
            this->setTen(a.getTen());
            break;
          }
        }
      }
    }
    while (run) {
      for (int i = 0;i < acc.size();i++) {
        if (strcmp(acc.at(i).getUsername().c_str(), u.c_str()) == 0 && strcmp(acc.at(i).getPassword().c_str(), p.c_str()) == 0) {
          for (Admin a : ads) {
            if (a.GetId() == acc[i].GetId()) {
              run = false;this->setUsername(u);
              this->setPassword(p);
              this->setId(acc.at(i).GetId());
              this->setTen(a.getTen());
              break;
            }
          }

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

    cout << "Dang nhap thanh cong" << endl;
    system("pause");
    system("cls");
    return m;
  }
  /**
   * @brief cập nhật thông tin cho Admin hiện tại
   *
   */
  void updateThongTin() {
    int chon;
    do {
      system("cls");
      cout << "\n=========================== CAP NHAT THONG TIN ===========================\n";
      cout << "1. Thay doi ten\n";
      // cout << "2. Thay doi tuoi\n";
      // cout << "3. Thay doi dia chi\n";
      cout << "Lua chon cua ban la: ";
      cin >> chon;
      if (chon != 1) {
        cout << "vui long chon lai chuc nang.\n";
        system("pause");
        system("cls");
      }
    } while (chon != 1);

    switch (chon) {
    case 1:
      cout << "\n=========================== CAP NHAT TEN ===========================\n";
      cout << "Ten cua ban: " << this->ten << endl;
      cout << "Nhap Ten moi: ";
      cin.ignore();
      getline(cin, this->ten);
      break;
    }
    cout << "Ban da thay doi thanh cong";
    system("pause");
    system("cls");
  }
  /**
   * @brief cập nhật thông tin cho độc giả.
   *
   * @param docGia danh sách các độc giả
   * @param id id cửa độc giả cần update thông tin
   */
  void updateThongTin(vector<DocGia>& docGia, int id) {
    string tem;
    int chon;
    do {
      system("cls");
      cout << "\n=========================== CAP NHAT THONG TIN DOC GIA ===========================\n";
      cout << "Cap nhat thong tin cho Doc gia: " << docGia[id].GetTen() << endl;
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

    switch (chon) {
    case 1:
      cout << "\n=========================== CAP NHAT TEN ===========================\n";
      cout << "Ten cua ban: " << docGia[id].GetTen() << endl;
      cout << "Nhap Ten moi: ";
      cin.ignore();

      getline(cin, tem);
      docGia[id].setTen(tem);
      break;
    case 2:
      cout << "\n=========================== CAP NHAT TUOI ===========================\n";
      cout << "Tuoi cua ban: " << docGia[id].GetTuoi() << endl;
      cout << "Nhap Tuoi moi: ";
      int tem2;
      cin >> tem2;
      docGia[id].setTuoi(tem2);
      break;
    case 3:
      cout << "\n=========================== CAP NHAT DIA CHI ===========================\n";
      cout << "Dia chi cua ban: " << docGia[id].GetDiaChi() << endl;
      cout << "Nhap dia chi moi: ";
      cin.ignore();
      getline(cin, tem);
      docGia[id].setDiaChi(tem);
      break;
    }
    cout << "Ban da thay doi thong tin thanh cong";
    system("pause");
    system("cls");
  }

  /**
   * @brief thêm sách mới
   *
   * @param sachs danh sách các sách có trong hệ thống.
   */
  void themSach(vector<Sach>& sachs) {
    cout << "\n================== THEM SACH MOI =============================\n";
    cout << "nhap so luong ban muon them: ";
    int sl;
    cin >> sl;
    string tem;
    int tem2;
    for (int i = 0;i < sl;i++) {
      Sach sachMoi;
      cin.ignore();
      sachMoi.setMSS(sachs.size());
      cout << "\n================ NHAP THONG TIN SACH =======================\n";
      cout << "Ten sach: ";
      getline(cin, tem);
      sachMoi.setTenSach(tem);
      cout << "Ten Tac gia: ";
      getline(cin, tem);
      sachMoi.setTenTacGia(tem);
      cout << "So trang: ";
      cin >> tem2;
      sachMoi.setSoTrang(tem2);
      cout << "Nam xuat ban: ";
      cin >> tem2;
      sachMoi.setNamXuatBan(tem2);
      sachs.push_back(sachMoi);
    }
    cout << "Da them " << sl << " sach thanh cong\n";
    system("pause");
    system("cls");
  }

  /**
   * @brief cap nhat thong tin cho sach da co
   *
   * @param sachs danh sách các sách có trong hệ thống
   */
  void updateThongTinSach(vector<Sach> sachs) {
    string tem;
    int tem2, chon;
    do {
      cout << "\n================== CAP NHAP =======================\n";
      cout << "Chon cach tim sach:\n";
      cout << "1. MSS.\n";
      cout << "2. Ten sach.\n";
      cout << "lua chon cua ban: ";
      cin >> chon;
    } while (chon < 1 || chon > 2);

    switch (chon) {
    case 1:
      do {
        cout << "\n==================================\n";
        cout << "Nhap Ma So Sach: ";
        cin >> tem2;
        if (tem2 > sachs.size() || tem2 < 0) {
          cout << "Ma so khong hop le.\nVui long nhap lai";
        }
      } while (tem2 > sachs.size() || tem2 < 0);
      updateThongTinSach(sachs, tem2);
      break;
    case 2:
      tem2 = Sach::timKiem(sachs);
      updateThongTinSach(sachs, tem2);
      break;
    }
    cout << "update Thong tin sach thanh cong\n";
    system("pause");

  }
  /**
   * @brief đăng ký độc giả mới.
   *
   * @param docGias danh sách các độc giả.
   * @param dn danh sách account
   */
  void themDocGia(vector<DocGia>& docGias, vector<DangNhap>& dn) {
    cin.ignore();
    int soLuong;
    cout << "\n================ THEM DOC GIA MOI ==================\n";
    cout << "nhap so luong doc gia them moi:";
    cin >> soLuong;
    for (int i = 0;i < soLuong;i++) {
      DocGia docGiaMoi;
      DangNhap d;
      string tem;
      int tem2;
      cout << "\n=============== NHAP THONG TIN ===================\n";
      cout << "Nhap ten: ";
      cin.ignore();
      getline(cin, tem);
      docGiaMoi.setTen(tem);
      cout << "Nhap dia chi: ";
      getline(cin, tem);
      docGiaMoi.setDiaChi(tem);
      cout << "Nhap tuoi: ";
      // getline(cin, tem);
      cin >> tem2;
      cin.ignore();
      docGiaMoi.setTuoi(tem2);
      cout << "Nhap UserName: ";
      getline(cin, tem);
      d.setUsername(tem);
      docGiaMoi.setUsername(tem);
      cout << "Nhap password: ";
      getline(cin, tem);
      d.setPassword(tem);
      docGiaMoi.setPassword(tem);
      d.setId(dn.size());
      docGiaMoi.setId(dn.size());
      docGias.push_back(docGiaMoi);
      dn.push_back(d);
      cout << "\n========== THEM THANH CONG ==========\n";
      system("pause");
      system("cls");
    }
  }

  void thongKe() { }
};
