/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start

/*
The idea is to find a way to arrange these tasks, and use as less idle intervals as possible.

By observing a few test cases, we know that it's a lot easier to start from the task with the highest frequency of occurrence. Let's say the task is A.
Then we can put all A tasks into the array, and make sure they are separated by n idle inervals.
A____A____A____A____A____A

number of A = num(A)            // the number of task A
gap = (num(A) - 1) x n          // the number of idle intervals
total length = num(A) + gap     // the total length
Now we need to replace the idle intervals with other tasks. Similarily, we'd better start from tasks with the second highest frequency of occurrence. Let's say it's B, then
a) if num(B) < num(A) && num(B) < gap, we know that the total length will not be affected. We simply decrement the gap by num(B).
AB___AB___AB____A____A____A
b) if num(B) == num(A) && num(B) < gap, we need to decrement the gap by num(B) - 1, and also increment total length by 1.
AB___AB___AB___AB___AB___AB
c) If we run out of gap, it is great, because this case is even easier to handle. It means we don't need any idle intervals at all. Simply return the length of all tasks, and we are done. Why? Let's say We have all gaps filled, we have an array like this:
ABCDABCDABCDABCDABCD
Now we need to insert task E, we can change the filled gaps a little bit, make extra spaces for task E, the number of changed gaps depends on how many E we have, then the array looks like:
ABCD_ABCD_ABCDABCDABCD
With E inserted:
ABCDEABCDEABCDABCDABCD
If E repeats as many times as A, the array will look like:
ABCDEABCDEABCDEABCDEABCDE
We can always find a way to arrange them without introducing idle intervals.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mp[26]={0};
        for(char ch: tasks) {
            mp[ch-'A']++;
        }
        sort(mp, mp+26, [&](int a, int b) {
            return a>b;
        });
        int gap = (mp[0]-1)*n;
        int total_len = gap + mp[0];
        for(int i=1;i<26;i++) {
            if(mp[i]==0) break;
            if(gap >= mp[i]) {
                if(mp[i] == mp[0]) {
                    total_len++;
                    gap-=(mp[0]-1);
                } else {
                    gap-=mp[i];
                }
            } else {
                return tasks.size();
            }
        }
        return total_len;
    }
};
// @lc code=end

