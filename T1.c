#include <stdio.h>

void quicksort(int vetor[0], int inicio, int fim);  //fun��o de orden��o por quicksort
void pmp(int vetord[], int tamvet);					//fun��o de pares mais pr�ximos(PMP)
void elun(int vetord[], int tamvet);				//fun��o de elementos �nicos (EL UN)
void df(int vetord[], int tamvet);					//fun��o de distribui��o de frequencia (DF)
													//nas fun��es pmp, elun e df: vetord corresponde a um vetor j� ordenado para entrada e tamvet � o tamanho deste vetor
main(){
	int i, tamvet, a;
	printf("Por favor, digite o tamanho desejado para o vetor: ");
	scanf("%d", &tamvet);												//entrada do tamanho do vetor
	
	while (tamvet<1) {
		printf("\nEste tamanho nao %c valido, por favor digite um valor inteiro maior que 0: ", 130);
		fflush(stdin);
		scanf("%d", &tamvet);											//corre��o da entrada caso o usuario entre com um valor inv�lido
	}																	
	
	int vetor[tamvet];
	printf("\nAgora digite os elementos que compoem o vetor:\n");
	
	for(i=0;i<tamvet;i++) {
		scanf("%d", &vetor[i]);											//entrada do vetor
	}
	
	quicksort(vetor, 0, tamvet-1);										//execu��o do quicksort de ordenamento
	printf("\nVetor ordenado:");										
	
	for(i=0;i<tamvet;i++) {												
		printf(" %d", vetor[i]);										//mostra o vetor ordenado
	}
	
	fflush(stdin);														//limpeza do buffer do teclado para windows
	while(a!=0) {
		fflush(stdin);
		printf("\n\nDigite:");
		printf("\n1 para encontrar o par de numeros do vetor com a menor diferen%ca entre eles.", 135);
		printf("\n2 para identificar elementos que ocorrem uma unica vez.");
		printf("\n3 identificar qual elemento ocorre em maior numero.");
		printf("\n0 para sair do programa.\n\n");								//menu do programa
		
		scanf("%d", &a);
		
		switch(a) {															//switch para escolher fun��o desejada
			case 1: 
				pmp(vetor, tamvet);
				break;
			case 2:
				elun(vetor, tamvet);
				break;
			case 3:
				df(vetor, tamvet);
				break;
		}
	}
}

void quicksort(int vetor[10], int inicio, int fim){
	int pivo, aux3, i, j;				//vari�veis auxiliares da fun��o
	i = inicio;							//reseta o valor do i para as pr�ximas execu��es
	j = fim;							//reseta o valor de j para as pr�ximas execu��es
	int meio =  (i + j) / 2;			//define o meio do vetor
	pivo = vetor[meio];					//define como elemento correspondente a posi��o do meio
	
	while(j > i){						//enquanto a posi��o j for maior que a posi��o i para n�o haver intersec��o e passagem
		while (vetor[i] < pivo) i++; 	//percorre o vetor come�ando pelo inicio at� o pivo
		while (vetor[j] > pivo) j--;	//percorre o vetor come�ando pelo final at� o pivo
		      
		if(i <= j){						//confere se i continua sendo menor ou igual a j, para garantir q n�o passou do pivo
			aux3 = vetor[i];        		// faz a troca de posi��es
			vetor[i] = vetor[j];			// ""
			vetor[j] = aux3;         		// ""
			i = i++;						//segue para o pr�ximo elemento em i
			j = j--;						//segue para o pr�ximo elemento em j
		}
	}
	if(inicio < j) quicksort(vetor, inicio, j); //re-executa a fun��o com a menor parte resultante do vetor
	if(i < fim) quicksort(vetor, i, fim);       //re-executa a fun��o com a maior parte resultante do vetor
}

void pmp(int vetord[], int tamvet) { 				//fun��o pares mais pr�ximos (pmp)
	int i, aux, aux2;               				//vari�veis auxiliares
	int el1, el2;									//variaveis que armazenar�o os par de termos
	aux = vetord[tamvet-1] - vetord[0];				//atribui��o m�xima diferen�ca para a variavel auxiliar, para n�o comprometer a checagem de aux2<aux.
	
	if(tamvet>1) {		         					//checa se o vetor tem mais de um elemento
		for(i=0; i < tamvet-1 ;i++) {   			//for que percorre o vetor at� o penultimo termo, porque para o ultimo ser� usado vetord[i+1]
			aux2 = vetord[i+1] - vetord[i];   		//atribui��o da diferen�a entre termos a uma variavel auxiliar
		
			if(aux2<aux) {                      	//checagem de qual diferen�a � menor
				aux = aux2;                     	//se for confirmada, a diferen�a verificada se torna a variavel principal
				el1 = vetord[i];                	//o primeiro elemento do par � o n�mero menor
				el2 = vetord[i+1];					//o segundo elemento do par � o n�mero maior
			}              	
		}
		printf("\nO par de elementos com menor diferen%ca %c %d e %d.", 135, 130, el1, el2);
	}
	else printf("\nNao ha um par de elementos no vetor");
	}

void elun(int vetord[], int tamvet) {
	int i;																	//variavel auxiliar para for
	
	if (tamvet>1) {	
		printf("\nOs seguintes elementos ocorrem uma unica vez: ");
																			//verifica se o vetor tem mais de um elemento
		if(vetord[0] != vetord [1]) printf("%d ", vetord[0]);				//verifica se o primeiro elemento � diferente do segundo
	
		for(i=1; i < tamvet-1 ;i++) {										
			if( vetord[i-1] != vetord[i] && vetord[i] != vetord[1+i] ) {	//verifica se o elemento n � diferente do elemento n+1 e n-1
				printf("%d ", vetord[i]);									
			}
		}
		if(vetord[tamvet-2] != vetord[tamvet-1]) printf("%d ", vetord[tamvet-1]); //verifica se o �ltimo elemento � diferente do penultimo
	}
	else printf("Ha ocorrencia de apenas o elemento %d", vetord[0]);
}

void df(int vetord[], int tamvet) {    
	int i, j, k;
	int v[tamvet];                                    
	int aux2 = 0;
	int elrp = 0;
	int aux = 0;												//variaveis auxiliares
	
	for(i=0; i < tamvet-1 ;i++) {   	
		if(vetord[i] == vetord[i+1]) aux2++;					//verifica se o elemento n � igual ao elemento n+1, se for adiciona 1 a variavel aux2  
			else aux2 =0;										//se for diferente, zera a variavel aux 2 para recome�ar a contagem
		if(aux2 > aux) {										//se a variavel secundaria aux2, for maior q a variavel principal aux, 
			aux = aux2;											//o valor de aux2 � copiado para aux
			j=0;												//zera o j para recome�ar a preencher o vetor de elementos repetidos
		}
		if(aux2==aux) {											//verifica a igualdade, n�o foi feito no if anteior para o caso de haver repeti��es
			v[j] = vetord[i];									//e � atribuido o valor do elemento do vetor q se repete (vetor[i]) para a variavel elrp(elemento repetido)
			j++;
		}
	}
	if(aux==0)  printf("\nNao ha elementos repetidos");			
		else {
			printf("\nElemento(s) com maior frequencia no vetor:"); //printf dos resultados
			for(k=0;k<j;k++) printf(" %d,", v[k]);				
			printf(" com %d ocorrencias (cada).", aux+1);
		}
}
