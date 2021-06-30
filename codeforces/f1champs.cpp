#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int t,n,ans[1010],v,u,cnt1,p[10]={25,18,15,12,10,8,6,4,2,1};
string s[60],str;
vector<vector<int> > cnt(1010,vector<int>(60));
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			if(!mp.count(str))
			{
				mp[str]=v;
				s[v]=str;
				v++;
			}
			u=mp[str];
			if(i<10)ans[u]+=p[i];
			cnt[u][i]++;
		}				
	}
	cnt1=0;
	for(int i=0;i<v;i++)
	{
		if(ans[i]>ans[cnt1]||(ans[i]==ans[cnt1]&&cnt[i]>cnt[cnt1]))
		{
			cnt1=i;
		}
	}
	cout<<s[cnt1]<<endl;
	cnt1=0;
	for(int i=0;i<v;i++)
	{
		if(cnt[i][0]>cnt[cnt1][0]||cnt[cnt1][0]==cnt[i][0]&&(ans[cnt1]<ans[i]||ans[cnt1]==ans[i]&&cnt[i]>cnt[cnt1]))
		{
			cnt1=i;
		}
	}
	cout<<s[cnt1]<<endl;
	return 0;
}
