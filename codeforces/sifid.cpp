#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; 
	cin>>t; 
	while(t-->0){
		int n; 
		cin>>n; 
		int a[n]; 
		for(int i=0;i<n;i++) 
		cin>>a[i];
		int x=n-1; 
		sort(a,a+n);
		for(int i=0;i<x;i++){
			if(a[i+1]-a[i] < a[x]){
				x--; i--;
			}
		}
		cout << x+1 << endl;
	}
}
