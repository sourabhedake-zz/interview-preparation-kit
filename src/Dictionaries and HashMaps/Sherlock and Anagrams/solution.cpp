#include <bits/stdc++.h>

using namespace std;

bool checkAnagram(string s1, string s2)
{
   if (s1.size() != s2.size())
   {
      return false;
   }

   int s1c[26] = {0};
   int s2c[26] = {0};
   for (int i = 0; i < s1.size(); i++)
   {
      s1c[s1[i] - 'a']++;
      s2c[s2[i] - 'a']++;
   }

   for (int i = 0; i < 26; i++)
   {
      if (s1c[i] != s2c[i])
      {
         return false;
      }
   }
   return true;
}

int sherlockAndAnagrams(string s)
{
   int size = s.size();
   int ana = 0;
   for (int i = 1; i < size; i++)
   {
      for (int j = 0; j + i - 1 < size; j++)
      {
         for (int k = j + 1; k + i - 1 < size; k++)
         {
            if (checkAnagram(s.substr(j, i), s.substr(k, i)))
            {
               ana++;
            }
         }
      }
   }
   cout << " eee " << endl;
   return ana;
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   int q;
   cin >> q;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   for (int q_itr = 0; q_itr < q; q_itr++)
   {
      string s;
      getline(cin, s);

      int result = sherlockAndAnagrams(s);

      fout << result << "\n";
   }

   fout.close();

   return 0;
}
