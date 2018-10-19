Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max1=0,chunk=0;
        for(int i=0;i<arr.size();++i)
        {
            max1=std::max(max1,arr[i]);
            if(max1==i)chunk++;
        }
        return chunk;
    }
};