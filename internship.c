// C++ program for Dynamic
// Programming implementation

#include<bits/stdc++.h>
using namespace std;
#define N 3
#include <bits/stdc++.h>
using namespace std;
// Function to find if number is prime
int checkPrime(int num){
    if (num <= 1)
      { return 0; }
   // Check from 2 to half of arr[i]
   for (int j = 2; j <= num/2; j++){
      if (num % j == 0){
         return 0;
      }
      return 1;
   }
}

// Function for finding maximum sum
int maxPathSum(int tri[][N], int m, int n)
{
	// loop for bottom-up calculation
	for (int i=m-1; i>=0; i--)
	{
		for (int j=0; j<=i; j++)
		{
			// for each element, check both
			// elements just below the number
			// and below right to the number
			// add the maximum of them to it
			if (tri[i+1][j] > tri[i+1][j+1])
				tri[i][j] += tri[i+1][j];
			else
				tri[i][j] += tri[i+1][j+1];
		}
	}

	// return the top element
	// which stores the maximum sum
	return tri[0][0];
}

/* Driver program to test above functions */
int main()
{
int tri[N][N] = { {4, 0, 0},
					{4, 10, 0},
					{1, 6, 3} };
					
int m = N;
int n = N;
int isprime=0;

for (int i=m-1; i>=0; i--)
	{
		for (int j=0; j<=i; j++)
		{
			isprime=checkPrime(tri[i][j]);
            if(isprime==1){
            tri[i][j] =0; 
            }
		}
	}				

cout << maxPathSum(tri, 2, 2);
return 0;
}
