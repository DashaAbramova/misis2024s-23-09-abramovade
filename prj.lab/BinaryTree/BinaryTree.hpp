#pragma once

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
	// Конструктор
	BinaryTree();

	// Деструктор
	~BinaryTree();

	// Метод для получения корневого узла дерева
	TreeNode *root();

	// Метод для добавления узла в дерево
	void add(int data);

	// Метод для проверки наличия узла в дереве
	bool has(int data);

	// Метод для поиска узла в дереве
	TreeNode *find(int data);

	// Метод для удаления узла из дерева
	void remove(int data);
	// найти ноду
	//  если лист - просто удалить
	//  если у ноду есть один из потомков
	//  если есть оба - минимальный узел в правом поддереве заменяет текущую

	// Метод для нахождения минимального значения в дереве
	int min();

	// Метод для нахождения максимального значения в дереве
	int max();

	bool empty();

private:
	TreeNode *root_;

	TreeNode *findPrev(int data);
	TreeNode *findMin(TreeNode *node);
	TreeNode *findMax(TreeNode *node);

	void deleteTree(TreeNode *node);

	bool isLeaf(TreeNode *node);
	bool hasOneChild(TreeNode *node); // имеет одного потомка
	bool hasTwoChildren(TreeNode *node); //имеет 2 потомка
};
