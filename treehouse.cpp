#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector> 
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <iomanip>
#include <ios>

using namespace std;

typedef long long ll;

#define endl (char(10))
#define zspace << " " <<
#define areEqual( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()
#define isAscending( frst , scnd , thrd ) ( ( frst <= scnd ) && ( scnd <= thrd ) )
#define startToEnd( zst )   zst.begin()  ,  zst.end()
#define yess cout << "YES" << endl ;
#define noo cout << "NO" << endl ;
#define pos cout << "POSSIBLE" << endl ;
#define impos cout << "IMPOSSIBLE" << endl ;
#define yesno( zst ) if( zst ) cout << "YES" << endl ; else cout << "NO" << endl ;
#define posimpos( zst ) if( zst ) cout << "POSSIBLE" << endl ; else cout << "IMPOSSIBLE" << endl ;
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd)

ll mod= (1000000007);
ll cache[1]={};
ll global=0;

//Try to do functional programming
unsigned long long add(vector<unsigned long long> &a){
	unsigned long long summ=0;
	unsigned long long n=a.size();
	sort(a.begin(),a.end());
	for (size_t i=0; i<n; i++){
		summ=(summ+(n-i)*a[i]);
	}
	return summ;
}

unsigned long long solve(vector<unsigned long long> *a, int x, int p){
	int m=a[x].size();
	if(m==0)
		return 1;
	vector<unsigned long long> temp(m,0);
	for (long long i=0; i<m; i++){
		if(a[x][i]==p)
		{
			continue;
		}
		temp[i]=solve(a,a[x][i],x);
	}
	return 1+add(temp);
}

void correctt(vector<unsigned long long> *a, int x/* , int *p */)
{
	int n=a[x].size();
	if(n==0)
		return;
	for (long long i=0; i<n; i++){
		int child=a[x][i];
		ll j;
		int m=a[child].size();
		for (j=0; j<m; j++){
			if(a[child][j]==x)
			{
				a[child].erase(a[child].begin()+j);
				break;
			}
		}
		correctt(a,child);
	}
}


int main()
{
    unsigned long long t;	cin>>t;
	while(t--){
		unsigned long long n;
		cin >> n ;
		unsigned long long x;
		cin>>x;
		
		vector<unsigned long long> a[n+1];
		// int p[n+1]={};
		
		for(unsigned long long i=0;i<n-1;i++){
			unsigned long long x,y;
			cin >> x>>y ;
			// if(x<y)
			a[x].push_back(y);
			// else
			a[y].push_back(x);
		}
		// correctt(a,1);
		// for(auto& i : p){
		// 	cout << i << endl ;
		// }
		// cout  << endl ;
		cout << ((solve(a,1,-1)%mod)*(x%mod))%mod << endl ;
	}
}
