#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
int a[maxn],b[maxn],dp[maxn][maxn];
signed main(){
	int n,init=0,maxx=0;
	cin>>n;
	for(int i=1;i*i<=n*n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i],init+=b[i]*a[i];
	for(int l=n;l>=1;l--){
		for(int r=l+1;r<=n;r++){
			dp[l][r]=dp[l+1][r-1]-a[l]*b[l]-a[r]*b[r]+a[l]*b[r]+a[r]*b[l];
			maxx=max(maxx,dp[l][r]);}
	}
	cout<<init+maxx;
}
