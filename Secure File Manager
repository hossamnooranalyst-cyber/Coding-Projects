#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// دالة بسيطة لتشفير محتوى الملف (XOR Encryption)
string encryptDecrypt(string data) {
    char key = 'K'; // مفتاح التشفير
    string output = data;
    for (int i = 0; i < data.size(); i++)
        output[i] = data[i] ^ key;
    return output;
}

class FileManager {
public:
    void writeFile() {
        string filename, content;
        cout << "Enter filename to create: ";
        cin >> filename;
        cout << "Enter content to write: ";
        cin.ignore();
        getline(cin, content);

        ofstream file(filename);
        if (file.is_open()) {
            file << encryptDecrypt(content); // حفظ النص مشفراً
            file.close();
            cout << "File saved securely!\n";
        }
    }

    void readFile() {
        string filename, line, content;
        cout << "Enter filename to read: ";
        cin >> filename;

        ifstream file(filename);
        if (file.is_open()) {
            while (getline(file, line)) {
                content += line;
            }
            cout << "Decrypted Content: " << encryptDecrypt(content) << endl;
            file.close();
        } else {
            cout << "File not found!\n";
        }
    }
};

int main() {
    FileManager fm;
    int choice;

    while (true) {
        cout << "\n--- Secure File Manager ---\n";
        cout << "1. Create Encrypted File\n2. Read & Decrypt File\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) fm.writeFile();
        else if (choice == 2) fm.readFile();
        else break;
    }
    return 0;
}
