#include<cstdio>
#include<cstdlib>

int main(){
	int t=3,tol='a'-'A';
	printf("%d\n",t);
	while(t--){
		int n=3+(3955+rand())%500,k=3*((rand()+6635)%100),s;
		printf("%d %d\n",n,k);
		for(int i=0;i<n;i++){
			char c[51];
			s=5+(7754+rand())%40;
			int x=2+(8862+rand())%(s/2);
			for(int j=1;j<=s;j++)
				c[j-1] = j%x?'A'+(6332+rand())%26:' ';
			c[s]='\0';
			printf("%s\n%d\n",c,k/3);	
		}
	}
}		
