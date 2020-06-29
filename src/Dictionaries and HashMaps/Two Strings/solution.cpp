#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int test;
   cin >> test;
   while (test--)
   {
      string s1, s2;
      cin >> s1 >> s2;
      int cnt1[26] = {0}, cnt2[26] = {0};

      for (int i = 0; i < s1.size(); i++)
         cnt1[s1[i] - 'a']++;

      for (int i = 0; i < s2.size(); i++)
         cnt2[s2[i] - 'a']++;

      int f = 0;
      for (int i = 0; i < 26; i++)
      {
         if (cnt1[i] > 0 && cnt2[i] > 0)
         {
            f = 1;
            break;
         }
      }
      if (f == 1)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
   return 0;
}
