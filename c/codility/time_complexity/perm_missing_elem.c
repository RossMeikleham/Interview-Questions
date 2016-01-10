/*
A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(int A[], int N);

that, given a zero-indexed array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Assume that:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>




/* sort signed ints > 0 */
static void radix_sort(int *from, int *to, int bit)
{
    if (!bit || to < from + 1) return;
 
    int *ll = from, *rr = to - 1;
    while (1) {
        /* find left most with bit, and right most without bit, swap */
        while (ll < rr && !(*ll & bit)) ll++;
        while (ll < rr &&  (*rr & bit)) rr--;
        if (ll >= rr) break;
      
        int temp = *ll;
        *ll = *rr;
        *rr = temp;
    }
 
    if (!(bit & *ll) && ll < to) ll++;
    bit >>= 1;
 
    radix_sort(from, ll, bit);
    radix_sort(ll, to, bit);
}
 


int solution(int A[], int N) {
    radix_sort(A, A + N, 1 << 17);
    
    for (int i = 0; i < N; i++) {
        if (A[i] != (i + 1)) {
        	return i + 1;
        } 
	}
	return N + 1;
}


int main(int argc, char *argv[]) {
    int x[] = {2, 3, 1, 5}; 

    for (int i = 0; i < sizeof(x) / sizeof(int); i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    printf("result: %d\n", solution(x, sizeof(x)/sizeof(int))); 
   
    for (int i = 0; i < sizeof(x)/sizeof(int); i++) {
        printf("%d ", x[i]);
        
    }

    printf("\n");

    return 0;
}

















