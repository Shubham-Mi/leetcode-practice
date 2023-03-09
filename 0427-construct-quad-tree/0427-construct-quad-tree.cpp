/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int row, int col, int len) {
        if (len == 1) return new Node(grid[row][col], true);
        Node* topLeft = construct(grid, row, col, len / 2);
        Node* topRight = construct(grid, row, col + len / 2, len / 2);
        Node* bottomLeft = construct(grid, row + len / 2, col, len / 2);
        Node* bottomRight = construct(grid, row + len / 2, col + len / 2, len / 2);
        if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf && topLeft -> val == topRight -> val && topLeft -> val == bottomLeft -> val && topLeft -> val == bottomRight -> val) {
            return new Node(topLeft -> val, true);
        }
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};