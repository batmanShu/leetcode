class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = list()
        for i in range(0, numRows):
            row = list()
            for j in range(0, i+1):
                if j == 0 or i == j:
                    row.append(1)
                else:
                    row.append(ret[i-1][j-1]+ret[i-1][j])
            ret.append(row)
        return ret
