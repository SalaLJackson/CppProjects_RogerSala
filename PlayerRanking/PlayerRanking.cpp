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
	ranking[1000] = { "RAMON" };
	ranking[800] = { "JOAN" };
	ranking[500] = { "ZOLTAN" };
	ranking[200] = { "SERGEI" };
	for(auto it=ranking.begin();it!=ranking.end();++it)
	{
		std::cout << it->second.name << " : " << it->second.punt << std::endl;
	}
	std::cout << "Introdueix el teu nom: ";
	std::cin >> name;
	std::cout << std::endl << "Introdueix la teva puntuacio: ";
	std::cin >> punt;
	ranking[punt] = {name};
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
			}
		}
	}
}