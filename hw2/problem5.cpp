#include<iostream>
#include<cstring>
using namespace std;

string s;
int dp[200][200];

#define INF 10000
int solve(int i, int j)
{
	int &ref = dp[i][j];
	if(ref != -1) 
		return ref;
	if(i > j) 
		return ref = 0;
	ref = INF;
	if(s[i] == s[j])
		ref = min(ref, solve(i+1,j-1));
	ref = min(ref, 1+solve(i,j-1));
	ref = min(ref, 1+solve(i+1,j));
	return ref;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	s = "cabba";
	cout<<solve(0,s.size()-1);
}
