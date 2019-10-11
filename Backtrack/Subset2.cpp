class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> tempList;
        vector<int> list;
       sort(nums.begin(),nums.end());
        generateSubset(tempList,list,nums,0);
        
        return tempList;
        
        
    }
    
    
    
    void generateSubset(vector<vector<int>> &tempList,vector<int> list,vector<int> nums,int start)
            
    {
        if(list.size()>=0)
        {
            tempList.push_back(list);
        }
        unordered_set<int> visited;
        for(int i=start;i<nums.size();i++)
        {
            if(visited.find(nums[i])!=visited.end())
                continue;
            visited.insert(nums[i]);
           
            list.push_back(nums[i]);
            generateSubset(tempList,list,nums,i+1);
            list.pop_back();
            
        }
        
        
    
    }
};
