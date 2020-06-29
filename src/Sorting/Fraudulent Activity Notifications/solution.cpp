#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int activityNotifications(vector<int> mylist, int d)
{
    int notif = 0;
    double median;
    int ori_count[201] = {0}, i;
    int count[201] = {0};
    for (i = 0; i < d; ++i)
        ++ori_count[mylist[i]];

    int a = 0, b = 0;
    int first = 0, second = 0;

    for (i = d; i < mylist.size(); i++)
    {
        if (i != d)
        {
            ori_count[mylist[i - d - 1]]--;
            ori_count[mylist[i - 1]]++;
        }

        count[0] = ori_count[0];
        for (int j = 1; j <= 200; ++j)
        {
            count[j] = count[j - 1] + ori_count[j];
        }

        if (d % 2 == 0)
        {
            first = d / 2;
            second = first + 1;
            for (int j = 0; j < 201; j++)
            {
                if (first <= count[j])
                {
                    a = j;
                    break;
                }
            }
            for (int j = 0; j < 201; j++)
            {
                if (second <= count[j])
                {
                    b = j;
                    break;
                }
            }
        }
        else
        {
            first = d / 2 + 1;
            for (int j = 0; j < 201; j++)
            {
                if (first <= count[j])
                {
                    a = j;
                    break;
                }
            }
        }

        if (d % 2 == 0)
        {
            median = (a + b) / double(2);
        }
        else
        {
            median = a;
        }

        if (median * 2 <= (double)mylist[i])
        {
            notif++;
        }
    }
    return notif;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
