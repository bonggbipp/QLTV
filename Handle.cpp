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
    this->admins = Admin::dsAdmin(this->adminFile);
    this->docGias = DocGia::dsDocGia(this->dgFile);
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
    Admin a;
    DocGia d;
    bool run = true;
    int chon;
    while (run)
    {
      cout << "\n==========================================\n";
      cout << "Chon chuc nang ban muon chay:\n";
      cout << "1. Admin dang nhap\n";
      cout << "2. Doc gia dang nhap\n";
      cout << "3. Thoat\n";
      cout << "lua chon cua ban: ";
      cin >> chon;
      if (chon < 1 || chon > 3) {
        cout << "vui long chon lai.\n";
        system("pause");
        system("cls");
      }
      else {
        switch (chon) {
        case 1:
        {
          system("cls");
          a.AdminDangNhap(users);
          bool aRun = true;
          int achon;
          while (aRun) {
            cout << "\n================ ADMIN ======================\n";
            cout << "Ten Admin: " << a.getTen() << endl;
            cout << "Cac chuc nang: \n";
            cout << "1. Lay thong tin sach\n";
            cout << "2. Them sach moi\n";
            cout << "3. Lay thong tin doc gia\n";
            cout << "4. Them doc gia\n";
            cout << "5. Thoat\n";
            cout << "lua chon cua ban la: ";
            cin >> achon;
            if (achon < 0 || achon>5) {
              // aRun = false;
            }
            else {
              switch (achon) {
              case 1: {
                system("cls");
                cout << "\n======== LAY THONG TIN SACH ========\n";
                cout << setw(10) << left << "id";
                cout << setw(25) << left << "Ten sach";
                cout << setw(25) << left << "Tac gia";
                cout << setw(10) << left << "So trang";
                cout << setw(15) << left << "Nam phat hanh";
                cout << endl;
                for (Sach s : books) {
                  cout << setw(10) << left << s.getMSS();
                  cout << setw(25) << left << s.getTenSach();
                  cout << setw(25) << left << s.getTenTacGia();
                  cout << setw(10) << left << s.getSoTrang();
                  cout << setw(15) << left << s.getNamXuatBan();
                  cout << endl;
                }
                system("pause");
              }
                    break;
              case 2:
              {
                system("cls");
                a.themSach(books);
              }
              break;
              case 3:
                cout << "\n=================== THONG TIN DOC GIA ====================\n";
                cout << setw(10) << left << "id";
                cout << setw(25) << left << "Ten";
                cout << setw(5) << left << "Tuoi";
                cout << setw(25) << left << "Dia chi";
                cout << endl;
                // cout << setw(15) << left << "Nam phat hanh";
                for (DocGia d : docGias) {
                  cout << setw(10) << left << d.GetId();
                  cout << setw(25) << left << d.GetTen();
                  cout << setw(5) << left << d.GetTuoi();
                  cout << setw(25) << left << d.GetDiaChi();
                  cout << endl;
                }
                cout << "\nin thong tin doc gia thanh cong\n";
                system("pause");
                system("cls");
                break;
              case 4:
                cout << "\n=============== THEM DOC GIA =================\n";
                a.themDocGia(docGias, users);
                break;
              case 5:
                aRun = false;
              }
            }
          }
        }
        break;
        case 2:
        {
          bool dRun = true;

          while (dRun)
          {
            cout << "\n============== DOC GIA ===================\n";
            cout << "Cac chuc nang: \n";
            cout << "1. Xem thong tin sach\n";
            cout << "0.Thoat\n";
            cout << "lua chon cua ban la: ";
            int chon2;
            cin >> chon2;
            cin.ignore();
            switch (chon2) {
            case 0:
              dRun = false;
              break;
            case 1:
            {
              system("cls");
              cout << "\n======== LAY THONG TIN SACH ========\n";
              cout << setw(10) << left << "id";
              cout << setw(25) << left << "Ten sach";
              cout << setw(25) << left << "Tac gia";
              cout << setw(10) << left << "So trang";
              cout << setw(15) << left << "Nam phat hanh";
              cout << endl;
              for (Sach s : books) {
                cout << setw(10) << left << s.getMSS();
                cout << setw(25) << left << s.getTenSach();
                cout << setw(25) << left << s.getTenTacGia();
                cout << setw(10) << left << s.getSoTrang();
                cout << setw(15) << left << s.getNamXuatBan();
                cout << endl;
              }
              system("pause");
            }
            break;
            }

          }
        }
        break;

        case 3:
          run = false;
          system("cls");
          cout << "cam on bn su dung ung dung.\nTam biet\n";
          system("pause");
          break;
        }
      }
    }
  }

};