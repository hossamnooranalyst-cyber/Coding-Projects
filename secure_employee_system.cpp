#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// دالة لتشفير البيانات المالية (Simple Encryption)
string xorEncrypt(string data) {
    char key = 'S'; 
    for (int i = 0; i < data.size(); i++) data[i] ^= key;
    return data;
}

class Employee {
public:
    int id;
    string name;
    string salary;

    Employee(int i, string n, string s) : id(i), name(n), salary(s) {}
};

class HRSystem {
private:
    vector<Employee> db;
    string dbFile = "company_data.dat";

public:
    void addEmployee(int id, string name, string salary) {
        // تشفير الراتب قبل الإضافة
        Employee newEmp(id, name, xorEncrypt(salary));
        db.push_back(newEmp);
        saveToFile();
        cout << "Employee [ " << name << " ] added and salary encrypted!\n";
    }

    void saveToFile() {
        ofstream file(dbFile, ios::app);
        if (file.is_open()) {
            for (auto &emp : db) {
                file << emp.id << "," << emp.name << "," << emp.salary << endl;
            }
            file.close();
            db.clear(); // مسح الذاكرة المؤقتة بعد الحفظ
        }
    }

    void showAll() {
        cout << "\n--- Current Staff Records (Decrypted for HR) ---\n";
        ifstream file(dbFile);
        string line, id, name, sal;
        while (getline(file, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.rfind(',');
            id = line.substr(0, p1);
            name = line.substr(p1 + 1, p2 - p1 - 1);
            sal = xorEncrypt(line.substr(p2 + 1)); // فك التشفير للعرض
            cout << "ID: " << id << " | Name: " << name << " | Salary: $" << sal << endl;
        }
    }
};

int main() {
    HRSystem hr;
    cout << "--- Secure HR Management System 2.0 ---\n";
    
    // محاكاة إضافة بيانات
    hr.addEmployee(101, "Hossam", "85000");
    hr.addEmployee(102, "Ahmed", "72000");
    
    // عرض البيانات بعد فك تشفيرها
    hr.showAll();

    return 0;
}
