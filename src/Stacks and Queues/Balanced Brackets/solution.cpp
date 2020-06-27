#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s)
{
   stack<char> balStack;
   char tmp;
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] == '{' || s[i] == '[' || s[i] == '(')
      {
         balStack.push(s[i]);
      }
      else
      {
         if (balStack.size() != 0)
         {
            tmp = balStack.top();
            balStack.pop();
            if ((tmp == '{' && s[i] == '}') || (tmp == '(' && s[i] == ')') || (tmp == '[' && s[i] == ']'))
            {
               continue;
            }
            else
            {
               return "NO";
            }
         }
         else
         {
            return "NO";
         }
      }
   }
   if (balStack.size() != 0)
   {
      return "NO";
   }
   return "YES";
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   int t;
   cin >> t;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   for (int t_itr = 0; t_itr < t; t_itr++)
   {
      string s;
      getline(cin, s);

      string result = isBalanced(s);

      fout << result << "\n";
   }

   fout.close();

   return 0;
}
