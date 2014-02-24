#include<stdio.h>
#include<cstdlib>

int main(){
	int t=10;
	printf("%d\n",t);
	while(t--){
		int n=1+(552+rand())%99999,ms=rand()%100,mr=rand()%10000;
		printf("%d %d %d\n",n,ms,mr);
		for(int i=0;i<n;i++){
			printf("%d %d\n",(55373+rand())%100,(63543+rand())%10000);
		}
		printf("%d\n",1+(66453+rand())%n);
	}
}
