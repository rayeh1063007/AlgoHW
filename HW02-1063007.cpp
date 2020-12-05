#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    int k,now=0,t=0,ans=0,de=100;

    vector<int> num,test;
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        num.push_back(rand()%1000);
    }
    cout<<"K : ";
    cin>>k;
    while(1)
    {
        t++;
        cout<<"Round #"<<t<<": "<<endl;
        int B_num=0,S_num=0,L_num=0;
        vector<vector<int> > pru;
        vector<int> bigger,same,little,temp,mid;
        for(int i=0,j=1;i<num.size();i++,j++)
        {
            if(j==6)
            {
                pru.push_back(temp);
                temp.clear();
                j=1;
            }
            temp.push_back(num[i]);
        }
        if(temp.size()<5)
        {
            int need=5-temp.size();
            for(int i=0;i<need;i++)
            {
                temp.push_back(10000);
            }
        }
        pru.push_back(temp);
        temp.clear();

        for(int i=0;i<pru.size();i++)
        {
            sort(pru[i].begin(),pru[i].end());
            mid.push_back(pru[i][2]);
        }

        sort(mid.begin(),mid.end());
        int mm=mid.size()/2,x=1;
        int m=mid[mm];
        while(m==10000)
        {
            m=mid[mm-x];
            x++;
        }

        cout<<"P: "<<m<<endl;

        for(int i=0;i<num.size();i++)
        {
            if(num[i]>m)
            {
                bigger.push_back(num[i]);
                B_num++;
            }
            else if(num[i]==m)
            {
                same.push_back(num[i]);
                S_num++;
            }
            else
            {
                little.push_back(num[i]);
                L_num++;
            }
        }

        if((B_num+now)<k)
        {
            bigger.clear();
            now+=B_num;
            if((now+S_num)<k)
            {
                same.clear();
                now+=S_num;
                if((now+L_num)>=k)
                {
                    if(L_num<=5)
                    {
                        sort(little.begin(),little.end());
                        reverse(little.begin(),little.end());
                        ans=little[k-now-1];
                        break;
                    }
                }
                num.clear();
                num.assign(little.begin(),little.end());
            }
            else if((now+S_num)>=k)
            {
                if(S_num<=5)
                {
                    sort(same.begin(),same.end());
                    reverse(same.begin(),same.end());
                    ans=same[k-now-1];
                    break;
                }
                now+=S_num;
                num.clear();
                num.assign(same.begin(),same.end());
            }

        }
        else if((B_num+now)>=k)
        {
            if(B_num<=5)
            {
                sort(bigger.begin(),bigger.end());
                reverse(bigger.begin(),bigger.end());
                ans=bigger[k-now-1];
                break;
            }
            num.clear();
            num.assign(bigger.begin(),bigger.end());
        }
        bigger.clear();
        same.clear();
        little.clear();
        mid.clear();
        pru.clear();
        cout<<"delete number : "<<de-num.size()<<endl<<endl;
        de=num.size();
    }
    cout<<"delete number : "<<de-num.size()<<endl<<endl;
    de=num.size();
    cout<<"ans : "<<ans<<endl;
    return 0;
}
