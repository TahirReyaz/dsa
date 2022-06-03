// 4/5/2022

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

// Hint 2: Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line. This way we are compromising on the width but we are looking forward to a longer length container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1, maxWater=0;
        while(start < end) {
            int shorterLine = min(height[start], height[end]);
            maxWater = max(shorterLine * (end - start), maxWater);
            
			int flag = 1, flag2 = 1;
            for(int i = start + 1; i < end; i++) {
                if(shorterLine < height[i] && height[start] == shorterLine) {
					start = i;  
					flag = 0; 
                    flag2 = 0;
                    break;
                }
            }
			if(flag) {
				for(int i = end - 1; i > start; i--) {
					if(shorterLine < height[i] && height[end] == shorterLine) {
						end = i; 
                        flag2 = 0;
                        break;
					}
				}
			}
            if(flag2) {
                return maxWater;
            }

            if(start == end - 1) {
				shorterLine = min(height[start], height[end]);
				maxWater = max(shorterLine * (end - start), maxWater);

				return maxWater;
            }
        }
        return maxWater;
    }   
};

// This solution passed 54/ 60 test cases and failed because Time limit exceeded