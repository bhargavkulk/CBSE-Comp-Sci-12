#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
  ll t;
	cin>>t;
	while(t--)
	{
		long long l,r;
		cin >> r>>l ;
		int num=(l-r);
		while(l!=0)
		{
			l/=10;
			r/=10;
			num+=(l-r);
		}
		cout << num << "\n" ;
	}
}
