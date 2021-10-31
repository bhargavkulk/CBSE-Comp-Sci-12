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
#define startToEnd( zst )   zst.start()  ,  zst.end()
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

int gcd(int frst, int scnd)
{
	if (scnd == 0)
		return frst;
	return gcd(scnd, frst % scnd);
}

struct EnterStructName{
	ll EnterFirstElementName;
};

bool compareStruct(EnterStructName i1, EnterStructName i2)
{
    return (i1.EnterFirstElementName < i2.EnterFirstElementName);
}

bool customCompare(ll frst,ll scnd)
{
    return (frst < scnd);
}

long long npowerofm(ll base,ll powerr, ll modd=1000000007)
{
	if(powerr==0)
		return 1;
	ll tempp=(npowerofm(base,powerr/2,modd))%modd;
	return ( ( (tempp*tempp)%modd )*( (powerr%2)?base:1) )%modd;
}

int numOfFactors(ll n)
{
	int count=0;
	for (long long i=1; i*i<=n; i++){
		if(n%i==0){
			count+=(i*i==n)?1:2;
		}
	}
	return count;
}


ll p[1]={};
//Putting it here vs putting it inside main
//Find number of factor works weirdly with square roots
//memset
//Try to do functional programming

int main()
{
	string b,c;
	cin >> b>>c ;
	int n=b.size();
	// char *a=&(b[0]);
	// cout << a[1] << "\n" ;
	vector<int> a[26];
	for (long long i=0; i<n; i++){
		a[b[i]-'a'].push_back(i);
	}
	int current=0;
	int count=1;
	for(auto i : c){
		int x=i-'a';
		if(a[x].empty())
		{
			goto endd;
		}
		int temp=lower_bound(a[x].begin(),a[x].end(),current)-a[x].begin();
		if(temp==a[x].size())
		{
			// cout << i << "\n" ;
			count++;
			current=a[x][0]+1;
		}
		else{
			current=a[x][temp]+1;
		}
	}
	cout << count << "\n" ;
	if(0){
		endd:
		cout << -1 << "\n" ;
	}
}




struct Node{
	Node* child[26]={};
	// vector<Node *> leaves;
};



// int withoutCutting()
// {
// 	Node root=*new Node();
// 	string s="abcabcacb",b="abcb";
// 	cin >> s>>b ;
// 	int n=s.size();
// 	Node* leaves[n]={};
// 	for (long long i=0; i<n; i++){
// 		int x=s[i]-'a';
// 		if(root.child[x]==NULL){
// 			leaves[i]=new Node();
// 			(root.child[x])=leaves[i];
// 		}
// 		else{
// 			leaves[i]=root.child[x];
// 		}
// 		for (long long j=0; j<i; j++){
// 			if(leaves[j]->child[x]==NULL){
// 				Node* temp=new Node();
// 				leaves[j]->child[x]=temp;
// 				leaves[j]=temp;
// 			}
// 			else{
// 				leaves[j]=leaves[j]->child[x];
// 			}
// 		}
// 	}
// 	int count=0;
// 	n=b.size();
// 	for (long long i=0; i<n; count++){
// 		int x=b[i]-'a';
// 		if(root.child[x]==NULL){
// 			goto endd;
// 		}
// 		else{
// 			Node temp=root;
// 			while(i<n&&temp.child[x]!=NULL)
// 			{
// 				temp=*(temp.child[x]);
// 				i++;
// 				x=b[i]-'a';
// 			}
// 		}
// 	}
	
// 	cout << count << "\n" ;
// 	if(0)
// 	{	
// 		endd:
// 		cout << -1 << "\n" ;
// 	}
// }
