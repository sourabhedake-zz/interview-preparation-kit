#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int cnt [26] = {0};

    for (int i=0; i<s.size(); i++) {
        cnt[s[i]-'a']++;
    }

    if (s.size() == 1) {
        return "YES";
    }
    sort(cnt, cnt+26);
    int i=0;
    while (cnt[i] == 0) {
        i++;
    }

    if ((cnt[i] == cnt[25]) || 
        ((cnt[i] <= cnt[i+1] + 1) && cnt[i+1] == cnt[25]) ||
        ((cnt[24] + 1 >= cnt[25]) && cnt[i] == cnt[24])) {
        return "YES";
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
