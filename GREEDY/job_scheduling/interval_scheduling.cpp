
#include<iostream>
#include<vector>

#define MAXTIME 1000000


using namespace std;


int main(){


    int num;
    int x, y;
    pair<int, int> p1;

    cin>>num;
    vector< pair<int,int> > jobs;
    vector< pair<int,int> > scheduled_jobs;

    for(int i = 0; i< num; i++){
        cin>>x>>y;
        p1 = make_pair(x,y);
        jobs.push_back(p1);
    }

    sort(jobs.begin(), jobs.end()); // if sorting on second key sort(jobs.begin(), jobs.end(), sortbysec)

    vector< pair<int,int> >:: iterator it1 ;



    for(it1 = jobs.begin(); it1 != jobs.end(); it1++)
    {
        cout<<(*it1).first<<"\t\t"<<(*it1).second<<endl;
    }


    int temp_start = -1;
    int temp_end = MAXTIME;


    for(it1 = jobs.begin(); it1 != jobs.end(); it1++)
    {
        cout<<"node is "<<(*it1).first<<","<<(*it1).second<<endl;
        if( (*it1).second < temp_end && (*it1).first < temp_end ){
            temp_end = (*it1).second;
            temp_start = (*it1).first;
        }
        else if( (*it1).first >= temp_end ){
            scheduled_jobs.push_back(make_pair(temp_start, temp_end));
            temp_start = (*it1).first;
            temp_end = (*it1).second;
        }
    }
    scheduled_jobs.push_back(make_pair(temp_start, temp_end));


    for(it1 = scheduled_jobs.begin(); it1 != scheduled_jobs.end(); it1++){
        cout<<(*it1).first<<"\t"<<(*it1).second<<endl; 
    }
    return 0;
}