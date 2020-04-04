# LeetCode题目记录
主要看到[labuladong](https://github.com/labuladong/fucking-algorithm)关于算法这部分的介绍，根据上面给的建议对LeetCode进行刷；主要按照各大类别进行划分。

## Tree

labuladong总结的关于二叉树的模板（套路）：

```cpp
void traverse(TreeNode root) {
    // 前序遍历
    traverse(root.left)
    // 中序遍历
    traverse(root.right)
    // 后序遍历
}
```

