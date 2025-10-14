#include<bits/stdc++.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    struct stat st; fstat(0, &st);
	char *p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    char w[1 << 16], *q = w, t[10], *o = t;
	auto R = [&]() {
		int ret = 0; char c = *p++, flag = 0;
        if (c == '-') c = *p++, flag = 1;
		for (; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return flag ? -ret : ret;
	};

    int n = R();
    vector<int> v(n); rep(i,0,n) v[i] = R();

    int idx = 0;
    rep(i,0,n){
        while(idx<n && v[i]==v[idx]) idx++;
        cout<<(idx<n ? idx+1 : -1)<<' ';
    }

}
