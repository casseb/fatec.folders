#include <stdio.h>

void fibonacci(int n){
	int i;
	for(i=0;i<n;i++){
		printf("%i ",fibonacciInt(i));
	}
}

int fibonacciInt(int n){
	if(n==0 || n==1){
		return 1;
	}else{
		return fibonacciInt(n-1)+fibonacciInt(n-2);
	}
}

int main(){
	fibonacci(5);
	return 0;
}
