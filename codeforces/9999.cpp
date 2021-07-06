#include<iostream>

using namespace std;

int main()  {
    unsigned long long n, m, sum = 0, p_sum;
    cin >> n >> m;
    unsigned long long n1 = n;
    int i=0, x;
    unsigned long long dig;
    while(sum <= m && n>0) {
        x = n%10;
        n/=10;
        x = x-9;
        if(x < 0)   {
            n--;
            x = 10+x;
        }
        dig = x;
        for(int j=0;j<i;j++)    {
            dig*=10;
        }
        p_sum = sum;
        sum = sum+dig;
        i++;
    }
    cout << n1 - p_sum;
}
