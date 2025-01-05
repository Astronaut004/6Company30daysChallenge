/*
Question OverView


You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle. Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

Note that an integer point is a point that has integer coordinates.

Implement the Solution class:

Solution(int[][] rects) Initializes the object with the given rectangles rects.
int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.
Input
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
Output
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

Explanation
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]
 
*/

class Solution {
public:
    vector<vector<int>>& rects;
    Solution(vector<vector<int>>& rects) : rects(rects) {}

    // wallah we used Reservoi Sampling


    vector<int> pick() {
        int sum_area = 0;
        //choosen will be here
        vector<int>selected;

        for(auto r : rects) {
            // calculate the width and height of rectangle
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            // total area of given rectangles
            sum_area += area;
            // if random number which is 0 to sum_area - 1 and if it is less then area
            // store this rectangle in seleced vector;
            if(rand() % sum_area < area) selected = r;
        }

        // use selected rectaglge to generate the random points
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        return { x, y };
    }
};

TC: O(n), SC: O(n)