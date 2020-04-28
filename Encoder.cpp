#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
#include <cstdlib>

using namespace std;

struct Item {
    string digits;
    int priority;

};

bool operator<(const Item& lhs, const Item& rhs) {
    return tie(lhs.priority, lhs.digits) > tie(rhs.priority, rhs.digits);
}

class Tree {
public:
    void Add(const string& dgts) {
        for(auto digit : dgts) {
            ++digits[{digit}];
        }
    }
    
    void CreateTree() {
        vector<Item> items;
        for(auto& d : digits) {
            items.push_back({d.first, d.second});
        }
 
        priority_queue<Item> sorted_digits(less<Item>(), items);
        string result;

        if(sorted_digits.size() == 1) {
            coded_digits[sorted_digits.top().digits[0]] = "0";
        }

        while(sorted_digits.size() > 1) {
            auto first = sorted_digits.top();
            sorted_digits.pop();
            auto second = sorted_digits.top();
            sorted_digits.pop();
            for(auto c : first.digits) {
                coded_digits[c] = "0" + coded_digits[c];
            }
            for(auto c : second.digits) {
                coded_digits[c] = "1" + coded_digits[c];
            }
            sorted_digits.push({first.digits + second.digits, first.priority + second.priority});
        }
    }
    
    void CodeString(const string& ins) {
        Add(ins);
        CreateTree();
        string result;
        for(auto c : ins) {
            result += coded_digits[c];
        }
        cout << coded_digits.size() << " " << result.size() << endl;
        for(auto a : coded_digits) {
            cout << a.first << ": " << a.second << endl;
        }
        cout << result << endl;
    }
    
private:
    unordered_map<string, int> digits;
    unordered_map<char, string> coded_digits;
};

int main() {
    string digits;
    cin >> digits;
    Tree w;
    w.CodeString(digits);
    cin.get();
    system("pause");
    return 0;
}
