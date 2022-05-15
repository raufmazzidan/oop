#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#define BASE_SALARY 200000
#define BASE_WORK_HOURS 8
#define OVERTIME_BONUS_PER_HOUR 25000

class Employee {
 private:
  string name;
  int number, workHours, overtimeBonus = 0, totalSalary = BASE_SALARY;

 public:
  void setData(int num, string n, int wh) {
    number = num;
    name = n;
    workHours = wh;
    if (workHours > BASE_WORK_HOURS) {
      overtimeBonus = OVERTIME_BONUS_PER_HOUR * (workHours - BASE_WORK_HOURS);
      totalSalary += overtimeBonus;
    }
  }
  int getTotalSalary() { return totalSalary; }
  void getSalaryInfo() {
    cout << left << setw(5) << number 
         << left << setw(20) << name 
         << left << setw(10) << BASE_SALARY
         << left << setw(20) << workHours 
         << left << setw(15) << overtimeBonus 
         << left << setw(15) << totalSalary
         << endl;
  }
};

int main() {
  int totalEmployee;
  string inputDate;
  cout << "PT Meriang Gembira"
       << "\n\n";
  cout << "Jumlah \t\t\t: ";
  cin >> totalEmployee;
  fflush(stdin);
  cout << "Tanggal Input \t: ";
  cin >> inputDate;
  fflush(stdin);
  cout << "---------------------------------------------------------------------------------"
       << endl;
  Employee myEmployee[totalEmployee];
  for (int i = 0; i < totalEmployee; i++) {
    string tempName;
    int tempWorkHours;
    cout << "Data Ke-" << i + 1 << endl;
    cout << "Nama Pegawai\t\t: ";
    cin >> tempName;
    fflush(stdin);
    cout << "Jumlah Jam Kerja\t: ";
    cin >> tempWorkHours;
    fflush(stdin);
    myEmployee[i].setData(i + 1, tempName, tempWorkHours);
  }
  cout << "---------------------------------------------------------------------------------"
       << endl;
  int allEmployeeSalary = 0;
  cout << "\nPT Meriang Gembira" << endl;
  cout << "Tanggal : " << inputDate << "\n\n";

  cout << "================================================================================="
       << endl;
  cout << left << setw(5) << "No." 
       << left << setw(20) << "Nama Pegawai" 
       << left << setw(10) << "Honor" 
       << left << setw(20) << "Jumlah Jam Kerja" 
       << left << setw(15) << "Honor Lembur"
       << left << setw(15) << "Total Honor" 
       << endl;
  cout << "================================================================================="
       << endl;
  for (int i = 0; i < totalEmployee; i++) {
    allEmployeeSalary += myEmployee[i].getTotalSalary();
    myEmployee[i].getSalaryInfo();
  }
  cout << "================================================================================="
       << endl;
  cout << left << setw(70) << "Total Honor Pegawai Sebesar" << left << setw(15)
       << allEmployeeSalary;
  return 0;
}
