#include "../main.h"
#include "./ElRetornoDelJedi.h"
#include "../mini_test.h" // framework para tests unitarios

/*
**  Ejercicio 3: El retorno del (que te) jedi
**  Tests unitarios
*/

using namespace std;

void test_fila() {
	int N = 3;
	int M = 1;
	int H = 5;
	vector < vector <int> > E = vector < vector <int> >(N, vector <int> (M,0));
	//  0  
	//  10 
	//  100
	E[0][0] = 100;
	E[1][0] = 10;
	E[2][0] = 100;
	
	vector < vector < pair < int, char > > > DP;
	pair < int, vector <char>  > solucion = resolver(N,M,H,E,DP);
	vector <char> camino ; camino.push_back('X'); camino.push_back('X');
	pair < int, vector <char>  > esperado = make_pair(170,camino);
	ASSERT_EQ(solucion.first, esperado.first);
	ASSERT(compararVectores(solucion.second, esperado.second));

}

void test_columna() {

	int N = 1;
	int M = 3;
	int H = 0;
	
	vector < vector <int> > E = vector < vector <int> >(N, vector <int> (M,0));
	//   0 |  10 | 100
	E[0][0] = 0; E[0][1] = 10; E[0][2] = 100;
	vector < vector < pair < int, char > > > DP;
	pair < int, vector <char>  > solucion = resolver(N,M,H,E,DP);
	vector <char> camino ; camino.push_back('Y'); camino.push_back('Y');
	pair < int, vector <char>  > esperado = make_pair(100,camino);
	ASSERT_EQ(esperado.first, solucion.first);
	ASSERT(compararVectores(solucion.second, esperado.second));

}

void test_unico() {
	int N = 1;
	int M = 1;
	int H = 666;
	vector < vector <int> > E = vector < vector <int> >(N, vector <int> (M,0));
	vector < vector < pair < int, char > > > DP;
	pair < int, vector <char>  > solucion = resolver(N,M,H,E,DP);
	pair < int, vector <char>  > esperado = make_pair(0,vector <char> ());
	ASSERT_EQ(esperado.first, solucion.first);
	ASSERT(compararVectores(solucion.second, esperado.second));

}

void test_3x3() {
	int N = 3;
	int M = 3;
	int H = 5;
	vector < vector <int> > E = vector < vector <int> >(N, vector <int> (M,0));
	//   0  | 10 | 5
	//   15 | 15 | 5
	//   5  | 10 | 20
	E[0][0] = 0 ; E[0][1] = 10; E[0][2] = 10;
	E[1][0] = 15; E[1][1] = 15; E[1][2] = 5 ;
	E[2][0] = 5 ; E[2][1] = 10; E[2][2] = 20;
	vector < vector < pair < int, char > > > DP;
	pair < int, vector <char>  > solucion = resolver(N,M,H,E,DP);
	vector <char> camino ; 
	camino.push_back('Y'); camino.push_back('X');camino.push_back('X'); camino.push_back('Y');
	pair < int, vector <char>  > esperado = make_pair(10,camino);
	ASSERT_EQ(esperado.first, solucion.first);
	// imprimirCamino(solucion.second);
	ASSERT(compararVectores(esperado.second, solucion.second));

}

void test_3x3_informe() {
	int N = 3;
	int M = 3;
	int H = 1;
	vector < vector <int> > E = vector < vector <int> >(N, vector <int> (M,0));
	//   4  | -2 | -1
	//   6  | 7  | -5
	//   0  | 3  | 4
	E[0][0] = 4 ; E[0][1] = -2; E[0][2] = -1;
	E[1][0] = 6; E[1][1] = 7; E[1][2] = -5;
	E[2][0] = 0 ; E[2][1] = 3; E[2][2] = 4;
	vector < vector < pair < int, char > > > DP;
	pair < int, vector <char>  > solucion = resolver(N,M,H,E,DP);
	vector <char> camino ;
	camino.push_back('X'); camino.push_back('Y');camino.push_back('X'); camino.push_back('Y');
	pair < int, vector <char>  > esperado = make_pair(4, camino);
	ASSERT_EQ(esperado.first, solucion.first);
	// imprimirCamino(solucion.second);
	ASSERT(compararVectores(esperado.second, solucion.second));

}
void correr_tests_unitarios() {
    RUN_TEST(test_unico);
    RUN_TEST(test_fila);
    RUN_TEST(test_columna);
    RUN_TEST(test_3x3);
    RUN_TEST(test_3x3_informe);
}
