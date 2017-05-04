#include <stack>
#include <deque>
#include <vector>
#include <queue>
#include "Activitat 9 - Stack.h"

int main()
{
	std::stack<int> s1({ 5,4,3,2,1 });
	std::stack<int> s2({9,8,7,6});
	std::stack<char> q1({'(','(','(',')','(',')',')',')','(',')'});
	superMerge(s1, s2);
	putHat(s1, s2);
	transformToQ(s1);
	isHat(s1, s2);
	balancedP(q1);
	change(s1);
	return 0;
}

std::stack<int> superMerge(std::stack<int> s1, std::stack<int> s2)
{
	std::stack<int> result;
	std::stack<int> r2;
	while(!s2.empty() || !s1.empty())
	{
		if(!s1.empty() && s1.top()<=s2.top())
		{
			result.push(s1.top());
			s1.pop();
		}
		else
		{
			result.push(s2.top());
			s2.pop();
		}
	}
	while(!result.empty())
	{
		r2.push(result.top());
		result.pop();
	}
	return r2;
}

std::stack<int> putHat(std::stack<int> s1,std::stack<int> s2)
{
	std::stack<int> result;
	while(!s1.empty())
	{
		result.push(s1.top());
		s1.pop();
	}
	while(!s2.empty())
	{
		result.push(s2.top());
		s2.pop();
	}
	return result;
}

std::queue<int> transformToQ(std::stack<int> s1)
{
	std::queue<int> result;
	while(!s1.empty())
	{
		result.push(s1.top());
		s1.pop();
	}
	return result;
}

bool isHat(std::stack<int> s1,std::stack<int> s2)
{ 
	while(!s1.empty())
	{
		if(s1.top()==s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool balancedP(std::stack<char> q1)
{
	int dretaCount = 0;
	int esqCount = 0;
	while(!q1.empty())
	{
		if(q1.top()=='(')
		{
			esqCount++;
		}
		else
		{
			dretaCount++;
		}
		q1.pop();
	}
	return dretaCount == esqCount;
}

void change(std::stack<int> &s)
{
	std::deque<int> storeQ;
	int aux;
	std::stack<int> s2;
	while(!s.empty())
	{
		storeQ.push_back(s.top());
		s.pop();
	}
	aux = storeQ[0];
	storeQ[0] = storeQ[storeQ.size()-1];
	storeQ[storeQ.size() - 1] = aux;
	for(int i=0;i<storeQ.size()-1;i++)
	{
		s2.push(storeQ[i]);
	}
	while(!s2.empty())
	{
		s.push(s2.top());
		s2.pop();
	}
}
