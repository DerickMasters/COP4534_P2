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

#define PQSIZE = 100;

double GetNextInterval(double avg);
void PrintAnalytics(double lambda, double mu, int M);
double Summation(int M, double lambda, double mu);
int factorial(int i);
void ProcessNextEvent(pqueue* pqueue, fifoqueue* fifoqueue, double mu, int* servers, int* waitingcustomers, double* W, double* Wq, double* rho, std::vector<events*>* timeline, std::vector<int>* serverstatus);

int main()
{
	int n = 0; 		//number of arrival to simulate
	double lambda = 0; 	//average arrivals in a time period
	double mu = 0;		//average number served in a time period
	int M = 0;		//Number of service channels

	pqueue pqueue;
	fifoqueue fifoqueue;
	std::vector<event*> timeline;	//Maintain chronological timeline of events
	std::vector<int> serverstatus;	//keep track of server count at certain point in time
	std::vector<event*> arrivals;	//Initialize with n events
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
	std::cin(n);
	std::cout << " lambda = ";
	std::cin(lambda);
	std::cout << " mu = ";
	std::cin(mu);
	std::cout << " M = ";
	std::cin(M);

	if(n > 0)
	{
		for(int i = 0; i < n; i++)
		{
			customer* tempcustomer = new customer(GetNextInterval(lambda));
			event* tempevent = new event(true, tempcustomer);
			arrivals.push_back(tempevent);
		}
	}

	for(i = 0; i < M; i++)
	{
		pqueue.Push(arrivals.back());
		arrivals.pop_back();
	}

	servers = M;

	while(!pqueue.IsEmpty())
	{
		ProcessNextEvent(&pqueue, &fifoqueue, mu, &servers, &waitingcustomers, &W, &Wq, &rho, &timeline, &serverstatus);
		if((!arrivals.empty()) && pqueue.size() <= M)
		{
			pqueue.Push(arrivals.back());
			arrivals.pop_back();
		}	
	}

	double simulationtime = timeline.back()->GetPriority();

	//Perform Analysis
	std::cout << "Calculated Analytics" << std::endl;
	PrintAnalytics(lambda, mu, M);

	//Calculate Po
	for(i = 1; i < timeline.size(); i++)
	{
		if((!timeline.at(i-1)->IsArrival()) && (serverstatus.at(i-1) == 0))
		{
			Po += (timeline.at(i)->GetPriority() - timeline.at(i-1)->GetPriority());
		}
	}
	Po = Po/simulationtime;

	//Calculate W
	W = W/simulationtime;

	//Calculate Wq
	Wq = Wq/simulationtime;

	//calculate rho
	rho = rho/(M * simulationtime);

	//Calculate wait
	wait = waitingcustomers * 1.0/n;

	std::cout << std::endl;

	std::cout << "Simulated Analytics" << std::endl;
	std::cout << setprecision(5) << " Po = " << Po << std::endl;
	std::cout << " W = " << W << std::endl;
	std::cout << " Wq = " << Wq << std::endl;
	std::cout << " rho = " << rho << std::endl;
	std::cout << " Wait for service = " << wait << std::endl;

	return 0;
}

double GetNextInterval(double avg)
{
	//Generate Random Number (0-1]
	std::random_device rd;
	std::mt19937gen(rd());
	std::uniform_real_distribution<double> dis(0,1);
	double randNum = dis(gen);

	intervalTime = -1 * (1.0/avg) * log(randNum);

	return intervalTime;
}

void PrintAnalytics(double lambda, double mu, int M)
{
	double lambdamu = (1.0 * lambda/mu);
	double MmuLambda = (M * mu - lambda);
	double Mmu = (M * mu);

	//Percent Idle time Po
	double Po = (1/(Summation(M, lambda, mu) + ((1/factorial(M))*(pow(lambdamu,M))*(Mmu/MmuLambda))));
	std::cout << std::setprecision(5) << "Po = " << Po << std::endl;

	//Number in Line plus number being served
	double L = ((Po * lambda * mu * pow(lambdamu, M))/(factorial(M-1) * pow(MmuLambda, 2))) + lambdamu;
	std::cout << "L = " << L << std::endl;

	//Time spent in line plus time spent getting service
	double W = L/lambda;
	std::cout << "W = " << W << std::Endl;

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
	for(int i = 0; i < (M-1); i++)
	{
		temp += (1/factorial(i)) * pow((1.0 * lambda/mu),i)
	}
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

void ProcessNextEvent(pqueue* pqueue, fifoqueue* fifoqueue, double mu, int* servers, int* waitingcustomers, double* W, double* Wq, double* rho, std::vector<events*>* timeline, std::vector<int>* serverstatus)
{
	event* curEvent = pqueue->Pull();
	
	customer* curCustomer = curEvent->GetCustomer();

	timeline->push_back(curEvent);

	if(curEvent->IsArrival())
	{
		if(*servers > 0)
		{
			*servers--;
			curCustomer->SetService(curCustomer->GetArrival());
			cuCustomer->SetDeparture(curCustomer->GetService() + GetNextInterval(mu));
			pqueue->Push(curEvent);
		}
		else
		{
			fifoqueue->Push(curEvent);
			*waitingcustomers++;
		}
	}
	else
	{
		*servers++;
		*W += (curCustomer->GetDeparture() - curCustomer->GetArrival());
		*Wq += (curCustomer->GetService() - curCustomer->GetArrival());
		*rho += (curCustomer->GetDeparture() - curCustomer->GetService()); 

		if(!fifoqueue->IsEmpty())
		{
			event* curEvent_2 = fifoqueue->Pull();
			customer* curCustomer_2 = curEvent_2->GetCustomer();
			curCustomer_2->SetService(curCustomer->GetDeparture());
			curCustomer_2->SetDeparture(curCustomer_2->GetService() + GetNextInterval(mu));
			pqueue->Push(curEvent_2);
			*servers--;	
		}	

	}

	serverstatus->push_back(*servers);
}
