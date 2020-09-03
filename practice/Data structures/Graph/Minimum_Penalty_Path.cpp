//https://www.hackerrank.com/challenges/beautiful-path/problem?isFullScreen=true

#include <bits/stdc++.h>
const int N = 1111;
using namespace std;
bool used[N][N];
vector<string> split_string(string);

// Complete the beautifulPath function below.
int beautifulPath(vector<vector<int>> edges, int A, int B) {
    vector<pair<int,int>> gr[N];
    for(int i=0;i<(int)edges.size();i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        gr[u].push_back({v,wt});
        gr[v].push_back({u,wt});
    }
    queue<pair<int,int>> q;
    q.push({A,0});
    while(!q.empty()) {
        int ver = q.front().first; 
        int res = q.front().second;
        q.pop();
        used[ver][res] = true;
        for(auto child: gr[ver]) {
            int to = child.first;
            int add = child.second;
            if(!used[to][(add|res)]) {
                used[to][add|res] = true;
                q.push({to,add|res});
            }
        }
    }
    int ans = -1;
    for(int i=0;i<N;i++) {
        if(used[B][i]) {
            ans = i;
            break;
        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B);

    fout << result << "\n";

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
