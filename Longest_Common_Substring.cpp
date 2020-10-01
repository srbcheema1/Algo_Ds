/*
Problem:-Print the longest common substring of two strings.
Time Complexity:-O(n*m)
Space COmplexity:-O(2*n)
*/
#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++) 
#define fp(i,a,b) for(int i=a;i<=b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
string lcsubstr(string s1,string s2)
{
    int len1=s1.length(),len2=s2.length();
    int dp[2][len2+1];
    int curr=0,res=0,end=0;
    fp(i,0,len1)
    {
        fp(j,0,len2)
        {
            if(i==0 || j==0)
             dp[curr][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                dp[curr][j]=dp[1-curr][j-1] + 1;
                if(res<dp[curr][j])
                {
                    res=dp[curr][j];
                    end=i-1;
                }
            }
            else
            {
                dp[curr][j]=0;
            }
        }
        curr=1-curr;
    }
    if(res==0)
        return "0";
    string ans;
    ans=s1.substr(end-res+1,res);
    return ans;
}
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    string ans=lcsubstr(s1,s2);
   if(ans!="0")
        cout << ans << '\n';
    else
        cout << "No Common Substring\n";
    return 0;
}

/*
Longest Common Substring using suffix automaton.
*/
#include<bits/stdc++.h>
using namespace std;
struct state {
    int len, link;
    map<char, int> next;
};
const int MAXLEN = 250000;
state st[MAXLEN*2 + 5];
int sz, last;
void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
int lcs (string S, string T) 
{
    sa_init();
    for (int i = 0; i < S.size(); i++)
        sa_extend(S[i]);

    int v = 0, l = 0, best = 0, bestpos = 0;
    for (int i = 0; i < T.size(); i++) {
        while (v && !st[v].next.count(T[i])) {
            v = st[v].link ;
            l = st[v].len ;
        }
        if (st[v].next.count(T[i])) {
            v = st [v].next[T[i]];
            l++;
        }
        if (l > best) {
            best = l;
            bestpos = i;
        }
    }
	return best;
} 
int main()
{
	string a,b;
	cin >> a >>b;
	cout << lcs(a,b) << '\n';
	return 0;
}
