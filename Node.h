#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
    int id; // id 1 = truong, id 2 = khoa, id 3 = nhom, id 4 = giao vien
    string name;
    int numPub; //
    int ma;
    vector<Node *> children;

public:
    Node(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    
    Node(int id, string name, int numPub, int ma)
    {
        this->id = id;
        this->name = name;
        this->numPub = numPub;
        this->ma = ma;
    }
    void add(Node *node)
    {
        children.push_back(node);
    }
    void print()
    {
        cout << name << endl;
    }
    int getId()
    {
        return id;
    }
    int getNumPub()
    {
        return numPub;
    }
    int getma()
    {
        return ma;
    }
    string getName()
    {
        return name;
    }
    vector<Node *> getChildren()
    {
        return children;
    }
};
#endif