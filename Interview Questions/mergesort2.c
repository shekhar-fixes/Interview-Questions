#include<stdio.h>
void merge(int arr1[], int arr2[], int m, int n, int b[]){
    int i=0;
    int j=0;
    int k=0;
    while(i<=m && j<=n){
        if(arr1[i]<arr2[j]){
            b[k++]=arr1[i++];
        }
        else{
            b[k++]=arr2[j++];
        }
    }
    while(i<=m){
        b[k++]=arr1[i++];
    }
    while(j<=n){
        b[k++]=arr2[j++];
    }
}
void mergesort(int arr[], int n){
    if(n<2){
        return;
    }
    int mid=n/2;
    int left[mid];
    int right[n- mid];
    for(int i=0; i<mid; i++){
        left[i]=arr[i];
    }
    for(int j=mid; j<n; j++){
        right[j-mid]=arr[j];
    }
    mergesort(left, mid);
    mergesort(right, n-mid);
    merge(left, right, mid-1, n-mid-1, arr);
}
int main(){
    int arr[]={38,27,43,3,9,82,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}