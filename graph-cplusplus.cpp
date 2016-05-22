#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
 int MatrizOriginal[1000][1000];
 int MatrizAux[1000][1000];
 int MatrizLoca[1000][1000];
 
 class nodo{
	 public:
	 string coor;
	 int i;
	 int j;
	 int longitud;
	 nodo *sig;
	 nodo(string c, int posi,int posj, int lon, nodo* s){
		 coor = c;
		 i = posi;
		 j= posj;
		 longitud = lon;
		 sig = s;
	 }
 };
 
 class lista{
	 public:
	 nodo *primero;
	 lista(){
		 primero = NULL;
	 }
	  void HacerProducto(int matriz[][1000], int mat_aux[][1000],int matrizLoca[][1000], int n, int longitud);	 
	  bool EsVacia();
	  void CaminosLong1(int matriz[][1000],int n);
	  void MostrarLista();
	  void OrdenarLista();
 };
 
void ArchivoMatriz(int matriz[][1000],int n){
	fstream f;
	f.open("Hendrix_Roa.out",ios::out);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			f << matriz[i][j]; 
		}
		f <<endl;
	}
	f<<endl;
	f.close();
}

void lista::MostrarLista(){
	nodo *buffer=primero;
	int aux = 1;
	fstream f;
	f.open("Hendrix_Roa.out",ios::out | ios::app);
	f <<"Caminos de longitud "<<aux<<endl;
	while(buffer != NULL){
		if(buffer->longitud > aux){
			aux++;
			f<<endl;
			f<<"Caminos de longitud "<<aux<<endl;
		}
		f <<"V"<<buffer->i<<" a V"<<buffer->j<<"= ";
		string buf= buffer->coor;
		int tam = buf.length();
		for(int i=0;i < tam;i++){
			f<<"V"<<buf[i]<<" ";
		}
		
		f<<endl;
		buffer = buffer->sig; 
	}
	f.close(); 
}

void LlenarMatriz(int matriz[][1000],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matriz[i][j]=0; 
		}
	}
}

void CopiarMatriz(int destino[][1000],int fuente[][1000],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			destino[i][j] = fuente[i][j]; 
		}
	}
}

bool lista::EsVacia(){return !primero;} 

void lista::OrdenarLista(){
	nodo *actual;
	nodo *siguiente;
	string auxcoor;
	int auxi,auxj,auxlong;
	actual = primero;
	while(actual->sig != NULL){
		siguiente = actual->sig;
		while(siguiente!=NULL){
			if(actual->i > siguiente->i || actual->longitud > siguiente->longitud){
				auxcoor = siguiente->coor;
				auxi = siguiente->i;
				auxj = siguiente->j;
				auxlong = siguiente->longitud;
				siguiente->coor = actual->coor;
				siguiente->i = actual->i;
				siguiente->j = actual->j;
                siguiente->longitud = actual->longitud;
                actual->coor = auxcoor;
                actual->i = auxi;
                actual->j = auxj;
                actual->longitud = auxlong;  				
			}
			siguiente = siguiente->sig;
		}
		actual = actual->sig;
		siguiente = actual->sig;
	}
}

string ConvertirCoor(int i,int j){
	ostringstream convert;
	string aux1,aux2,aux3;
	convert << i;
	aux1 = convert.str();
    convert.str("");
	convert << j;
	aux2 = convert.str();
	convert.str("");
	aux3 = aux1 + aux2;
	return aux3;
}

void lista::CaminosLong1(int matriz[][1000],int n){
	string strBuffer;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(matriz[i][j]==1){
				if(EsVacia()){
					    strBuffer = ConvertirCoor((i+1),(j+1));
						primero = new nodo(strBuffer,i+1,j+1,1,NULL);
						strBuffer="";
				}else{
					nodo *buffer=primero;
					if(buffer->i > (i+1)){
						strBuffer = ConvertirCoor((i+1),(j+1));
						primero = new nodo(strBuffer,i+1,j+1,1,buffer);
						strBuffer = "";
					}else{
						while(buffer->sig && buffer->sig->i < (i+1)){
							buffer = buffer->sig;
						}
						strBuffer = ConvertirCoor((i+1),(j+1));
						buffer->sig = new nodo(strBuffer,i+1,j+1,1,buffer->sig);
						strBuffer = "";
					   }
					}
				}
			}
		}
	}

void lista::HacerProducto(int matriz[][1000], int mat_aux[][1000],int matrizLoca[][1000], int n, int longi){
	string strBuffer,strBuffer1,strBuffer2,buf,auxi,aaa;
	ostringstream bf,b;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				mat_aux[i][j] = mat_aux[i][j] | (matrizLoca[i][k] & matriz[k][j]);
				if((matrizLoca[i][k] & matriz[k][j])==1){
						     nodo *bfaux = primero;
						     while(bfaux != NULL){
								 if(bfaux->i == (i+1) && bfaux->j == (k+1) && bfaux->longitud != longi){
									   b << (j+1);
									   buf = b.str(); 
									   strBuffer1 = bfaux->coor;
									   strBuffer1.append(buf);
									   int a = bfaux->i;
									    nodo *auxiliar = primero;
									    primero = new nodo(strBuffer1,a,j+1,longi,auxiliar);
									    strBuffer = strBuffer1 = strBuffer2 = "";    
									    auxi="";
									    b.str("");
									    buf="";
									  break;
								 }
								 bfaux=bfaux->sig; 
								    auxi="";
								    strBuffer = strBuffer1 = strBuffer2 = "";  
									  b.str("");
									  buf=""; 
								 }    
					    }
					}
				} 
			} 
		}
	
int main(){
	fstream file,file2;
	lista list;
	int R,N;
	file.open("tarea1.in",ios::in);
	if(!file.is_open()){
		cout<<"Erro, no se pudo abrir el archivo!"<<endl;
	}else{
		while(!file.eof()){
			file >> R >> N;
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					file >> MatrizOriginal[i][j];
					MatrizAux[i][j] = 0;
					MatrizLoca[i][j] = MatrizOriginal[i][j]; 
				}
			}
		}
	}
	
   list.CaminosLong1(MatrizOriginal,N);

   if(R > 1){
   for(int k=2;k<=R;k++){
   list.HacerProducto(MatrizOriginal,MatrizAux,MatrizLoca,N,k);
   CopiarMatriz(MatrizLoca,MatrizAux,N);
   LlenarMatriz(MatrizAux,N);   
   }
   //mostrar otros caminos 
  }
     ArchivoMatriz(MatrizLoca,N);
     cout<<endl;
     list.OrdenarLista();
     list.MostrarLista();
     cout<<endl;
     
return 0;
}
