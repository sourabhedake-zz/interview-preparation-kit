#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
   int n, q;
   cin >> n >> q;
   vll vec(n + 3, 0);
   vll singleVec(n + 3, 0);
   vector<bool> single(n + 3, 0);
   int a, b, c;

   for (int i = 0; i < q; i++)
   {
      cin >> a >> b >> c;
      a--;
      b--;

      if (a == b)
      {
         single[a] = true;
         singleVec[a] += c;
      }
      else
      {
         vec[a] += c;
         vec[b + 1] -= c;
      }
   }

   ll maxx = 0, value = 0;
   for (int i = 0; i < n; i++)
   {
      value += vec[i];
      value += singleVec[i];

      if (value > maxx)
         maxx = value;
      if (single[i])
         value -= singleVec[i];
   }
   cout << maxx << endl;
   return 0;
}
