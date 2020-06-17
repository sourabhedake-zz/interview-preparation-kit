#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    vector < pair <char, int>> count;
    int curCnt=1;
    char curChar=s[0];
    for (int i=1; i<s.size(); i++) {
        if (curChar == s[i]) {
            curCnt++;
        } else {
            count.push_back(make_pair(curChar, curCnt));
            curChar = s[i];
            curCnt = 1;
        }
    }
    count.push_back(make_pair(curChar, curCnt));

    long result=0;
    for (int i=0; i<count.size(); i++) {
        result += (count[i].second * (count[i].second+1)) / 2;
        if (i>0 && i<count.size()-1) {
            if (count[i-1].first == count[i+1].first && count[i].second == 1) {
                result += min (count[i-1].second, count[i+1].second);
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
