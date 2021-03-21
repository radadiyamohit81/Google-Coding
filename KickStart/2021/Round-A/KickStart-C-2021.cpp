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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve(int test){
	cout << "Case #" << test << ": ";
	int r,c;
	cin >> r >> c;
	vector<vector<int>> h(r,vector<int>(c));
	
	set<pair<int, pii>> s;
	
	rep(i,0,r){
		rep(j,0,c){
			cin >> h[i][j];
			s.insert({-h[i][j],{i,j}});
		}
	}
	
	int ans = 0;
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(s.begin());
		int height = -cur.fr;
		int x = cur.sc.fr, y = cur.sc.sc;
		
		rep(i,0,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx == r || ny < 0 || ny == c){
				continue;
			}
			if(h[nx][ny] >= height - 1){
				continue;
			}
			int diff = height - 1 - h[nx][ny];
			ans += diff;
			s.erase({-h[nx][ny],{nx,ny}});
			h[nx][ny] = height - 1;
			s.insert({-h[nx][ny],{nx,ny}});
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
