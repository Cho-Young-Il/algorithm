
#include<stdio.h>



int strLen(char* str){
	int len = 0;
	while (*str++){
		len++;
	}
	return len;
}

int main(){
	char str[1001000];
	int len = 0;
	int minLen;

	scanf("%s", str);
	len = strLen(str);

	for (int i = 1; str[i]!='\0'; i++){
		if (len%i != 0) continue;
		if (str[0] == str[i]){
			bool check = true;
			for (int j = 0; j < i; j++){
				if (str[j] != str[i + j]){
					check = false;
					break;
				}
			}
			if (check){1
				printf("%d\n", len/i);
				return 0;
			}
		}
	}
	printf("1\n");

}