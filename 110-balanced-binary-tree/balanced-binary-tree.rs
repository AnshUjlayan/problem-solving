// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn get_depth(node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let Some(node) = node else { return 0; };
        let node = node.borrow();

        let left_depth = Self::get_depth(node.left.clone());
        let right_depth = Self::get_depth(node.right.clone());

        if left_depth + right_depth > 1_000_000_000 ||
            (left_depth - right_depth).abs() > 1 {
            1_000_000_000
        } else {
            left_depth.max(right_depth) + 1
        }
    }

    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::get_depth(root) < 1_000_000_000
    }
}