#include "Admin.cpp"
#include "DocGia.cpp"
#include "Sach.cpp"
#include "MuonTra.cpp"
#include "ThongKe.cpp"

#define RESET(f) reset(f, 5)


int main() {
  fstream file[5];

  vector<Sach> books;
  vector<DangNhap> users;
  vector<DocGia> docGias;
  vector<Admin> admins;
  vector<Record> muonTra;

  file[0].open("./db/user.txt", ios::in | ios::out);
  file[1].open("./db/book.txt", ios::in | ios::out);
  file[2].open("./db/admin.txt", ios::in | ios::out);
  file[3].open("./db/docGia.txt", ios::in | ios::out);
  file[4].open("./db/muon.txt", ios::in | ios::out);

  RESET(file);

  users = DangNhap::dsTaiKhoan(file[0]);
  books = Sach::dsSach(file[1]);
  admins = Admin::dsAdmin(file[2]);
  docGias = DocGia::dsDocGia(file[3]);
  muonTra = MuonTra::dsMT(file[4]);

  /*****************************************************/

  bool run = true;
  while (run)
  {
    char chon;
    cout << "\n-------------------------------------------\n";
    cout << "Chon chuc nang ban muon chay:\n";
    cout << "1. Admin dang nhap\n";
    cout << "2. Doc gia dang nhap\n";
    cout << "0. Thoat\n";
    cout << "lua chon cua ban: ";
    cin >> chon;

    switch (chon) {
    case '1':
    {
      Admin a;
      system("cls");
      a.AdminDangNhap(users, admins);
      bool aRun = true;
      char achon;
      while (aRun) {
        cout << "\nTen Admin: " << a.getTen() << endl;
        cout << "\n----------------------- ADMIN ------------------------\n";
        cout << setw(53) << left << "| Cac chuc nang: " << " |\n";
        cout << setw(53) << left << "| 1. Lay thong tin sach" << " |\n";
        cout << setw(53) << left << "| 2. Them sach moi" << " |\n";
        cout << setw(53) << left << "| 3. Lay thong tin doc gia" << " |\n";
        cout << setw(53) << left << "| 4. Them doc gia" << " |\n";
        cout << setw(53) << left << "| 5. Hien thi thong tin cac the muon." << " |\n";
        cout << setw(53) << left << "| 6. Thong Ke." << " |\n";
        cout << setw(53) << left << "| 0. Thoat" << " |\n";
        cout << "-----------------------------------------------------\n";
        cout << "lua chon cua ban la: ";
        cin >> achon;
        switch (achon) {
        case '1':
        {
          system("cls");
          cout << "\n------------------------------------- LAY THONG TIN SACH --------------------------------- \n";
          cout << setw(10) << left << "| id" << "|";
          cout << setw(25) << left << "Ten sach" << "|";
          cout << setw(25) << left << "Tac gia" << "|";
          cout << setw(10) << left << "So trang" << "|";
          cout << setw(15) << left << "Nam phat hanh" << "|";
          cout << endl;
          cout << "------------------------------------------------------------------------------------------\n";
          for (Sach s : books) {
            cout << "| " << setw(8) << left << s.getMSS() << "|";
            cout << setw(25) << left << s.getTenSach() << "|";
            cout << setw(25) << left << s.getTenTacGia() << "|";
            cout << setw(10) << left << s.getSoTrang() << "|";
            cout << setw(15) << left << s.getNamXuatBan() << "|";
            cout << endl;
          }
          cout << "------------------------------------------------------------------------------------------\n";
          system("pause");
          system("cls");
        }
        break;
        case '2':
        {
          system("cls");
          a.themSach(books);
        }
        break;
        case '3':
        {
          system("cls");
          cout << "\n---------------------------- THONG TIN DOC GIA ---------------------------\n";
          cout << setw(10) << left << "| id" << "|";
          cout << setw(25) << left << "Ten" << "|";
          cout << setw(10) << left << "Tuoi" << "|";
          cout << setw(25) << left << "Dia chi" << "|";
          cout << endl;
          cout << "--------------------------------------------------------------------------\n";
          // cout << setw(15) << left << "Nam phat hanh";
          for (DocGia d : docGias) {
            cout << "| " << setw(8) << left << d.getId() << "|";
            cout << setw(25) << left << d.getTen() << "|";
            cout << setw(10) << left << d.getTuoi() << "|";
            cout << setw(25) << left << d.getDiaChi() << "|";
            cout << endl;
          }
          cout << "--------------------------------------------------------------------------\n";
          cout << "\nIn thong tin doc gia thanh cong\n";
          system("pause");
          system("cls");
        }
        break;
        case '4':
          a.themDocGia(docGias, users);
          break;
        case '5':
          system("cls");
          MuonTra::hienThiDSTheMuon(muonTra);
          system("pause");
          system("cls");
          break;
        case '6':
        {
          system("cls");
          char t;
          bool tkRun = true;
          while (tkRun) {
            cout << "\n------------------------ THONG KE --------------------------\n";
            cout << setw(62) << left << "| 1. Thong ke theo nguoi." << "|\n";
            cout << setw(62) << left << "| 2. Thong ke theo Ngay muon." << "|\n";
            cout << setw(62) << left << "| 3. Thong ke theo Ngay Tra." << "|\n";
            cout << setw(62) << left << "| 0. Thoat." << "|\n";
            cout.width(62);
            cout.fill('-');
            cout << "";
            cout.fill(' ');

            cout << "\nLua chon cua ban la: ";
            cin >> t;
            switch (t) {
            case '0':
              tkRun = false;
              system("cls");
              break;
            case '1':
              ThongKe::thongKeTheoNguoiMuon(muonTra);
              break;
            case '2':
              ThongKe::thongKeTheoThang(muonTra);
              break;
            case '3':
              ThongKe::thongKeTheoThang(muonTra, false);
              break;
            default:
              cout << "Vui long nhap lai.";
              system("pause");
              system("cls");
            }
          }
        }
        break;
        case '0':
          aRun = false;
          break;
        default:
          cout << "vui long chon lai.\n";
          system("pause");
          system("cls");
        }
      }
    }
    break;
    case '2':
    {
      system("cls");
      DocGia d;
      d.docGiaDangNhap(users, docGias);
      bool dRun = true;
      while (dRun)
      {
        cout << "\n--------------------- DOC GIA --------------------- \n";
        cout << "Cac chuc nang: \n";
        cout << "1. Xem thong tin ca nhan\n";
        cout << "2. Xem thong tin sach\n";
        cout << "3. Muon sach\n";
        cout << "4. Tra sach\n";
        cout << "0.Thoat\n";
        cout << "lua chon cua ban la: ";
        char chon2;
        cin >> chon2;
        cin.ignore();
        switch (chon2) {
        case '0':
          dRun = false;
          system("cls");
          break;
        case '1':
        {
          system("cls");
          cout << "\n--------------------- DOC GIA --------------------- \n";
          cout << setw(10) << left << "id";
          cout << setw(25) << left << "Ten";
          cout << setw(10) << left << "Tuoi";
          cout << setw(25) << left << "Dia chi";
          cout << endl;
          cout << setw(10) << left << d.getId();
          cout << setw(25) << left << d.getTen();
          cout << setw(10) << left << d.getTuoi();
          cout << setw(25) << left << d.getDiaChi() << endl;

          system("pause");
          system("cls");
        }
        break;
        case '2':
        {
          system("cls");
          cout << "\n--------------------- LAY THONG TIN SACH --------------------- \n";
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
          system("cls");
        }
        break;
        case '3':
        {
          cout << "\n--------------------- MUON SACH --------------------- \n";
          if (d.getIdTheMuon() >= 0) {
            cout << "Ban dang muon sach!\nVui long tra trc khi muon.\n";
            system("pause");
            system("cls");
          }
          else {
            int mss = Sach::timKiem(books);
            if (mss >= 0) {
              for (Sach s : books) {
                if (s.getMSS() == mss) {
                  MuonTra::muon(s, d, muonTra);
                  break;
                }
              }
              cout << "\nMuon sach thanh cong\n";
              system("pause");
            }
            system("cls");
          }
        }
        break;
        case '4':
        {
          system("cls");
          cout << "\n-------------------- TRA SACH ----------------------------\n";
          if (d.getIdTheMuon() >= 0) {
            MuonTra::tra(d.getIdTheMuon(), muonTra);
            d.setIdTheMuon(-1);
            cout << "Tra sach thanh cong\n";
          }
          else {
            cout << "Ban khong muon sach nao ca\n";
          }
          system("pause");
          system("cls");
        }
        break;
        default:
          cout << "vui long chon lai.\n";
          system("pause");
          system("cls");
        }
      }
    }
    break;
    case '0':
      run = false;
      system("cls");
      cout << "cam on ban su dung ung dung.\nTam biet\n";
      system("pause");
      break;
    default:
      cout << "vui long chon lai.\n";
      system("pause");
      system("cls");
    }
  }
  /*****************************************************/
  RESET(file);
  // muon tra
  MuonTra::luu(file[4], muonTra);
  // user
  for (int i = 0;i < users.size() - 1;i++) {
    users[i].luu(file[0]);
    file[0] << endl;
  }
  users[users.size() - 1].luu(file[0]);
  // Sach
  for (int i = 0; i < books.size() - 1; i++) {
    books[i].luu(file[1]);
    file[1] << endl;
  }
  books[books.size() - 1].luu(file[1]);
  // Admin
  for (int i = 0; i < admins.size() - 1; i++) {
    admins[i].luu(file[2]);
    file[2] << endl;
  }
  admins[admins.size() - 1].luu(file[2]);
  // DocGia
  for (int i = 0; i < docGias.size() - 1; i++) {
    docGias[i].luu(file[3]);
    file[3] << endl;
  }
  docGias[docGias.size() - 1].luu(file[3]);

  for (size_t i = 0;i < 5;i++) file[i].close();
  return 0;
}