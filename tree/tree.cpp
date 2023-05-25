#include <iostream>

#include "tree.hpp"

    tree::tree() {
      root = nullptr;
      count = 0;
    }
    treeNode* tree::searchNodeRef(int elem) {
      if (elem == root->getElem()) return root;
    }
    treeNode* tree::searchNodeRef(int elem, treeNode *n) {
      if (n == nullptr) return nullptr;
      if (elem == n->getElem()) return n;
      else {
        treeNode* aux = nullptr;
        for (int i = 0; i < n->getSubTreeSize() && aux == nullptr; i++) {
          aux = searchNodeRef(elem, n->getSubTree(i));
        }
        return aux;
      }
    }
    void tree::add(int elem) {
      treeNode* n = new treeNode(elem);
      if (root != nullptr) { //se arvore nao esta vazia
        n->addSubTree(root); //inserir elem como raiz
        root = n;       
      } else root = n; //arvore vazia
      count++;
    }
    bool tree::add(int elem, int elemDad) {
      //inserir elem como filho de elempai
      treeNode* aux = searchNodeRef(elemDad, root);
      if (aux != nullptr) {
        //cria nodo
        treeNode* n = new treeNode(elem);
        //aux esta apontando pra o nodo onde elempai esta armazenado
        aux->addSubTree(n);
        n->setFather(aux);
        count++;
        return true;
      }
      return false;
    }

    list<int> positionWidth();
    list<int> positionPre();
    int countNodes(treeNode *n);
    int countNodes();
    void positionPreAux(treeNode *n, list<int> &list);
    list<int> positionPos();
    void positionPosAux(treeNode *n, list<int> &list);
    int size();
    bool contains(int elem);
    bool tree::removeBranch(int elem) {
      if (root == nullptr) {
        cout << "Arvore vazia" << endl;
        return false;
      }
    }
    int tree::level(int elem) {
      treeNode *aux = searchNodeRef(elem, root);
      if (aux == nullptr) return -1;
      else return height(aux);
    }
    bool tree::isExternal(int elem) {
      treeNode *aux = searchNodeRef(elem, root);
      if (aux == nullptr) throw NoSuchException;
      else if (aux->getSubTreeSize() == 0) return true;
      else return false;
    }
    bool tree::isInternal(int elem) {
      return !isExternal(elem);
    }
    int tree::getMaxChildren() {
      return getMaxChildren(root, 0);
    }
    int tree::getMaxChildren(treeNode *n, int numChildren) {
      int nSubTreeSize = n->getSubTreeSize();
      if (n == nullptr || nSubTreeSize == 0) return numChildren;
      else if (numChildren < nSubTreeSize) numChildren = n->getSubTreeSize();
      for (int i = 0; i < nSubTreeSize; i++) {
        numChildren = getMaxChildren(n->getSubTree(i), numChildren);
      }
      return numChildren;
    }
    int tree::height() {
      if (root == nullptr || root->getSubTreeSize() == 0) return 0;
      else return height(root);
    }
    int tree::height(treeNode *n) {
      if (n->getSubTreeSize() == 0) return 0;
      else {
        int h = 0;
        for (int i = 0; i < n->getSubTreeSize(); i++) {
          h = max(h, height(n->getSubTree(i)));
        }
        return 1+h;
      }
    }
    void print();
};
