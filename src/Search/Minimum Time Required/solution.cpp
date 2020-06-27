#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long minTime(vector<long> machines, long goal)
{
   sort(machines.begin(), machines.end());

   long high = goal * machines.front();
   long low = high / machines.size();
   while (low < high)
   {
      long mid = (low + high) / 2;
      long prod = 0;
      for (int i = 0; i < machines.size(); i++)
      {
         prod += floor(mid / machines[i]);
      }
      if (prod >= goal)
      {
         high = mid;
      }

      if (prod < goal)
      {
         low = mid + 1;
      }
   }
   return low;
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string nGoal_temp;
   getline(cin, nGoal_temp);

   vector<string> nGoal = split_string(nGoal_temp);

   int n = stoi(nGoal[0]);

   long goal = stol(nGoal[1]);

   string machines_temp_temp;
   getline(cin, machines_temp_temp);

   vector<string> machines_temp = split_string(machines_temp_temp);

   vector<long> machines(n);

   for (int i = 0; i < n; i++)
   {
      long machines_item = stol(machines_temp[i]);

      machines[i] = machines_item;
   }

   long ans = minTime(machines, goal);

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
