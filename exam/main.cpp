#include <cmath>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define HARGA_PER_KG 10000
#define FLAT_FEE_BESOK_SAMPAI 1000
#define HARGA_PER_KM 20000

// Base Class
class Paket {
 protected:
  float beratBarang, totalHarga;

 public:
  virtual void setData(float b) {
    beratBarang = b;
    // Total harga based on Berat Barang
    totalHarga = beratBarang * HARGA_PER_KG;
  }
  virtual void getResult() {
      cout << "Total Harga\t\t\t: " << totalHarga << endl;
  }
};

// Derived Class
class PaketBesokSampai : public Paket {
 public:
  void setData(float b) {
    beratBarang = b;
    // Total harga based on Berat barang ditambah flat-fee per 5kg
    // 5kg pertama dianggap 1x flat fee
    float beratPerLima = b > 5 ? b / 5 : 1;
    totalHarga = beratBarang * HARGA_PER_KG + round(beratPerLima) * FLAT_FEE_BESOK_SAMPAI;
  }
};

// Derived Class
class PaketInstan : public Paket {
 protected:
  int jarak;
 public:
  void setData(float b, int j) {
    beratBarang = b;
    jarak = j;
    // Total harga based on jarak
    totalHarga = jarak * HARGA_PER_KM;
  }
  void getResult() {
    // Validation jika max berat 10kg 
    if (beratBarang <= 10) {
      cout << "Total Harga\t\t\t: " << totalHarga << endl;
    } else {
      cout << "Berat barang anda melebihi 10kg, Harap menggunakan jenis paket yang lain." << endl;
    }
  }
};

string aliasPaket(int type) {
  string res;
  switch (type) {
    case 1:
      res = "Standar";
      break;
    case 2:
      res = "Besok Sampai";
      break;
    case 3:
      res = "Instan";
      break;
  }
  return res;
}

int main() {
  cout << "JASA KIRIM PAKET" << endl;
  cout << "--------------------- \n\n";
  cout << "Pilih Jenis Paket" << endl;
  cout << "(1) Standar" << endl;
  cout << "(2) Besok Sampai" << endl;
  cout << "(3) Instan" << endl;

  int jenisPaket;
  cout << "Jenis Paket : ";
  cin >> jenisPaket;
  fflush(stdin);
  cout << "--------------------- \n\n";

  if (jenisPaket < 1 || jenisPaket > 3) {
    cout << "Jenis paket yang anda input tidak valid!";
    return 0;
  }

  cout << "Pengiriman Paket " << aliasPaket(jenisPaket) << endl;
  float tempBerat;
  int tempJarak;
  cout << "Berat Barang (kg)\t: ";
  cin >> tempBerat;
  fflush(stdin);
  if (jenisPaket == 3) {
    cout << "Jarak (km)\t\t\t: ";
    cin >> tempJarak;
    fflush(stdin);
  }

  // Object
  Paket s;
  PaketBesokSampai bs;
  PaketInstan i;

  if (jenisPaket == 1) {
    s.setData(tempBerat);
    s.getResult();
  } else if (jenisPaket == 2) {
    bs.setData(tempBerat);
    bs.getResult();
  } else if (jenisPaket == 3) {
    i.setData(tempBerat, tempJarak);
    i.getResult();
  }

  return 0;
}
