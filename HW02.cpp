#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    int k,now=0,t=0,ans=0,de=100,br=0;

    vector<int> num,test;
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        num.push_back(rand()%1000);
    }
    test.assign(num.begin(),num.end());
    sort(test.begin(),test.end());
    reverse(test.begin(),test.end());
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
        /*
        for(int i=0;i<pru.size();i++)
        {
            for(int j=0;j<5;j++)
                cout<<pru[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;

        cout<<"sort : "<<endl;
        */
        for(int i=0;i<pru.size();i++)
        {
            sort(pru[i].begin(),pru[i].end());
            mid.push_back(pru[i][2]);
        }
        /*
        for(int i=0;i<pru.size();i++)
        {
            for(int j=0;j<5;j++)
                cout<<pru[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        */
        sort(mid.begin(),mid.end());
        int mm=mid.size()/2,x=1;
        int m=mid[mm];
        while(m==10000)
        {
            m=mid[mm-x];
            x++;
        }
        /*
        for(int i=0;i<mid.size();i++)
        {
            cout<<mid[i]<<" ";
        }
        */
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
        /*
        cout<<"bigger : "<<endl;
        for(int i=0;i<B_num;i++)
           cout<<bigger[i]<<" ";
        cout<<endl<<endl;

        cout<<"same : "<<endl;
        for(int i=0;i<S_num;i++)
           cout<<same[i]<<" ";
        cout<<endl<<endl;

        cout<<"little : "<<endl;
        for(int i=0;i<L_num;i++)
           cout<<little[i]<<" ";
        cout<<endl<<endl;
        */
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
                        br=1;
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
                    br=2;
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
                br=3;
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
    //cout<<"break from : "<<br<<endl;
    cout<<"delete number : "<<de-num.size()<<endl<<endl;
    de=num.size();
    //cout<<"test : "<<test[k-1]<<endl;
    cout<<"ans : "<<ans<<endl;

}
/*
先以隨機方式產生100個1至1000的正整數。接著從鍵盤輸入K，讓演算法找第K大的數字。

每回合，selection problem演算法會先找出P值，並刪減部分的數字。

最終會找到第K大的數字為何。

每回合，程式請印出所選擇的P值，以及此回合刪減了幾個數字。

最終印出找到的第K大的數字。
for(int i=0;i<20;i++)
    {
        for(int j=0;j<5;j++)
            cout<<pru[i][j]<<" ";
        cout<<endl;
    }
*/
