#include "MTree.h"
#include <iostream>

MTree::MTree () {}


int MTree::makeBinary(vector<Node*> &node_vector){

    int vectSize = node_vector.size();

    if((vectSize%2) != 0){
        node_vector.push_back(node_vector.end()[-1]);
        vectSize++;
    }
    return vectSize;
}

string MTree::buildMTree(){

    do {
        vector<Node*> new_nodes;
        makeBinary(this->base.end()[-1]);

        for (int i = 0; i < this->base.end()[-1].size(); i = i+2) {
            Node* new_parent = new Node;
            this->base.end()[-1][i]->setParent(new_parent);
            this->base.end()[-1][i+1]->setParent(new_parent);

            new_parent->setHash(this->base.end()[-1][i]->getHash() + this->base.end()[-1][i+1]->getHash());
            new_parent->setChildren(this->base.end()[-1][i],this->base.end()[-1][i+1]);
            new_nodes.push_back(new_parent);
//            std::cout << "Hash together: " << this->base.end()[-1][i]->getHash() << " and " << this->base.end()[-1][i+1]->getHash() << " attached: " << endl<<&new_parent << endl;
        }
//        cout<<endl;

        //printTreeLevel(new_nodes);
        this->base.push_back(new_nodes);
//        std::cout << "Hashed level with: " << this->base.end()[-1].size() << '\n';

    } while(this->base.end()[-1].size() > 1);

    this->merkleRoot = this->base.end()[-1][0]->getHash();
    return this->merkleRoot;

}

void MTree::printTreeLevel(vector<Node*> v){

    cout << endl;

    for (Node* el : v) {
        cout << el->getHash() << endl;
    }
}


void MTree::buildBaseLeafes(vector<string> base_leafs){

    vector<Node*> new_nodes;

    //输出叶子节点的hash值
//    std::cout << "Root leafs are: " << '\n';
    for (auto leaf : base_leafs){
        Node* new_node = new Node;
        new_node->setHash(leaf);
//        std::cout << new_node->getHash() << '\n';

        new_nodes.push_back(new_node);
    }
    this->base.push_back(new_nodes);
//    std::cout  << '\n';
}

string MTree::getMerkleRoot() {
    return merkleRoot;
}

void MTree::iterateUp(int element){
    Node* el_node = this->base[0][element];

    do {
        std::cout << "Current Hash: " << el_node->getHash() << '\n';
        /*std::cout << "Next Node: " << el_node << '\n';
        std::cout << "Next Parent: " << el_node->getParent() << '\n';*/
    }while ((el_node = el_node->getParent()) != NULL);
    //std::cout << "Done iterating" << '\n';
}

MTree::~MTree () {}
