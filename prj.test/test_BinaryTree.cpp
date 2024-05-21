#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <BinaryTree/BinaryTree.hpp>

#include "doctest.h"

TEST_CASE("BinaryTree tests") {
	BinaryTree bst;
	BinaryTree bstEmpty;

	//         5
	//     3       7
	//   2   4   6

	CHECK(bst.empty() == true);
	bst.add(5);
	bst.add(3);
	bst.add(7);
	bst.add(2);
	bst.add(4);
	bst.add(6);
	CHECK(bst.empty() == false);
	CHECK_THROWS_WITH(bst.add(5), "Element already exists");
	CHECK(bst.root()->data == 5);

	CHECK(bst.has(5) == true);
	CHECK(bst.has(3) == true);
	CHECK(bst.has(7) == true);
	CHECK(bst.has(2) == true);
	CHECK(bst.has(4) == true);
	CHECK(bst.has(6) == true);
	CHECK(bst.has(8) == false);
	CHECK_THROWS_WITH(bstEmpty.has(5), "Empty tree");

	TreeNode *node = bst.find(3);
	CHECK(node->data == 3);
	CHECK(node->left->data == 2);
	CHECK(node->right->data == 4);
	CHECK_THROWS_WITH(bstEmpty.find(5), "Empty tree");

	bst.remove(3);
	CHECK(bst.has(3) == false);
	CHECK_THROWS_WITH(bstEmpty.remove(5), "Empty tree");
	CHECK_THROWS_WITH(bst.remove(3), "Empty tree");

	CHECK(bst.min() == 2);
	CHECK(bst.max() == 7);

	CHECK(bst.empty() == false);
}
