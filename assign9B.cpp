// B. There are 5 jobs, each with a deadline and associated profit. The Select a subset of jobs that
// maximize the total profit while ensuring that each selected job is completed within its deadline.
// Display the selected jobs with their deadlines.
// Job Deadline Profit
// A 2 100
// B 1 19
// C 2 27
// D 1 25
// E 3 15

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct job
{
    char id;
    int deadline;
    int profit;
};

bool compare(job a, job b)
{
    return a.profit>b.profit;
}

int main()
{
    int n;
    cout<<"enter the number of jobs: ";
    cin>>n;

    vector<job>jobs(n);
    cout<<"enter job_id, deadline, and profit for each job:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"job"<<i+1<<" : ";
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    }

    sort(jobs.begin(),jobs.end(),compare);

    int maxdeadline=0;
    for(int i=0;i<n;i++)
    {
        maxdeadline=max(maxdeadline,jobs[i].deadline);
    }

    vector<int>slots(maxdeadline+1,-1);
    vector<char>selectedjobs;
    int totalprofit=0;

    for(int i=0;i<n;++i)
    {
        for(int j=jobs[i].deadline;j>0;j--)
        {
            if(slots[j]==-1)
            {
                slots[j]=i;
                selectedjobs.push_back(jobs[i].id);
                totalprofit+=jobs[i].profit;
                break;
            }
        }
    }

    cout<<"\n selected jobs: ";
    for(char job: selectedjobs)
    {
        cout<<job<<" ";
    }
    cout<<"\n total profit: "<<totalprofit<<endl;
    return 0;
}