#pragma once
#include "Nexus.hh"

class myControl
{
public:
	myControl(MyMap &myMatrix);

	~myControl();

	enum class Weapon { sword, bow, unarmed };

	struct Entio
	{
		int currentActions;
		int totalTurns;
		int fatigue;
		int hitPoints;
		int arrows;
		int positionX;
		int positionY;
		Weapon myWeapon;
		std::string myName;
		bool isAlive;
		bool isPlaying;
		static MyMap &Matrix; //Tambi�n se lo paso por referencia a los entios (de otro modo no me reconoce al objeto mapa al usar un m�todo del struct Entio)
		std::stack<Entio> mistakenActions; //Para undoActions y redoActions
		char tile;

		Entio(int i, bool flag)
		{
			if (flag)
			{
				std::string studentArmy[] = { "Carla", "Bea", "Guille", "Alessandro", "Ferran", "Dani" }; //Mis arrays de strings que s�lo existe en el scope del constructor de Entio
				myName = studentArmy[i];
			}
			else
			{
				std::string teacherArmy[] = { "Tona", "Radev", "Carles", "Oscar", "Rita", "Albert" }; //...
				myName = teacherArmy[i];
			}

			currentActions = 0;
			totalTurns = 0;
			fatigue = 0;
			hitPoints = 10;
			arrows = 10;
			myWeapon = Weapon::unarmed;
			isAlive = true;
			tile = '.';
		}
		bool myControl::Entio::meleeCheck(enti::InputKey direction);

		bool myControl::Entio::terrainCheck(int originX, int originY, int destinyX, int destinyY, enti::InputKey direction);
	};

	enum class playerState { keepCalm, attackEntio, moveEntio, undoAction, redoAction, changeEntio, endTurn, notMyTurn };

	struct thePlayers
	{
		int remainingActions; // Las acciones que le quedan por hacer en el turno
		std::vector <Entio> myArmy;
		size_t myArmySize;
		Entio currentEntio;
		bool myTurn;
		enti::InputKey lastKeyPressed;
		playerState state;
		bool tag;
		char enemyEntios[6];
		std::stack<Entio> mistakenActions;

		thePlayers(MyMap &myMatrix) : Matrix{ myMatrix } {}

		void myControl::thePlayers::keepCalm(enti::InputKey keyPressed);

		bool myControl::thePlayers::checkPlayer();

		void myControl::thePlayers::attackEntio(enti::InputKey direction);

		void myControl::thePlayers::undoAction();

		void myControl::thePlayers::redoAction();

		void myControl::thePlayers::moveEntio(enti::InputKey direction);

		void myControl::thePlayers::changeEntio();

		void myControl::thePlayers::endTurn();

		MyMap &Matrix;
	};
	friend bool operator < (const Entio &A, const Entio &B); //He sobrecargado el operador para que se considere que el Entio con menor fatiga sea el mayor

private:

	thePlayers student;
	thePlayers teacher;
	MyMap &Matrix;
};

