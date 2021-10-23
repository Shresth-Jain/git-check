                
#include<bits/stdc++.h>
using namespace std;

#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
const char nl = '\n';
const long long MAX_SIZE = 10000001;
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
int main()
{
    int p,r;
    cin>>p>>r;
    int totalres[r];
    for (int i = 0; i < r; ++i)
    {
        cin>>totalres[i];    
    }

    int allocated[p][r];
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            cin>>allocated[i][j];
        }
    }

    int MAX[p][r];
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            cin>>MAX[i][j];
        }
    }
    
    int need[p][r];
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            need[i][j]=MAX[i][j]-allocated[i][j];
            cout<<need[i][j]<<' ';
        }
        cout<<endl;
    }
cout<<endl;
    int available[r];
    for (int i = 0; i < r; ++i)
    {
        available[i]=totalres[i];
        cout<<available[i]<<' ';

        for (int j = 0; j < p; ++j)
        {
            available[i]-=allocated[i][j];
        }
        cout<<available[i]<<' ';
    }
    
    int pcount=0;
    bool successful;
    vector<int> res;
    while(1){
        bool flag=false;
        //check if we can satisfy the need with available 
        for (int i = 0; i < p; ++i)
        {
            bool button=true;
            
            if(need[i][0]==INT_MAX)continue;

            for (int j = 0; j < r; ++j)
            {
                if(need[i][j]<available[j])
                    {
                        button=false;
                        break;
                    }
            }
            if(button==true){
                flag=true;
                for (int j = 0; j < r; ++j)
                {
                    need[i][j]=INT_MAX;
                    available[j]+=allocated[i][j];
                }

                res.push_back(i);
                break;
            }
        }
        if(flag==true){
            pcount++;
        }

        if(pcount==p){
            successful=true;
            break;
        }

        if(flag==false){
            successful=false;
            break;
        }
    }
    if(successful){
        cout<<"System is in safe state with following order of execution\n";
        for(auto i:res)
            cout<<i<<' '<<'\n';
    }
    else{
        cout<<"System is in Deadlock State\n";
    }
    return 0;
}

