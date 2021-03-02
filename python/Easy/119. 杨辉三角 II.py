class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        prerow = list()
        row = list()
        prerow.append(1)
        for i in range(0,rowIndex+1):
            if i == 0:
                row = prerow
            else:
                prevrow = row.copy()
                row.clear()
                for j in range(0,i+1):
                    if j==0 or j==i:
                        row.append(1)
                    else:
                        row.append(prevrow[j]+prevrow[j-1])
        return row
