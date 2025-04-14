#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int tbt;
    int ct;
    int tat;
    int wt;
}P[3];

int main(){
    int n;
    cout<<"Enter the number of processes\n";
    cin >> n;
    cout<<"Enter Time Quantum\n";
    int tq;
    cin >> tq;
    for (int i = 0; i < n; i++)
    {
        P[i].pid = i+1;
        cout<<"Enter Arrival Time of Process "<<P[i].pid<<endl;
        cin >> P[i].at;
        cout<<"Enter Burst Time of Process\n";
        cin >> P[i].bt;
        P[i].tbt = P[i].bt;
    }

    int x=0,y=0;
    int i=0;
    while (true) 
    {
        if(P[i].bt > 0){
            if(P[i].bt >= tq){
                P[i].bt -= tq;
                x += tq;
            }
            else{
                y++;
                x += P[i].bt;
                P[i].tat = x;
                P[i].wt = P[i].tat - P[i].tbt;
                P[i].bt = 0;
            }
        }
        
        if(y >= n){
            break;
        }
        i = (i+1)%n;
    }
    cout<<"\nProcess Id\tAt\tBt\tTat\tWt\t\n";
    for (int i = 0; i < n; i++)
    {
        cout<<P[i].pid<<"\t"<<P[i].at<<"\t"<<P[i].tbt<<"\t"<<P[i].tat<<"\t"<<P[i].wt<<"\t";
    }
    
    
    return 0;
}