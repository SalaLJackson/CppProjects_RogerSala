#include <list>
#include "Activitat 10 - List.h"

int main()
{
	std::list<int> l1({ 9,8,5,3,2,1 });
	std::list<int> l2({ 7,6,4,2 });
	std::list<int> lmerge;
	lmerge=superMerge(l1, l2);
	change(lmerge);
	getElementPos(lmerge, 2);
	removeDuplicates(lmerge);
	removeElement(lmerge,9);
	std::list<int> pal({1,2,3,2,1});
	palindrome(pal);
	return 0;
}

std::list<int> superMerge(std::list<int> l1, std::list<int> l2)
{
	std::list<int> lmerge;
	while(!l1.empty() && !l2.empty())
	{
		if(l1.back() < l2.back())
		{
			lmerge.push_back(l1.back());
			l1.pop_back();
		}
		else
		{
			lmerge.push_back(l2.back());
			l2.pop_back();
		}
	}
	while(!l1.empty() || !l2.empty())
	{
		if(l1.empty())
		{
			lmerge.push_back(l2.back());
			l2.pop_back();
		}
		else
		{
			lmerge.push_back(l1.back());
			l1.pop_back();
		}
	}
	return lmerge;
}

void change(std::list<int> &l)
{
	int aux=l.back();
	l.pop_back();
	l.push_back(l.front());
	l.pop_front();
	l.push_front(aux);
}

int getElementPos(std::list<int> l, int pos)
{
	while(pos!=0)
	{
		l.pop_front();
		pos--;
	}
	return l.front();
}

void removeDuplicates(std::list<int> &l)
{
	std::list<int>::iterator it, it2;
	it = l.begin();
	for(int i=0;i<l.size();i++)
	{
		it2 = l.begin();
		for(int j=0;j<l.size();j++)
		{
			if(*it==*it2 && i!=j)
			{
				it2 = l.erase(it2);
			}
			else
			{
				it2++;
			}
		}
		it++;
	}
}

void removeElement(std::list<int> &l,int n)
{
	std::list<int>::iterator it = l.begin();
	for (int j = 0; j<l.size(); j++)
	{
		if (*it==n)
		{
			it = l.erase(it);
		}
		else
		{
			it++;
		}
	}
}

bool palindrome(std::list<int> l)
{
	while(l.size()>1)
	{
		if(l.front()!=l.back())
		{
			return false;
		}
		l.pop_front();
		l.pop_back();
	}
	return true;
}