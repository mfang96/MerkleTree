#include "Node.h"
#include <openssl/sha.h>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

Node::Node (){
  this->parent = NULL;
  this->children[0] = NULL;
  this->children[1] = NULL;
}

void Node::setHash(string hash_str){
  this->hash_str=sha256(hash_str);
}

Node* Node::getParent(){
  return this->parent;
}

void Node::setParent(Node* parent){
  this->parent = parent;
}

void Node::setChildren(Node* children_l, Node* children_r){
  this->children[0] = children_l;
  this->children[1] = children_r;
}

Node* Node::getSibling(){
  Node* parent = this->getParent();
  return parent->getChildren(0) == this ? parent->getChildren(1) : parent->getChildren(0);

}

Node* Node::getChildren(int index){
  return index <= 1 ? children[index] : NULL;
}

string Node::getHash(){
  return this->hash_str;
}

int Node::checkDir(){
  return parent->getChildren(0) == this ? 0 : 1;
}



Node::~Node () {}

string Node::sha256(const string str) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);

  stringstream ss;
  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
  {
    ss << hex << setw(2) << setfill('0') << (int)hash[i];
  }
  return ss.str();
}
