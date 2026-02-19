#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class TimeMap {
	std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> table;

public:
    TimeMap() {
    }

    void set(std::string key, std::string value, int timestamp) {
		table[key].emplace_back(timestamp, value);
    }

	std::string get(std::string key, int timestamp) {
		auto it = std::upper_bound(
				table[key].begin(), table[key].end(), timestamp,
				[](int t, const auto& p) {return t < p.first;});
		if (it == table[key].begin())
			return "";
		return (*--it).second;
    }
};

