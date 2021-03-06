// Mergesort implementation and timing test driver
// Basic Mergesort version

#include "book.h"

// Include comparator functions
#include "compare.h"

// Standard insertion sort implementation
#include "Inssort.cpp"

extern int THRESHOLD;

/* *** ODSATag: MergesortOpt *** */
template <typename E, typename Comp>
void mergesort(E A[], E temp[], int left, int right) {
  if ((right-left) <= THRESHOLD) { // Small list
    inssort<E,Comp>(&A[left], right-left+1);
    return;
  }
  int i, j, k, mid = (left+right)/2;
  mergesort<E,Comp>(A, temp, left, mid);
  mergesort<E,Comp>(A, temp, mid+1, right);
  // Do the merge operation.  First, copy 2 halves to temp.
  for (i=mid; i>=left; i--) temp[i] = A[i];
  for (j=1; j<=right-mid; j++) temp[right-j+1] = A[j+mid];
  // Merge sublists back to A
  for (i=left,j=right,k=left; k<=right; k++)
    if (Comp::prior(temp[i], temp[j])) A[k] = temp[i++];
    else A[k] = temp[j--];
}
/* *** ODSAendTag: MergesortOpt *** */

template <typename E, typename Comp>
void sort(E* array, int n) {
  static E* temp = NULL;
  if (temp == NULL) temp = new E[n];  // Declare temp array
  mergesort<E,Comp>(array, temp, 0, n-1);
}

#include "sortmain.cpp"

int main(int argc, char** argv) {
  return sortmain<minintCompare>(argc, argv);
}
