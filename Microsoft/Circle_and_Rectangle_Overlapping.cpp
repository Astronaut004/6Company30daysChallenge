#include<bits/stdc++.h>
// Question OverView
/*
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

Example

Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).

Example 2:

Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false

Example 3:

Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

Constraints:

1 <= radius <= 2000
-104 <= xCenter, yCenter <= 104
-104 <= x1 < x2 <= 104
-104 <= y1 < y2 <= 104

*/


/*It toook me 25 min*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // radius, xCenter, yCenter cirlce

        // x1, y1,  x2,  y2  rectangle

    //    first check the circle position 
    // left, right, top, bottom
    int loc1 = min(x2,xCenter); // if xCenter is greater circle is on right side but if smaller it is on left side
    int loc2 = min(y2, yCenter); // if yCenter is greater it is on top but if it is smaller it is on bottom side.

    int cX = max(x1,loc1); // if less than x1 it is outside and left to rectanlge
    int cY = max(y1,loc2); // same

    int collpasePoint = pow((cX - xCenter),2) + pow((cY - yCenter),2);
    if(collpasePoint > radius*radius) return false;
    return true;
    
    }
};