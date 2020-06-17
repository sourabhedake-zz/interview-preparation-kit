#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    int cnt1[26] = {0};
    int cnt2[26] = {0};

    for (int i=0; i< a.size(); i++) {
        cnt1[a[i] - 'a']++;
    }

    for (int i=0; i< b.size(); i++) {
        cnt2[b[i] - 'a']++;
    }

    int charDel=0;
    for (int i=0; i<26; i++) {
        charDel += (abs(cnt1[i]-cnt2[i]));
    }
    return charDel;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
