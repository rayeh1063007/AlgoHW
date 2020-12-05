#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
using namespace std;

void left()
{

};

int main()
{
    fstream fin;
    string a;
    string aa;
    vector<pair<int,int> > point;
    int i=0;
    fin.open("node.txt");
    while(getline(fin,a))
    {
        aa+=a;
        char b;
        stringstream ss;
        pair<int,int> temp;
        ss<<a;
        ss>>temp.first>>b>>temp.second;
        point.push_back(temp);
    }
    cout<<"輸入 : "<<endl;
    for(int i=0;i<point.size();i++)
    {
        cout<<point[i].first<<","<<point[i].second<<endl;
    }

    ///依x排序
    sort(point.begin(),point.end());
    /*
    for(int i=0;i<point.size();i++)
    {
        cout<<point[i].first<<"-"<<point[i].second<<endl;
    }
    */
    ///找切割線
    int len=point.size();
    int le=len/2;
    int ri=le+1;
    ///處理左邊
    pair<pair<int,int>,pair<int,int> > min_p;
    float d=100000000;
    for(int i=0;i<le-1;i++)
    {
        for(int j=i+1;j<le;j++)
        {
            int temp;
            temp=sqrt(pow((point[i].first-point[j].first),2) + pow((point[i].second-point[j].second),2));
            if(temp<d)
            {
                d=temp;
                min_p.first.first=point[i].first;
                min_p.first.second=point[i].second;
                min_p.second.first=point[j].first;
                min_p.second.second=point[j].second;
            }
        }
    }
    //cout<<"left min : "<<min_p.first.first<<"-"<<min_p.first.second<<"_"<<min_p.second.first<<"-"<<min_p.second.second<<fixed<<setprecision(4)<<" d : "<<d<<endl;
    ///處理右邊
    for(int i=ri-1;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            int temp;
            temp=sqrt(pow((point[i].first-point[j].first),2) + pow((point[i].second-point[j].second),2));
            if(temp<d)
            {
                d=temp;
                min_p.first.first=point[i].first;
                min_p.first.second=point[i].second;
                min_p.second.first=point[j].first;
                min_p.second.second=point[j].second;
            }
        }
    }
    //cout<<"right min : "<<min_p.first.first<<"-"<<min_p.first.second<<"_"<<min_p.second.first<<"-"<<min_p.second.second<<fixed<<setprecision(4)<<" d : "<<d<<endl;
    ///處理中間
    vector<pair<int,int> > mid_min;///x,y相反存
    int mid_le=point[le-1].first-d,mid_ri=point[le-1].first+d;
    for(int i=0;i<len;i++)
    {
        if(point[i].first>=mid_le&&point[i].first<=mid_ri)
        {
            pair<int,int> temp;
            temp.second=point[i].first;
            temp.first=point[i].second;
            mid_min.push_back(temp);
        }
    }
    sort(mid_min.begin(),mid_min.end());
    /*
    for(int i=0;i<mid_min.size();i++)
    {
        cout<<mid_min[i].first<<"-"<<mid_min[i].second<<endl;
    }
    */
    int m_len=mid_min.size();
    for(int i=0;i<m_len-1;i++)
    {
        for(int j=i+1;j<m_len;j++)
        {
            int temp;
            temp=sqrt(pow((mid_min[i].first-mid_min[j].first),2) + pow((mid_min[i].second-mid_min[j].second),2));
            if(temp<d)
            {
                d=temp;
                min_p.first.first=mid_min[i].second;
                min_p.first.second=mid_min[i].first;
                min_p.second.first=mid_min[j].second;
                min_p.second.second=mid_min[j].first;
            }
        }
    }
    cout<<"輸出 : "<<endl;
    cout<<min_p.first.first<<","<<min_p.first.second<<endl;
    cout<<min_p.second.first<<","<<min_p.second.second<<endl;
    cout<<fixed<<setprecision(4)<<d<<endl;

    return 0;
}

