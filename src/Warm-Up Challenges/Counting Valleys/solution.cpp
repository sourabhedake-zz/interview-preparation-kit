#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
   ios_base::sync_with_stdio(false);
   int t, n, q;
   ll res = 0;
   cin >> t;
   string s;
   cin >> s;
   int level = 0, cnt = 0;
   for (int i = 0; i < t; i++)
   {
      if (s[i] == 'U')
         level++;
      else
      {
         level--;
         if (level == -1)
            cnt++;
      }
   }
   cout << cnt << endl;
   return 0;
}
