#include<iostream>
#include<cstring>
using namespace std;

int dp[200][200];
string a, b;
#define INF 10000

int solve(int i, int j)
{
	int &ref = dp[i][j];
	if(ref != -1)
		return ref;
		
	if(i == a.size()) return ref = b.size()-j;
	if(j == b.size()) return ref = a.size()-i;
	
	ref = INF;
	if(a[i] == b[j])
		ref = min(ref, 1 + solve(i+1,j+1));
	
	ref = min(ref, 1 + solve(i,j+1));
	ref = min(ref, 1 + solve(i+1,j));
	return ref;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	a = "abcd"; b = "ram";
	cout << solve(0,0) << endl;
}
