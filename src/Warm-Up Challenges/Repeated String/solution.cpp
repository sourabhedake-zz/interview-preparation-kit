#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n)
{
   long cntA = 0;
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] == 'a')
      {
         cntA++;
      }
   }

   long divStrCnt = n / s.size();
   long remStrCnt = n % s.size();

   cntA *= divStrCnt;

   for (int i = 0; i < remStrCnt; i++)
   {
      if (s[i] == 'a')
      {
         cntA++;
      }
   }
   return cntA;
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string s;
   getline(cin, s);

   long n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   long result = repeatedString(s, n);

   fout << result << "\n";

   fout.close();

   return 0;
}
