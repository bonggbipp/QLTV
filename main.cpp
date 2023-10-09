#include "Admin.cpp"
#include "DocGia.cpp"
#include "Sach.cpp"
#include "MuonTra.cpp"
#include "lib.cpp"

#define RESET reset(fs, 5)

int main() {
  fstream userFile;
  fstream bookFile;
  fstream muonFile;
  fstream dgFile;
  fstream adminFile;

  fstream* fs[5] = { &userFile, &bookFile, &adminFile, &dgFile, &muonFile };

  vector<Sach> books;
  vector<DangNhap> users;
  vector<DocGia> docGias;
  vector<Admin> admins;

  userFile.open("./db/user.txt", ios::in | ios::out);
  bookFile.open("./db/book.txt", ios::in | ios::out);
  adminFile.open("./db/admin.txt", ios::in | ios::out);
  dgFile.open("./db/docGia.txt", ios::in | ios::out);
  muonFile.open("./db/muon.txt", ios::in | ios::out);

  RESET;


  users = DangNhap::dsTaiKhoan(userFile);
  books = Sach::dsSach(bookFile);
  admins = Admin::dsAdmin(adminFile);
  docGias = DocGia::dsDocGia(dgFile);

  /*****************************************************/

  DocGia d;
  bool run = true;
  while (run)
  {
    char chon;
    cout << "\n==========================================\n";
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
      cout << a.AdminDangNhap(users, admins) << endl;
      bool aRun = true;
      char achon;
      while (aRun) {
        cout << "\n================ ADMIN ======================\n";
        cout << "Ten Admin: " << a.getTen() << endl;
        cout << "Cac chuc nang: \n";
        cout << "1. Lay thong tin sach\n";
        cout << "2. Them sach moi\n";
        cout << "3. Lay thong tin doc gia\n";
        cout << "4. Them doc gia\n";
        cout << "0. Thoat\n";
        cout << "lua chon cua ban la: ";
        // cin.ignore();
        cin >> achon;
        switch (achon) {
        case '1':
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
        case '4':
          a.themDocGia(docGias, users);
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
      bool dRun = true;
      while (dRun)
      {
        cout << "\n============== DOC GIA ===================\n";
        cout << "Cac chuc nang: \n";
        cout << "1. Xem thong tin sach\n";
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
      cout << "cam on bn su dung ung dung.\nTam biet\n";
      system("pause");
      break;
    default:
      cout << "vui long chon lai.\n";
      system("pause");
      system("cls");
    }
  }
  /*****************************************************/
  RESET;
  for (int i = 0;i < users.size() - 1;i++) {
    users[i].luu(userFile);
    userFile << endl;
  }
  users[users.size() - 1].luu(userFile);
  // Sach
  for (int i = 0; i < books.size() - 1; i++) {
    books[i].luu(bookFile);
    bookFile << endl;
  }
  books[books.size() - 1].luu(bookFile);

  // Admin
  for (int i = 0; i < admins.size() - 1; i++) {
    admins[i].luu(adminFile);
    adminFile << endl;
  }
  admins[admins.size() - 1].luu(adminFile);

  // DocGia
  for (int i = 0; i < docGias.size() - 1; i++) {
    docGias[i].luu(dgFile);
    dgFile << endl;
  }
  docGias[docGias.size() - 1].luu(dgFile);

  userFile.close();
  bookFile.close();
  adminFile.close();
  dgFile.close();
  muonFile.close();
  return 0;
}