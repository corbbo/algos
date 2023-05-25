#include "treeNode.hpp"

using namespace std;

class tree {
  private:
    treeNode *root;
    int count;
  public:
    tree();
    treeNode *searchNodeRef(int elem);
    treeNode *searchNodeRef(int elem, treeNode *n);
    void add(int elem);
    bool add(int elem, int elemDad);
    list<int> positionWidth();
    list<int> positionPre();
    int countNodes(treeNode *n);
    int countNodes();
    void positionPreAux(treeNode *n, list<int> &list);
    list<int> positionPos();
    void positionPosAux(treeNode *n, list<int> &list);
    int size();
    bool contains(int elem);
    bool removeBranch(int elem);
    int level(int elem);
    bool isExternal(int elem);
    bool isInternal(int elem);
    int getMaxChildren();
    int getMaxChildren(treeNode *n, int numChildren);
    int height();
    int height(treeNode *n);
    void print();
};
