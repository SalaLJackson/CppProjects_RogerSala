#include <deque>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include "Activitat 8 -  Deque.h"

const int cap = 10;

int main()
{
	// -----------------------------------------Exercici 1
	std::deque<float> prices(10, 10.50);
	// Fiquem 32.43 com a últim valor.
	prices[cap-1] = 32.43;
	// Borrem primer element.
	prices.pop_front();
	// Assignem la deque a una de nova.
	std::deque<float> newDeque(prices);
	// Fiquem els dos valors davant la 2na deque.
	newDeque.push_front(5.64);
	newDeque.push_front(20.3);
	// Fiquem 10 a la segona posició.
	newDeque.insert(newDeque.begin()+1, 10.f);
	// Imprimim la primera deque amb backward iterator.
	std::cout << "First Deque: " << std::endl;
	for(auto it=prices.rbegin();it!=prices.rend();it++)
	{
		std::cout << *it << std::endl;
	}
	// Imprimim la segona deque.
	std::cout << "Second Deque: " << std::endl;
	for (auto it = prices.begin(); it != prices.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	// -----------------------------------------Exercici 2
	std::vector<float> v1(cap,10.50);
	// Fiquem 32.43 com a últim valor.
	v1[cap-1] = 32.43;
	// Borrem el primer element.
	v1.erase(v1.begin());
	// Assignem al vector a un de nou
	std::vector<float> v2(v1);
	// Fiquem els dos valors davant el nou vector.
	v2.insert(v2.begin(), 5.64);
	v2.insert(v2.begin(), 20.3);
	// Fiquem 10 a la segona posició.
	v2.insert(v2.begin() + 1, 10.f);
	// Imprimim el vector amb backward operator.
	std::cout << "First Vector: " << std::endl;
	for(auto it=v1.rbegin();it!=v1.rend();++it)
	{
		std::cout << *it << std::endl;
	}
	// Imprimim el segon vector.
	std::cout << "Second Vector: " << std::endl;
	for (auto it = v1.begin(); it != v1.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	// -----------------------------------------Exercici 3
	std::priority_queue<int> pq1(5,5);
	std::priority_queue<int> pq2(3,3);
	auto test = superMergeP(pq1, pq2);
	
	//std::queue<int> q1(5);
	//std::queue<int> q2(3 );
	return 0;
}

std::priority_queue<int> superMergeP(std::priority_queue<int> p1, std::priority_queue<int> p2)
{
	std::priority_queue<int> pResult(p1);
	while(!p2.empty())
	{
		pResult.push(p2.top());
		p2.pop();
	}
	return pResult;
}

/*std::priority_queue<int> concatQueue(std::priority_queue<int> p1, std::priority_queue<int> p2)
{
	
}*/