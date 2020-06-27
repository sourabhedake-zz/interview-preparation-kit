#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int d)
   {
      data = d;
      left = NULL;
      right = NULL;
   }
};

class Solution
{
public:
   Node *insert(Node *root, int data)
   {
      if (root == NULL)
      {
         return new Node(data);
      }
      else
      {
         Node *cur;
         if (data <= root->data)
         {
            cur = insert(root->left, data);
            root->left = cur;
         }
         else
         {
            cur = insert(root->right, data);
            root->right = cur;
         }

         return root;
      }
   }

   /*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

   node *find(node *cur, int v)
   {
      while (1)
      {
         if (cur->data == v)
            return cur;
         else if (cur->data < v)
            cur = cur->right;
         else
            cur = cur->left;
      }
   }

   node *lca(node *root, int v1, int v2)
   {
      if (!root || root->data == v1 || root->data == v2)
         return root;

      node *l = lca(root->left, v1, v2);
      node *r = lca(root->right, v1, v2);

      if (l && r)
         return root;

      return (l) ? l : r;
   }

}; //End of Solution

int main()
{

   Solution myTree;
   Node *root = NULL;

   int t;
   int data;

   std::cin >> t;

   while (t-- > 0)
   {
      std::cin >> data;
      root = myTree.insert(root, data);
   }

   int v1, v2;
   std::cin >> v1 >> v2;

   Node *ans = myTree.lca(root, v1, v2);

   std::cout << ans->data;

   return 0;
}
