#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long triplets(vector<int> a, vector<int> b, vector<int> c)
{
   sort(a.begin(), a.end());
   a.erase(unique(a.begin(), a.end()), a.end());
   sort(b.begin(), b.end());
   b.erase(unique(b.begin(), b.end()), b.end());
   sort(c.begin(), c.end());
   c.erase(unique(c.begin(), c.end()), c.end());

   long long cnt = 0;
   int smallA = 0;
   int smallC = 0;
   int j = 0;
   for (int i = 0; i < b.size(); i++)
   {
      while (smallA < a.size() && a[smallA] <= b[i])
      {
         smallA++;
      }

      while (smallC < c.size() && c[smallC] <= b[i])
      {
         smallC++;
      }

      if (smallA == -1 || smallC == -1)
      {
         continue;
      }
      cnt += (long long)smallA * (long long)smallC;
   }
   return cnt;
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string lenaLenbLenc_temp;
   getline(cin, lenaLenbLenc_temp);

   vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

   int lena = stoi(lenaLenbLenc[0]);

   int lenb = stoi(lenaLenbLenc[1]);

   int lenc = stoi(lenaLenbLenc[2]);

   string arra_temp_temp;
   getline(cin, arra_temp_temp);

   vector<string> arra_temp = split_string(arra_temp_temp);

   vector<int> arra(lena);

   for (int i = 0; i < lena; i++)
   {
      int arra_item = stoi(arra_temp[i]);

      arra[i] = arra_item;
   }

   string arrb_temp_temp;
   getline(cin, arrb_temp_temp);

   vector<string> arrb_temp = split_string(arrb_temp_temp);

   vector<int> arrb(lenb);

   for (int i = 0; i < lenb; i++)
   {
      int arrb_item = stoi(arrb_temp[i]);

      arrb[i] = arrb_item;
   }

   string arrc_temp_temp;
   getline(cin, arrc_temp_temp);

   vector<string> arrc_temp = split_string(arrc_temp_temp);

   vector<int> arrc(lenc);

   for (int i = 0; i < lenc; i++)
   {
      int arrc_item = stoi(arrc_temp[i]);

      arrc[i] = arrc_item;
   }

   long long ans = triplets(arra, arrb, arrc);

   fout << ans << "\n";

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
