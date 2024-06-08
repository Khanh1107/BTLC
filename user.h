#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include<sstream>

using namespace std;

class User {
private:
    string username;
    string password;
    int permission;

public:
    User(const string& uname = "", const string& pwd = "", const int& per = 0)
        : username(uname), password(pwd), permission(per) {}
  
    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }

    int getPermission() const {
        return permission;
    }

    bool checkPassword(const string& pwd) const {
        return password == pwd;
    }

    bool checkPermission(const int& per) const {
        return permission == per;
    }

    // Lưu thông tin người dùng vào file
    void saveToFile(ofstream& outFile) const {
        outFile << username << ' ' << password << ' ' << permission << endl;
    }

    // Tải thông tin người dùng từ file
   /* static User loadFromFile(ifstream& inFile) {
        string uname, pwd;
        int per;
        inFile >> uname >> pwd >> per;
        if (inFile) {  // Kiểm tra nếu việc đọc thành công
            return User(uname, pwd, per);
        }
        return User();  // Trả về User mặc định nếu việc đọc thất bại
    }*/
};

vector<User> users;

// Tải danh sách người dùng từ file
void loadUsers() {
    ifstream inFile("users.txt", ifstream :: in);
    string name ,password;
    int per;
    if (inFile.is_open()) {
           inFile >> name >> password >> per;
            User user (name , password ,per);
            if (inFile && !user.getUsername().empty()) {  // Chỉ thêm người dùng nếu việc đọc thành công
                for (int i = 0; i<users.size();i++){
                    if(users[i].getUsername() == name && users[i].getPermission() == per && users[i].getPassword() == password){
                        break;
                    }
                    else  users.push_back(user);
                    }
               // users.push_back(user);
            }
        inFile.close();
    } else {
        cout << "Không thể mở file users.txt để đọc.\n";
    }
}

// Lưu danh sách người dùng vào file
void saveUsers() {
    ofstream outFile("users.txt",ofstream :: out);  // Mở file với chế độ trunc để ghi đè nội dung cũ
    if (outFile.is_open()) {
        for (int i = 0 ; i< users.size();i++) {
            outFile << users[i].getUsername()<< " "<<users[i].getPassword()<<" "<<users[i].getPermission()<<endl;
        }
        outFile.close();
    } else {
        cout << "Không thể mở file users.txt để ghi.\n";
    }
}

// Đăng ký người dùng mới
void registerUser() {
    string username, password;
    int permission;
    cout << "Nhap ten dang nhap: ";
    cin >> username;
    cout << "Nhap mat khau: ";
    cin >> password;
    cout << "Giang vien : 1, PDT : 2 " << endl;
    cin >> permission;

    users.emplace_back(username, password, permission);
    saveUsers(); // Lưu thông tin người dùng mới vào file
    cout << "Dang ky thanh cong!\n";
}

// Đăng nhập người dùng
int loginUser() {
    string username, password;
    int permission;
    cout << "Nhap ten dang nhap: ";
    cin >> username;
    cout << "Nhap mat khau: ";
    cin >> password;
    cout << "Giang vien - 1, PDT - 2 : ";
    cin >> permission;

    for (const User& user : users) {
        if (user.getUsername() == username && user.checkPassword(password) && user.checkPermission(permission)) {
            cout << "Dang nhap thanh cong!\n";
            return user.getPermission();
        }
    }
    cout << "Ten dang nhap hoac mat khau sai.\n";
    return 0;
}

#endif
