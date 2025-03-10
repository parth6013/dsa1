// Most meetings

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(pair<int,int> p1,pair<int,int> p2){
        return p1.second < p2.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        pair<int,int> p;
        for(int i=0;i<n;i++){
            
            p.first=start[i];
            p.second=end[i];
            v.push_back(p);
        }
        v.pop_back();
        sort(v.begin(),v.end(),compare);
        
    // for(int i=0;i<n;i++){
    //     cout<<v[i].first<<v[i].second<<endl;
    // }
    
    int ans=1;
    int end2=v[0].second;
    
    for(int i=1;i<n;i++){
        if(v[i].first>=end2){
            ans++;
            end2=v[i].second;
        }
    }
        cout<<ans;
}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  