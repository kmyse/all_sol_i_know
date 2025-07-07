#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll a[1000005],q,n,i,k,l,r;
struct nodes
{
    ll val;
    ll carry1;
    ll carry2;
};
nodes tree[4000005];
void build(ll index,ll l,ll r)
{
    if(l==r)
    {
        tree[index].val=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    tree[index].val=tree[2*index].val+tree[2*index+1].val;

}
ll sum(ll l,ll r)
{
    return (l+r)*(r-l+1)/2;
}
void lazy(ll index,ll l,ll r)
{
    tree[index].val+=tree[index].carry1*(r-l+1)+sum(1,r-l+1)*tree[index].carry2;
    if(l!=r)
    {
        ll mid=(l+r)/2;
        tree[2*index].carry1+=tree[index].carry1;
        tree[2*index].carry2+=tree[index].carry2;
        tree[2*index+1].carry1+=tree[index].carry1+(mid+1-l)*tree[index].carry2;
        tree[2*index+1].carry2+=tree[index].carry2;
    }
    tree[index].carry1=0;
    tree[index].carry2=0;


}
void update(ll index,ll l,ll r,ll u,ll v)
{
    lazy(index,l,r);
    if(u>r||l>v)
        return;
    if(u<=l&&v>=r)
    {
        tree[index].carry1+=l-u;
        tree[index].carry2++;
        lazy(index,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update(2*index,l,mid,u,v);
    update(2*index+1,mid+1,r,u,v);
    tree[index].val=tree[2*index].val+tree[2*index+1].val;
}
ll summm(ll index, ll l, ll r, ll u, ll v)
{
    lazy(index,l,r);
    if(u>r||l>v)
        return 0;
    if(u<=l&&v>=r)
    return tree[index].val;
    ll mid=(l+r)/2;
    return summm(index*2,l,mid,u,v)+summm(index*2+1,mid+1,r,u,v);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(".inp","r"))
    {
        freopen(".inp","r",stdin);
        freopen(".out","w",stdout);
    }
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    for(ll j=1;j<=q;j++)
    {
        cin>>k;
        if(k==1)
        {
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else
        {
            cin>>l>>r;
            cout<<summm(1,1,n,l,r)<<'\n';
        }
    }
}
