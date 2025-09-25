#include<iostream>
using namespace std;
int getmax(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n, int exp){
    int output[n];
    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[(arr[i]/exp) % 10]++;
    }
    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        output[--count[(arr[i]/exp) % 10]] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}
void radixsort(int arr[], int n){
    int max= getmax(arr, n);
    for(int exp=1; max/exp>0; exp *=10){
        countsort(arr, n, exp);
    }
}
int main(){
    int arr[]={170,45,75,90,802,24,2,66};
    int n= sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}