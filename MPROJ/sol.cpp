#include<cstdio>
#include<cstdlib>


int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int ms,mr,cnt=0,n,s,r;
		scanf("%d%d%d",&n,&ms,&mr);
		while(n--){
			scanf("%d%d",&s,&r);
			if(s>ms || r>mr)cnt++;
		}
		int ac;
		scanf("%d",&ac);
		int c=gcd(ac,cnt);
		printf("%d/%d\n",cnt/c,ac/c);
	}
}
