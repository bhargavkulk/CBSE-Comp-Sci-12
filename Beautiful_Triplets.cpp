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
using namespace std;

typedef long long ll;

int main()
{
	ll n,d;
	cin>>n>>d;
	int a[20000]={};
	for (long long i=0; i<n; i++){
		int temp;
		cin >> temp ;
		a[temp]++;
	}
	ll ans=0;
	for (long long i=0; i<20000-2*d; i++){
		ans+=a[i]*a[i+d]*a[i+d+d];
	}
	cout << ans << "\n" ; 
}
