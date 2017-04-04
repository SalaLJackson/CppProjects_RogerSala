#include <vector>

//Constructor sin argumentos
std::vector<int>v1;

//Constructor con una lista de iniciación
std::vector<int> v12({ 10,9,8,7,6,5,4,3,2,1 });

//Constructor de copia
std::vector<int>v4(v12);

//Constructor con num elementos
std::vector<int>v9(5);

//Constructor con num de elementos y valor inicial de estos
std::vector<int>v10(5, 10);

//Constructor con iteradores que copia v12 en v7
std::vector<int>v7(v12.begin(), v12.end());

//Constructor con iteradores,se puede dar un rango, copiando todos los elementos en v7 menos el primero y el último
std::vector<int>v7(v12.begin() + 1, v12.end() - 1);

//Constructor con iteradores, desde arrays
int myArray[]{ 16,2,77,29 };
std::vector<int> v20(myArray, myArray + sizeof(myArray) / sizeof(int));

//Constructor con iteradores desde array
int *pv;
pv = new int[4]{ 1,2,3,4 };
std::vector<int> v21(pv, pv + 4);