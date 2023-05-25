#include <iostream>

using namespace std;

class VetorDinamico {
private:
  int size;
  int used;
  int *numero;
  static const int LIM = 10;
public:
  // Metodos a serem criados :
  // - construtor : deve alocar o vetor com um tamanho passado como parametro
  VetorDinamico(int s = 1, int u = 0) {
    size = s;
    used = u;
    numero = new int[size];
  }
  // - adiciona : coloca um dado no vetor . Se nao houver mais espaco , deve
  // alocar um novo vetor
  int *adiciona(int n) {
    if (used == size) {
      size += LIM;
      used++;
      int *aux = new int[size];
      for (int i = 0; i < used-1; i++) {
        aux[i] = numero[i];
      }
      aux[used-1] = n;
      int* oldvet = numero;
      numero = aux;
      delete [] oldvet;
      return numero;
    }
    numero[used++] = n;
    return numero;
  }
  int getQtdDados()      {return used;}
  int getDado(int n)     {if (n >= size || n >= used) return -1; return numero[n];}
};

int main() {
  VetorDinamico V1(5);
  int dado;
  do {
    cin >> dado;
    if (dado > 0)
      V1.adiciona(dado);
    else
      break;
  } while (1);
  for (int i = 0; i < V1.getQtdDados(); i++)
    cout << V1.getDado(i) << endl;
  return 0;
}
