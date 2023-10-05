#include "Book.cpp"

int main() {
  Book book;
  book.setTenSach("Cuon sach cua toi");
  book.setMSS("123456");
  book.setTenTacGia("Tac gia cua toi");
  book.setSoTrang(100);
  book.setNamXuatBan(2023);
  fstream file;
  file.open("./db/book.txt", ios::out | ios::in);
  book.luu(file);

  vector<Book> res = book.dsBook(file);
  for (int i = 0;i < res.size();i++) {
    cout << res[i].getMSS() << "|" << res[i].getTenSach() << "|" << res[i].getTenTacGia() << "|" << res[i].getSoTrang() << "|" << res[i].getNamXuatBan() << "\n";
  }
  return 0;
}