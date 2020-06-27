#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
   vector<vector<int>> visited(grid.size(), vector<int>(grid.size(), 0));
   vector<vector<int>> value(grid.size(), vector<int>(grid.size(), 1000));
   value[startX][startY] = 0;
   if (startX == goalX && startY == goalY)
   {
      return 0;
   }

   queue<pair<int, int>> q;
   q.push(make_pair(startX, startY));
   int val = 0;
   while (!q.empty())
   {
      pair<int, int> point = q.front();
      q.pop();
      int x = point.first;
      int y = point.second;
      val = value[x][y];
      if (x == goalX && y == goalY)
      {
         break;
      }
      visited[x][y]++;

      for (int i = x - 1; i >= 0; i--)
         if (!visited[i][y] && grid[i][y] == '.')
         {
            if (value[i][y] >= 1000)
               value[i][y] = val + 1;
            q.push(make_pair(i, y));
         }
         else
         {
            break;
         }
      for (int i = y - 1; i >= 0; i--)
         if (!visited[x][i] && grid[x][i] == '.')
         {
            if (value[x][i] >= 1000)
               value[x][i] = val + 1;
            q.push(make_pair(x, i));
         }
         else
         {
            break;
         }
      for (int i = x + 1; i < grid.size(); i++)
         if (!visited[i][y] && grid[i][y] == '.')
         {
            if (value[i][y] >= 1000)
               value[i][y] = val + 1;
            q.push(make_pair(i, y));
         }
         else
         {
            break;
         }
      for (int i = y + 1; i < grid.size(); i++)
         if (!visited[x][i] && grid[x][i] == '.')
         {
            if (value[x][i] >= 1000)
               value[x][i] = val + 1;
            q.push(make_pair(x, i));
         }
         else
         {
            break;
         }
   }

   return val;
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   int n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   vector<string> grid(n);

   for (int i = 0; i < n; i++)
   {
      string grid_item;
      getline(cin, grid_item);

      grid[i] = grid_item;
   }

   string startXStartY_temp;
   getline(cin, startXStartY_temp);

   vector<string> startXStartY = split_string(startXStartY_temp);

   int startX = stoi(startXStartY[0]);

   int startY = stoi(startXStartY[1]);

   int goalX = stoi(startXStartY[2]);

   int goalY = stoi(startXStartY[3]);

   int result = minimumMoves(grid, startX, startY, goalX, goalY);

   fout << result << "\n";

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
