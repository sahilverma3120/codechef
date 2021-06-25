#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

int32_t main(){
 	int n,m;
 	cin >> n >> m;
 	vector<int> v(m+1,-1);
 	v[0] = 0;
 	for(int i=0;i<n;i++) {
 		int t,x,y,z;
 		cin>>t>>x>>y;
 		z = x/100000;
 		for(int j=0;j<=m;j++) {
 			if(v[j] == -1 || v[j]==i+1) continue;
 			int k = j,l = 0;
 			while(l < y) {
 				if(t == 1) k = k+z+(x%100000?1:0);
 				else k = k*x/100000+(k*x%100000?1:0);
 				if(k > m || v[k] != -1) break;
 				v[k] = i+1;
 				l++;
 			}
 		}
 	}
 	for(int i=1;i<=m;i++) cout<<v[i]<<' ';
}
