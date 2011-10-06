#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

string overlap(string &a, string &b)
{
	int i, j;
	string ret = a + b;
	for(i = 0; i < a.size(); i++)
	{
		for(j = 0; j < a.size() - i; j++)
		{
			if(j >= b.size())
				break;
			if(a[j + i] != b[j])
				break;
		}
		if(j == a.size() - i)
		{
			string t = a + b.substr(j, b.size() - j + 1);
			if(ret.size() > t.size())
				ret = t;
		}
	}
	return ret;
}

string overlap_2(string &a, string &b)
{
	if(a.find(b) != string::npos)
		return a;
	if(b.find(a) != string::npos)
		return b;
	string a1 = overlap(a, b);
	string a2 = overlap(b, a);
	if(a1.size() < a2.size())
	{
		return a1;
	}
	else
	{
		return a2;
	}
}
string get_superstring(vector<string> v)
{
	int i, j, k;
	while(v.size() > 1)
	{
		int x = 0, y = 1;
		int overlap_val = 0;
		for(i = 1; i < v.size(); i++)
		{
			for(j = 0; j < i; j++)
			{
				string t = overlap_2(v[i], v[j]);
				if(overlap_val < v[i].size() + v[j].size() - t.size())
				{
					x = i;
					y = j;
					overlap_val = v[i].size() + v[j].size() - t.size();
				}
			}
		}
		vector<string> tx;
		//cout<<"Chosen strings : " << v[x] << " " << v[y] << " " << overlap_2(v[x], v[y]) << endl;
		for(i = 0; i < v.size(); i++)
		{
			if(i == x || i == y)
				continue;
			tx.push_back(v[i]);
		}
		tx.push_back(overlap_2(v[x], v[y]));
		v = tx;
	}
	return v[0];
}
void solve(vector<string> &v)
{
	string sup = get_superstring(v);
	cout << sup << endl;
}
int main()
{
	int n, m;
	cin >> n >> m;
	getchar();
	int i, j, k;
	char *c = new char[m + 3];
	vector<string> v;
	for(i = 0; i < n; i++)
	{
		cin.getline(c, m + 3);
		string t(c);
		v.push_back(t);
	}
	solve(v);
	return 0;
}

