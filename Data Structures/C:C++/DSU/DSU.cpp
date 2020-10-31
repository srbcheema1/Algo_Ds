
struct DSU{
    ll N;
    vll par , sz;
    
    DSU(ll n) : N(n), par(N+1,0), sz(N+1,1) {
        iota(all(par),0);
    }
    void assign(ll n){
        par.resize(n+1);
        iota(all(par),0);
        sz.resize(n+1,1);
        N=n; // Assigning n+1 sized vector according to 1-based or 0-based
    }
    

    void make(ll v){
        par[v]=v;
        sz[v]=1;
        ++N;
    }

    ll find(ll v){
        if(par[v]==v) return v;
        return par[v] = find(par[v]);
    }

    void merge(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
            --N;
        }
    } 
};
