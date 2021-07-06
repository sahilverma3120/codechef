#include<iostream>

using namespace std;

int main()  {
    long long n;
    cin >> n;
    long long a[n];
    long long x = 0;
    for(long long i=0;i<n;i++)    {
        cin >> a[i];
    }
    for(long long i=0;i<n;i++)	{
    	x = x^a[i];
    	for(long long j=1;j<=i;j++)
    	    x = x^((i+1)%j);
    	if((n-i)%2 != 0 && (n-i)>=0)
    	    x = x^i;
	}
        cout << x;
    return 0;
}
