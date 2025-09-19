#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start < end) {
        while(arr[start] <= pivot && start < ub) start++;
        while(arr[end] > pivot) end--;
        if(start < end) {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

void QuickSort(int arr[], int lb, int ub){
    if(lb < ub) {
        int loc = partition(arr, lb, ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
    }
}

int main(){
    int arr[7] = {10, 5, 80, 2, 95, 7, 20};
    QuickSort(arr, 0, 6);
    for(int i = 0; i < 7; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}