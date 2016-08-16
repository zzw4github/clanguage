#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = malloc(sizeof(struct node)); // new(struct node); // "new" is like malloc
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return node;
}

/*
  Given a binary search tree and a number, inserts a new node
  with the given number in the correct palce in the tree.
  Return the new root pointer which the caller should
  then use (the standard trick to avoid using refrence
  parameters).
*/
struct node* insert(struct node* node, int data)
{
	// 1. If the tree is empty, return a new, single node
	if (node == NULL)
	{
		return (newNode(data));
	}
	else {
		// 2. Otherwise, recur down the tree
		if (data <= node->data) node -> left = insert(node->left, data);
		else node->right = insert(node->right, data);

		return (node); // return the (unchanged) node pointer
	}
};

// call newNode() three times
struct node* build123a()
{
	struct node* root = newNode(2);
	struct node* lChild = newNode(1);
	struct node* rChild = newNode(3);
	
	root->left = lChild;
	root->right = rChild;

	return (root);
}

// call newNode() three times, and use only one loca variable
struct node* build123b()
{
	struct node* root = newNode(2);
	root->left = newNode(1);
	root->right = newNode(3);

	return (root);
}
/**
  Build 123 by calling insert() thress times.
  Node that the '2' must be inserted first/
*/
struct node* build123c()
{
	struct node* root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);

	return (root);
}

// 2 size() Soluctiion(C/C++)

/*
  Computer the number of nodes in a tree.
*/
int size(struct node* node)
{
	if (node == NULL)
	{
		return (0);
	}
	else
	{
		return size(node->left) + 1 + size(node->right);
	}
}

// 3. maxDepth() Solution(C/C++)

/*
  Computer the "maxDepth" of a tree -- the number of nodes along
  the longest path from the root node down to the farthest leaf node.
*/
 int maxDepth(struct node* node)
 {
 	if (node == NULL)
 	{
 		return (0);
 	}
 	else
 	{
 		// compute the depth of each subtree
 		int lDepth = maxDepth(node->left);
 		int rDepth = maxDepth(node->right);

 		if(lDepth > rDepth) return (lDepth + 1);
 		else return (rDepth + 1);
 	}
 }

// 4. minValue() Solution(C/C++)

/*
  Given a non-empty binary search tree,
  return the minimum data value found in that tree.
  Note that the entire tree does not need be searched.
*/
int minValue(struct node* node)
{
	struct node* current = node;

	// loop down to find the leftmost left
	while( current->left != NULL)
	{
		current = current->left;
	}

	return (current->data);
}

// 5. printTree() Solution(C/C++)

/*
  Given a binary search tree, print out
  tree data elements in increasing sorted order.
*/
void printTree(struct node* node)
{
	if (node == NULL) return ;

	printTree(node->left);
	printf("%d\n", node->data);
	printTree(node->right);
}

// 6.printPostorder() Solution(C/C++)

/*
  Given a binary tree, print its
  nodes according to the "bottom-up"
  postorder traversal.
*/
void printPostorder(struct node* node)
{
	if (node == null) return ;
	
	// first recur on both subtrees
	printTree(node->left);
	printTree(node->right);

	// then deal with the node
	printf("%d\n", node->data);
}

// 7. hasPathSum() Solution(C/C++)

/*
  Given a tree and a sum, return true if there is a path from the root
  down to a leaf, such that adding up all the  values along the path equals the given sum.
  Strategy: substract the node value from the sum when recurring down,
  adn check to see if the sum is 0 when you run out of tree.
*/
int hasPathSum(struct node* node, int sum)
{
	// return true if we run out of tree and sum==0
	if (node == NULL)
	{
		return (sum == 0);
	}
	else
	{
		// otherwise check both substees
		int subSum = sum - node->data;
		return (hasPathSum(node->left, subSum) ||
			    hasPathSum(node->right),subSum);
	}
}

// 8. printPaths() Solution(C/C++)

/*
  Given a binary tree, print out all of its root-to-leaf
  paths, one per line, Uses a recursive helper to do the work.
*/
void printPaths(sturct node* node)
{
	int path[1000];

	printPathsRecur(node, path, 0);
}

/*
  Recursive help function -- given a node , and an array containing
  the path from the root node up to but not including this node,
  print out all the root-leaf paths.
*/
void printPathsRecur(struct node* node, int path[], int pathLen)
{
	if (node == NULL) return;

	// append this node to the path array
	path[pathLen] node->data;
	pathLen++;

	// it's a leaf, so  print the path that led to here
	if (node->left == NULL && node->right == NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		// otherwise try both subtrees
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

// Utility that prints out an array on a line.
void printArray(int ints[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", ints[i]);
	}
	printf("\n");
}

// 9. mirror() Solution(C/C++)

/*
  Change a tree so that the rols of the 
  left and right pointers are swapped at every node.
*/
void mirror(struct node* node)
{
	if (node == NULL)
	{
		return ;
	}
	else
	{
		struct node* temp;

		// do the substrees
	    mirror(node->left);
	    mirror(node->right);

	    // swap the pointer in this node
	    temp = node->left;
	    node->left = node->right;
	    node->right = temp;
	}
}

// 10. doubleTree() Solution(C/C++)

/*
For each node in a binary search tree,
create a new duplicate node, and insert
the duplicate as the left child of the original node.
The resulting tree should still be a binary search tree.
So the tree...
   2
  / \
 1   3
Is changed to...
         2
        / \
       2   3
      /   /
     1   3
    /
   1
*/
void doubleTree(struct node* node) {
	struct node* oldLeft;

	if (node==NULL) return;

	// do the subtrees
	doubleTree(node->left);
	doubleTree(node->right);

	// duplicate this node to its left

	oldLeft = node->left;
	node->left = newNode(node->data);
	node->left->left = oldLeft;
}

//11. sameTree() Solution (C/C++)

/*
Given two trees, return true if they are
structurally identical.
*/
int sameTree(struct node* a, struct node* b) 
{
	// 1. both empty -> true
	if (a==NULL && b==NULL) return(true);
	// 2. both non-empty -> compare them
	else if (a!=NULL && b!=NULL) {
		return(
				a->data == b->data &&
				sameTree(a->left, b->left) &&
				sameTree(a->right, b->right)
		);
	}
	// 3. one empty, one not -> false
	else return(false);
}

//12. countTrees() Solution (C/C++)

/*
	For the key values 1...numKeys, how many structurally unique
	Binary Trees Page: 16
	http:/ / cslibrary.stanford.edu/ 110/
	BinaryTrees.html
	binary search trees are possible that store those keys.
	Strategy: consider that each value could be the root.
	Recursively find the size of the left and right subtrees.
*/
int countTrees(int numKeys) 
{
	if (numKeys <=1) {
		return(1);
	}
	else 
	{
		// there will be one value at the root, with whatever remains
		// on the left and right each forming their own subtrees.
		// Iterate through all the values that could be the root...
		int sum = 0;
		int left, right, root;
		for (root=1; root<=numKeys; root++) {
			left = countTrees(root - 1);
			right = countTrees(numKeys - root);
			// number of possible trees with this root == left*right
			sum += left*right;
		}
		return(sum);
	}
}

//13. isBST1() Solution (C/C++)

/*
  Returns true if a binary tree is a binary search tree.
*/
int isBST(struct node* node) 
{
	if (node==NULL) return(true);
	// false if the min of the left is > than us
	if (node->left!=NULL && minValue(node->left) > node->data)
		return(false);
	// false if the max of the right is <= than us
	if (node->right!=NULL && maxValue(node->right) <= node->data)
		return(false);
	// false if, recursively, the left or right is not a BST
	if (!isBST(node->left) || !isBST(node->right))
		return(false);
	// passing all that, it's a BST
	return(true);
}

//14. isBST2() Solution (C/C++)

/*
Returns true if the given tree is a binary search tree
(efficient version).
*/
int isBST2(struct node* node) 
{
	return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/*
Returns true if the given tree is a BST and its
values are >= min and <= max.
*/
int isBSTUtil(struct node* node, int min, int max) {
	if (node==NULL) return(true);
	// false if this node violates the min/max constraint
	if (node->data<min || node->data>max) return(false);
	// otherwise check the subtrees recursively,
	// tightening the min or max constraint
	return (
			isBSTUtil(node->left, min, node->data) &&
			isBSTUtil(node->right, node->data+1, max)
			);
}

int main()
{
	printTree(build123a());
}