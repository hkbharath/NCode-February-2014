#include<cstdio>
#include<cstdlib>

int main(){
	int t=3;
	printf("%d\n",t);
	int x=rand()%7643;
	while(x--)rand();
	while(t--){
		int n=1+rand()%500,m=1+rand()%500,rc=rand()%100;
		printf("%d %d %d\n",n,m,rc);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				printf("%d ",-40+rand()%131);
			printf("\n");
		}	
	}
}
