//-----------------------------------------------
// Derick Masters
// COP4534_Data_Structures
// main.cpp
//
// This program will analyze the
// fitness of a Priority Queue and a FIFO Queue
// in handling the throughput for a hypothetical
// service center with a variable number of 
// service channels
//
// ----------------------------------------------

#include"fifoqueue.hpp"
#include"pqueue.hpp"
#include"event.hpp"
#include"customer.hpp"
#include<random>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<vector>

double GetNextInterval(double avg);
void PrintAnalytics(double lambda, double mu, int M);
double Summation(int M, double lambda, double mu);
int factorial(int i);
void ProcessNextEvent(pqueue& pqueue, fifoqueue& fifoqueue, double mu, int& servers, int& waitingcustomers, double& W, double& Wq, double& rho, std::vector<double>& timeline_1, std::vector<bool>& timeline_2, std::vector<int>& serverstatus);

int main()
{
	int n = 0; 		//number of arrival to simulate
	double lambda = 0; 	//average arrivals in a time period
	double mu = 0;		//average number served in a time period
	int M = 0;		//Number of service channels

	pqueue Pqueue;
	fifoqueue fifoqueue;
	pqueue arrivals;
	std::vector<double> timeline_1;	//Maintain chronological timeline of events for Po Calculation
	std::vector<bool> timeline_2;	//Maintain Record of Server Status for Po Calculation
	std::vector<int> serverstatus;	//keep track of server count at certain point in time

	int waitingcustomers = 0;
	double Po = 0.0;
	double W = 0.0;
	double Wq = 0.0;
	double rho = 0.0;
	double wait = 0.0;
	int servers;

	//Prompt for input
	
	std::cout << "Please supply the following: " << std::endl;
	std::cout << " n = ";
	std::cin >> n;
	std::cout << " lambda = ";
	std::cin >> lambda;
	std::cout << " mu = ";
	std::cin >> mu;
	std::cout << " M = ";
	std::cin >>M;

	if(n > 0)
	{
		double previnterval = 0;

		for(int i = 1; i < n; i++)
		{
			customer* tempcustomer = new customer(previnterval + GetNextInterval(lambda));
			event* tempevent = new event(true, tempcustomer);
			previnterval = tempevent->GetPriority();

			arrivals.Add(tempevent);
		}
	}

	for(int i = 0; i < M; i++)
	{
		Pqueue.Add(arrivals.Pull());
	}

	servers = M;

	while(!Pqueue.IsEmpty())
	{
		ProcessNextEvent(Pqueue, fifoqueue, mu, servers, waitingcustomers, W, Wq, rho, timeline_1, timeline_2, serverstatus);
		if((!arrivals.IsEmpty()) && Pqueue.size() <= M)
		{
			while(Pqueue.size() < 100 && !arrivals.IsEmpty())
			{
				Pqueue.Add(arrivals.Pull());
			}
		}	
	}

	double simulationtime = timeline_1.back();

	//Perform Analysis
	std::cout << "Calculated Analytics" << std::endl;
	PrintAnalytics(lambda, mu, M);

	//Calculate Po
	for(int i = 1; i < timeline_1.size(); i++)
	{
		if((!timeline_2.at(i-1)) && (serverstatus.at(i-1) == M))
		{
			Po += (timeline_1.at(i) - timeline_1.at(i-1));
		}
	}
	Po = Po/simulationtime;

	//Calculate W
	W = W/n;

	//Calculate Wq
	Wq = Wq/n;

	//calculate rho
	rho = rho/(M * simulationtime);

	//Calculate wait
	wait = waitingcustomers * 1.0/n;

	std::cout << std::endl;

	std::cout << "Simulated Analytics" << std::endl;
	std::cout << std::setprecision(5) << " Po = " << Po << std::endl;
	std::cout << " W = " << W << std::endl;
	std::cout << " Wq = " << Wq << std::endl;
	std::cout << " rho = " << rho << std::endl;
	std::cout << " Wait for service = " << wait << std::endl;

	return 0;
}

double GetNextInterval(double avg)
{
	//Generate Random Number (0-1]
	thread_local static std::random_device rd;
	thread_local static std::mt19937 gen(rd());
	thread_local std::uniform_real_distribution<double> dis(0,1);
	double randNum = dis(gen);

	double intervalTime = -1 * (1.0/avg) * log(randNum);

	return intervalTime;
}

void PrintAnalytics(double lambda, double mu, int M)
{ 
	double lambdamu = (1.0 * lambda/mu);
	double MmuLambda = ((M * mu) - lambda);
	double Mmu = (M * mu);

	//Percent Idle time Po
	double Po = (1.0/(Summation(M, lambda, mu) + ((1.0/factorial(M))*(pow(lambdamu,M))*(Mmu/MmuLambda))));
	std::cout << std::setprecision(5) << "Po = " << Po << std::endl;

	//Number in Line plus number being served
	double L = ((Po * lambda * mu * pow(lambdamu, M))/(1.0 * factorial(M-1) * pow(MmuLambda, 2))) + lambdamu;
	std::cout << "L = " << L << std::endl;

	//Time spent in line plus time spent getting service
	double W = L/lambda;
	std::cout << "W = " << W << std::endl;

	//Avg number of customers in the queue
	double Lq = L - lambdamu;
	std::cout << "Lq = " << Lq << std::endl;

	//Avg time customer spends waiting in queue
	double Wq = Lq/lambda;
	std::cout << "Wq = " << Wq << std::endl;

	//proportion of system resources used by the traffic which arrives
	double rho = lambda/Mmu;
	std::cout << "Rho = " << rho << std::endl;
}

double Summation(int M, double lambda, double mu)
{
	double temp = 0;
	for(int i = 0; i < M; i++)
	{
		temp += (1.0/factorial(i)) * pow((1.0 * lambda/mu),i);
	}
	return temp;
}

int factorial(int i)
{
	int temp = 1;
	for(int j = i; j > 0; j--)
	{
		temp *= j; 
	}
	return temp;
}

void ProcessNextEvent(pqueue& Pqueue, fifoqueue& fifoqueue, double mu, int& servers, int& waitingcustomers, double& W, double& Wq, double& rho, std::vector<double>& timeline_1, std::vector<bool>& timeline_2, std::vector<int>& serverstatus)
{
	event* curEvent = Pqueue.Pull();
	
	customer* curCustomer = curEvent->GetCustomer();

	timeline_1.push_back(curEvent->GetPriority());
	timeline_2.push_back(curEvent->IsArrival());

	if(curEvent->IsArrival())
	{
		if(servers > 0)
		{
			servers--;
			curCustomer->SetService(curCustomer->GetArrive());
			curCustomer->SetDeparture(curCustomer->GetService() + GetNextInterval(mu));
			curEvent->SetDeparture();
			Pqueue.Add(curEvent);
		}
		else
		{
			fifoqueue.Push(curEvent);
			waitingcustomers++;
		}
	}
	else
	{
		servers++;

		W += (curCustomer->GetDeparture() - curCustomer->GetArrive());
		Wq += (curCustomer->GetService() - curCustomer->GetArrive());
		rho += (curCustomer->GetDeparture() - curCustomer->GetService());
	
		if(!fifoqueue.IsEmpty())
		{


			event* curEvent_2 = fifoqueue.Pop();
			customer* curCustomer_2 = curEvent_2->GetCustomer();
			curCustomer_2->SetService(curCustomer->GetDeparture());
			curCustomer_2->SetDeparture(curCustomer_2->GetService() + GetNextInterval(mu));
			curEvent_2->SetDeparture();
			Pqueue.Add(curEvent_2);
			servers--;	
		}	
	}
	int tempint = servers;
	serverstatus.push_back(tempint);
}
