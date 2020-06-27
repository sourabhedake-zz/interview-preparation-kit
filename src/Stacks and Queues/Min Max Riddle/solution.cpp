#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<long> riddle(vector<long> arr)
{

   stack<long> s;

   vector<long> left(arr.size() + 1, -1);
   vector<long> right(arr.size() + 1, arr.size());

   vector<long> ans(arr.size() + 1, 0);

   for (int i = 0; i < arr.size(); i++)
   {
      while (!s.empty() && arr[s.top()] >= arr[i])
      {
         s.pop();
      }
      if (!s.empty())
      {
         left[i] = s.top();
      }
      s.push(i);
   }

   while (!s.empty())
   {
      s.pop();
   }

   for (int i = arr.size() - 1; i >= 0; i--)
   {
      while (!s.empty() && arr[s.top()] >= arr[i])
      {
         s.pop();
      }
      if (!s.empty())
      {
         right[i] = s.top();
      }
      s.push(i);
   }

   int len;
   for (int i = 0; i < arr.size(); i++)
   {
      len = right[i] - left[i] - 1;
      ans[len] = max(ans[len], arr[i]);
   }

   for (int i = arr.size() - 1; i >= 1; i--)
   {
      ans[i] = max(ans[i], ans[i + 1]);
   }

   return vector<long>(ans.begin() + 1, ans.end());
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   int n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   string arr_temp_temp;
   getline(cin, arr_temp_temp);

   vector<string> arr_temp = split_string(arr_temp_temp);

   vector<long> arr(n);

   for (int i = 0; i < n; i++)
   {
      long arr_item = stol(arr_temp[i]);

      arr[i] = arr_item;
   }

   vector<long> res = riddle(arr);

   for (int i = 0; i < res.size(); i++)
   {
      fout << res[i];

      if (i != res.size() - 1)
      {
         fout << " ";
      }
   }

   fout << "\n";

   fout.close();

   return 0;
}

vector<string> split_string(string input_string)
{
   string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
      return x == y and x == ' ';
   });

   input_string.erase(new_end, input_string.end());

   while (input_string[input_string.length() - 1] == ' ')
   {
      input_string.pop_back();
   }

   vector<string> splits;
   char delimiter = ' ';

   size_t i = 0;
   size_t pos = input_string.find(delimiter);

   while (pos != string::npos)
   {
      splits.push_back(input_string.substr(i, pos - i));

      i = pos + 1;
      pos = input_string.find(delimiter, i);
   }

   splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

   return splits;
}
