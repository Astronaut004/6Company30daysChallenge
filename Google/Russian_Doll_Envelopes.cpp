/*
Question overview


You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/


/*
Approach if where we use simple sorting and comparision


WRONG

NOT calculating all values
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        int first = nums[0][0];
        int second = nums[0][1];
        for(int i=1; i<n; i++) {
            if(first < nums[i][0] && second < nums[i][1]) {
                count++;
                first = nums[i][0];
                second = nums[i][1];
            }
        }
        return count+1;
    }
};
*/



/*
    use dp with sorting 

    class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        // sort the array in ascending order for better check and overlapping
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            // just checking over the array 
            cout<<nums[i][0]<<"   "<<nums[i][1]<<endl;
        }
        // minimum russian doll envelop
        int max = 1;
        vector<int>dp(n+1,1); // initialise a dp/vector which tells that
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {

                // check how many envelops can fit
                if(nums[i][0] > nums[j][0] // first element of current and previous row
                && nums[i][1] > nums[j][1] // second element of current and previous row
                && 1 + dp[j] > dp[i]){     // if all conditions are true check if curr envelop can be merge and previous merging value is less.
                    dp[i] = 1 + dp[j];
                    // update current;
                }
                if(max < dp[i]) {
                    max = dp[i]; // update the maximum;
                }
            }
        }
        return max; // return maximum
    }
};

TLE on large cases
*/


/*
Optimal solution
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        
        // sort the array if num[i][0] == nums[i+1][0] push greater height first else push greater width
        sort(nums.begin(), nums.end(), [](const vector<int>&a,const vector<int>&b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int>h;
        // store only height becuz it has condition for width they are either equal or in ascending order;
        for(int i=0; i<nums.size(); i++) {
            h.push_back(nums[i][1]);
        }

        vector<int>longy;
        // check for all possible values in longy vector
        for(auto i : h) {

            //first first element greater than or equal to i in longy
            auto it = lower_bound(longy.begin(),longy.end(),i);

            if(it == longy.end()) longy.push_back(i);  //if not push at back
            else *it = i; //replace first element which is greater or equal to i in longy
        }

        return longy.size(); //calculate total envelop we pushed
    }
};

// TC: O(nlogn) , SC: O(n);
