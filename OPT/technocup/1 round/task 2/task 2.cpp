int n;
cin >> n;

map<string, int> times, is_dot;
vector<string> ans;

while (n--) {
    string file;
    cin >> file;

    times[file]++;
    if (times[file] != 1) {
        if (times[file] > 2) {
            if (is_dot[file] == -1) {
                file += '(' + to_string(times[file] - 1) + ')';
                ans.push_back(file);
            } else {
                string _file;
                int i = is_dot[file];

                for (int j = 0; j < i; j++) _file += file[j];
                _file += '(' + to_string(times[file] - 1) + ')';

                for (int j = i; j < file.size(); j++) _file += file[j];
                ans.push_back(_file);
            }
        }

        else {
            int i;
            bool flag = true;

            for (i = file.size() - 1; i >= 0; i--) {
                if (file[i] == '.') {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                is_dot[file] = -1;

                file += '(' + to_string(times[file] - 1) + ')';
                ans.push_back(file);
            } else {
                is_dot[file] = i;
                string _file;

                for (int j = 0; j < i; j++) _file += file[j];
                _file += '(' + to_string(times[file] - 1) + ')';

                for (int j = i; j < file.size(); j++) _file += file[j];
                ans.push_back(_file);
            }
        }

    } else {
        ans.push_back(file);
    }
}

sort(ans.begin(), ans.end());
for (auto &file : ans) cout << file << '\n';
