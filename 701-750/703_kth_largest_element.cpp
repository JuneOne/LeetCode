/*
 * @see https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * 
 * 输出第K大的数
 * Input: 
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * Output: [null, 4, 5, 5, 8, 8]
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 * It is guaranteed that there will be at least k elements in the array.
 */
class KthLargest {
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> _small;

public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto& num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        _small.push(val);
        if (_small.size() > _k) {
            _small.pop();
        }
        return _small.top();
    }
};

int main()
{
    vector<int> nums = {4,5,8,2};
    KthLargest* obj = new KthLargest(3, nums);
    for (auto& val : {3,5,10,9,4}) {
        cout << obj->add(val) << ' ';
    }
    cout << endl;
    return 0;
}
