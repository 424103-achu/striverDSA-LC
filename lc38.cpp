class Solution {
public:
    string findRLE(string a) {
        string ans = "";
        int n = a.size();
        for (int i = 0; i < n; i++) {
           int count=1;
           while(i+1<n && a[i]==a[i+1]){
            count++;
            i++;
           }
           ans+=to_string(count)+a[i];
        }
       
        return ans;
    }
    string countAndSay(int n) {
        int i = 1;string a="1";
        while (i < n) {
            a = findRLE(a);
            i++;
        }
        return a;
    }
};