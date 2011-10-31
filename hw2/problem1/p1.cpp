#include<string>
#include<iostream>
#include<vector>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<malloc.h>
#include<cstring>
#define MAXN 510000
#define PMAXN 1100
using namespace std;
vector<string> needles;
string haystack;
int powr[MAXN];
int primes[10*PMAXN + 10];
vector<int> pr;
vector<int> getprimes(int limit)
{
	memset(primes, 0, sizeof primes);
	int i, j, k;
	for(i = 2; i < limit; i++)
	{
		if(primes[i] == 1)
			continue;
		for(j = i + i; j < limit; j += i)
		{
			primes[j] = 1;
		}
	}
	vector<int> ret;
	int prcnt = 0;
	for(i = 2; i < limit; i++)
	{
		if(primes[i] == 0)
		{
			prcnt++;
			if(i < 100 || i > limit - 100 || prcnt%10==0)
			{
				ret.push_back(i);
			}
		}
	}

	return ret;
}
bool rabin_karp(string &hay, string &needle, int prime)
{
	int i, j, k;
	int hash = 0;
	int nhash = 0;
	//cout<<hay<<" "<<needle<<endl;
	for(i = 0; i < needle.size(); i++)
	{
		nhash *= powr[1];
		nhash += (needle[i] - 'a' + 1);
		nhash %= prime;
	}
	for(i = 0; i < hay.size(); i++)
	{
		//cout<< i <<" "<<hash<<" "<<nhash<<" "<<endl;
		if(i - (int)needle.size() >= 0)
		{
			hash -= (((hay[i - needle.size()] - 'a' + 1)*powr[(int)needle.size() - 1])%prime);
			//cout<< "In : " << i <<" "<<hash<<" "<<nhash<<" "<<endl;
			if(hash < 0)
				hash += prime;
		}
		hash *= powr[1];
		hash += (hay[i] - 'a' + 1);
		hash %= prime;
		//cout<<"Do "<< i <<" "<<hash<<" "<<nhash<<" "<<endl;
		if(hash == nhash && i - (int)needle.size() + 1 >= 0)
		{
			//cout<<"Entered " << i <<" "<<hash<<" "<<nhash<<" "<<endl;
			if(hay.substr(i - (int)needle.size() + 1, needle.size()) == needle)
				return 1;
		}
	}
	//cout<<"out"<<endl;
	return 0;
}
void solve(int base, int prime)
{
	int i, j, k;
	powr[0] = 1;
	for(i = 1; i < MAXN; i++)
	{
		powr[i] = powr[i-1] * base;
		powr[i] %= prime;
	}
	for(i = 0; i < needles.size(); i++)
	{
		assert(rabin_karp(haystack, needles[i], prime) == 1);
		//cout<<needles[i]<<" done"<<endl;
	}
}
int main()
{
	pr = getprimes(2*PMAXN);
	int cnt = 0;
	while(cin >> haystack)
	{
		cnt++;
		int n, i;
		needles.clear();
		cin >> n;
		while(n--)
		{
			string s;
			cin >> s;
			needles.push_back(s);
		}
		for(i = 0; i < pr.size(); i++)
		{
			time_t st, en;
			time(&st);
			solve(26, pr[i]);
			time(&en);
			printf("Time taken for set numbered %d and prime %d : %g\n", cnt, pr[i], difftime(en, st));
		}
		printf("\n");
	}
	return 0;
}
