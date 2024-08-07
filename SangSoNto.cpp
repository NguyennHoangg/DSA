#include<iostream>
#include<math.h>
using namespace std;

const int maxn = 1000000 + 5;
int prime[maxn];
void isPrime(int n){
    //Tạo 1 mảng lưu toàn bộ giá trị
    for(int i = 2; i <= n; i++){
        //Cho tất cả các giá trị <n đều là số nguyên tố
        prime[i] = true;
    }
        //Loại 0, 1 vì 0, 1 không phải là số nguyên tố
        prime[0] = prime[1] = false;
        for(int i = 2; i <= sqrt(n); i++){
            if(prime[i]){
            //duyệt tất cả các bội số của i và cho nó không phải là số nguyên tố
            for(int j = i * i; j <= n; j += i){
               prime[j] = false;
            }
        }
    }
    }
    
int main(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        if(prime){
            cout << i << " ";
        }
    }
    system("pause");
    return 0;
}