#include <stdlib.h>
#include <stdio.h>

int Fibonacci(int n1);

int main(){
    int x;
    for(x=0;x<=10;x++){
        printf("%d\n",Fibonacci(x));
    }

return 0;
}

int Fibonacci(int n1){
    if(n1==0){
        return 0;
    }else{
        return n1+Fibonacci(n1-1);
    }
}


