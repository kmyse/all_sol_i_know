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
void lazy1(ll index,ll l,ll r)
{
    if(tree[index].carry1 != 0)
    {
        tree[index].val+=(r-l+1)*tree[index].carry1;
        if(l!=r)
        {
            tree[2*index].carry1+=tree[index].carry1;
            tree[2*index+1].carry1+=tree[index].carry1;
        }
        tree[index].carry1=0;
    }


}
void lazy2(ll index,ll l,ll r)
{
    if(tree[index].carry2!=LLONG_MAX)
    {
        tree[index].val=(r-l+1)*tree[index].carry2;
        if(l!=r)
        {
            tree[2*index].carry2=tree[index].carry2;
            tree[2*index+1].carry2=tree[index].carry2;
            tree[2*index].carry1=0;
            tree[2*index+1].carry1=0;

        }
        tree[index].carry2=LLONG_MAX;
    }


}
void update1(ll index,ll l,ll r,ll u,ll v,ll valu)
{
    lazy2(index,l,r);
    lazy1(index,l,r);
    if(u>r||l>v)
        return;
    if(u<=l&&v>=r)
    {
        tree[index].carry1+=valu;
        lazy1(index,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update1(2*index,l,mid,u,v,valu);
    update1(2*index+1,mid+1,r,u,v,valu);
    tree[index].val=tree[2*index].val+tree[2*index+1].val;
}
void update2(ll index,ll l,ll r,ll u,ll v,ll valu)
{
    lazy2(index,l,r);
    lazy1(index,l,r);
    if(u>r||l>v)
        return;
    if(u<=l&&v>=r)
    {
        tree[index].carry2=valu;
        lazy2(index,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update2(2*index,l,mid,u,v,valu);
    update2(2*index+1,mid+1,r,u,v,valu);
    tree[index].val=tree[2*index].val+tree[2*index+1].val;
}
ll summm(ll index, ll l, ll r, ll u, ll v)
{
    lazy2(index,l,r);
    lazy1(index,l,r);
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
    for(i=1;i<=4000005;i++)
        tree[i].carry2=LLONG_MAX;
    for(ll j=1;j<=q;j++)
    {
        cin>>k;
        if(k==1)
        {
            cin>>l>>r>>k;
            update1(1,1,n,l,r,k);
        }
        else if (k==2)
        {
            cin>>l>>r>>k;
            update2(1,1,n,l,r,k);
        }
        else
        {
            cin>>l>>r;
            cout<<summm(1,1,n,l,r)<<'\n';
        }
    }
}
