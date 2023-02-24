#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

struct pessoa{;
    string nome;
    int rg;
};


void limpaTela(){
 system("CLS");
}

void imprimeSequencial(pessoa *PonteiroSequencial, int tamanhoDaLista){

 int cont;
 for(cont = 0; cont < tamanhoDaLista; cont++){
    cout << cont << "-" << PonteiroSequencial[cont].nome << "," << PonteiroSequencial[cont].rg << "\n";
 }

}

 void adcComecoInicial( pessoa *&ponteiroSequencial, int *tamanhoDalista, string nome, int rg){

     //Se a lista for vazia cria uma lista nova
     if(tamanhoDalista == 0){

    //Caso a lista ja tenha membros
      pessoa *novaListaSequencial = new pessoa[1];

    //Insere o primeiro novo elemento
    novaListaSequencial[0].nome = nome;
    novaListaSequencial[0].rg = rg;

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

 }else{
       //Caso a lista ja tenha membros
  pessoa *novaListaSequencial = new pessoa[*tamanhoDalista + 1];

  //Insere o primeiro novo elemento
  novaListaSequencial[0].nome = nome;
  novaListaSequencial[0].rg = rg;

  //Passa os elementos do vetor antigo para o novo
 int cont;
 for(cont = 0; cont < *tamanhoDalista; cont++ ){
    novaListaSequencial[cont + 1].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont + 1].rg = ponteiroSequencial[cont].rg;
}

//Atualiza o ponteiro para a lista nova
ponteiroSequencial = novaListaSequencial;

 }

 //Aumenta o tamanho da lista
*tamanhoDalista = *tamanhoDalista + 1;

 }


int main(){

  int funcaoDesejada = 1;

//Ponteiro para lista sequencial
  pessoa *ponteiroSequencial;

//Tamanho da Lista
  int tamanhoDalista = 0;

  //Exemplos
  pessoa *exemploListaSequencial = new pessoa[1];

 //Dois registro de exemplo
   /*exemploListaSequencial[0].nome = "Gregory";
   exemploListaSequencial[0].rg = 3456;
   exemploListaSequencial[1].nome = "Victor";
   exemploListaSequencial[1].rg = 6543;*/

   //Faz o ponteiro principal apontar para o novo vetor
    ponteiroSequencial = exemploListaSequencial;


while(funcaoDesejada < 10 && funcaoDesejada > 0){

 imprimeSequencial(ponteiroSequencial, tamanhoDalista );

        //Mostrando o menu
 cout << " Operacoes \n";
 cout << " 1 - Insercao de um node no inicio da lista \n";
 cout << " 2 - Insercao de um node no fim da lista \n";
 cout << " 3 - Insercao de um node na posição N \n";
 cout << " 4 - retirar  um node no inicio da lista";
 cout << " 5 - Retirar  um node no fim da lista \n";
 cout << " 6 - Retirar  um node na posição N \n";
 cout << " 7 - procurar um node com o campo RG \n";
 cout << " 8 - Imprimir a Lista. \n";
 cout << " 9 - Imprimir do sistema. \n";
 cout << " \n Escolha um numero e pressione ENTER: \n";

     // Lendo a opção do usuario
  cin >> funcaoDesejada;

  limpaTela();

  //Variaveis usadas nas operações
   string nome;
   int rg;

  //Chama a função desejada
  switch(funcaoDesejada){
      case 1:
           cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista \n";

           cout << "Digite um nome:";
           cin >> nome;
           cout << "digite um rg:";
           cin >> rg;

           adcComecoInicial(ponteiroSequencial, &tamanhoDalista, nome, rg);
        break;

         case 2:
           cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista \n";

           cout << "Digite um nome:";
           cin >> nome;
           cout << "digite um rg:";
           cin >> rg;

           //Se a lista for vazia uso a função de criar no inicio
           if(tamanhoDalista == 0){
            adcComecoInicial(ponteiroSequencial, &tamanhoDalista, nome, rg);
           }else{

           }



        break;

  }

}

return 0;
}
