#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
        std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> table;
        for (auto &i : nums) {
                table[i]++;
        }
        std::vector<std::pair<int,int>> vec;
        for (auto [key, value] : table) {
                vec.push_back({value, key});
        }
        std::sort(vec.rbegin(), vec.rend());

        std::vector<int> result;
        for (int i=0;i<k;i++) {
                result.push_back(vec[i].second);
        }

        return result;
    }
};

int main() {
        std::vector<int> nums = {7,7};
        Solution sol;
        for (auto& i: sol.topKFrequent(nums, 1)) {
                std::cout << i << " ";
        }
        std::cout << std::endl;
}
