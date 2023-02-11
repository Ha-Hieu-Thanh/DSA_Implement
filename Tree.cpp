#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef struct Tnode
{
  string word;
  struct Tnode *left;
  struct Tnode *right;
} treeNode;

treeNode *makeTreeNode(string word)
{
  treeNode *newNode = new treeNode;
  newNode->word = word;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

class BinaryTree
{
private:
  Tnode *root;

public:
  BinaryTree()
  {
    root = NULL;
  }

  BinaryTree(Tnode *root)
  {
    this->root = root;
  }

  Tnode *getRoot()
  {
    return root;
  }
};

void freeTree(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return;
  freeTree(new BinaryTree(root->left));
  freeTree(new BinaryTree(root->right));
  delete tree;
}

void printPreorder(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return;
  cout << root->word << " ";
  printPreorder(new BinaryTree(root->left));
  printPreorder(new BinaryTree(root->right));
}

void printInorder(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return;
  printInorder(new BinaryTree(root->left));
  cout << root->word << " ";
  printInorder(new BinaryTree(root->right));
}

void printPostorder(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return;
  printPostorder(new BinaryTree(root->left));
  printPostorder(new BinaryTree(root->right));
  cout << root->word << " ";
}

int countNodes(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return 0;
  return 1 + countNodes(new BinaryTree(root->left)) + countNodes(new BinaryTree(root->right));
}

int countLeaves(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  return countLeaves(new BinaryTree(root->left)) + countLeaves(new BinaryTree(root->right));
}

int depth(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
    return 0;
  int leftDepth = depth(new BinaryTree(root->left));
  int rightDepth = depth(new BinaryTree(root->right));
  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else
    return rightDepth + 1;
}

void drawBinaryTree(BinaryTree *tree, int space)
{
  Tnode *root = tree->getRoot();
  if (root == NULL)
  {
    return;
  }
  space += 10;
  drawBinaryTree(new BinaryTree(root->right), space);
  cout << endl;
  for (int i = 10; i < space; i++)
  {
    cout << " ";
  }
  cout << root->word << endl;
  drawBinaryTree(new BinaryTree(root->left), space);
}

bool IsLeaf(Tnode *node)
{
  if (node->left == NULL && node->right == NULL)
  {
    return true;
  }
  return false;
}

bool IsOperator(string word)
{
  if (word == "+" || word == "-" || word == "*" || word == "/")
  {
    return true;
  }
  return false;
}

bool IsDigit(char c)
{
  if (c >= '0' && c <= '9')
  {
    return true;
  }
  return false;
}

bool IsNum(string word)
{
  for (int i = 0; i < word.length(); i++)
  {
    if (!IsDigit(word[i]))
    {
      return false;
    }
  }
  return true;
}

int evaluateExpressionTree(BinaryTree *tree)
{
  Tnode *root = tree->getRoot();
  if (IsLeaf(root))
  {
    return stoi(root->word);
  }
  int left = evaluateExpressionTree(new BinaryTree(root->left));
  int right = evaluateExpressionTree(new BinaryTree(root->right));
  if (root->word == "+")
  {
    return left + right;
  }
  else if (root->word == "-")
  {
    return left - right;
  }
  else if (root->word == "*")
  {
    return left * right;
  }
  else if (root->word == "/")
  {
    return left / right;
  }
  return 0;
}

vector<string> splitExpression(const string &prefixExpression)
{
  istringstream iss(prefixExpression);
  vector<string> tokens;
  string token;

  while (getline(iss, token, ' '))
  {
    tokens.push_back(token);
  }

  return tokens;
}

// BinaryTree *prefixToTree(string prefix)
// {
// }
// BinaryTree *postfixToTree(string postfix)
// {
// }
// BinaryTree *infixToTree(string infix)
// {
// }

int main()
{
  treeNode *root = makeTreeNode("A");
  root->left = makeTreeNode("B");
  root->right = makeTreeNode("C");
  root->left->left = makeTreeNode("D");
  root->left->right = makeTreeNode("E");
  root->right->left = makeTreeNode("F");
  root->right->right = makeTreeNode("G");
  root->left->left->left = makeTreeNode("H");
  root->left->left->right = makeTreeNode("I");
  root->left->right->left = makeTreeNode("J");
  root->left->right->right = makeTreeNode("K");
  root->right->left->left = makeTreeNode("L");
  root->right->left->right = makeTreeNode("M");
  root->right->right->left = makeTreeNode("N");
  root->right->right->right = makeTreeNode("O");
  BinaryTree *tree = new BinaryTree(root);
  drawBinaryTree(tree, 10);
  cout << endl
       << endl;

  cout << "Preorder: ";
  printPreorder(tree);
  cout << endl;
  cout << "Inorder: ";
  printInorder(tree);
  cout << endl;
  cout << "Postorder: ";
  printPostorder(tree);
  cout << endl;
  cout << "Number of nodes: " << countNodes(tree) << endl;
  cout << "Number of leaves: " << countLeaves(tree) << endl;
  cout << "Depth: " << depth(tree) << endl;
  freeTree(tree);
  cout << "***************************************" << endl;
  treeNode *root2 = makeTreeNode("*");
  root2->left = makeTreeNode("-");
  root2->right = makeTreeNode("/");
  root2->left->left = makeTreeNode("8");
  root2->left->right = makeTreeNode("5");
  root2->right->left = makeTreeNode("+");
  root2->right->right = makeTreeNode("3");
  root2->right->left->left = makeTreeNode("4");
  root2->right->left->right = makeTreeNode("2");
  BinaryTree *tree2 = new BinaryTree(root2);
  cout << evaluateExpressionTree(tree2);
  return 0;
}
