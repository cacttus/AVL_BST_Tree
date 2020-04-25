#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define Max_Keys 1000

//AVL Tree
class AVLNode {
public:
  AVLNode* _left=nullptr;
  AVLNode* _right = nullptr;
  double _key = 0;
  AVLNode(double key) {
    _left = _right = nullptr;
    _key = key;
  }
  virtual ~AVLNode() {
    delete _left;
    delete _right;
  }
  AVLNode* insert(AVLNode* parent, double key) {
    if (key < _key) {
      parent->_left = new AVLNode(key);
    }
    else if (key > _key) {
      parent->_right = new AVLNode(key);
    }
    else {
      return parent; // Equal keys are not allowed.
    }
  }
  void print(AVLNode* n) {
    /*
               a
         /            \
         b
        / \  < Height Width -1
      2.2  6.4 << Height width   

      height width = width of all formatted numbers
    */
    getHeight(n)
  }
};
int main(int argc, char* argv[]) {
  std::vector<double> keys;
  for (size_t iKey = 0; iKey < Max_Keys; iKey++) {
    double dr = (double)rand() / (double)RAND_MAX;
    keys.push_back(dr);
  }

  AVLNode* root = nullptr;
  for (size_t k = 0; k < keys.size(); ++k) {
    if (root == nullptr) {
      root = new AVLNode(keys[k]);
    }
    else {
      root->insert(root, keys[k]);
    }
  }

  delete root;
  keys.clear();
  return 0;
}

