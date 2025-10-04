class Solution {
  public:
    bool possible(vector<int> &stalls, int dist,int cows){
        int cntCows=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=dist){
                cntCows++;
                last=stalls[i];
            }
            if(cntCows>=cows) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(stalls,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
