#include <iostream>
#include "MTree.h"

using namespace std;

int main(int argc, char const *argv[]) {
//    string check_str = "";
//    std::cout << "Enter Merkle Leafes: " << '\n';
    std::vector<string> leaves;

//    while(1) {
//        string str;
//        std::cin >> str;
//        if(str != ";")
//            leaves.push_back(str);
//        else
//            break;
//    }
    leaves.emplace_back("a1");
    leaves.emplace_back("a2");
    leaves.emplace_back("a3");
    leaves.emplace_back("a4");
    leaves.emplace_back("a5");

    MTree nMTree;
    string mRoot;
    nMTree.buildBaseLeafes(leaves);
    mRoot=nMTree.buildMTree();
    std::cout << "Merkle Root is: " << mRoot << endl << endl;
    return 0;
}
