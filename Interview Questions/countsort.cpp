#include<iostream>
using namespace std;
void countsort(int arr[], int n){
    int output[n];
    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[(arr[i]) % 10]++;
    }
    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        output[--count[(arr[i]) % 10]] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}
int main(){
    int arr[]={5,8,2,6,8,9,2,1,0,6,4,3,7,5,4,3,2,1,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    countsort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}