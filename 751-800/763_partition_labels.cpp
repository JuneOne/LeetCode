/*
 * @see https://leetcode.com/problems/partition-labels
 * 
 * 拆分成尽可能多的块，相同的字母在同一个块
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.size() == 0) {
            return {};
        }
        vector<int> pos(26, 0), lens;
        for (int i = 0; i < S.size(); i++) {
            pos[S[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for (int i = 0; i < S.size(); i++) {
            end = max(end, pos[S[i] - 'a']);
            if (i == end) {
                lens.push_back(end - start + 1);
                // start = end = i + 1;
                start = end + 1;
            }
        }
        return lens;
    }
};

int main()
{
    string str = "ababcbacadefegdehijhklij";
    Solution s;
    vector<int> lens = s.partitionLabels(str);
    for (auto& len: lens) {
        cout << len << ' ';
    }
    cout << endl;

    return 0;
}
