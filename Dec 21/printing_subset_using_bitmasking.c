#include<stdio.h>
#include<string.h>

void print(char *s,int i){
	int j=0;
	while(i){
		if(i&1){
			printf("%c",s[j]);
		}
		j++;
		i>>=1;
	}
	printf("\n");
}

int main(int argc, char const *argv[]){
	char str[100];
	scanf("%s",&str);
	int len = strlen(str);
	len = 1<<len;
	for(int i=0;i<len;++i){
		print(str,i);
	}
	return 0;
}

// Sample Input :

// abcd

// Sample Output :


// a
// b
// ab
// c
// ac
// bc
// abc
// d
// ad
// bd
// abd
// cd
// acd
// bcd
// abcd