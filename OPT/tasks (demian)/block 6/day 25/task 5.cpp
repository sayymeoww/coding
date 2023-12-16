const int maxn = 310000;
char t[maxn];

int n;
cin >> n;

vector<int> v;
for (int i = 0; i < n; i++) {
    scanf("%s", t);
    v.push_back(strlen(t));
}

sort(v);

int ptr = 0, cnt = 0;
string res = "";
for (int i = 1; ptr < n || cnt; i++) {
    while (ptr < n && v[ptr] == i) {
        ptr++;
        cnt++;
    }
    if (cnt > 0) {
        res += '1';
        cnt--;
    } else {
        res += '0';
    }
}

reverse(res.begin(), res.end());
printf("%s\n", res.c_str());