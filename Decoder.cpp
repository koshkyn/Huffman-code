#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

class Decoder {
public:
    void AddDigit(char c, const string& code) {
        decoded_digits[code] = c;
    }
    string Decode(const string& decode_str, const int& l) {
        if(l == 1) {
            return {decoded_digits[decode_str]};
        }
        string result;
        stringstream ss;
        ss << decode_str;
        string codestr;
        for(int i = 0; i < l; ++i) {
            char temp;
            ss >> temp;
            codestr += temp;
            if (decoded_digits.find(codestr) != decoded_digits.end()) {
                result += decoded_digits[codestr];
                codestr.erase();
            }
        }

        return result;
    }
private:
    unordered_map<string, char> decoded_digits;
};
int main() {
    int q = 0, l = 0;
    cin >> q >> l;
    Decoder decdr;
    for(int i = 0; i < q; ++i) {
        string charset, code;
        cin >> charset >> code;
        decdr.AddDigit(charset[0], code);
    }
    string decode_this;
    cin >> decode_this;
    cout << decdr.Decode(decode_this, l) << endl;
    system("pause");
    return 0;
}
