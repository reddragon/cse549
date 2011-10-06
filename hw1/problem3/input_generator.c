#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<assert.h>
#include<string.h>

// This takes in a string of length n, and generates
// m fragments of length l each.

void get_fragments()
{
	// Read the actual string, and the parameters, m & l
	//freopen("actual_string.in", "r", stdin);
	
	int n, m, l, i, t, j;
	scanf("%d %d %d", &n, &m, &l);
	
	// Allocate memory for the big string
	char * str = (char *)(malloc(n + 10));
	// Die, if we can't
	assert(str != NULL);	
	
	scanf("%s", str);	
	
	// Check if the input is sane
	assert(n == (int)strlen(str) && n >= l);
		
	// Write the fragments to the file. This input would be used to test
	//freopen("fragments.in", "w", stdout);
	
	// Writing the number of fragments and fragment length to the file
	printf("%d %d\n", m, l);
	
	// Setting up the randomizer
	srand(time(0));
	
	// Now generate m fragments of length l each
	for(i = 0; i < m; i++) {
		// Find the starting point of the fragment of length l
		// Starting points can be any point between 0 & n - l
		t = rand() % (n - l + 1);
		
		// Writing the actual string
		for(j = t; j < t + l; j++) {
			printf("%c", str[j]);
		}
		printf("\n");
	}
	
	free(str);
}


void generate_random_string()
{
	freopen("random_string.in", "w", stdout);
	
	int m = 1024,i;
	
	srand(time(0));
	
	for(i = 0; i < m; i++) {
		printf("%c",'A'+rand() % (26));
	}
	printf("\n");
}


int main() 
{
	generate_string();
}
