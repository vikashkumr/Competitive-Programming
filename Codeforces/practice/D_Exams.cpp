#include<bits/stdc++.h>
using namespace std;
#define For(a,n) for(int i=1;i<=n;i++) cin>>a[i]

bool dePaye(int n, int m, int *d, int *a, vector<int> *ExamDaysMap) {
    vector<pair<int,int> > v;
    for(int i=1;i<=m;i++) {
        auto it = upper_bound(ExamDaysMap[i].begin(),ExamDaysMap[i].begin(),n);
        if(it==ExamDaysMap[i].begin()) return false;
        v.push_back({*(--it),i});
    }

    sort(v.begin(),v.end());
    int buffer = 0, earlier_exam_day = 0, prep_days = 0, exam_day = 0,available_day = 0;
    for(auto it : v) {
        exam_day = it.first;
        prep_days = a[it.second]+1;
        available_day = exam_day-earlier_exam_day+buffer;
        if(prep_days>available_day) {
            return false;
        } 
        buffer = available_day-prep_days;
        earlier_exam_day = exam_day;
    }
    return true;
}


int Exam(int n, int m, int *d, int *a) {
    vector<int> ExamDaysMap[100002];
    for(int i=1;i<=n;i++) {
        if(d[i]!=0) {
            ExamDaysMap[d[i]].push_back(i);
        }
    }
    int l = 1;
    int r = n+1;
    int ans = -1;
    while(l<r) {
        int mid = (l + r)/2;
        if(dePaye(mid,m,d,a, ExamDaysMap)){
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main()  {
    int n, m;
    cin >> n >> m;
    int *d = new int[n+1];
    int *a = new int[m+1];
    For(d,n);
    For(a,m);
    cout<<Exam(n, m, d, a);
    
    return 0;
}