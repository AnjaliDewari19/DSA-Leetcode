class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int startX = -1, startY = -1;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int numLitter = litter.size();
        int fullMask = (1 << numLitter) - 1;

        auto getLitterIndex = [&](int r, int c) {
            for (int k = 0; k < numLitter; ++k) {
                if (litter[k].first == r && litter[k].second == c) return k;
            }
            return -1;
        };

        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << numLitter, -1)));
        queue<vector<int>> q;

        int initialMask = 0;
        int idx = getLitterIndex(startX, startY);
        if (idx != -1) initialMask |= (1 << idx);

        q.push({startX, startY, initialMask, energy, 0});
        bestEnergy[startX][startY][initialMask] = energy;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr[0], c = curr[1], mask = curr[2], e = curr[3], steps = curr[4];

            if (mask == fullMask) return steps;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int ne = e - 1;
                    if (ne < 0) continue;

                    int nmask = mask;
                    if (classroom[nr][nc] == 'L') {
                        int lIdx = getLitterIndex(nr, nc);
                        if (lIdx != -1) nmask |= (1 << lIdx);
                    } else if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (ne > bestEnergy[nr][nc][nmask]) {
                        bestEnergy[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};