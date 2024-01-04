#User function Template for python3

class Solution:
    def singleElement(self, arr, N):
        # code here 
        s=dict()
        for i in range(N):
            if arr[i] not in s:
                s[arr[i]]=1
            else:
                s[arr[i]]+=1
        key_l=list(s.keys())
        val_l=list(s.values())
        return key_l[val_l.index(1)]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.singleElement(arr,N))
# } Driver Code Ends