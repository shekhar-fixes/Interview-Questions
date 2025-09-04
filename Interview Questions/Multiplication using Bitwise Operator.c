#include<stdio.h>
int add(int a, int b){
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int multiply(int a, int b){
    int result=0;
    while(b>0){
        if(b&1)result= add(result, a);
        a=a<<1;
        b=b>>1;
    }
    return result;
}
int main(){
    printf("Enter numbers:\n");
    int a, b;
    scanf("%d %d",&a,&b);

    printf("\n");
    printf("%d",multiply(a,b));
    return 0;
}
