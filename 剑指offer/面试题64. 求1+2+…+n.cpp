class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));//短路特性
        return n;
    }
};
