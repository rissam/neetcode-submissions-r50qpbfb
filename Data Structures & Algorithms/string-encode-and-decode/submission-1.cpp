class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string result;
        for(auto &str: strs) {
            result+= to_string(str.size()) + ",";
        }
        result += ";";
        for(auto &str: strs) {
            result+= str;
        }
        
        return result;
    }

    vector<string> decode(string s) {
        if(s.size() == 0) return {};
        vector<int> sizes;
        int sz = s.size();
        int substr_sz = 0;
        int i;
        for(i = 0; i < sz; i++) {
            char c = s[i];
            if(c == ';') {
                i++;
                break;
            }
            if(c == ',') {
                sizes.push_back(substr_sz);
                substr_sz = 0;
                continue;
            }
            substr_sz = (substr_sz*10) + (c - '0');
        }
        
        vector<string> result;
        for(int j = 0; j < sizes.size(); j++) {
            string sub = s.substr(i, sizes[j]);
            i+= sizes[j];
            result.push_back(sub);
        }
        return result;
    }
};
