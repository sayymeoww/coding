int from, to, a;
string d = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", s, b, answer;

cin >> from >> to;
cin >> s;

if (s == "0") {
    cout << '0';
    return 0;
}

while (s != "0") {
    for (int z = 0; z < s.length();) {
        while (z < s.length() && a < to) {
            a = a * from + d.find(s[z]);
            z++;
            if (b.length() > 0 && a < to && z < s.length()) b = b + '0';
        }
        b = b + d[a / to];
        a %= to;
    }

    answer = d[a] + answer;

    s = b;
    b = "";
    a = 0;
}

cout << answer << '\n';