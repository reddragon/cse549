#include<iostream>
#include<cstring>
using namespace std;

#define MAX 200
int dp[MAX][MAX][2], n;
int pizza_area[MAX];

#define MOD(x,y) ((x)>=(y)?(x)%(y):((x)<0?(x)+(n):(x)))

int solve(int i, int j, int alices_turn)
{
	int &ref = dp[i][j][alices_turn];
	if(ref != -1) return ref;
	
	if(i == 0 && j == n-1) return ref = 0;
	
	ref = 0;
	int left = MOD(i-1,n);
	if(left != j)
		ref = (alices_turn ? pizza_area[left] : 0) + solve(left,j,!alices_turn);
	
	int right = MOD(j+1,n);
	if(right != i)
		ref = max(ref, (alices_turn ? pizza_area[right] : 0) + solve(i,right,!alices_turn));
	return ref;
}

int solution()
{
	memset(dp, -1, sizeof(dp));
	pizza_area[0] = 1; pizza_area[1] = 2; pizza_area[2] = 1;
	pizza_area[3] = 1; pizza_area[4] = 2; pizza_area[5] = 1;
	pizza_area[6] = 1; pizza_area[7] = 2; pizza_area[8] = 1;
	n = 9;
	
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, pizza_area[i]+solve(i,i,0));	
	return ans;
}

int main()
{
	cout << solution() << endl;
}
