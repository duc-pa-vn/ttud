#include <bits/stdc++.h>
using namespace std;

typedef struct book{
    char *id;
    char *name;
    int pages;
} book;

typedef struct node{
    struct book data;
    struct node *next;
} Node;
Node *head = NULL;

void nhapsach(){
    Node *newNode = new Node;
    cout << "nhap du lieu: ";
    cin >> newNode->data.id >> newNode->data.name >> newNode->data.pages;
        newNode->next = head;
        head = newNode;
};

int main(){
    int n;
    cout << "menu" << endl;
    cout << "Nhap sach moi an 1" << endl;
    cout << "xoa sach mong nhan 2" << endl;
    cout << "doi ten sach nhan 3" << endl;
    cout << "nhap 0 de thoat" << endl;
    cin >> n;
    while(n != 0){
        if(n == 1){
            Node *newNode = new Node;
            char *newid, *newname;
            int newpages;
            cout << "nhap du lieu: ";
            cin >> newid >> newname >> newpages;
            newNode->data.id = newid;
            newNode->data.name = newname;
            newNode->data.pages = newpages;
            newNode->next = head;
            head = newNode;
        //case 2:
            //xoasach();
        //case 3:;
            //doiten();
        }
        cout << "menu" << endl;
        cout << "Nhap sach moi an 1" << endl;
        cout << "xoa sach mong nhan 2" << endl;
        cout << "doi ten sach nhan 3" << endl;
        cout << "nhap 0 de thoat" << endl;
        cin >> n;
    }
    return 0;
}
