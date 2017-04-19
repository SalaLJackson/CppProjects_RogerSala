#include <map>
#include <vector>
#include <iostream>
#include <string>

struct Puntuacio
{
	std::string name;
	int punt;
};

void main()
{
	bool goPun;
	int punt;
	std::string name;
	std::map<int,Puntuacio>ranking;
	ranking[1] = { "DIO",1000 };
	ranking[2] = { "JOJO",800 };
	ranking[3] = { "ZEPPELIN",500 };
	ranking[4] = { "SPEEDWAGON",200 };
	ranking[5] = {};
	for(auto it=ranking.begin();it!=ranking.end();++it)
	{
		std::cout << it->second.name << " : " << it->second.punt << std::endl;
	}
	std::cout << "Introdueix el teu nom: ";
	std::cin >> name;
	std::cout << std::endl << "Introdueix la teva puntuacio: ";
	std::cin >> punt;
	for(auto it=ranking.begin();it!=ranking.end();++it)
	{
		if(it->second.name==name)
		{
			std::cout << "ERROR - El nom introduit ja s'ha triat";
		}
		else
		{
			goPun = true;
		}
	}
	if(goPun)
	{
		for (auto it = ranking.rbegin();it!=ranking.rend();++it)
		{
			if(it->second.punt<=punt && it->second.punt==0)
			{
				int aux = it->second.punt;
				it->second.punt = punt;
				ranking[it - 1] = aux;
			}
		}
	}
}