#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void maxheapify(int arr[], int n, int i){
    int largest = i;
    int l = i * 2;
    int r = i * 2 + 1;
    if(l <= n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r <= n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    for(int i = n/2; i > 0; i--){
        maxheapify(arr, n, i);
    }
    for(int i = n; i > 1; i--){
        swap(arr[1], arr[i]);
        maxheapify(arr, i-1, 1); 
    }
}
int main(){
    int arr[]={-1,38,27,43,3,9,82,10};
    int n= sizeof(arr)/sizeof(arr[0])-1;
    heapsort(arr, n);
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}