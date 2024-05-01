#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <string>
#include <windows.h>

/*
* 
* Esta aplicación sirve para transcribir un texto a su forma fonética, ya que en
* el lenguaje castellano no pronunciamos las palabras tal cual las escribimos, sino 
* que, y dependiendo del contexto incluso, las pronunciamos de distinta manera. Por
* ello este programa lo que hace es llamar a un código en python que lo que hará será,
*  o bien de manera escrita o bien de manera oral, generar un fichero txt con una oración 
* que el usuario haya dicho. Más tarde, esta aplicación en c++ lo que hará será leer ese mismo 
* fichero con la oración escrita en el lenguiaje natural castellano y reescribir un otro fichero
* el texto original que se ha generado con python y por otra parte el texto Transcrito que se irá 
* generando mediante funciones, el cual estará comprendido entre los carácteres "[ //]".
* Recalcar que una vocal que lleva acento, el acento se elimina y se pone un apostrofe " ' " en 
* la sílaba misma donde está la vocal acentuada (por ejemplo, en el caso de " " acabaría 
* siendo tal que " ")
* 
* Ejemplos:
* Frase original:
* Frase transcrita :
* 
**************************************************************************************************************
* 
* Frase original: 
* Frase transcrita: 
* 
*/

using namespace std;

/*
* Declaración de las funciones auxiliares
*/
string Transcripcion(string);
void Escribir_en_Fichero(string, string);
string Leer_Fichero(string & );
string Vocales(string);

/*
*
* Funcion main
* Funcion básica que inicializa el proyecto y que llama al resto de funciones auxiliares
* para el correcto funcionamiento de la aplicación. En ella se ha creado mediante cout un
* pequeño menú explicatorio de que es y que hace la aplicación
*
*/
int main(void){
    bool bandera = true;
    int salir;
    string frase_or = " ", frase, frase1;
    
    cout << "	***************************************************************************************************" <<endl;
    cout << "	* Bienvenidos a la aplicacion para la Transcripcion fonetica de palabras castellanas.             *"  <<endl;
    cout << "	* En esta aplicacion podra tanto escribir la oracion tan larga como lo desee, con signos          *" <<endl;
    cout << "	* de puntuacion, acentos, MAYUSCULAS y minusculas a su alcance, siempre y cuando respete          *" <<endl;
    cout << "	* que las palabras han de pertenecer a la lengua castellana. Una vez tenga la oracion lista       *" <<endl;
	cout << "	* pulse enter y asi se generara un archivo txt con su oracion original y la transcripcion         *" <<endl;
	cout << "	* de la misma.                                                                                    *" <<endl;
	cout << "	* Por otra parte, tambien podra generar la oracion que desee de manera vocal, es decir, podra     *" <<endl;
	cout << "	* hablarle al ordenador y decirle la oracion que desee; no obstante, en este modo los signos      *" <<endl;
	cout << "	* de puntuacion no se veran correctamente reflejados, sino que si le dice 'punto'' al ordenador   *" <<endl;
	cout << "	* esperando que aparezca un '.', lo que saldra sera la palabra 'punto' en la transcripcion.       *" <<endl;
	cout << "	* Al transcurrir un par de segundos sin hablar el ordenador supondra que ya ha dicho la oracion   *" <<endl;
	cout << "	* entera y generara la transcripcion de la misma manera que si lo hubieras escrito. En un fichero *" <<endl;
	cout << "	* txt saldra tanto la frase original como la transcrita.                                          *" <<endl;
	cout << "	*                                        MUCHAS GRACIAS POR USARNOS.                              *" <<endl;
	cout << "	***************************************************************************************************" <<endl;
    cout << "\n"<<endl;
    

    system("python untitled.py");
    
    frase1 = Leer_Fichero(frase_or);
    Escribir_en_Fichero(frase_or, frase1);
    
    //system("start mostrar_fonetica.html");
    system("notepad fonetica.txt");

    return 0;
}

/*
* 
* Funcion Transcripcion
* Parámetros de entrada: String
* Parámetros de salida: String
* A esta función se le pasa un string que será una frase del fichero donde está lo 
* que se quiere transcribir y por consiguiente y mediante un conjunto anidado de if-else
* dentro de un bucle for se irá Transcribiendo para así obtener la frase transcrita de la
* original, la cual se devolverá mediante el return. En este caso se ha hecho uso tanto de
* el valor numérico de los char del abecedario (Para el único caso de la ñ) y un tipo char 
* de cada palabra del abecedario.
*     
*/
string Transcripcion(string entrada){
    string frase, salida;
	char ultima;
	
	frase = Vocales(entrada);
    for(int i = 0; i < frase.length(); i++){
        cout << "\n1." <<static_cast<int>(frase[i]) << " + " << frase[i] <<endl;
    	if(static_cast<int>(frase[i] == -79)){
        	salida += "ɲ";
			cout << "Ñ ";
		}
        else if(frase[i] == '.' || frase[i] == ',' || frase[i] == ';' || frase[i] == ':'){
        	if(frase[i - 1] == '\''){
        		salida = "/";
        		cout << "PUNTUACION SEPARADA";
			}
			else{
	        	salida += "/";
	        	cout << "puntuacion";
	        }
		}
        else if(frase[i] == 'a'){
        	if (frase[i + 1] == 'o' || frase[i + 1] == 'u' || frase[i + 1] == 'l' || frase[i + 1] == 'j' || (frase[i + 1] == 'g' && (frase[i + 2] == 'e' || frase[i + 2] == 'i'))){
				salida += "ạ";
	        	cout << "a1";
	        }
	        else if((i == 0 && (frase[i + 1] == 'n' || frase[i + 1] == 'm')) || ((i == 1 && frase[0] == '\'') && (frase[i + 1] == 'n' || frase[i + 1] == 'm')) || ((frase[i - 1] == 'm' && frase[i + 1] == 'n') ||( frase[i - 1] == 'n' && frase[i + 1] == 'm'))){
	        	salida += "ã";
	        	cout << "a2";
			}
			else{
				salida += "a";
				cout << "a3";
			}
		}
		else if(frase[i] == 'e'){
			if(frase[i + 1] == 'r' || frase[i - 1] == 'r' || frase[i + 1] == 'j' || frase[i + 1] == 'i' || frase[i - 1] == 'i' || frase[i + 1] == 'y' || (frase[i + 1] == 'g' && (frase[i + 2] == 'e' || frase[i + 2] == 'i'))){//Falta mirar si con rey, peine, pierna
				salida += "ę";
				cout << "e1";
			}
	        else if((i == 0 && (frase[i + 1] == 'n' || frase[i + 1] == 'm')) || ((i == 1 && frase[0] == '\'') && (frase[i + 1] == 'n' || frase[i + 1] == 'm')) || ((frase[i - 1] == 'm' && frase[i + 1] == 'n') ||( frase[i - 1] == 'n' && frase[i + 1] == 'm'))){
				salida += "ẽ";
				cout << "e2";
			}
			else{
				salida += "e";
				cout << "e3";
			}
		}
		else if(frase[i] == 'i'){
			salida += "i";
			cout << "i1";
		}
		else if(frase[i] == 'o'){
			/*
				salida += "ǫ";
				cout << "o1";
				
				salida += "õ";
				cout << "o2";
			*/
			
			salida += "o";
			cout << "o3";
		}
		else if(frase[i] == 'u'){
			salida += "u";
			cout << "u1";
		}
        else if(frase[i] == 'v' || frase[i] == 'b'){
        	if((i == 1 && frase[0] == '\'') || i == 0 || frase[i - 1] == 'n' || frase[i - 1] == 'm' || frase[i - 1] == -79 || frase[i + 1] == 'n' || frase[i + 1] == 'm' || frase[i + 1] == 79){//La ñ == -79 sigue dando problemas
	            salida += "b";
	            cout << "2 ";
	        }
	        else{
	        	salida += "β";
	        	cout << "3 ";
			}
        }
        else if(frase[i] == 'c'){
        	if(frase[i + 1] == 'h'){
        		salida += "t͡s";
	            i++;
	            cout << "4 ";
			}
			else if(frase[i + 1] == 'e' || frase[i + 1] == 'i'){
				salida += "θ";
				cout << "5 ";
			}
			else{
	            salida += "k";
	            cout << "6 ";
			}//mirar esto por lo  de clase que va con k y no theta 
		}
		else if(frase[i] == 'k' || frase[i] == 'q'){
			salida += "k";
            cout << "7 ";
		}
		else if(frase[i] == 'z'){
			salida += "θ";
			cout << "8 ";
		}
		else if(frase[i] == 'f'){
			if(frase[i + 1] != 'n'){
            	salida += "f";
            	cout <<"9 ";
			}
		}
		else if(frase[i] == 'g'){
			if(frase[i + 1] == 'e' || frase[i + 1] == 'i'){
	            salida += "χ";
				cout << "10 ";
			}
			else if((frase[i + 1] == 'n' && i == 0) || (i == 1 && frase[0] == '\'' && frase[i + 1] == 'n')){//gnomo la g no se pronuncia
				cout << "11 ";
			}
			else if(frase[i + 1] == 'a' || frase[i + 1] == 'o' || frase[i + 1] == 'u'){
				salida += "ɣ";
				cout << "12 ";
			}
			else{            
				salida += "g";
				cout << "13 ";
			}
		}
		else if(frase[i] == 'j'){
			salida += "χ";
            cout << "14 ";
		}
		else if(frase[i] == 'm'){
			salida += "m";
            cout << "15 ";
		}
		else if(frase[i] == 'n'){
			if(frase[i + 1] == 'p' || frase[i - 1] == 'p' || frase[i + 1] == 'm' || frase[i - 1] == 'm' || ((frase[i + 1] == 'b' || frase[i + 1] == 'v') && (frase[i + 2] == 'n' || frase[i + 2] == 'm' || static_cast<int>(frase[i + 2] == -79)))){
				salida += "m";
            	cout << "16 ";
			}
			else if((frase[i - 1] == 'b' || frase[i - 1] == 'v') && (i - 1 == 0 || (i - 1 == 1 && frase[0] == '\''))){
				salida += "m";
            	cout << "17 ";
			}
			else if(frase[i + 1] == 'f'){
				salida += "ɱ";
            	cout << "18 ";
			}
			else if((frase[i + 1] == 'c' && frase[i + 2] == 'h') || (frase[i + 1] == 'l' && frase[i + 2] == 'l')){//mirar a ver que falta
				salida += "nj";
            	cout << "19 ";
			}
			else if(frase[i + 1] == 'z' || (frase[i + 1] == 'c' && (frase[i + 2] == 'e' || frase[i + 2] == 'i')) || (frase[i - 2] == 'c' && (frase[i - 1] == 'e' || frase[i - 1] == 'i'))){
				salida += "n̟";
            	cout << "20 ";
			}
			else if(frase[i - 1] == 't' || frase[i + 1] == 'd' || frase[i - 1] == 't' || frase[i - 1] == 'd'){
				salida += "n̪";
            	cout << "21 ";
			}
			else if(frase[i + 1] == 'k' || frase[i - 1] == 'k' || frase[i + 1] == 'g' || frase[i - 1] == 'g' || frase[i + 1] == 'j' || frase[i - 1] == 'j' || (frase[i + 1] == 'c' && (frase[i + 2] == 'a' || frase[i + 2] == 'o' || frase[i + 2] == 'u')) || (frase[i - 2] == 'c' && (frase[i - 1] == 'a' || frase[i - 1] == 'o' || frase[i - 1] == 'u'))){
				salida += "ŋ";
            	cout << "22 ";
			}
			else{
				salida += "n";
				cout << "38 ";
			}
		}
		else if(frase[i] == 'r'){
			if(frase[i + 1] == 'r'){
				salida += "r";
	            i++;
	            cout << "23 ";
			}
			else if (i == 0 || (i == 1 && frase[0] == '\'')){
				salida += "r";
				cout << "23.1 ";
			}
			else{
				salida += "ɾ";
            	cout << "24 ";
			}
		}
		else if(frase[i] == 't'){
			if(frase[i - 1] == 'z'){// em theta en todos los casos
				salida += "̟t";
			}
			else{
				//salida += "t";
	            cout << "25 ";
	        }
		}
		else if(frase[i] == 'y'){//mirara a ver si es así
			salida += "y";
            cout << "26 ";
		}
		else if(frase[i] == 'h'){
			cout << "27 ";
		}
		else if(frase[i] == 'x'){
			salida += "ks";
			cout << "28 ";
		}
		else if(frase[i] == '\''){
			salida += '\'';
			cout << "29 ";
		}
		else if(frase[i] == 's'){
			if(frase[i + 1] == 'l' || frase[i + 1] == 'r' || frase[i + 1] == 'm' || frase[i + 1] == 'b' || frase[i + 1] == 'g' || frase[i + 1] == 'd' || frase[i - 1] == 'l' || frase[i - 1] == 'r' || frase[i - 1] == 'm' || frase[i - 1] == 'b' || frase[i - 1] == 'g' || frase[i - 1] == 'd'){
				salida += "s̬";
				cout << "30 ";
			}
			else{
				salida += "s";
				cout << "31 ";
			}
		}
		else if(frase[i] == 'l'){
			if(frase[i + 1] == 'l'){
				salida += "ʎ";
	            i++;
	            cout << "32 ";
			}
			else if((frase[i + 1] == 'c' && frase[i + 2] == 'h') || (frase[i - 2] == 'c' && frase[i - 1] == 'h') || (frase[i - 1] == 'l' && frase[i - 2] == 'l')){//mirar el palatal, faltan la ñ y el ni+e
				salida += "lj";
            	cout << "33 ";
			}
			else if((frase[i + 1] == 'c' && (frase[i + 2] == 'e' || frase[i + 2] == 'i')) || (frase[i - 2] == 'c' && (frase[i - 1] == 'e' || frase[i - 1] == 'i')) || frase[i + 1] == 'z' || frase[i - 1] == 'z'){
				salida += "l̟";
            	cout << "34 ";
			}
			else if(frase[i + 1] == 't' || frase[i + 1] == 'd' || frase[i - 1] == 't' || frase[i - 1] == 'd'){
				salida += "l̪";
            	cout << "35 ";
			}
			else{
				salida +="l";
				cout << "36 ";
			}
		}
		else if(frase[i] == 'p'){
			salida += "p";
			cout << "37 ";
		}
		else if(frase[i] == 'd'){
			if(frase[i - 1] == 'n' || frase[i - 1] == 'm' || frase[i - 1] == 'ñ'){
				salida += "d";
				cout << "38 ";
			}
			else{
				salida += "ð";
				cout << "39 ";
			}
			
		}//faltan cosas
        else{//quitarlo cuando ya esté porque los símbolos como ?¿¡€ no tienen que aparecer.  
            salida += frase[i];
            cout << "else " << i <<endl;
        }
    }

    return salida;
}

/*
* 
* Función Escribir_en_Fichero
* Parámetros de entrada: String, String
* Parámetros de salida: void
* 
* Esta función editará el fichero fonetica.txt para que en el mismo se pueda leer una
* primera frase inicial "Texto original: " precedida del texto original que estaba
*  en el fichero de inicio ya modificado con anterioridad por python. A continuación 
* se encontrará con la siguiente frase "Texto transcrita [" y su consiguiente Trasncripción 
* de la frase original, todo esto finalizado por un "//]".
* 
*/
void Escribir_en_Fichero(string entrada, string salida){
    ofstream fichero;
    
    try{
        fichero.open("fonetica.txt", ios::binary);
        fichero << "Texto original: \n";
        fichero << entrada;
        fichero << "\nTexto transcrito: \n";
        fichero << salida;
        fichero.close();
        
        cout << "Escritura realizada correctamente." <<endl;
    }catch(exception e){
        cout << "Error al escribir en el fichero fonetica.txt" << e.what() << endl;
    }

    return;
}

/*
*
* Funcion Leer_Fichero
* Parámetros de entrada: String
* Parámetros de salida: String, String
* 
* Esta función lo que hace es leer de un fichero llamado entrada.txt 
* la información linea por linea y la deposita en un string, a su vez, 
* esta función llama a la función auxiliar Transcripcion pasándole un 
* string  para transcribir cada frase del fichero entrada.txt a como se 
* pronunciaría, para al final devolver mediante el return un string con 
* todo el texto nuevo de como se pronunciaría, es decir, la transcripción
* correctamente generada y por referencia el texto que se ha leido del fichero 
* entrada.txt
*
*/
string Leer_Fichero(string & entrada){
    string salida, texto, x, ayuda, letra;
    size_t pos;
    ifstream fichero;
    bool bandera = false;

    fichero.open("entrada.txt", ios::binary);
    while(getline(fichero, x)){
        istringstream auxiliar(x);
        salida += "[";
        
		auxiliar >> texto;
        ayuda = texto;

		pos = texto.find('\'');
        texto.erase(pos, 1);
        
		entrada += texto; 
        entrada += " ";
        
		salida += Transcripcion(ayuda);
		
		while(auxiliar >> texto){
			
			if(texto[0] == '\''){
				if(ayuda[ayuda.length() - 1] == texto[1]){
					salida += ": ";
					letra = texto[1];
					texto.erase(texto.begin ()+ 1);
					bandera = true;
				}
				else{
					salida += " ";
				}
			}
			else{
				if(ayuda[ayuda.length() - 1] == texto[0]){
					salida += ": ";
					letra = texto[0];
					texto.erase(texto.begin());
					bandera = true;
				}
				else{
					salida += " ";
				}
			}
			
			salida += Transcripcion(texto);

            pos = texto.find('\'');
            texto.erase(pos, 1);
            if(bandera == true){
				bandera = false;
				entrada += letra;
				entrada += texto; 
            	entrada += " ";
			}
			else{
				entrada += texto; 
            	entrada += " ";
			}
            
            
			ayuda = texto;
        }
        
        if(salida[salida.length() - 1] == '/'){
        	salida += "/]";
		}
		else{
			salida += "//]";
		}

        salida += "\n";
        entrada += "\n";
    }

    fichero.close();

    return salida;
}

/*
* 
* Funcion Vocales
* Parámetros de entrada: string
* Parámetros de salida: string
* 
* A esta función se le pasa un string con la palabra a transcribir, y lo que hará será
* ir letra por letra observando que es, si es una letra con acento (á, é, í, ó, ú) o su 
* respectiva en mayúscula (Á, É, Í, Ó, Ú) o la ñ en mayúsculas o minúsculas (ñ, Ñ) y devolverá 
* la vocal sin acento y en minúscula y en el caso de la ñ la ñ minúscula. Por otra parte, 
* si la letra es distinta de vocal con acento lo que hará será devolverla tal cual si está
* en minúscula y si está en mayúscula pasarla a miúscula y devolver la palabra entera en minúscula
* 
*/
string Vocales(string frase){
    string salida;
	
	for (int i = 0; i < frase.length(); i++){
		switch(static_cast<int>(frase[i])){
	        case -31:
	        case -63:
	            salida += 'a';
	            break;
	
	        case -23:
	        case -55:
	            salida += 'e';
	            break;
	
	        case -19:
	        case -51:
			    salida += 'i';
	            break;
	
	        case -13:
	        case -45:
			    salida += 'o';
	            break;
	
			case -6:
			case -38:
	            salida += 'u';
	            break;
				
			case -15:
			case -47:
				salida += 'ñ';
				break;
				
	        default:
	        	if (frase[i] >= 'A' && frase[i] <= 'Z') {
        			salida += frase[i] - ('A' - 'a');
        		}
        		else{
        			salida += frase[i];
				}
	            break;
    }

	}
    
    return salida;
}
