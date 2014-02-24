#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[505][505],tb[505][505],adp[505][505];
int n,m,init,ans,pans;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(tb,0,sizeof(tb));
		memset(adp,0,sizeof(adp));
		scanf("%d%d%d",&n,&m,&init);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			scanf("%d",&tb[i][j]);
		ans=-1;
		int s,b,a;
		for(int i=1;i<=m;i++){
			dp[1][i]=-1*tb[1][i]+init;
			if(dp[1][i]>=100)adp[1][i]=100;
			else if(dp[1][i]<=0)adp[1][i]=0;
			else adp[1][i]=dp[1][i];
//			printf("%d ",dp[1][i]);
		}
//		printf("\n");
		for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(adp[i-1][j-1] && adp[i-1][j+1]){
				dp[i][j]=max(-1*tb[i][j]+adp[i-1][j-1],-1*tb[i][j]+adp[i-1][j+1]);
				if(dp[i][j]>=100)adp[i][j]=100;
				else if(dp[i][j]<=0)adp[i][j]=0;
				else adp[i][j]=dp[i][j];
			}	
			else if(adp[i-1][j-1]){
				dp[i][j]=-1*tb[i][j]+adp[i-1][j-1];
				if(dp[i][j]>=100)adp[i][j]=100;
				else if(dp[i][j]<=0)adp[i][j]=0;
				else adp[i][j]=dp[i][j];	
			}	
			else if(adp[i-1][j+1]){
				dp[i][j]=-1*tb[i][j]+adp[i-1][j+1];
				if(dp[i][j]>=100)adp[i][j]=100;
				else if(dp[i][j]<=0)adp[i][j]=0;
				else adp[i][j]=dp[i][j];
			}	
			else
				adp[i][j]=0,dp[i][j]=-1;
				
//			printf("%d ",dp[i][j]);
		}
//		printf("\n");
		}
		if(0)for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++)printf("%d ",adp[i][j]);
			printf("\n");
		}	
		for(int i=1;i<=m;i++){
			if(adp[n][i]>0)
				ans=max(ans,adp[n][i]);
			else if(dp[n][i]==0)
				ans=max(ans,adp[n][i]);
		}	
		printf("%d\n",ans);
	}
}
