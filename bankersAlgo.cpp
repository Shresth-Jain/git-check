                
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p,r;
    cout<<"\nEnter the number of processes and resources: ";
    cin>>p>>r;
    int totalres[r];
    cout<<"\nEnter the total count of all resources: ";
    for (int i = 0; i < r; ++i)
    {
        cin>>totalres[i];    
    }
    cout<<"\nEnter the Allocated Matrix: \n";

    int allocated[p][r];
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            cin>>allocated[i][j];
        }
    }
    cout<<"\nEnter the Max Requirement Matrix: \n";

    int MAX[p][r];
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            cin>>MAX[i][j];
        }
    }
    
    int need[p][r];
    cout<<"\nThe Need Matrix is as follows :\n";
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

        for (int j = 0; j < p; ++j)
        {
            available[i]-=allocated[j][i];
        }
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
                if(need[i][j]>available[j])
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

