#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int H, W;
vector<string> grid;
bool used[500][500];

// Всі 4 напрями
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


// Повертає фігуру у вигляді канонічного рядка
string normalize(vector<pair<int,int> > fig)
{
    vector< vector<pair<int,int> > > variants;

    for (int rot = 0; rot < 4; rot++)
    {
        vector<pair<int,int> > v;
        for (int i = 0; i < (int)fig.size(); i++)
        {
            int x = fig[i].first;
            int y = fig[i].second;

            int nx, ny;

            if (rot == 0)      { nx = x; ny = y; }
            else if (rot == 1) { nx = y; ny = -x; }
            else if (rot == 2) { nx = -x; ny = -y; }
            else               { nx = -y; ny = x; }

            v.push_back(make_pair(nx, ny));
        }

        // Зсув у (0,0)
        int minx = v[0].first, miny = v[0].second;
        for (int i = 1; i < (int)v.size(); i++) {
            if (v[i].first < minx) minx = v[i].first;
            if (v[i].second < miny) miny = v[i].second;
        }
        for (int i = 0; i < (int)v.size(); i++) {
            v[i].first -= minx;
            v[i].second -= miny;
        }

        sort(v.begin(), v.end());
        variants.push_back(v);
    }

    // Вибрати лексикографічно мінімальний варіант
    sort(variants.begin(), variants.end());

    // Перетворити в рядок
    string s;
    for (int i = 0; i < (int)variants[0].size(); i++) {
        s += "(" + to_string(variants[0][i].first)
           + "," + to_string(variants[0][i].second) + ")";
    }

    return s;
}


// BFS – знаходить фігуру
vector<pair<int,int> > bfs(int sx, int sy)
{
    queue<pair<int,int> > q;
    vector<pair<int,int> > fig;

    used[sx][sy] = true;
    q.push(make_pair(sx, sy));
    fig.push_back(make_pair(sx, sy));

    while (!q.empty())
    {
        pair<int,int> p = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = p.first + dx[k];
            int ny = p.second + dy[k];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W &&
                !used[nx][ny] && grid[nx][ny] == '#')
            {
                used[nx][ny] = true;
                q.push(make_pair(nx, ny));
                fig.push_back(make_pair(nx, ny));
            }
        }
    }

    return fig;
}


int main()
{
    ifstream fin("input.txt");
    fin >> H >> W;

    grid.resize(H);
    for (int i = 0; i < H; i++)
        fin >> grid[i];
    fin.close();

    multiset<string> shapes;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (grid[i][j] == '#' && !used[i][j])
            {
                vector<pair<int,int> > fig = bfs(i, j);

                // Нормалізувати фігуру
                // Спочатку перенесемо точки відносно (0,0)
                int minx = fig[0].first, miny = fig[0].second;
                for (int t = 1; t < (int)fig.size(); t++) {
                    if (fig[t].first < minx) minx = fig[t].first;
                    if (fig[t].second < miny) miny = fig[t].second;
                }
                for (int t = 0; t < (int)fig.size(); t++) {
                    fig[t].first -= minx;
                    fig[t].second -= miny;
                }

                string canon = normalize(fig);
                shapes.insert(canon);
            }

    cout << "Кількість фігур: " << shapes.size() << endl;

    // Кількість унікальних фігур (враховуючи повороти)
    set<string> unique(shapes.begin(), shapes.end());
    cout << "Кількість різних фігур: " << unique.size() << endl;

    return 0;
}
