#include "treeNode.hpp"
#define IndexOutOfBoundsException 2

    treeNode::treeNode() {
      father = nullptr;
      element = 0;
    }
    treeNode::treeNode(int elem) {
      father = nullptr;
      element = elem;
    }
    treeNode* treeNode::getSubTree(int i) {
      if ((i < 0) || (i >= subtrees.size())) {
        throw IndexOutOfBoundsException;
      }

      list<treeNode*>::iterator k;
      k = subtrees.begin();
      advance(k,i);
      return *k;
    }
    int treeNode::getSubTreeSize() {
      return (int)subtrees.size();
    }
    void treeNode::addSubTree(treeNode *n) {
      n->father = this;
      subtrees.push_back(n);
    }
    void treeNode::removeAllSubTrees() {
      list<treeNode*>::iterator k;
      //nodo sem filhos
      if (subtrees.size() == 0) return;
      //nodo com filhos
      for (k = subtrees.begin(); k != subtrees.end(); k++) {
        (*k)->removeAllSubTrees();
        delete *k;
      }
      //limpa lista
      subtrees.clear();
    }
    bool treeNode::removeSubTree(treeNode *n) {
      list<treeNode*>::iterator k;
      for (k = subtrees.begin(); k != subtrees.end(); k++) {
        if (*k == n) {
          (*k)->removeAllSubTrees(); //antes de remover k, remove todos os filhos de k
          delete *k;
          subtrees.erase(k); //apaga o elemento da posição k
          return true;
        }
      }
      return false;
    }
    void treeNode::print(int level)
    void treeNode::print()
    void treeNode::clear()
}
