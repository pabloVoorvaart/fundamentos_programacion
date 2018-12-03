#include <stdio.h>
#include <stdlib.h>
int mcd(int a, int b);

int main()
{
    printf("%d", mcd(25, 10));
    return 0;
}

int mcd(int a, int b){

    if(a == b){
        return(a);
    }
    if(a>b){
        a = a-b;
        return mcd(a,b);
    }
    if(b>a){
        b = b-a;
        return mcd(a,b);
    }
}

