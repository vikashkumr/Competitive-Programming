// https://www.hackerrank.com/challenges/equal/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int solve(vector<int> &arr, int mn) {
    int cnt = 0;
    for(int i=0;i<(int)arr.size();i++) {
        int x = arr[i]-mn;
        cnt+=x/5 + x%5/2 + x%5%2;
    }
    return cnt;
}


// Complete the equal function below.
int equal(vector<int> arr) {
    int mn = *min_element(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i=0;i<5;i++) {
        int temp = solve(arr, mn-i);
        ans = min(ans, temp);
    }
    return ans;
}
// =====================================
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
