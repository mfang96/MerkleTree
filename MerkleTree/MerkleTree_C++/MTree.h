#include "Node.h"


using namespace std;

class MTree{
private:
    string merkleRoot;
    int makeBinary(vector<Node*> &node_vector);
    void printTreeLevel(vector<Node*> v);
    vector<vector<Node*>> base;

public:
    MTree();
    string buildMTree();
    string getMerkleRoot();
    void buildBaseLeafes(vector<string> base_leafs);
    void iterateUp(int element);
//  int verify(string hash);
    virtual ~MTree();
};
