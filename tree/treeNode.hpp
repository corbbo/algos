using namespace std;

#include <list>

class treeNode {
  private:
    treeNode *father;
    int element;
    list<treeNode*> subtrees;
  public:
    treeNode();
    treeNode(int elem);
    treeNode* getFather();
    int getElem();
    void setFather(treeNode* nodo);
    void setElem(int elem);
    treeNode *getSubTree(int i);
    int getSubTreeSize();
    void addSubTree(treeNode *n);
    void removeAllSubTrees();
    bool removeSubTree(treeNode *n);
    void print(int level);
    void print();
    void clear();
}
