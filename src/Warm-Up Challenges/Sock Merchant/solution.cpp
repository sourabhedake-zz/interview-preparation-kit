#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, col;
   cin >> n;
   map<int, int> cnt;
   for (int i = 0; i < n; i++)
   {
      cin >> col;
      if (cnt.count(col) > 0)
         cnt[col]++;
      else
         cnt[col] = 1;
   }

   int pairs = 0;
   for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
   {
      pairs += it->second / 2;
   }
   cout << pairs << endl;
   return 0;
}
