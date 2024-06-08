
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Tree.h"
#include "user.h"

using namespace std;

void ThemTruongCon(Tree *tree)
{
    string name;
    cout << "Nhap ten truong: ";
    cin.ignore();
    getline(cin, name);
    Node *node = new Node(1, name);
    Node *find = tree->findTruong(name);
    if (find)
    {
        cout << "Truong da ton tai!" << endl;
    }
    else
    {
        cout << "Them thanh cong!" << endl;
        tree->add(node);
    }
}
Node *ThemKhoa1(Tree *tree)
{
    if (tree->getRoot()->getChildren().size() == 0)
    {
        cout << "Chua co truong nao!" << endl;
        return NULL;
    }
    tree->printTruong();
    int cmd;
    cout << "Nhap so thu tu truong: ";
    cin >> cmd;
    if (cmd > tree->getRoot()->getChildren().size() || cmd < 1)
    {
        cout << "Khong ton tai truong nay!" << endl;
        return NULL;
    }
    else
    {
        return tree->getRoot()->getChildren()[cmd - 1];
    }
}
void ThemKhoa(Tree *tree)
{
    // /in ra lỗi nếu chưa có trường nào

    string name;
    cout << "Nhap ten khoa: ";
    cin.ignore();
    getline(cin, name);
    Node *node = new Node(2, name);

    Node *truong = ThemKhoa1(tree);
    if (!truong)
        return;
    // thêm khoa vào trường đó
    Node *find = tree->findKhoa(name, truong);
    if (find)
    {
        cout << "Khoa da ton tai!" << endl;
    }
    else
    {
        cout << "Them thanh cong!" << endl;
        truong->add(node);
    }
}
void ThemNhomChuyenMon(Tree *tree)
{
    // in ra lỗi nếu chưa có trường hoặc khoa nào

    string name;
    cout << "Nhap ten nhom chuyen mon: ";
    cin.ignore();
    getline(cin, name);
    Node *node = new Node(3, name);
    // tương tự thêm khoa
    Node *truong = ThemKhoa1(tree);
    if (!truong)
        return;
    // in ra lỗi nếu chưa có khoa nào
    if (truong->getChildren().size() == 0)
    {
        cout << "Chua co khoa nao!" << endl;
        return;
    }
    tree->printKhoa(truong);
    int cmd2;
    cout << "Nhap so thu tu khoa: ";
    cin >> cmd2;
    if (cmd2 > truong->getChildren().size() || cmd2 < 1)
    {
        cout << "Khong ton tai khoa nay!" << endl;
        return;
    }

    Node *khoa = truong->getChildren()[cmd2 - 1];
    Node *find = tree->findNhom(name, khoa);
    if (find)
    {
        cout << "Nhom chuyen mon da ton tai!" << endl;
    }
    else
    {
        cout << "Them thanh cong!" << endl;
        khoa->add(node);
    }
}

void ThemGiaoVien(Tree *tree)
{
    // in ra lỗi nếu chưa có trường hoặc khoa hoặc nhóm nào
    if (tree->getRoot()->getChildren().size() == 0)
    {
        cout << "Chua co truong nao!" << endl;
        return;
    }
    string name;
    cout << "Nhap Ten Giang Vien: " << endl;
    cin.ignore();
    getline(cin, name);
    int ma;
    cout << "Nhap ma so Giang Vien"<<endl;
    cin >> ma;
    int numPub;
    cout << "Nhap so luong bai bao: " << endl;
    cin >> numPub;
    
    Node *node = new Node(4, name, numPub, ma);
    // tương tự thêm khoa
    tree->printTruong();
    int cmd ;
    
  /*  if (cmd > tree->getRoot()->getChildren().size() || cmd < 1)
    {
        cout << "Khong ton tai truong nay!" << endl;
        return;
    }*/
    cout << "Nhap so thu tu truong: ";
    cin >> cmd;
    Node *truong = tree->getRoot()->getChildren()[cmd - 1];
    if (truong->getChildren().size() == 0)
    {
        cout << "Chua co khoa nao!" << endl;
        return;
    }
    tree->printKhoa(truong);
    int cmd2;
    cout << "Nhap so thu tu khoa: ";
    cin >> cmd2;
    if (cmd2 > truong->getChildren().size() || cmd2 < 1)
    {
        cout << "Khong ton tai khoa nay!" << endl;
        return;
    }
    Node *khoa = truong->getChildren()[cmd2 - 1];
    if (khoa->getChildren().size() == 0)
    {
        cout << "Chua co nhom nao!" << endl;
        return;
    }
    tree->printNhom(khoa);
    int cmd3;
    cout << "Nhap so thu tu nhom: ";
    cin >> cmd3;
    if (cmd3 > khoa->getChildren().size() || cmd3 < 1)
    {
        cout << "Khong ton tai nhom nay!" << endl;
        return;
    }
    Node *nhom = khoa->getChildren()[cmd3 - 1];
    Node *find = tree->findGV(name, nhom, ma);
    if (find)
    {
        cout << "Giang vien da ton tai!" << endl;
    }
    else
    {
        cout << "Them thanh cong!" << endl;
        nhom->add(node);
    }
}
void TdeleGiaoVien(int ma,Tree *tree)
{
    // in ra lỗi nếu chưa có trường hoặc khoa hoặc nhóm nào
    vector<Node *> truong = tree->getRoot()->getChildren();
        int c =0;
        for (int i = 0; i < truong.size(); i++)
        {
            vector<Node *> khoa = truong[i]->getChildren();
            for (int j = 0; j < khoa.size(); j++)
            {
                vector<Node *> nhom = khoa[j]->getChildren();
                for (int k = 0; k < nhom.size(); k++)
                {
                    vector<Node *> gv = nhom[k]->getChildren();
                    for (int l = 0; l < gv.size(); l++)
                    {
                        if (gv[l]->getma() == ma)
                        {
                            string name = "";
                            int ma = 0;
                            int numPub = 0;
                            Node *node = new Node(4, name, numPub, ma);
                           *gv[l]=*node;
                           c=1;
                           cout<<"Da xoa Giang vien ma la "<<ma<<endl;
                        }
                        
                    }
                }
            }
        }
        if(c == 0)  cout<<"Khong tim thay GV : "<<ma<<endl;
}
/*void TimGVien(Tree *tree)
{   string name;
    cout << "Nhap Ten Giang Vien can tim: " << endl;
    cin>>name;
    for(int i = 0;i<tree->getRoot()->getChildren().size();i++){
        Node *truong = tree->getRoot()->getChildren()[i];
        for(int j = 0;j < truong->getChildren().size();j++){
            Node *khoa = truong->getChildren()[j];
            for(int k = 0;k < khoa->getChildren().size();k++){
                Node *nhom = khoa->getChildren()[k];
                for(int t = 0;t < nhom->getChildren().size();t++){
                    Node *gv = nhom->getChildren()[t];
                    string name2 = gv->getName;
                    if(name2==name){
                        truong->print;
                        khoa->print;
                        nhom->print;
                        gv->print;
                    }
                    else cout<<"Khong co Giang Vien";
                }
            }
        }
    }
}*/
void printMenu()
{
    cout << "-------------------------------------------------------" << endl;
    cout << "MENU" << endl;
    cout << "1. Khoa co nhieu nhom chuyen mon nhat" << endl;
    cout << "2. Nhom co nhieu GV nhat" << endl;
    cout << "3. GV co so luong xuat ban cao nhat" << endl;
    cout << "4. In thoong tin GV" << endl;
    cout << "5. Tim Giang Vien bang ten" << endl;
    cout << "6. Luu" << endl;
    cout << "7. Thoat" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Nhap lenh: ";
}
void printMenuPDT()
{
    cout << "-------------------------------------------------------" << endl;
    cout << "MENU" << endl;
    cout << "1. Them truong con" << endl;
    cout << "2. Them khoa" << endl;
    cout << "3. Them nhom chuyen mon" << endl;
    cout << "4. Them giang vien" << endl;
    cout << "5. Khoa co nhieu nhom chuyen mon nhat" << endl;
    cout << "6. Nhom co nhieu GV nhat" << endl;
    cout << "7. GV co so luong xuat ban cao nhat" << endl;
    cout << "8. Tim Giang Vien bang ten" << endl;
    cout << "9. Xoa Giang vien bang ma" << endl;
    cout << "10. In thoong tin GV" << endl;
    cout << "11. Luu" << endl;
    cout << "12. Thoat" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Nhap lenh: ";
}


void writeFile(Tree *tree)
{
    // write file data.txt
    ofstream file("data.txt", ofstream::out);
    for (int i = 0; i < tree->getRoot()->getChildren().size(); i++)
    {
        Node *truong = tree->getRoot()->getChildren()[i];
        file << truong->getId() << endl;
        file << truong->getName() << endl;
        for (int j = 0; j < truong->getChildren().size(); j++)
        {
            Node *khoa = truong->getChildren()[j];
            file << khoa->getId() << endl;
            file << khoa->getName() << endl;
            for (int k = 0; k < khoa->getChildren().size(); k++)
            {
                Node *nhom = khoa->getChildren()[k];
                file << nhom->getId() << endl;
                file << nhom->getName() << endl;
                for (int l = 0; l < nhom->getChildren().size(); l++)
                {
                    Node *gv = nhom->getChildren()[l];
                    file << gv->getId() << endl;
                    file << gv->getNumPub() << endl;
                    file << gv->getName() << endl;
                    file << gv->getma()<<endl;
                }
            }
        }
    }
    cout << "Write file success!" << endl;
    file.close();
}
void readFile(Tree *tree)
{
    // read file data.txt
    ifstream file("data.txt", ifstream::in);
    int id;
    int numpub;
    string name;
    int ma;
    while (file >> id)
    {
        if (id == 1)
        {
            file.ignore();
            getline(file, name);
            Node *node = new Node(1, name);
            tree->getRoot()->add(node);
        }
        else if (id == 2)
        {
            file.ignore();
            getline(file, name);
            Node *node = new Node(2, name);
            Node *truong = tree->getRoot()->getChildren().back();
            truong->add(node);
        }
        else if (id == 3)
        {
            file.ignore();
            getline(file, name);
            Node *node = new Node(3, name);
            Node *truong = tree->getRoot()->getChildren().back();
            Node *khoa = truong->getChildren().back();
            khoa->add(node);
        }
        else if (id == 4)
        {
            
            file >> numpub;
            file.ignore();
            getline(file, name);
            file >> ma;
            Node *node = new Node(4, name, numpub, ma);
            Node *truong = tree->getRoot()->getChildren().back();
            Node *khoa = truong->getChildren().back();
            Node *nhom = khoa->getChildren().back();
            nhom->add(node);
        }
        else  {
            readFile(tree);
            writeFile(tree);
            
            };
    }
    cout << "Read file success!" << endl;
    file.close();
}

void mainMenuPDT(Tree *tree, int cmd)
{
    switch (cmd)
    {
    case 1:
    {
        ThemTruongCon(tree);
        break;
    }
    case 2:
    {
        ThemKhoa(tree);
        break;
    }
    case 3:
    {
        ThemNhomChuyenMon(tree);
        break;
    }
    case 4:
        ThemGiaoVien(tree);
        break;
    case 5:
    {
        cout << "Khoa co nhieu nhom chuyen mon nhat: " << tree->findKhoaMaxNhom() << endl;
        break;
    }
    case 6:
    {
        cout << "Nhom co nhieu GV nhat: " << tree->findNhomMaxGV() << endl;
        break;
    }
    case 7:
    {
        tree->findGVMaxPub();
        break;
    }
    case 8:
    {
        string ten;
        cout<<"Ten : ";
        cin.ignore();
        getline(cin, ten);
        tree->findnameGV(ten);
        break;
    }
    case 9 : 
    {
        int ma;
        cout<<"Nhap ma GV can xoa :";
        cin>>ma;
        TdeleGiaoVien(ma,tree);
        break;
    }
    case 10:
    {
        tree->print();
        break;
    }
    case 11:
    {
        writeFile(tree);
        break;
    }
    }
}
void mainMenu(Tree *tree, int cmd)
{
    switch (cmd)
    {
    case 1:
    {
        cout << "Khoa co nhieu nhom chuyen mon nhat: " << tree->findKhoaMaxNhom() << endl;
        break;
    }
    case 2:
    {
        cout << "Nhom co nhieu GV nhat: " << tree->findNhomMaxGV() << endl;
        break;
    }
    case 3:
    {
        tree->findGVMaxPub();
        break;
    }
    
    case 4:
    {
        tree->print();
        break;
    }
    case 5:
    {
        string ten;
        cout<<"Ten : ";
        cin.ignore();
        getline(cin, ten);
        tree->findnameGV(ten);
        break;
    }
    
    case 6:
    {
        writeFile(tree);
        break;
    }
    }
}
void userInterPDT()
{
    Tree tree;
    int cmd;
    readFile(&tree);
    while (true)
    {
    printMenuPDT();
        cin >> cmd;
        if (cmd < 1 || cmd > 13)
        {
            cout << "Nhap lenh khong hop le!" << endl;
            continue;
        }
        if (cmd == 12)
        {
            cout << "Tam biet!" << endl;
            break;
        }
        mainMenuPDT(&tree, cmd);
    }
}
void userInterGV()
{
    Tree tree;
    int cmd;
    readFile(&tree);
    while (true)
    {
    printMenu();
        cin >> cmd;
        if (cmd < 1 || cmd > 8)
        {
            cout << "Nhap lenh khong hop le!" << endl;
            continue;
        }
        if (cmd == 7)
        {
            cout << "Tam biet!" << endl;
            break;
        }
        mainMenu(&tree, cmd);
    }
}

int main()
{   
    int choice;
    int per = 0;
    string username,password;
    int permission;
    do {
        loadUsers(); // Tải thông tin người dùng từ file
        cout << "1. Dang ky\n";
        cout << "2. Dang nhap\n";
        cout << "3. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
            
                
               /* cout << "Nhap ten dang nhap: ";
                cin >> username;
                cout << "Nhap mat khau: ";
                cin >> password;
                cout << "Giang vien : 1, PDT : 2 "<<endl;
                cin>>permission;
                registerUser(username,password,permission);*/
                fflush(stdin);
                registerUser();
                break;
            
            case 2:{
                int a;
                a = loginUser();
                if(a==1){
                     userInterGV();
                     break;
                }
                else if(a==2){
                    userInterPDT();
                    break;
                    }
                 a = 0;
                break;}
               
            case 3:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (choice != 3);
        
    return 0;
}