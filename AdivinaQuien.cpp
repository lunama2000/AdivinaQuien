#include <iostream>
#include <string.h>

using namespace std;
int yesNo(string);
int main() {
  /*
    [0] Super Mario
    [1] Bigote
    [2] Bueno
    [3] Persona "Humanoide"
    [4] Pelo largo
    [5] Pelo claro
    [6] Chaparro
    [7] Dinosaurio
    */
  int personajes[16][8] = {
{1,1,1,1,0,0,1,0}, //Mario
{1,1,1,1,0,0,0,0}, //Luigi
{1,1,0,1,0,0,1,0}, //Wario
{1,1,0,1,0,0,0,0}, //Waluigi
{1,0,1,1,1,1,0,0}, //Pricesa Peach
{1,0,1,1,1,0,0,0}, //Princesa Daisy
{0,0,1,0,0,0,1,0}, //Kirby
{1,0,1,0,0,0,1,1}, //Yoshi
{1,0,0,0,0,0,0,1}, //Bowser
{1,0,0,0,0,0,1,1}, //Bowser Jr
{1,0,1,0,0,0,0,0}, //Donkey Kong
{1,0,1,0,0,0,1,0}, //Diddy Kong
{0,0,0,1,0,0,0,0}, //Ganondorf
{0,0,1,1,0,1,0,0}, //Link
{0,0,1,1,1,1,0,0}, //Zelda
{0,0,1,1,0,0,0,0}}; //Sheik
  int guess[8] = {0,0,0,0,0,0,0,0};
  string nombres[] = {"Mario", "Luigi", "Wario", "Waluigi", "Pricesa Peach", "Princesa Daisy", "Kirby", "Yoshi", "Bowser", "Bowser Jr", "Donkey Kong", "Diddy Kong","Ganondorf", "Link", "Zelda", "Sheik"};
  
  cout << "Elige uno de los siguientes personajes y lo intentaré adivinar:" << endl;
  for(int i = 0; i < 16; i++){
    cout << "  " << i+1 << ". " <<nombres[i] << endl;
  }
  cout << endl << endl;

  guess[2] = yesNo("Tu personaje es de los buenos?");
  guess[0] = yesNo("Tu personaje es de la franquicia de Super Mario?");
  guess[3] = yesNo("Tu personaje es un humano/humanoide?");
  if(guess[3] == 0){
    guess[7] = yesNo("Tu personaje es un dinosaurio o tortuga?");
  }else{
      guess[5] = yesNo("Tu personaje tiene el cabello de un color claro?");
      guess[1] = yesNo("Tu personaje tiene bigote?");
      if(guess[1] == 0){
        guess[4] = yesNo("Tu personaje tiene el cabello largo?");
        
      }
    }
  guess[6] = yesNo("Tu personaje tiene baja estatura a comparacion de los demas personajes?");
  
  
  


  bool coincide = false;
  
  for(int persona = 0; persona < 16; persona++){
    for(int i = 0; i < 8; i++){
      if(guess[i] == personajes[persona][i]){
        coincide = true;
      }else{
        coincide = false;
      }
  
      if(coincide == false){
        break;
      }
    }
    if(coincide == true){
      cout << "Tu personaje es " << nombres[persona] << endl;
      return 0;
    }
  }

  cout << "La informacion que respondiste no coincide con ninguno de los personajes :(" << endl;
  
}


int yesNo(string pregunta){
  cout << pregunta << endl;
  cout << "  1. Si\n  2. No o n/a" << endl;
  uint temp;
  cin >> temp;
  while(temp>2 || temp < 1){
    cout << "Elige una de las opciones disponibles(Escribe 5 si quieres volver a imprimir el menu)" << endl;
    cin >> temp;
    if(temp == 5)temp = yesNo(pregunta);
    }

  if(temp == 1){
    return 1;
  }else{
    return 0;
  }
}