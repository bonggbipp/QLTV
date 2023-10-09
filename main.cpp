// #include "Book.cpp"
#include "DocGia.cpp"
#include "Sach.cpp"
#include "Handle.cpp"
// #include <termcolor/termcolor.hpp>
int main() {
  // Sach sach;
  // fstream f;
  // f.open("./db/book.txt", ios::out | ios::in);

  // vector<Sach> sachs = sach.dsSach(f);
  // cout << "========================================== THONG TIN SACH ==========================================\n";
  // cout << setw(5) << "MSS";
  // cout << setw(25) << "ten sach";
  // cout << setw(25) << "ten tac gia";
  // cout << setw(15) << "so trang";
  // cout << setw(15) << "nam phat hanh";
  // cout << endl;
  // for (int i = 0; i < sachs.size(); i++) {
  //   cout << setw(5) << sachs.at(i).getMSS();
  //   cout << setw(25) << sachs.at(i).getTenSach();
  //   cout << setw(25) << sachs[i].getTenTacGia();
  //   cout << setw(15) << sachs[i].getSoTrang();
  //   cout << setw(15) << sachs[i].getNamXuatBan();
  //   cout << endl;
  // }
  // f.close();
  Handle handle;
  handle.run();
  // fstream f("./db/muon.txt", ios::in);
  // while (!f.eof())
  // {
  //   string tem;
  //   getline(f, tem);
  //   cout << tem << endl;
  // }

  return 0;
}