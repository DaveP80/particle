#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
// You are given a list of bombs. The range of a bomb is defined as the area where 
// its effect can be felt. This area is in the shape of a circle with the center as 
// the location of the bomb.

// The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = 
// [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of 
// the ith bomb, whereas ri denotes the radius of its range.

// You may choose to detonate a single bomb. When a bomb is detonated, it will detonate 
// all bombs that lie in its range. These bombs will further detonate the bombs that 
// lie in their ranges.

// Given the list of bombs, return the maximum number of bombs that can be detonated if 
// you are allowed to detonate only one bomb.

class Solution
{
public:
    int maximumDetonation(std::vector<std::vector<int>> &bombs)
    {
        std::unordered_map<int, std::vector<int>> adj;

        for (int i = 0; i < bombs.size(); ++i)
        {
            for (int j = i + 1; j < bombs.size(); ++j)
            {
                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                double d = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));

                if (d <= r1)
                {
                    adj[i].push_back(j);
                }
                if (d <= r2)
                {
                    adj[j].push_back(i);
                }
            }
        }

        int res = 0;

        for (int i = 0; i < bombs.size(); ++i)
        {
            res = std::max(res, dfs(i, adj));
        }

        return res;
    }

private:
    int dfs(int i, std::unordered_map<int, std::vector<int>> &adj)
    {
        std::unordered_set<int> visit;

        return dfsHelper(i, visit, adj);
    }

    int dfsHelper(int i, std::unordered_set<int> &visit, std::unordered_map<int, std::vector<int>> &adj)
    {
        for (const auto &item : visit)
        {
            std::cout << item << std::endl;
        }
        if (visit.find(i) != visit.end())
        {
            return 0;
        }

        visit.insert(i);

        int len = visit.size();

        for (int nei : adj[i])
        {
            len = std::max(len, dfsHelper(nei, visit, adj));
        }

        return len;
    }
};

int main()
{
    Solution solution;

    std::vector<std::vector<int>> bombs = {
        {2, 1, 3},
        {4, 1, 1},
        {6, 3, 6},
        {8, 2, 5},
        {9, 3, 2}
        // Add more bomb coordinates and radii as needed
    };

    int result = solution.maximumDetonation(bombs);
    std::cout << "Maximum Detonation: " << result << std::endl;

    return 0;
    //Maxiumum Detonation: 5
}