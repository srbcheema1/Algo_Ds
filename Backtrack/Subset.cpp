class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     
        vector<vector<int>> templist;
        vector<int> list;
        generatesubset(templist,list,nums,0);
        
        return templist;
        
        
    }
    
    
    void generatesubset(vector<vector<int>> &templist,vector<int> temp,vector<int> &nums,int index)
    {
        
        if(temp.size()>=0)
        {
            templist.push_back(temp);
        }
        
        for(int i=index;i<nums.size();i++)
        {
            
            temp.push_back(nums[i]);
            generatesubset(templist,temp,nums,i+1);
            temp.pop_back();
            
        }
        
        
    }
    
    
    

};
