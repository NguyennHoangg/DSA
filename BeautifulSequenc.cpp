#include<iostream>
#include<vector>
using namespace std;

    
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        arr[i] = rand();
    }

    for(auto i : arr){
        cout << i << " ";
    }

} 

//Quick sort
#include<iostream>  
#include<vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}