int x;
cin >> x;

int i = 1, j = 1, a = 1, b = 1;
int result = 0;

while (x) {
    if (a <= b) {
        x += (a == b);
        result = a;

        i += 1;
        a = i * i;
    } else {
        result = b;

        j += 1;
        b = j * j * j;
    }

    x--;
}

cout << result << '\n';