int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums)
        if (top3.insert(num).second && top3.size() > 3)
            top3.erase(top3.begin());
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}
