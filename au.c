#define max(a) a

#include<stdio.h>

int main(){
    int k = 8;
    int m = 7;
    int z = k < m ? k++ : m++;

    printf("%d", z);

}   