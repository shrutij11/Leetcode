// 993. Cousins in Binary Tree

// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.



// The level-order traversal is the most time-efficient solution for this problem since we only go as deep as the first potential cousin. The memory complexity is O(n/2) to accommodate the longest level, vs. O(h) for recursive solutions, where h is the height of the tree (could be n in the worst case).

// We use queue q to iterate through the current level nodes and populate their children into q1. We also insert nullptr into q1 after inserting each node's children (to separate siblings froum cousins).

// If we find a node with value x or y, we have one potential cousin. If we find another potential cousin, we return true if they are not siblings (nullptr sets siblings to false). If we finished the level with just one potential cousin, we stop and return false.

bool isCousins(TreeNode* root, int x, int y, bool siblings = false, bool cousin = false) {
  queue<TreeNode*> q, q1;
  q.push(root);
  while (!q.empty() && !cousin) {
    while (!q.empty()) {
      auto n = q.front();
      q.pop();
      if (n == nullptr) siblings = false;
      else {
        if (n->val == x || n->val == y) {
          if (!cousin) cousin = siblings = true;
          else return !siblings;
        }
        q1.push(n->left), q1.push(n->right), q1.push(nullptr);
      }
    }
    swap(q, q1);
  }
  return false;
}
