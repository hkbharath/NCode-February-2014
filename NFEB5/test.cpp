#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define clr(f,z) memset(f,z,sizeof(f))
using namespace std;
const int mm=1005;
char s[mm],rs[mm];
class Node
{
	public:
		int len;string s;
		bool operator<(const Node&x)const
		{
			if(len!=x.len)return len<x.len;
			return s>x.s;
		}
}dp[mm][mm];
void LCS(int len)
{
	FOR(i,0,len)
	{
		dp[i][0].len=0;dp[i][0].s.clear();
		dp[0][i].len=0;dp[0][i].s.clear();
	}
	FOR(i,1,len)FOR(j,1,len)
	{
		if(s[i]==rs[j])//lcs
		{
			dp[i][j].len=dp[i-1][j-1].len+1;
			dp[i][j].s=dp[i-1][j-1].s+s[i];
		}
		else
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
}
string revrse(string s)
{
	string tmp="";
	for(int i=s.length()-1;i>=0;--i)
		tmp+=s[i];
	return tmp;
}
string getans(int len)
{
	Node ans;
	ans.s.clear();ans.len=0;
	FOR(i,1,len-1)
	{
		ans=max(ans,dp[i][len-i]);
	}
	ans.len+=ans.len;
	ans.s+=revrse(ans.s);
	Node tmp;
	FOR(i,1,len)
	{ tmp.len=2*dp[i-1][len-i].len+1;
		tmp.s=dp[i-1][len-i].s+s[i]+revrse(dp[i-1][len-i].s);
		ans=max(ans,tmp);
	}
	return ans.s;
}
int main()
{
	int t;
	cin>>t;
	string st;
	while(cin>>s+1)
	{
		if(t==0)
			break;
		t--;
		int len=strlen(s+1);
		FOR(i,1,len)rs[i]=s[len-i+1];
		LCS(len);
		string st=getans(len);
		int x=st.size();
		int p=0;
		int q=0;
		int a1=0;
		int a2=0;
		string f=s+1;
		while(p<x)
		{
			if(st[p]==f[q])
			{
				if(q%2==0)
					a1+=1;
				else
					a2+=1;
				printf("%d %d\n",p,q);
				p+=1;
				q+=1;
			}
			else
			{
				q+=1;
			}
		}
		if(a1>a2)
		{
			cout<<"Gopu"<<endl;
		}	
		else if(a1<a2)
		{
			cout<<"Dholu"<<endl;
		}	
		else
		{
			cout<<"Draw"<<endl;
		}
		if(t==0)
			break;
	}
	return 0;
}
