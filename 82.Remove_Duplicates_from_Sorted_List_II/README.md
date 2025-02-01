## 82. Remove Duplicates from Sorted List II

Given the `head` of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

### Examples

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

- **Input:** `head = [1,2,3,3,4,4,5]`
- **Output:** `[1,2,5]`
- **Explanation:** The nodes with values `3` and `4` are duplicates, so they are removed. The resulting list is `[1,2,5]`.

**Example 2:**

![Example 2](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

- **Input:** `head = [1,1,1,2,3]`
- **Output:** `[2,3]`
- **Explanation:** The nodes with value `1` are duplicates, so they are removed. The resulting list is `[2,3]`.

### Constraints

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be sorted in ascending order.
