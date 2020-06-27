#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;
   int arr[n];
   int can[n];

   can[0] = 1;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   for (int i = 0; i < n - 1; i++)
   {
      if (arr[i] < arr[i + 1])
         can[i + 1] = can[i] + 1;
      else
         can[i + 1] = 1;
   }

   for (int i = n; i > 0; i--)
   {
      if (arr[i] < arr[i - 1])
      {
         if (can[i - 1] > can[i])
            continue;
         else
            can[i - 1] = can[i] + 1;
      }
   }
   long long c = 0;
   for (int i = 0; i < n; i++)
   {
      //cout<<can[i] <<" ";
      c += can[i];
   }
   cout << c << endl;

   return 0;
}
