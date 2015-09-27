# Trab1-LPA2015
SSC0300 - Linguagens de Programação e Aplicações 2015
Prof. Adenilso da Silva Simão
Trabalho 1

Aplicações de Algoritmos de Ordenação

Aluno: Pedro Eduardo Rodrigues Barazetti 
Nº USP 9312582
GitHub Username:PedroBarazetti
Diretório do Trabalho: https://github.com/PedroBarazetti/Trab1-LPA2015/

Instruções de Uso do Programa:
Primeiramente o usuário deve inserir o número correspondente a quantidade de elementos que se deseja inserir no vetor. Em seguida basta o usuário entrar com todos os elementos para preencher o vetor, lembrando que ambas as entradas devem ser em números inteiros. Quando o usuário terminar de inserir os elementos do vetor eles serão ordenados do menor para o maior e imprimidos em tela.
Após a ordenação aparecerá um menu na tela perguntando o que o usuário deseja fazer em seguida:

"Digite:
1 para encontrar o par de numeros do vetor com a menor diferença entre eles.
2 para identificar elementos que ocorrem uma unica vez.
3 identificar qual elemento ocorre em maior numero.
0 para sair do programa."

Desta forma basta o usuário entrar com o número correspondente a ação que quer realizar. Caso o usuário digite um número invalido a mensagem será reimpressa.


Funcionamento: 
Para realizar as ações pedidas pelo trabalho o programa teria que realizar diversos testes sobre o vetor para verificar o que foi pedido. Para simplificar o código e evitar o uso desnecessário de processamento foi usado um algorítimo de ordenação, para que os testes sejam feitos sobre um vetor já ordenado. Com um vetor ordenado pode-se realizar a analise requisitada sobre o vetor com funções de poucas linhas (em torno de 15 cada uma) e pouco processamento (um "for" que percorresse o vetor inteiro foi o suficiente para a função fazer todos os testes necessários sobre o vetor).
Na prática, o programa após receber a entrada, imediatamente reordena o vetor pelo algorítimo quicksort e aguarda a chamada da função, que depende da entrada do usuário correspondente a um caso da função "switch". Neste caso 1 chama a função "Pares mais Próximos (pmp)", 2 chama a função "Elementos Únicos (elun)", 3 chama a função "Distribuição de Frequência (df)" e 0 sai do menu, que está em loop em uma função while. Foi utilizado a função while no menu do programa para evitar que o usuário tivesse que repetir a entrada para realizar testes diferentes sobre um mesmo vetor.
Para o desenvolvimento do programa foi utilizado o compilador DEV C++ em Windows 8.1 Pro x64, a compilação foi gerada automaticamente pelo compilador, não houve alterações. Para o código do programa bastou a inclusão da biblioteca stdio, que forneceu todas as funções necessárias para o funcionamento. O programa não está preparado para receber entradas externas, todas as entradas devem ser feitas na execução e serão lidas pelo comando scanf.

Para ordenação foi usado um algorítimo quicksort com escolha de pivo central.

A função Pares mais Próximos(pmp), calcula a diferença entre um termo e o próximo e copia a diferença para uma variavel secundaria, checa essa diferença com a variavel principal que guarda a menor diferença. Se o valor da variável secundaria for menor que o da variável principal, é copiado o valor da variavel secundária para a variavel principal e salvo o par de elementos do vetor que foi constatado essa diferença Isso com todos os elementos do vetor. Ao final o programa será impresso o último par que foi salvo, ou seja a menor diferença encontrada até o final do vetor.

A função Elementos Únicos (elun), checa se o elemento do vetor é diferente do próximo e do anterior. Se for diferente dos dois ele imprimi o elemento. Para o primeiro e último elemento foi feitos separadamente do ciclo em for, já que o primeiro só faz a checagem com o segundo e o último só faz a checagem com o penúltimo.

A função Distribuição de Frequência (df), checa se determinado elemento do vetor é igual ao seu próximo, se for ele adiciona 1 a variavel secundária, se a variavel secundária for maior que a variavel principal, o valor da variavel secundária é copiado para a variavel principal e o elemento do vetor é salvo em outra variavel para ser imprimido ou substiuido. Caso o próximo elemeno seja diferente, o valor da variavel secundária é zerado para recomeçar a contagem, sobrando salvo apenas o valor da variavel principal que tem o maior número de ocorrencias até o momento. Se no final da execução o valor da variavel principal for 0, o programa imprimirá uma mensagem dizendo que não há elementos iguais. Senão ele imprimira o elemento salvo que constatou o maior número de repetições juntamente com o número de ocorrências.
