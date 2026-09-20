class Solution {
public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int left, int right) {

        // No elements left
        if (left > right) {
            return nullptr;
        }

        // Find middle
        int mid = left + (right - left) / 2;

        // Middle element becomes root
        TreeNode* root = new TreeNode(nums[mid]);

        // Build left subtree
        root->left = build(nums, left, mid - 1);

        // Build right subtree
        root->right = build(nums, mid + 1, right);

        return root;
    }
};
