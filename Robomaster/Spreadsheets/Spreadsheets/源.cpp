#include <iostream>
#include <string>
#include <cctype>    
#include <algorithm> 
using namespace std;
string toLetters(int col) {
    string result;
    while (col > 0) {
        int rem = (col - 1) % 26;      
        char letter = char('A' + rem); 
        result.push_back(letter);
        col = (col - 1) / 26;          
    }
    reverse(result.begin(), result.end());
    return result;
}
int toNumber(const string &letters) {
    int value = 0;
    for (char ch : letters) {
        int digit = ch - 'A' + 1;      
        value = value * 26 + digit;    
    }
    return value;
}

int main() {
    int n;
    cin >> n;          

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;     

       
        bool isR1C1 = false;
        size_t posC = string::npos;
        if (!s.empty() && s[0] == 'R') {
            posC = s.find('C');
            if (posC != string::npos) {
                bool digitsBetween = (posC > 1); 
                for (size_t j = 1; j < posC; ++j) {
                    if (!isdigit(static_cast<unsigned char>(s[j]))) {
                        digitsBetween = false;
                        break;
                    }
                }
                bool digitsAfter = (posC + 1 < s.size()); 
                for (size_t j = posC + 1; j < s.size(); ++j) {
                    if (!isdigit(static_cast<unsigned char>(s[j]))) {
                        digitsAfter = false;
                        break;
                    }
                }
                isR1C1 = digitsBetween && digitsAfter;
            }
        }

        if (isR1C1) {
            int row = stoi(s.substr(1, posC - 1));    
            int col = stoi(s.substr(posC + 1));       
            string letters = toLetters(col);          
            cout << letters << row << "\n";         
        } else {
            size_t idx = 0;
            while (idx < s.size() && isalpha(static_cast<unsigned char>(s[idx]))) {
                ++idx;         
            }
            string letters = s.substr(0, idx);       
            int row = stoi(s.substr(idx));            
            int col = toNumber(letters);             
            cout << "R" << row << "C" << col << "\n";
        }
    }
    return 0;
}