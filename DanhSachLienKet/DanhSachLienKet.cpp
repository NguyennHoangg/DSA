#include<iostream>
using namespace std;

struct DanhSachLienKet
{
    int data;
    DanhSachLienKet *next;
};

typedef DanhSachLienKet *DSLK;

DSLK TaoNode(int data)
{
    DSLK node = new DanhSachLienKet;
    node->data = data;
    node->next = NULL;
    return node;
}

bool KiemTraRong(DSLK &head)
{
    return head == NULL;
}

int Size(DSLK &head){
    int count = 0;
    DSLK temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

//Them node vao danh sach lien ket
void themNode(DSLK &head, int data){
    DSLK node = TaoNode(data);
    if(KiemTraRong(head)){
        head = node;
    }else{
        DSLK temp = head;
        temp->next = node;
    }
}

//Them node vao cuoi danh sach lien ket
void themNodeCuoi(DSLK &head, int data){
    DSLK node = TaoNode(data);
    if(head == NULL){
        head = node;
    }else{
        DSLK temp = head;
        while(temp -> next != NULL){
            temp -> next = temp;
        }
    }
}

//Thêm 1 node vào giữa DSLK
void themNode(DSLK &head, int data, int pos){
    if(pos <= 0 || pos > Size(head)){
        cout << "Vi tri them khong hop le" << endl;
        return;
    }
    if(pos == 1){
        DSLK node = TaoNode(data);
        node->next = head;
        head = node;
    }
    if(pos == Size(head)){
        themNodeCuoi(head, data);
    }
    else{
        DSLK tmp = head;
        for(int i = 1; i < pos - 1; i++){
            tmp = tmp->next;
        }
        DSLK node = TaoNode(data);
        node->next = tmp->next;
        node->next = tmp;
    }
}

//Xoa node dau tien
void xoaNodeDauTien(DSLK &head){
    if(KiemTraRong(head)){
        return;
    }
    DSLK temp = head;
    head = head->next;
    delete temp;
}

//Xoa node cuoi cung
void xoaNodeCuoi(DSLK &head){
    if(KiemTraRong(head)){
        return;
    }
    if(head->next == NULL){
        xoaNodeDauTien(head);
        return;
    }
    DSLK temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

//Xoa node o vi tri bat ki
void xoaNode(DSLK &head, int pos){
    if(pos <= 0 || pos > Size(head)){
        cout << "Vi tri xoa khong hop le" << endl;
        return;
    }
    if(pos == 1){
        xoaNodeDauTien(head);
    }
    if(pos == Size(head)){
        xoaNodeCuoi(head);
    }
    else{
        DSLK tmp = head;
        for(int i = 1; i < pos - 1; i++){
            tmp = tmp->next;
        }
        DSLK del = tmp->next;
        tmp->next = del->next;
        delete del;
    }
}

