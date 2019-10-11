/*
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
*/
 class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int small=INT_MAX;
        int big=INT_MAX;
        
        
        for(auto u:nums){
            
            if(u<=small)
                small=u;
            else if(u<=big)
                big=u;
            else
                return true;
        }
        return false;
    }
};
