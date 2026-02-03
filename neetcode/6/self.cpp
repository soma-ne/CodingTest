#include <vector>
#include <string>

class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
            std::string encoded = "";

            for (auto& str : strs) {
                    encoded = encoded + std::to_string(str.size()) + ",";
            }

            encoded = encoded + ";";

            for (auto& str: strs) {
                    encoded = encoded + str;
            }

            return encoded;
    }

    std::vector<std::string> decode(std::string s) {
            std::vector<int> len;
            std::vector<std::string> strs;

            int i = 0;
            while (s[i] != ';') {
                    int j = 0;
                    std::string num_s = "";
                    while (s[i + j] != ',') {
                            num_s = num_s + s[i + j];
                            j++;
                    }
                    len.push_back(std::stoi(num_s));
                    i += j + 1;
            }

            i++;

            for (auto& k : len) {
                    std::string str = "";
                    for (int l=0;l<k;l++) {
                            str = str + s[i + l];
                    }
                    strs.push_back(str);
                    i += k;
            }

            return strs;
    }
};


int main()
{
}
