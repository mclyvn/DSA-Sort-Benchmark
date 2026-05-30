#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 2147483647;
const int MIN = -2147483648;

mt19937 rng(1337); 

int getRandomInt(int min_val, int max_val) {
    uniform_int_distribution<int> dist(min_val, max_val);
    return dist(rng);
}

char getRandomChar() {
    return (char)('a' + getRandomInt(0, 25));
}

void genProblemA(int test_id) {
    int n = 100000;
    cout << n << "\n";
    
    if (test_id == 1) {
        // Bộ test ngẫu nhiên
        for (int i = 0; i < n; ++i) cout << getRandomInt(MIN, MAX) << "\n";
    } 
    else if (test_id == 2) {
        // Bộ test tăng dần
        for (int i = 0; i < n; ++i) cout << MIN + i << "\n";
    } 
    else if (test_id == 3) {
        // Bộ test giảm dần
        for (int i = 0; i < n; ++i) cout << MAX - i << "\n";
    } 
    else if (test_id == 4) {
        // Bộ test trùng lặp
        for (int i = 0; i < n; ++i) cout << MIN << "\n";
    } 
    else if (test_id == 5) {
        // Bộ test dao động
        for (int i = 0; i < n; ++i) {
            cout << ((i % 2 == 0) ? MIN : MAX) << "\n";
        }
    }
}

//Bài B
void genProblemB(int test_id) {
    int n = 100000;
    cout << n << "\n";

    if (test_id == 1) {
        for (int i = 0; i < n; ++i) {
            string s = "";
            for(int j = 0; j < 100; ++j) s += getRandomChar();
            cout << s << "\n";
        }
    } 
    else if (test_id == 2) {
        string prefix(99, 'a'); 
        for (int i = 0; i < n; ++i) {
            char last_char = 'z' - (i % 26); 
            cout << prefix << last_char << "\n";
        }
    }
    else if (test_id == 3) {
        vector<string> a(n);
        string prefix = "";
        for(int j = 0; j < 99; ++j) prefix += getRandomChar(); 
        
        for (int i = 0; i < n; ++i) {
            a[i] = prefix + getRandomChar(); 
        }
        shuffle(a.begin(), a.end(), rng);
        for (int i = 0; i < n; ++i) cout << a[i] << "\n";
    } 
    else if (test_id == 4) {
        for (int i = 0; i < n; ++i) {
            int len = getRandomInt(0, 1) ? 100 : getRandomInt(10, 15);
            string s = "";
            for(int j = 0; j < len; ++j) s += getRandomChar();
            cout << s << "\n";
        }
    } 
    else if (test_id == 5) {
        string s(100, 'x');
        for (int i = 0; i < n; ++i) cout << s << "\n";
    }
}

// Bai C
void genProblemC(int test_id) {
    int n = 10000;
    cout << n << "\n";

    if (test_id == 1) {
        string prefix(99, 'a');
        for (int i = 0; i < n; ++i) {
            cout << prefix << getRandomChar() << "\n";
        }
    } 
    else if (test_id == 2) {
        vector<string> a(n);
        string prefix(50, 'b');
        for (int i = 0; i < n; ++i) {
            string s = prefix;
            for(int j = 0; j < 50; ++j) s += getRandomChar();
            a[i] = s;
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < n; ++i) cout << a[i] << "\n";
    }
    else if (test_id == 3) {
        string s(100, 'z');
        for (int i = 0; i < n; ++i) cout << s << "\n";
    } 
    else if (test_id == 4) {
        string prefix = "aaaaaaaaaa";
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                cout << prefix << "\n"; 
            } else {
                string s = prefix;
                for(int j = 0; j < 90; ++j) s += getRandomChar();
                cout << s << "\n";
            }
        }
    } 
    else if (test_id == 5) {
        for (int i = 0; i < n; ++i) {
            int len = getRandomInt(10, 100);
            string s = "";
            for(int j = 0; j < len; ++j) s += getRandomChar();
            cout << s << "\n";
        }
    }
}


int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (argc < 3) {
        cerr << "Cu phap hop le: " << argv[0] << " <int|strlexi|strlenlexi> <1|2|3|4|5>\n";
        return 1;
    }

    string problem = argv[1];
    int test_id = stoi(argv[2]);

    if (test_id < 1 || test_id > 5) {
        cerr << "Loi: So thu tu test case phai nam trong khoang [1, 5].\n";
        return 1;
    }

    if (problem == "int") {
        genProblemA(test_id);
    } 
    else if (problem == "strlexi") {
        genProblemB(test_id);
    } 
    else if (problem == "strlenlexi") {
        genProblemC(test_id);
    } 
    else {
        cerr << "Loi: Ten bai toan khong hop le! Vui long chon: int, strlexi, hoac strlenlexi\n";
        return 1;
    }
    return 0;
}