#include<stdio.h>
int add(int a, int b) {   //Define add function
    while (b != 0) {
        int carry = a & b;   
        a = a ^ b;           
        b = carry << 1;     
    }
    return a;
}
int subtract(int a, int b){
    return add(a,add(~b,1));  //Two's compliment
}
int main(){
    printf("%d",subtract(10,5)); //Substracting 5 from 10
    return 0;
}