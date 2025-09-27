#include<iostream>
int collatzConjecture(int n){
    int count =0;
    while(n!=1){
        if(n%2==0){
            n=n/2;
            count++;
        }
        else{
            n=3 * n +1;
            count++;
        }
    }
    return count;
}

int main() {
    int n=83; //arbitrary number
    int CC= collatzConjecture(n);
    printf("%d", CC);

    return 0;
}