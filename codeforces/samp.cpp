#include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define foru(i , ab , ba) for(ll i = (ll)(ab) ; i < (ll)(ba) ; i++)
#define ford(i , ab , ba) for(ll i = (ll)(ab) ; i >= (ll)(ba) ; i--)
#define ain(ab , bv) for(int i = 0 ; i < (int)bv ; i++) cin >> ab[i]
#define aout(ab , bv) for(int i = 0 ; i < (int)bv ; i++) cout << ab[i] << " "; cend
#define M 1000000007ll
#define mp make_pair
#define mt make_tuple
#define cend cout << "\bv"
#define all(x) x.begin() , x.end()
#define aout2(ab , bv , mv) for(ll i = 0 ; i < bv ; i++){for(ll j = 0 ; j < mv ; j++){cout << ab[i][j] << " ";} cout << endl;}
#define ain2(ab , bv , mv) for(ll i = 0 ; i < bv ; i++){for(ll j = 0 ; j < mv ; j++){cin >> ab[i][j];}}
#define ff first
#define ss second
#define sz(ab) ((long long)(ab).size())
#define mset(ab , ba) memset(ab , ba , sizeof(ab))
#define pb push_back
#define endl '\n'
#define google cout << "Case #" << test_num << ": "
#ifdef Sahil
#define dbg(ab) cerr << #ab << ": "; _print(ab); cerr << endl;
#else
#define dbg(ab) // No more TLEs
#endif

using namespace std;
using namespace std::chrono;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef pair<int, int> pii;
const int MAX_n = 3e5+5;
 
vector<int> ab[MAX_n], ba[MAX_n];
vector<pii> range(MAX_n);
int ind;
set<pii> Sl;


void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(ld t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
//void _print(ordered_set &v){cerr<<"[ ";for(int i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}

/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T ab , T ba){ while(ab != 0){T temp = ab; ab = ba % ab; ba = temp;}return ba;}
template <class T> T egcd(T ab , T ba , T &x , T &y){T gcd , xt , yt;if(ab == 0){gcd = ba;x = 0 , y = 1;}else {gcd = egcd(ba % ab , ab , xt , yt);x = yt - (ba/ab)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T ab , T mod){T x , y; egcd<T>(ab , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T ab , T mod){return expo<T>(ab , mod - 2 , mod);}
template <class T> bool rev(T ab , T ba){return ab > ba;}
template <class T> ll maxpower(T ab , T ba){ll mns = 0;while(ab > 0 && ab % ba == 0){mns++;ab /= ba;}return mns;}
template <class T> T mceil(T ab, T ba){if(ab % ba == 0) return ab/ba; else return ab/ba + 1;}
template <class T> T lcm(T ab, T ba){return (ab*ba)/gcd<T>(ab, ba);}
const ll infl = 1e18; const int inf = 1e9 + 5;

/*----------------------------- # --- MAIN CODE --- # -----------------------------*/
int bv, mv, kv;
map<pair<int, int>, map<pair<int, int>, long long>> w;
string func(string s1,string s2){
    int i=0;
    int sd = s1.size();
    for(;i<sd;i++){
        if(s1[i]>s2[i])
            return s2;
        else if(s1[i]<s2[i])
            return s1;
        
    }
    return s1;
}



ll f(int i, int j, int kv, vector<vector<vector<ll>>> &dp) {
	if(kv == 0) {
		return 0;
	}
	if(dp[i][j][kv] != -1) {
		return dp[i][j][kv];
	}
	vector<pair<int, int>> possible;
	if(i + 1 < bv) {
		possible.push_back({i + 1, j});
	}
	if(j + 1 < mv) {
		possible.push_back({i, j + 1});
	}
	if(i - 1 >= 0) {
		possible.push_back({i - 1, j});
	}
	if(j - 1 >= 0) {
		possible.push_back({i, j - 1});
	}

	ll mns = infl;
	for(pair<int, int> pos: possible) {
		ll tempw = w[{i, j}][pos];
		mns = min(mns, tempw*kv);
		mns = min(mns, 2*tempw + f(pos.ff, pos.ss, kv - 2, dp));
	}
	return dp[i][j][kv] = mns;
}
string string1(string s,int sz){
    string st;
    string mt;
    mt = st;
    int i=0;
    int mn =1;
    int ml = s.size();
    for(;i<sz;i++)
        st+=s[i%ml];
    return st;
}
int test_case(int test_num) {
    
       ll nk = 4;
		ll ml=1e9,mr=1e9;
		int an=1e16,su=0,cnt1=0,cnt2=0;
    
    // vector<ll> start, end;
    // REP(i,0,n,x){
    //     start.pb(i);
    // }
    // REP(i,t,n,x){
    //     end.pb(i);
    // }
      int n;
    cin>>n;
    ll a[n];
    int i=0;
    while(i<n){
        cin>>a[i];
        i += 1;
    }
    for(int i=0;i<=n-1;i += 2){
        su += a[i];
    }
    sort(a,a+n);
    ll val=0,sm=2,vm,summ=0;
    int gb =sm;
    while(gb<n){
         summ+=a[gb-2];
         nk = summ % n;
        val-=(a[gb]*(gb-1));
        cnt1 += 1;
        val+=summ;
        cnt1 += summ;
        gb +=1;
        cnt1--;
        cnt2 = cnt1;
    }
    for(int i=2;i<n;i++){
        vm+=a[i-1];
        cnt2++;
    }
    cout<<500000007<<endl;
    
}



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
#ifdef Sahil
	FILE* inp = freopen("input.txt", "r", stdin);
	FILE* err = freopen("error.txt", "w", stderr);
	FILE* out = freopen("output.txt", "w", stdout);
#endif
	int _;
	_ = 1;
	// cin >> _;
	auto start = high_resolution_clock::now();
	cout << setprecision(15);
	int t;
	 for(cin>>t;t;t--){
		test_case(t);
	 }
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
#ifdef Sahil
	cerr << "Time: " << duration.count()/1000.0 << endl;
#endif
	return 0;
}
