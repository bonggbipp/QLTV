#include "Admin.cpp"
#include "DocGia.cpp"
#include "Book.cpp"

class Handle {
private:
  fstream userFile;
  fstream bookFile;
  vector<Book> books;
  vector<DangNhap> users;


public:
  Handle() {
    userFile.open("./db/user.txt", ios::in | ios::out);
    BookFile.open("./db/book.txt", ios::in | ios::out);
    DangNhap tem;
    this->users = tem.dsTaiKhoan();
  }

  void run() {

  }

  ~Handle() {
    userFile.close();
    bookFile.close();
  }
};