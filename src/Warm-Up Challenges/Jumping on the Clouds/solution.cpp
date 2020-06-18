#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   int cnt = 0;
   int zcnt = 0;
   cin >> n;
   int tmp;
   for (int i = 0; i < n; i++)
   {
      cin >> tmp;
      if (tmp == 0)
      {
         zcnt++;
         if (i == n - 1)
            cnt += zcnt / 2;
      }
      else
      {
         cnt += zcnt / 2 + 1;
         zcnt = 0;
      }
   }
   cout << cnt << endl;
   return 0;
}
