class Solution:
    def f(self, x,arr):
        n=len(arr)
        count=0
        for i in arr:
            if(i>=x):
                count=count+1
        return count>=x
    def hIndex(self, arr):
        n=len(arr)
        l=0
        r=max(arr)
        while l<=r :
            mid=(r+l)//2
            if(self.f(mid,arr)):
                l=mid+1
            else:
                r=mid-1
        return r