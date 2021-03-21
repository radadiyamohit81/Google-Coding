#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

void solve(int test){
	cout << "Case #" << test << ": ";
	int r,c; cin >> r >> c;
	vector<vector<int>> v(r,vector<int>(c));
	
	vector<vector<int>> left(r,vector<int>(c));
	vector<vector<int>> right(r,vector<int>(c));
	vector<vector<int>> up(r,vector<int>(c));
	vector<vector<int>> down(r,vector<int>(c));
	
	rep(i,0,r){
		rep(j,0,c){
			cin >> v[i][j];
		}
	}
	
	rep(i,0,r){
		rep(j,0,c){
			left[i][j] = v[i][j];
			if(j && v[i][j]){
				left[i][j] += left[i][j - 1];
			}
		}
	}
	rep(j,0,c){
		rep(i,0,r){
			up[i][j] = v[i][j];
			if(i && v[i][j]){
				up[i][j] += up[i - 1][j];
			}
		}
	}
	
	rep(i,0,r){
		for(int j = c - 1; j >= 0; j--){
			right[i][j] = v[i][j];
			if(j < c - 1 && v[i][j]){
				right[i][j] += right[i][j + 1];
			}
		}
	}
	
	rep(j,0,c){
		for(int i = r - 1; i >= 0; i--){
			down[i][j] = v[i][j];
			if(i < r - 1 && v[i][j]){
				down[i][j] += down[i + 1][j];
			}
		}
	}
	
	int ans = 0;
	rep(i,0,r){
		rep(j,0,c){
			// ur
			if(up[i][j] > 1){
				if(right[i][j] > 2)
				ans += min(up[i][j],right[i][j]/2)-1;
				if(left[i][j] > 2)
				ans += min(up[i][j],left[i][j]/2)-1;
			}
			if(down[i][j] > 1){
				if(right[i][j] > 2)
				ans += min(down[i][j],right[i][j]/2)-1;
				if(left[i][j] > 2)
				ans += min(down[i][j],left[i][j]/2)-1;
			}
			if(left[i][j] > 1){
				if(up[i][j] > 2)
				ans += min(left[i][j],up[i][j]/2)-1;
				if(down[i][j] > 2)
				ans += min(left[i][j],down[i][j]/2)-1;
			}
			if(right[i][j] > 1){
				if(up[i][j] > 2)
				ans += min(right[i][j],up[i][j]/2)-1;
				if(down[i][j] > 2)
				ans += min(right[i][j],down[i][j]/2)-1;
			}
		}
	}
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	rep(i,1,t+1) solve(i);
	return 0;
}
