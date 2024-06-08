#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include <algorithm>
using namespace std;
class Tree
{
    Node *root;

public:
    Tree()
    {
        root = new Node(0, "DHBK Ha Noi");
    }
    void add(Node *node)
    {
        root->add(node);
    }
    Node *getRoot()
    {
        return root;
    }
    
    Node *findTruong(string Truong)
    {
        vector<Node *> node = root->getChildren();
        for (int i = 0; i < node.size(); i++)
        {
            if (node[i]->getName() == Truong)
            {
                return node[i];
            }
        }
        return NULL;
    }
    Node *findKhoa(string Khoa, Node *Truong)
    {
        vector<Node *> node = Truong->getChildren();
        for (int i = 0; i < node.size(); i++)
        {
            if (node[i]->getName() == Khoa)
            {
                return node[i];
            }
        }
        return NULL;
    }
    Node *findNhom(string Nhom, Node *Khoa)
    {
        vector<Node *> node = Khoa->getChildren();
        for (int i = 0; i < node.size(); i++)
        {
            if (node[i]->getName() == Nhom)
            {
                return node[i];
            }
        }
        return NULL;
    }
    Node *findGV(string GV, Node *nhom, int ma)
    {
        vector<Node *> node = nhom->getChildren();
        for (int i = 0; i < node.size(); i++)
        {
            if (node[i]->getName() == GV && node[i]->getma() == ma)
            {
                return node[i];
            }
        }
        return NULL;
    }
   
    // print
    void print()
    {
        root->print();
        vector<Node *> truongs = root->getChildren();
        for (int i = 0; i < truongs.size(); i++)
        {
            cout << "Truong: " << truongs[i]->getName() << endl;
            vector<Node *> khoas = truongs[i]->getChildren();
            for (int j = 0; j < khoas.size(); j++)
            {
                cout << "\tKhoa: " << khoas[j]->getName() << endl;
                vector<Node *> nhoms = khoas[j]->getChildren();
                for (int k = 0; k < nhoms.size(); k++)
                {
                    cout << "\t\tNhom: " << nhoms[k]->getName() << endl;
                    vector<Node *> gvs = nhoms[k]->getChildren();
                    for (int l = 0; l < gvs.size(); l++)
                    {
                        if(gvs[l]->getName() == ""){}
                        else{
                        cout << "\t\t\tGiang Vien: " << gvs[l]->getName() << endl;
                        cout << "\t\t\tMa so Giang Vien : " << gvs[l]->getma() << endl;
                        cout << "\t\t\t\tSo bai bao: " << gvs[l]->getNumPub() << endl;
                        }
                    }
                }
            }
        }
    }
    // tìm khoa có nhiều nhóm chuyên môn nhất
    string findKhoaMaxNhom()
    {
        vector<Node *> truong = root->getChildren();
        int max = 0;
        string name;
        for (int i = 0; i < truong.size(); i++)
        {
            vector<Node *> khoa = truong[i]->getChildren();
            for (int j = 0; j < khoa.size(); j++)
            {
                if (khoa[j]->getChildren().size() > max)
                {
                    max = khoa[j]->getChildren().size();
                    name = khoa[j]->getName();
                }
            }
        }
        if (max == 0)
            return "Khong co khoa nao";
        return name;
    }
    // Tìm nhóm chuyên môn có đông GV nhất
    string findNhomMaxGV()
    {
        vector<Node *> truong = root->getChildren();
        int max = 0;
        string name;
        for (int i = 0; i < truong.size(); i++)
        {
            vector<Node *> khoa = truong[i]->getChildren();
            for (int j = 0; j < khoa.size(); j++)
            {
                vector<Node *> nhom = khoa[j]->getChildren();
                for (int k = 0; k < nhom.size(); k++)
                {
                    if (nhom[k]->getChildren().size() > max)
                    {
                        max = nhom[k]->getChildren().size();
                        name = nhom[k]->getName();
                    }
                }
            }
        }
        if (max == 0)
            return "Khong co nhom nao";
        return name;
    }
    // in ra giáo viên có số bài báo cao nhất
    void findGVMaxPub()
    {
        vector<Node *> truong = root->getChildren();
        int max = 0;
        string name;
        string truong1;
        string khoa1;
        string nhom1;
        int ma;
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
                        if (gv[l]->getNumPub() > max)
                        {
                            max = gv[l]->getNumPub();
                            name = gv[l]->getName();
                            truong1 = truong[i]->getName();
                            khoa1 = khoa[j]->getName();
                            nhom1 = nhom[k]->getName();
                            ma = gv[l]->getma();
                        }
                    }
                }
            }
        }
        
        if (max != 0)
        {
            cout << "Giang vien co so bai bao cao nhieu nhat la: " << endl;
            cout<<"Truong : "<< truong1<<endl;
            cout<<"\tKhoa : "<<khoa1<<endl;
            cout<<"\t\tNhom : "<<nhom1<<endl;
            cout<<"\t\t\tGiang Vien : "<<name<<endl;
            cout<<"\t\t\tMa so Giang Vien : "<<ma<<endl;
            cout<<"\t\t\tSo bai bao : "<<max<<endl;
        }
        else
        {
            cout << "Khong co giang vien nao bao cao bai bao" << endl;
        }
    }
    void findnameGV(string name1)
    {
        vector<Node *> truong = root->getChildren();
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
                        
                        if (gv[l]->getName() == name1)
                        {
                            cout<<"Truong : "<< truong[i]->getName()<<endl;
                            cout<<"\tKhoa : "<<khoa[j]->getName()<<endl;
                            cout<<"\t\tNhom : "<<nhom[k]->getName()<<endl;
                            cout<<"\t\t\tGiang Vien : "<<gv[l]->getName()<<endl;
                            cout<<"\t\t\tMa so Giang Vien : "<<gv[l]->getma()<<endl;
                            cout<<"\t\t\tSo bai bao : "<<gv[l]->getNumPub()<<endl;
                            c =1;
                        }
                    }
                }
            }
        }
        if(c == 0) cout<<"khong co GV"<<endl;
    }
    
    void dele_gv(int ma,Tree *tree)
    {
        vector<Node *> truong = root->getChildren();
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
                            delete gv[l];
                            //gv[l]=NULL;
                           // writeFile1(tree);
                            gv.erase(gv.begin()+l);
                            cout<<"Xoa thanh cong"<<endl;
                            c=1;
                        }
                        
                    }
                }
            }
        }
        if(c == 0)  cout<<"Khong tim thay GV : "<<ma<<endl;
    }
    void writeFile1(Tree *tree)
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
    void printTruong()
    {
        vector<Node *> truongs = root->getChildren();
        for (int i = 0; i < truongs.size(); i++)
        {
            cout << i + 1 << ": " << truongs[i]->getName() << endl;
        }
    }
    void printKhoa(Node *truong)
    {
        vector<Node *> khoas = truong->getChildren();
        for (int i = 0; i < khoas.size(); i++)
        {
            cout << "Khoa:\n";
            cout << "\t" << i + 1 << ": " << khoas[i]->getName() << endl;
        }
    }
    void printNhom(Node *khoa)
    {
        vector<Node *> nhoms = khoa->getChildren();
        for (int i = 0; i < nhoms.size(); i++)
        {
            cout << "Nhom:\n";
            cout << "\t" << i + 1 << ": " << nhoms[i]->getName() << endl;
        }
    }
   
};
#endif