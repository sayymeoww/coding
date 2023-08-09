int r, g, b;
cin >> r >> g >> b;

cout << ((abs(r - g) <= 25 && abs(r - b) <= 25 && abs(g - b) <= 25)
             ? "ALLOWED"
             : "FORBIDDEN")
     << '\n';