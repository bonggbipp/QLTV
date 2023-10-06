#pragma once
#include "lib.cpp"

class ThongKe
{
private:
  Record* record;
public:
  ThongKe() {

  }
  ~ThongKe() { delete[] this->record }
};

