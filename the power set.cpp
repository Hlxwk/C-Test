class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        res.push_back(tmp);
        int n=nums.size();
        find_set(res,tmp,n,0,nums);
        return res;
    }
    void find_set(vector<vector<int> >& res,vector<int>& tmp,int n,int pos,vector<int>& nums)
    {
        if(pos>=n)return;
        for(int i=pos;i<n;i++)
        {
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            find_set(res,tmp,n,i+1,nums);
            tmp.pop_back();
        }
    }
};