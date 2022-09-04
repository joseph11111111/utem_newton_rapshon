#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;
/*
* metodo de newtone rapshon
*/ 
 
void evaluapoli(int n, double *f, double x, double &p);
void derivapoli(int n, double *f, double *fd);
void newtonraphson(int n, double *f, double *fd, double &x, int &contador);
 
int main(){
 
 
 //leera el fichero en donde tenemos los datos de nuestro polinomio 
 ifstream label1 ("datos//datos.in");
 
 int n, contador = 0;
 double *f, *fd, x;
 
 
 //Indicamos donde puede encontrar los datos por si los quiere modificar
 cout << "El grado del polinomio y sus coeficientes están en datos/datos.in"<<endl<<endl;
 
 
 //Introduce el grado del polinomio y lo mostramos por la pantalla
 label1 >> n; 
 cout << "grado = " << n << "\n\n";
  
 
 f = new double [n+1];   // Creamos un arreglo para los coeficientes del polinomio
 fd = new double [n];    // Creamos otro arreglo para los coeficientes de la derivada del polinomio
 
 
 // Se obtinen los valores desde datos.in y se imprimen en pantalla los coeficientes del polinomio
 cout << "Coeficientes del polinomio\n\n";
 
 for (int i = n; i > -1; i--) {  
 
  label1 >> f[i]; 
 
  cout << "F" << i << " = " << f[i] << "\n";
 
 }
 
 cout << "\n";
 
 derivapoli (n, f, fd);  // Obtenemos la primera derivada y se imprimen sus coeficientes
 
 cout << "Coeficientes del polinomio primera derivada\n\n";
 
 for (int i = n - 1; i > -1; i--) {  
 
  cout << "Fd" << i << " = " << fd[i] << "\n";
 
 }
 
 cout << "\n";
 
 cout << "Introduzca el valor de inicio para la raiz: \n" << endl << "X = "; 
 
 
 // Se introduce el valor de x
 
 cin >> x;
 cout << endl;
 
 //Llamamons a la fución del método de Newton-Raphson para resolver el polinomio
 newtonraphson (n, f, fd, x, contador); 
 
 
 //mostramos los resultados
 cout << "La raiz es x = " << x << " y se obtuvo en " << contador << " iteraciones"<<endl;
 cout << "==integrantes=="<<endl;
 cout << "Jose Zamorano Covarrubia"<<endl;
 
 return 0;
 
}
 
void evaluapoli(int n, double *f, double x, double &p){
 
 int i; 
 double *a;
 
 a = new double [n];
 
 
 // Crea una copia de los elementos de f[i] porque el ciclo for inferior los destruye
 for (i = n; i > -1; i--) {
  a[i] = f[i];                   
 } 
 
 for (i = n; i > 0; i--) {
 
 // P es el valor del polinomio en el punto x
  p = a[i] * x + a[i - 1];
 
  a[i - 1] = p;
 
 } 
}
 
void derivapoli(int n, double *f, double *fd){
 
 int i;
 
 for (i = n; i > 0; i--){
 
  fd[i-1] = i * f[i];
 
 }
 
}
 
void newtonraphson(int n, double *f,double *fd, double &x, int &contador){
 
 double p=0, y1, y2, verificador = 0, z = 0;
 
 
 // La función evaluapoli determina el valor del polinomio en el punto x, determina el valor del polinomio en el punto.
 do {    evaluapoli (n, f, x, p);
 
  y1 = p;
  evaluapoli (n-1, fd, x, p);  //Valor de la primera derivada en el punto
  y2 = p;
  x = x - y1/y2;
  verificador = fabs(x - z); //Obtiene el valor absoluto
  z = x;
  contador += 1;  
 } while (verificador > 1e-10);//Tolerancia o diferencia entre dos valores consecutivos
 
}
