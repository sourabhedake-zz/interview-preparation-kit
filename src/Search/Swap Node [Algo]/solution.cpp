#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;

   Node(int data)
   {
      this->data = data;
   }
};

void getInorder(vector<int> &out, Node *root)
{
   if (root)
   {
      if (root->left)
      {
         getInorder(out, root->left);
      }
      out.push_back(root->data);
      if (root->right)
      {
         getInorder(out, root->right);
      }
   }
}

Node *swapChild(Node *node)
{
   if (node)
   {
      Node *tmp = node->left;
      node->left = node->right;
      node->right = tmp;
   }
   return node;
}

Node *findAndInsert(Node *root, int find, int childL, int childR)
{
   if (root)
   {
      if (root->data == find)
      {
         if (childL != -1)
         {
            root->left = new Node(childL);
            root->left->left = NULL;
            root->left->right = NULL;
         }
         if (childR != -1)
         {
            root->right = new Node(childR);
            root->right->left = NULL;
            root->right->right = NULL;
         }
      }
      else
      {
         if (root->left && root->left->data <= find)
         {
            findAndInsert(root->left, find, childL, childR);
         }

         if (root->right && root->right->data <= find)
         {
            findAndInsert(root->right, find, childL, childR);
         }
      }
   }
   return root;
}

Node *buildTree(vector<vector<int>> index, Node *root)
{
   root = new Node(1);
   root->left = root->right = NULL;
   for (int i = 0; i < index.size(); i++)
   {
      findAndInsert(root, i + 1, index[i][0], index[i][1]);
   }

   return root;
}

void swapChild(Node *node, int depth, int currentDepth)
{
   if (node)
   {
      swapChild(node->left, depth, currentDepth + 1);
      swapChild(node->right, depth, currentDepth + 1);

      if (currentDepth % depth == 0)
      {
         node = swapChild(node);
      }
   }
}
/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
   vector<vector<int>> out(queries.size());
   Node *root = buildTree(indexes, root);

   for (int i = 0; i < queries.size(); i++)
   {
      swapChild(root, queries[i], 1);
      getInorder(out[i], root);
   }
   return out;
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   int n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   vector<vector<int>> indexes(n);
   for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++)
   {
      indexes[indexes_row_itr].resize(2);

      for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++)
      {
         cin >> indexes[indexes_row_itr][indexes_column_itr];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }

   int queries_count;
   cin >> queries_count;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   vector<int> queries(queries_count);

   for (int queries_itr = 0; queries_itr < queries_count; queries_itr++)
   {
      int queries_item;
      cin >> queries_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      queries[queries_itr] = queries_item;
   }

   vector<vector<int>> result = swapNodes(indexes, queries);

   for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++)
   {
      for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++)
      {
         fout << result[result_row_itr][result_column_itr];

         if (result_column_itr != result[result_row_itr].size() - 1)
         {
            fout << " ";
         }
      }

      if (result_row_itr != result.size() - 1)
      {
         fout << "\n";
      }
   }

   fout << "\n";

   fout.close();

   return 0;
}
