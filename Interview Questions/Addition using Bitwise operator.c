#include<stdio.h>
int add(int a, int b){
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int main(){
    printf("Enter numbers:\n");
    int a, b;
    scanf("%d %d",&a,&b);

    printf("\n");
    printf("Result of addition is: %d",add(a,b));
    return 0;
}