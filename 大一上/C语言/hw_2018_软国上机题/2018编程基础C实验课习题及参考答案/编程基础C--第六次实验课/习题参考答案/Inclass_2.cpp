#include<stdio.h>
printnChars(int n, char t){
	int i=0;
	for(i=0;i<n;i++){
		printf("%c",t);
	}
}
int main(){
	printnChars(5, 'a');
	return 0;
}
