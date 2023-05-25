#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int start, int middle, int end) {
  int p = start, q = middle + 1, k = 0;
  int *temp = (int *) malloc((end - start+1) * sizeof(int));
  for (int i = start; i <= end; i++) {
    if (p > middle) temp[k++] = a[q++]; // no more left val
    else if (q > end) temp[k++] = a[p++]; //no more right val
    else if (a[p] < a[q]) temp[k++] = a[p++]; //right > left
    else temp[k++] = a[q++]; // else left > right
  }
  for (int i = 0; i < k; i++) a[start++] = temp[i];
  free(temp);
}

void mergeSort(int a[], int start, int end) {
  if (end - start < 1) { //if run size == 1
    return; // it's sorted
  } //else split the run longer than 1 item into halves
  int middle = (end + start) / 2; //find mid point which disconsiders decimal points (e.g.: 5/2 = 2.5, so middle = 2)
  mergeSort(a, start, middle); //sort left side
  mergeSort(a, middle+1, end); //sort right side
  merge(a, start, middle, end); //merge results
}

int main(void) {
  int vet[5] = {2, 135, 59, 0, 23};
  mergeSort(vet, 0, 4);
  for (int i = 0; i < 5; i++) {
    printf("%d ", vet[i]);
  }
}
