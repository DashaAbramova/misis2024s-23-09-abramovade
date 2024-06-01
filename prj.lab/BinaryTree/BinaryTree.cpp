// Programm [2024] <Programm Daria>

#include <BinaryTree/BinaryTree.hpp>
#include <stack>
#include <stdexcept>

BinaryTree::BinaryTree() : root_(nullptr) {}

BinaryTree::~BinaryTree() { deleteTree(root_); }

TreeNode *BinaryTree::root() { return root_; }

bool BinaryTree::empty() { return root_ == nullptr; }

bool BinaryTree::isLeaf(TreeNode *node) {
  return node->left == nullptr && node->right == nullptr;
}
bool BinaryTree::hasOneChild(TreeNode *node) {
  return (node->left != nullptr ^ node->right != nullptr);
}
bool BinaryTree::hasTwoChildren(TreeNode *node) {
  return (node->left != nullptr && node->right != nullptr);
}


void BinaryTree::deleteTree(TreeNode *node) {
  std::stack<TreeNode *> s;
  TreeNode *current = node;
  TreeNode *lastVisited = nullptr;

  while (current || !s.empty()) {
    if (current) {
      s.push(current);
      current = current->left;

    } else {
      TreeNode *topNode = s.top();

      if (topNode->right && topNode->right != lastVisited) {
        current = topNode->right;

      } else {
        lastVisited = topNode;
        s.pop();
        delete topNode;
      }
    }
  }
}

TreeNode *BinaryTree::findPrev(int data) {
  if (empty()) {
    return nullptr;
  }
  TreeNode *current = root_;
  TreeNode *prev = nullptr;
  while (current != nullptr && current->data != data) {
    prev = current;
    current = (data < current->data) ? current->left : current->right;
  }
  return prev;
}

TreeNode *BinaryTree::findMin(TreeNode *node) {
  TreeNode *current = node;
  TreeNode *prev = nullptr;
  while (current != nullptr) {
    prev = current;
    current = current->left;
  }
  return prev;
}

TreeNode *BinaryTree::findMax(TreeNode *node) {
  TreeNode *current = node;
  TreeNode *prev = nullptr;
  while (current != nullptr) {
    prev = current;
    current = current->right;
  }
  return prev;
}

void BinaryTree::add(int data) {
  if (empty()) {
    root_ = new TreeNode(data);
    return;
  }
  TreeNode *prev = findPrev(data);
  if ((root_->data == data) ||
    (prev->left != nullptr && prev->left->data == data) ||
      (prev->right != nullptr && prev->right->data == data)) {
    throw std::logic_error("Element already exists");
  }
  (data < prev->data) ? prev->left = new TreeNode(data)
                      : prev->right = new TreeNode(data);
}

bool BinaryTree::has(int data) {
  if (empty()) {
    throw std::logic_error("Empty tree");
  }
  if (root_->data == data) {
    return true;
  }
  TreeNode *prev = findPrev(data);
  return ((prev->left != nullptr && prev->left->data == data) ||
          (prev->right != nullptr && prev->right->data == data));
}

TreeNode *BinaryTree::find(int data) {
  if (empty()) {
    throw std::logic_error("Empty tree");
  }
  if (data == root_->data) {
    return root_;
  }
  TreeNode *prev = findPrev(data);
  if (data < prev->data && prev->left != nullptr
    && data == prev->left->data) {
    return prev->left;
  } else if (data > prev->data && prev->right != nullptr &&
             data == prev->right->data) {
    return prev->right;
  } else {
    return nullptr;
  }
}

void BinaryTree::remove(int data) {
  if (empty()) {
    throw std::logic_error("Empty tree");
  }
  if (!has(data)) {
    throw std::logic_error("Empty tree");
  }
  TreeNode *node = find(data);
  TreeNode *prev = findPrev(data);
  if (isLeaf(node)) {
    delete node;
    data < prev->data ? prev->left = nullptr : prev->right = nullptr;
    return;
  }

  if (hasOneChild(node)) {
    TreeNode *child = (node->left != nullptr) ? node->left : node->right;
    delete node;
    (data < prev->data) ? prev->left = child : prev->right = child;
    return;
  }

  if (hasTwoChildren(node)) {
    TreeNode *replace = findMin(node->right);
    if (replace == node->right) {
      node->right = replace->right;
      node->data = replace->data;
      delete replace;
      return;
    }
    int replaceData = replace->data;
    TreeNode *replacePrev = findPrev(replaceData);
    if (isLeaf(replace)) {
      node->data = replaceData;
      replacePrev->left = nullptr;
      delete replace;
      return;
    } else {
      replacePrev->left = replace->right;
      node->data = replaceData;
      delete replace;
      return;
    }
  }
}

int BinaryTree::min() {
  if (empty()) {
    throw std::logic_error("Empty tree");
  }
  TreeNode *current = root_;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current->data;
}

int BinaryTree::max() {
  if (empty()) {
    throw std::logic_error("Empty tree");
  }
  TreeNode *current = root_;
  while (current->right != nullptr) {
    current = current->right;
  }
  return current->data;
}
