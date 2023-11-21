#pragma region libs

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// ? other libs

using namespace std;
using path = string;

#pragma endregion libs

#pragma region class
class Generator {
   public:
    path i1 = "TEST/tester/in/in 1.txt", i2 = "TEST/tester/in/in 2.txt",
         i3 = "TEST/tester/in/in 3.txt", i4 = "TEST/tester/in/in 4.txt";
    path o1 = "TEST/tester/out/out 1.txt", o2 = "TEST/tester/out/out 2.txt",
         o3 = "TEST/tester/out/out 3.txt", o4 = "TEST/tester/out/out 4.txt";

    vector<path> cin = {i1, i2, i3, i4};
    vector<path> cout = {o1, o2, o3, o4};

    void make(int t);
};
#pragma endregion class

inline void test(ofstream& in, ofstream& out, int t) {
    cout << "Input "
         << "(" << t << "): " << '\n';
    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
}

#pragma region make
inline void Generator::make(int t) {
    fstream f("TEST/tests.txt");

    int _n;
    f >> _n;
    const size_t n = _n;

    vector<ofstream> in;
    in.reserve(n);
    for (size_t i = 0; i < n; i++) in.push_back(ofstream(cin[i], ios::out));

    vector<ofstream> out;
    out.reserve(n);
    for (size_t i = 0; i < n; i++) out.push_back(ofstream(cout[i], ios::out));

    for (int i = 0; i < t; i++) test(in[i], out[i], i + 1);
}
#pragma endregion make

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    cout << "Еnter your input test data here!" << '\n';

    Generator gen;
    gen.make(t);

    cout.flush();
    return 0;
}