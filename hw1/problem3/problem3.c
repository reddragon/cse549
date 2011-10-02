#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<assert.h>
#include<string.h>

#define	MAX_M		100 // Defines the maximum number of fragments.
#define MAX(a,b)	(a>b?a:b)

int overlap_matrix[MAX_M][MAX_M];
char * str[MAX_M];

void read_frags()
{
	
}

int longest_overlap(char * a, char * b) 
{
	//TODO Naive algorithm. Replace by suffix trees or whatever.
	// We check b for an overlap with a.
	int best_overlap = 0, overlap, i;
	for(overlap = 1; overlap <= strlen(b); overlap++) {
		int works = 1;
		for(i = 0; i < overlap; i++) {
			if(b[i] != a[strlen(a)-overlap + i])
				{ works = 0; break; }
		}
		if(works) 
			best_overlap = MAX(best_overlap, overlap);
	}
	return best_overlap;
}

void construct_overlap_graph() 
{
	
}

void test_sanity() {
	assert(longest_overlap("abcdef", "efgha") == 2);
	assert(longest_overlap("abcdef", "abcdef") == 6);
	assert(longest_overlap("abcdef", "zzzzzzzzzz") == 0);
}

int main()
{
	test_sanity();
	return 0;
}
