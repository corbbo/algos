#include <iostream>

using namespace std;

int main() {
  int **m;
  const int nLinhas = 3, nColunas = 4;
  m = new int*[nLinhas];
  for (int i = 0; i < nLinhas; i++) {
    m[i] = new int[nColunas];
  }
  for (int i = 0; i < nLinhas; i++) {
    for (int j = 0; j < nColunas; j++) {
      m[i][j] = i*nLinhas+j;
    }
  }
  for (int i = 0; i < nLinhas; i++) {
    cout << *m[i] << "  :  ";
    for (int j = 0; j < nColunas; j++) {
      cout << m[i][j] << ",";
    }
    cout << endl;
  }
  for (int i = 0; i < nLinhas; i++) {
    delete [] m[i];
  }
  delete [] m;
  return 0;
}
