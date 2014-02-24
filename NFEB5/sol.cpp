#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

char s[501];
vector<int> pos;
int maxPal[501][501];
int t;

void backtrack(int i,int j){
	if(i==j)return;
	if(s[i]==s[j-1]){
		if(i==j-1){
			pos.push_back(i);
			return;
		}	
		else{
			pos.push_back(i);
			pos.push_back(j-1);
			backtrack(i+1,j-1);
		}	
	}
	else if(maxPal[i+1][j]>maxPal[i][j-1])
		backtrack(i+1,j);
	else
		backtrack(i,j-1);	
}

int main(){
	
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int n = strlen(s);
		pos.clear();
		memset(maxPal, 0, sizeof(maxPal));
		for (int start = 0; start < n; start++)
			maxPal[start][start + 1] = 1;

		for (int len = 2; len <= n; len++) {
			for (int start = 0; start + len <= n; start++) {
				int end = start + len;
				if (s[start] == s[end - 1])
					maxPal[start][end] = maxPal[start + 1][end - 1] + 2; 
				else
					maxPal[start][end] = max(maxPal[start + 1][end], maxPal[start][end - 1]);
					//printf("%d ",maxPal[start][end]);
			}
			//printf("\n");
		}	
		//printf("%d\n",maxPal[0][n]);
		if(0)for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)printf("%d ",maxPal[i][j]);
			printf("\n");
		}	
		backtrack(0,n);
		int x=pos.size();
		int dholu=0,gopu=0;
		if(x!=maxPal[0][n])printf("Error\n");
		
		for(int i=0;i<x;i++){
			if(pos[i]%2)dholu++;
			else gopu++;
			printf("%d\n",pos[i]);
		}
		if(gopu>dholu)printf("Gopu\n");
		else if(dholu>gopu)printf("Dholu\n");
		else printf("Draw\n");		
	}
}
