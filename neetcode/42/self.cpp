#include <list>
#include <vector>

class LRUCache {
	int max;
	int size = 0;
	std::list<std::pair<int,int>> ls;
	std::vector<std::list<std::pair<int,int>>::iterator> vec;
public:
    LRUCache(int capacity) : ls(), max(capacity), vec(1001, ls.end())
	{
    }

    int get(int key)
	{
		if (vec[key] == ls.end())
			return -1;

		auto it = vec[key];
		int value = it->second;
		ls.erase(it);
		ls.push_front(std::pair<int,int>(key,value));
		vec[key] = ls.begin();
		return value;
    }

    void put(int key, int value)
	{
		if (vec[key] == ls.end()) {
			if (size < max) {
				size++;
			} else {
				auto it = std::prev(ls.end());
				vec[it->first] = ls.end();
				ls.erase(it);
			}
			ls.push_front(std::pair<int,int>(key,value));
			vec[key] = ls.begin();
		} else {
			ls.erase(vec[key]);
			ls.push_front(std::pair<int,int>(key, value));
			vec[key] = ls.begin();
		}
    }
};
