//Xây dựng chương trình quản lí sinh viên bằng cấu trúc dữ liệu danh sách liên kết(DSLK)

#include<iostream>
using namespace std;

struct Student {
    string hoTen;
    int tuoi;
    int MSSV;
};

struct DanhSachLienKet{
    Student data;
    DanhSachLienKet *next;
};

typedef struct DanhSachLienKet *sv;

//tao 1 node
sv TaoNode(Student data){
    sv sv1 = new DanhSachLienKet;
    sv1->data = data;
    sv1->next = NULL;
    return sv1;
}

bool SizeNode(sv &head){
    return head == NULL;
}
//Them 1 node
void themData(sv &head, Student data){
    sv node = TaoNode(data);
    if(SizeNode(head)){
        head =node;
    }
    else{
        sv tmp = head;
        tmp ->next = node;

    }
}

//Xoa 1 node
void deleteNode(sv &head, Student data, int pos){
    sv tmp = head;
    if(SizeNode(head)){
        return;
    }
    if(head->data.MSSV == data.MSSV){
        sv tmp = head;
        head = head -> next;
        delete tmp;
    }
    for(int i = 1; i < pos - 1; i++){
        tmp = tmp -> next;
    }
    sv del = tmp -> next;
    tmp -> next = del -> next;
    delete del;
}

void in(sv &head){
    sv tmp = head;
    while(tmp != NULL){
        cout << tmp->data.hoTen << " " << tmp->data.tuoi << " " << tmp->data.MSSV << endl;
        tmp = tmp->next;
    }
}


int main(){
    int pos;
    cin >> pos;
    sv head = NULL;

    Student sv1;
    sv1.hoTen = "Nguyen Van A";
    sv1.tuoi = 20;
    sv1.MSSV = 123;

    Student sv2;
    sv2.hoTen = "Nguyen Van B";
    sv2.tuoi = 21;
    sv2.MSSV = 124;

    Student sv3;
    sv3.hoTen = "Nguyen Van C";
    sv3.tuoi = 22;
    sv3.MSSV = 125;


    themData(head, sv1);
    themData(head, sv2);
    themData(head, sv3);
    in(head);
    deleteNode(head, sv2,pos);

}