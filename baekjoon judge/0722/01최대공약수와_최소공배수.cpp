#include<stdio.h>


int gcd(int a, int b){

	int temp=b;
	while (b){
		temp = (a%b);
		a = b;
		b = temp;
	}
	return a;
}
int main(){

	int a, b;
	scanf("%d%d", &a, &b);

	int g = gcd(a, b);
	printf("%d\n%d",g,a*b/g);
	return 0;
}