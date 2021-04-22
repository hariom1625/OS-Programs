// Priority Handler
#include<bits/stdc++.h>
using namespace std;

struct Process
{
	int pid;
	int b;
	int p;
};

bool comp(Process a, Process b)
{
	return (a.p > b.p);
}

void findWaitingTime(Process proc[], int n,
                     int wt[])
{
	wt[0] = 0;

	for (int i = 1; i < n ; i++ )
		wt[i] = proc[i - 1].b + wt[i - 1] ;
}

void findTurnAroundTime( Process proc[], int n,
                         int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = proc[i].b + wt[i];
}

void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(proc, n, wt);

	findTurnAroundTime(proc, n, wt, tat);

	cout << "\nProcesses " << " Burst time "
	     << " Waiting time " << " Turn around time\n";


	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
		     << proc[i].b << "\t " << wt[i]
		     << "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = "
	     << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
	     << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
	sort(proc, proc + n, comp);

	cout << "Order in which processes gets executed \n";
	for (int i = 0 ; i < n; i++)
		cout << proc[i].pid << " " ;

	findavgTime(proc, n);
}

int main()
{
	int n, b, p;
	cout << "Enter Number of processes: ";
	cin >> n;

	Process proc[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter Burst Time for Process " << i + 1 << " : ";
		proc[i].pid = i + 1;
		cin >> b;
		proc[i].b = b;

		cout << "Enter Priority for Process " << i + 1 << " : ";
		cin >> p;
		proc[i].p = p;
	}

	priorityScheduling(proc, n);
	return 0;
}
