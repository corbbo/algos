#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition(int a[], int start, int end) {
  int i, tmp, left = start, pivot = a[end];
  //elements smaller than pivot to the left
  for (i = start; i < end; i++) {
    if (a[i] < pivot) {
      tmp = a[left];
      a[left] = a[i];
      a[i] = tmp;
      left++;
    }
  }
  //move pivot inbetween left and right sides
  a[end] = a[left];
  a[left] = pivot;
  return left;
}

void quickSort(int a[], int start, int end) {
  int pivPos;
  if (end - start + 1 <= 1) return;
  //partition array and get pivot pos
  pivPos = partition(a, start, end);
  //sort partitions
  quickSort(a, start, pivPos - 1);
  quickSort(a, pivPos+1, end);
}

int main(void) {
  int vet[5] = {124, 43, 39, 0, 1};
  quickSort(vet, 0, 4);
  for (int i = 0; i < 5; i++) {
    printf("%d ", vet[i]);
  }
}
