string toBin(char c) {
    switch (c) {
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'A':
            return "1010";
        case 'B':
            return "1011";
        case 'C':
            return "1100";
        case 'D':
            return "1101";
        case 'E':
            return "1110";
        case 'F':
            return "1111";
    }
}

char toEight(string s) {
    if (s == "000") return '0';
    if (s == "001") return '1';
    if (s == "010") return '2';
    if (s == "011") return '3';
    if (s == "100") return '4';
    if (s == "101") return '5';
    if (s == "110") return '6';
    if (s == "111") return '7';
}

string zeros(string s) {
    if (s.length() % 3 == 0) return s;

    string z = "";
    for (int i = 0; i <= s.length() % 3; i++) z += '0';

    return z + s;
}

string f(string s) {
    string answer = "";
    for (auto c : s) answer += toBin(c);
    return answer;
}

string solve(string bin) {
    string answer = "";
    for (int i = 0; i <= bin.length() - 3; i += 3)
        answer += toEight(bin.substr(i, 3));
    return answer;
}

char d;
int l;
string s;

cin >> d >> l >> s;
string ans = solve(f(s));

int count = 0;
for (auto c : ans)
    if (c == d) count++;

cout << count << '\n';