/*
 * @see https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * 最长连续不重复子串长
 * Input: s = "abcabcbb"
 * Output: 3
 *
 * Note: 滑动窗口；用数组做 HashMap
 */

#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max_len = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
        	if (map.find(s[i]) != map.end()) {
        		j = max(j, map[s[i]] + 1); // 窗口左右界只能往前走，不能回退
        	}
        	max_len = max(max_len, i - j + 1);
        	map[s[i]] = i;
        }
        return max_len;
    }

    /*
    int lengthOfLongestSubstring(string s) {
        int hash_map[256] = {}; 
        int max_len = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
        	if (hash_map[s[i]]) {
        		j = max(j, hash_map[s[i]]); // 注意 hash_map 里记的是 index+1
        	}
        	max_len = max(max_len, i - j + 1);
        	hash_map[s[i]] = i + 1; // 由于要用 0 表示该字符没出现，则记录 index+1
        }
        return max_len;
    }
    */
};

int main()
{
	string s = "abcabcbb";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));
}

