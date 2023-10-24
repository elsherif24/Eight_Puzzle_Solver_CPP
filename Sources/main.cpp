#include <iostream>
#include <random>
#include <vector>
#include "../Headers/BFS.h"
#include "../Headers/DFS.h"
#include "../Headers/AStarMan.h"
#include "../Headers/AStarEuc.h"

using namespace std;
void print(vector<vector<int>>& ref) {
    for (auto tt : ref) {
        int inx{};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << tt[inx++] << ' ';
            }
            cout << '\n';
        }
        cout << "======\n";
    }
}
vector<vector<int>> convertTo2d(vector<int>& grid) {
    vector<vector<int>> grid2d;
    int inx{};
    for (int i = 0; i < 3; ++i) {
        vector<int> temp;
        for (int j = 0; j < 3; ++j) {
            temp.push_back(grid[inx++]);
        }
        grid2d.push_back(temp);
    }
    return grid2d;
}

void gen(vector<int> grid) {

    vector<int> goalGrid({1,2,5,3,4,0,6,7,8});

    vector<vector<int>> grid2d(convertTo2d(grid));
    vector<vector<int>> goalGrid2d(convertTo2d(goalGrid));
    size_t manhattanDistance = 0;
    for (int nm = 1; nm <= 8; ++nm) {
        int cellX{}, cellY{}, goalX{}, goalY{};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j <3; ++j) {
                if (grid2d[i][j] == nm) {
                    cellX = i;
                    cellY = j;
                }
                if (goalGrid2d[i][j] == nm) {
                    goalX = i;
                    goalY = j;
                }
            }
        }
        manhattanDistance += abs(cellX - goalX) + abs(cellY - goalY);
    }
    cout << manhattanDistance;
}
int main() {
    vector<int> grid({0, 1, 8,2 ,7, 3,6, 4, 5});
    AStarEuc x = AStarEuc(grid);
    try {
        x.search();
        cout << "Steps:" << '\n';
        print(x.path);
        cout << "cost = " << x.costOfPath << '\n';
        cout << "search depth = " << x.maxDepthSearch << '\n';
        cout << "Running time = " << x.runningTime << " ms\n";
        cout << "Nodes expanded = " << x.nodesExpanded << '\n';
    } catch(exception& e) {
        cout << "No Solution\n";
        cout << "search depth = " << x.maxDepthSearch << '\n';
        cout << "Nodes expanded = " << x.nodesExpanded << '\n';
        cout << "Running time = " << x.runningTime << " ms\n";
    }



    return 0;
}