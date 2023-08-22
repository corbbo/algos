#include <iostream>
#include <time.h>

#define MAX 1000000

class heapsort {
  private:
    int size;
    int* data;
    int numData;
  public:
    heap() {
      size = MAX;
      data = new int[size];
      numData = 1;  // pos 0 não é utilizada
    }
    ~heap() {
      delete data;
    }
    void swim(int pos) {
      while (pos > 1 && data[pos/2] < data[pos]) {
        int tmp = data[pos];
        data[pos] = data[pos/2];
        data[pos/2] = tmp;
        pos = pos * 0.5;
      }
    }
    void sink(int pos) {
      while (2*pos <= numData) {
        int j = 2*pos;
        if ( j < numData && data[j] < data[j+1] ) j++;
        if ( data[pos] >= data[j] ) break;
        int tmp = data[pos];
        data[pos] = data[j];
        data[j] = tmp;
        pos = j;
        }
    }
    void put(int data) {
      data[numData] = data;
      swim(numData);
      numData++;
    }
    int get() {
      int res = data[1];
      data[1] = data[numData--];
      sink(1);
      return res;
    }
    void sort() {
      int n = numData-1;
      for (int i = n * 0.5; i >= 1; i--) sink(i, n);
      while (n > 1) {
        int tmp = data[n];
        data[n] = data[1];
        data[1] = tmp;
        n--;
        sink(1);
    }
}


int main() {
   // Inicializa gerador aleatorio
   srand(time(0));

   int v[MAX+1];
   v[1] = 0;  // posicao 0 nao e' usada
   int size = 1;

   for(int i=0; i<MAX; i++)
     put(v, &size, rand()%(MAX*10)); // preenche aleatoriamente

//  print(v, size, 1, 1, 64);
//  printf("\n");

   // Ordena
   long start = clock();
   sort(v, size);
   long end = clock();

//   printf("\nOrdenado:\n");

//   for(int i=1; i<size; i++)
//     printf("%d ", v[i]);
//   printf("\n");

   printf("Tempo para %d elementos: %ld ns\n", MAX,(end-start));
}

