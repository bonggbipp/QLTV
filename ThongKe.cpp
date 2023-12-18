#pragma once
#include "lib.cpp"
#include "DocGia.cpp"
#include "MuonTra.cpp"

class ThongKe {
public:
  static void thongKeTheoThang(const vector<Record>& ds, bool m = true) {
    system("cls");
    // nam / vector<thang / vector>
    set<int> nam; // list danh sach cac nam;
    vector<pair<int, vector<int>*>> res; /// mangr chua nam vaf mangr thang 
    for (Record r : ds) {
      if (m)
        nam.insert(r.getNgayMuon().getNam());
      else if (r.getDaTra()) {
        nam.insert(r.getNgayTra().getNam());
      }
    }
    for (int n : nam) {
      vector<int>* d = new vector<int>[13];
      for (int i = 0;i < ds.size();i++) {
        // d[ds[i].getNgayMuon().getThang()]->v.push_back(i);
        if (m) {
          if (ds[i].getNgayMuon().getNam() == n)
            d[ds[i].getNgayMuon().getThang()].push_back(i);
        }
        else if (ds[i].getDaTra() && ds[i].getNgayTra().getNam() == n) {
          d[ds[i].getNgayTra().getThang()].push_back(i);
        }
      }
      res.push_back(make_pair(n, d));
    }

    /***************************************************/
    cout << "\n---------------------------------------- THONG KE THEO NGAY " << (m ? "MUON" : "TRA") << " ---------------------------------------------\n";
    for (int n : nam) {
      cout << "nam: " << n << endl;
      for (pair<int, vector<int>*> e : res) {
        if (e.first == n) {
          for (int i = 1;i <= 12;i++) {
            if (e.second[i].size() != 0) {
              cout << "--------------------------------------- DANH SACH CAC THE MUON THANG " << i << " ---------------------------------------\n";
              cout << " | " << setw(10) << left << "id";
              cout << " | " << setw(25) << left << "Ten sach";
              cout << " | " << setw(25) << left << "Nguoi muon";
              cout << " | " << setw(10) << left << "Ngay muon";
              cout << " | " << setw(10) << left << "Ngay tra";
              cout << " | " << setw(10) << left << "Trang thai";
              cout << " | " << endl;
              for (int _r : e.second[i]) {
                cout << " | " << setw(10) << left << ds[_r].getId();
                cout << " | " << setw(25) << left << ds[_r].getTenSach();
                cout << " | " << setw(25) << left << ds[_r].getNguoiMuon();
                cout << " | " << setw(10) << left << ds[_r].getNgayMuon().xuat();
                cout << " | " << setw(10) << left << ds[_r].getNgayTra().xuat();
                cout << " | " << setw(10) << left << (ds[_r].getDaTra() ? "da tra" : "chua tra");
                cout << " | " << endl;
              }
              cout << "\n--------------------------------------------------------------------------------------------------------------\n";
              cout << endl;
            }
          }
        }
      }
    }
    system("pause");
    system("cls");
    /***************************************************/
    for (auto& a : res) {
      delete[] a.second;
    }
  }

  static void thongKeTheoNguoiMuon(const vector<Record>& ds) {
    system("cls");
    vector < pair<int, vector<Record>>> res;
    for (Record r : ds) {
      bool run = true;
      for (pair<int, vector<Record>>& e : res) {
        if (r.getIdNguoiMuon() == e.first) {
          e.second.push_back(r);
          run = false;
        }
      }
      if (run) {
        vector<Record> v;
        v.push_back(r);
        res.push_back(make_pair(r.getIdNguoiMuon(), v));
      }
    }

    cout << "\n--------------- THONG KE THEO NGUOI MUON -----------------\n";
    for (pair<int, vector<Record>> e : res) {
      cout << "Doc gia " << e.second.at(0).getNguoiMuon() << ":\n";
      // for (Record r : e.second) {
      MuonTra::hienThiDSTheMuon(e.second);
      // }
    }
    system("pause");
    system("cls");
  }
};