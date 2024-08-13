#include<iostream>
using namespace std;

struct ThongTinSach{
    string maSach;
    string tenSach;
    string tacGia;
    string theLoai;
    string nhaXuatBan;
    int namXuatBan;
};

struct DanhSachLienKet{
    ThongTinSach data;
    DanhSachLienKet *next;
};

typedef struct DanhSachLienKet *DSLK;

//tao node
DSLK TaoNode(ThongTinSach data){
    DSLK node = new DanhSachLienKet;
    node->data = data;
    node->next = NULL;
    return node;
}

//Size
bool SizeNode(DSLK &head){
    return head == NULL;
}

//Them sach
void themSach(DSLK &head, ThongTinSach data){
    DSLK node = TaoNode(data);
    if(SizeNode(head)){
        head = node;
    }else{
        DSLK tmp = head;
        tmp -> next = node;
    }
    cout << "Them sach thanh cong" << endl;
}

//Xoa sach
void xoaSach(DSLK &head, ThongTinSach data, int pos){
    DSLK tmp = head;
    if(SizeNode(head)){
        return;
    }
    if(head->data.tenSach == data.tenSach || head -> data.maSach == data.maSach){
        DSLK tmp = head;
        head = head -> next;
        delete tmp;
    }
    for(int i = 1; i < pos - 1; i++){
        tmp = tmp -> next;
    }
    DSLK del = tmp -> next;
    tmp -> next = del -> next;
    delete del;
}


//Tim sach
void timSach(DSLK &head, ThongTinSach data){
    DSLK tmp = head;
    if(SizeNode(head)){
        return;
    }
    if(head->data.maSach == data.maSach || head->data.tenSach == data.tenSach){
        cout << "Ma sach: " << head->data.maSach << endl;
        cout << "Ten sach: " << head->data.tenSach << endl;
        cout << "Tac gia: " << head->data.tacGia << endl;
        cout << "The loai: " << head->data.theLoai << endl;
        cout << "Nha xuat ban: " << head->data.nhaXuatBan << endl;
        cout << "Nam xuat ban: " << head->data.namXuatBan << endl;
    }
}

//In danh sach
void in(DSLK &head){
    DSLK tmp = head;
    while(tmp != NULL){
        cout << "Ma sach: " << tmp->data.maSach << endl;
        cout << "Ten sach: " << tmp->data.tenSach << endl;
        cout << "Tac gia: " << tmp->data.tacGia << endl;
        cout << "The loai: " << tmp->data.theLoai << endl;
        cout << "Nha xuat ban: " << tmp->data.nhaXuatBan << endl;
        cout << "Nam xuat ban: " << tmp->data.namXuatBan << endl;
        tmp = tmp->next;
    }
}

int main() {
    int choice;
    cout << "1. Nhap danh sach sach" << endl;
    cout << "2. Tim sach" << endl;
    cout << "3. Xoa sach" << endl;
    cout << "Chon chuc nang: ";
    while(choice <1 || choice > 3){
        cin >> choice;
    }
    cin >> choice;
    DSLK head = NULL;

    if (choice == 1) {
        while (true) {
            ThongTinSach data;
            cout << "Nhap ma sach (nhap 'q' de thoat): ";
            cin >> data.maSach;
            if (data.maSach == "q") {
                break;
            }
            cin.ignore();
            cout << "Nhap ten sach: ";
            getline(cin, data.tenSach);
            cout << "Nhap tac gia: ";
            getline(cin, data.tacGia);
            cout << "Nhap the loai: ";
            getline(cin, data.theLoai);
            cout << "Nhap nha xuat ban: ";
            getline(cin, data.nhaXuatBan);
            cout << "Nhap nam xuat ban: ";
            cin >> data.namXuatBan;
            cin.ignore();

            themSach(head, data);
        }
    }

    if(choice == 2){
        ThongTinSach data;
        cout << "Nhap ma sach can tim: ";
        cin >> data.maSach;
        timSach(head, data);
    }

    if(choice == 3){
        ThongTinSach data;
        cout << "Nhap ma sach can xoa: ";
        cin >> data.maSach;
        xoaSach(head, data, 1);
    }

    // In danh sách sách sau khi nhập
    cout << "Danh sach sach:" << endl;
    in(head);

    return 0;
}