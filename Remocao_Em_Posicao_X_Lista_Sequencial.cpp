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

 void adcFimInicial( pessoa *&ponteiroSequencial, int *tamanhoDalista, string nome, int rg){

 //Cria uma lista com o tamanho maior
 pessoa *novaListaSequencial = new pessoa[*tamanhoDalista + 1];

  //Passa os elementos do vetor antigo para o novo
   int cont;
   for(cont = 0; cont < *tamanhoDalista; cont++ ){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
}
   //Posiciona o ultimo elemento
   novaListaSequencial[*tamanhoDalista].nome = nome;
   novaListaSequencial[*tamanhoDalista].rg = rg;

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Aumenta o tamanho da lista
   *tamanhoDalista = *tamanhoDalista + 1;


 }

 void adcPosicaoSequencial( pessoa *&ponteiroSequencial, int *tamanhoDalista, string nome, int rg, int posicao){

 //Cria uma lista com o tamanho maior
 pessoa *novaListaSequencial = new pessoa[*tamanhoDalista + 1];

 //Passa os elementos do vetor antigo para o novo
   int cont;
   for(cont = 0; cont < posicao; cont++ ){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
}

 //Adiciona o novo registro na posição correta
    novaListaSequencial[posicao].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[posicao].rg = ponteiroSequencial[cont].rg;

//Coloca o resto dos valores antigos

  for(cont = posicao + 1; cont < *tamanhoDalista + 1; cont++ ){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont - 1].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont - 1].rg;
}

  //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Aumenta o tamanho da lista
   *tamanhoDalista = *tamanhoDalista + 1;



 }

void removeInicioSequencial(pessoa *&ponteiroSequencial, int *tamanhoDalista){

 //Cria um vetor com uma posição a menos
 pessoa *novaListaSequencial = new pessoa[*tamanhoDalista - 1];

 //Passa os elementos do vetor antigo para o novo
   int cont;
   for(cont = 1; cont < *tamanhoDalista; cont++ ){
    novaListaSequencial[cont-1].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont-1].rg = ponteiroSequencial[cont].rg;
}

   //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Reduzo tamanho da lista
   *tamanhoDalista = *tamanhoDalista - 1;


}

void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDalista){

 //Cria um vetor com uma posição a menos
 pessoa *novaListaSequencial = new pessoa[*tamanhoDalista - 1];

 //Passa os elementos do vetor antigo para o novo menos o ultimo
   int cont;
   for(cont = 0; cont < *tamanhoDalista -1 ; cont++ ){
    novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
    novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
}

    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Reduzo tamanho da lista
   *tamanhoDalista = *tamanhoDalista -void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDalista

void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDalista, int posicao){

  //Cria um vetor com uma posição a menos
 pessoa *novaListaSequencial = new pessoa[*tamanhoDalista - 1]

 //Passa os valores de acordo com o contador
  int cont;
  for(cont = 0; cont < *tamanhoDalista - 1; cont++){

    if (cont < posicao){

    //Se estiver antes da posição, passa normalmente
     novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
     novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
    }else{
     novaListaSequencial[cont].nome = ponteiroSequencial[cont + 1].nome;
     novaListaSequencial[cont].rg = ponteiroSequencial[cont + 1].rg;
    }

     //Atualiza o ponteiro para a lista nova
    ponteiroSequencial = novaListaSequencial;

    //Reduzo tamanho da lista
   *tamanhoDalista = *tamanhoDalista - 1;

  }

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
   int rg, posicao;

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
            adcFimInicial(ponteiroSequencial, &tamanhoDalista, nome, rg);
            }

         case 3:
            cout << "Funcao escolhida:  3 - Insercao de um node na posição N \n";

           cout << "digite uma posicao:";
           cin >> posicao;
           cout << "Digite um nome:";
           cin >> nome;
           cout << "digite um RG:";
           cin >> rg;


           if(posicao == 0){
               //Se estiver adicionando no começo
               adcComecoInicial(ponteiroSequencial, &tamanhoDalista, nome, rg);
          }else if(posicao == tamanhoDalista){
              //Se estiver adicionado no final
              adcFimInicial(ponteiroSequencial, &tamanhoDalista, nome, rg);
          }else{
              //Adiciona uma posição especifica
              adcPosicaoSequencial(ponteiroSequencial, &tamanhoDalista, nome, rg, posicao);
        }

          break;


         case 4:
           cout << "funcao escolhida: 4 - retirar  um node no inicio da lista \n";

           //Caso a lista for vazia
           if(tamanhoDalista == 0){
           }else{
               removeInicioSequencial(ponteiroSequencial, &tamanhoDalista);
           }

           break;


        case 5:
           cout << "funcao escolhida: 5 - retirar  um node no fim da lista \n";

           //Caso a lista for vazia
           if(tamanhoDalista == 0){
             cout << " Lista Vazia \n";
           }else{
               removeFimSequencial(ponteiroSequencial, &tamanhoDalista);
           }

           break;

        case 6:
             cout << "funcao escolhida: 6 - Retirar  um node na posição N \n";

              //Caso a lista for vazia
           if(tamanhoDalista == 0){
             cout << " Lista Vazia \n";
           }else{

               cout << "digite uma posicao:";
               cin >> posicao;

               removePosicaoSequencial(ponteiroSequencial, &tamanhoDalista, posicao);
           }

           break;




  }

}

return 0;
}
