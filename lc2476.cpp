class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        inorder(root, nums);

        vector<vector<int>> ans;
        int n=queries.size();
        for (int i=0;i<n;i++) {
            int x=queries[i];
            auto it = lower_bound(nums.begin(), nums.end(), x);

            int low = -1;
            int high = -1;

            if(it!=nums.end()){
                high=*it;
            }
            else{
                high=-1;
            }
            if(it!=nums.end() && *it==x){
                low=x;
            }
            else if(it!=nums.begin()){
                it--;
                low=*it;
            }
            else{
                low=-1;
            }
            ans.push_back({low, high});
        }

        return ans;
    }
};