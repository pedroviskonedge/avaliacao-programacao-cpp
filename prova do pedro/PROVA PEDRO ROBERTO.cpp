#include <stdio.h>

int main() {

    char nome[50];
    int idade;
    int a, b;
    float nota1, nota2, media;
    int numero;
    float salario;
    int opcao;
    float x, y, resultado;
    float altura, peso;
    
    // Variaveis novas para as Etapas 2 e 3
    int opcao_pagamento;
    float valor_original;
    float valor_final;

    // 1. Nome
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Ola, %s!\n", nome); // faltou &, ao inves de "%d" é "%s" -> Nota: em strings (%s), o '&' nao é necessario porque o nome do array ja é um ponteiro!

    // 2. Idade
    printf("\nDigite sua idade: ");
    scanf("%d", &idade); // era float, o correto é d

    if (idade >= 18){ // faltou as chaves
        printf("Entrada permitida\n");
    }
    else{
        printf("Entrada nao permitida\n");
    }

    // 3. Soma
    printf("\n Digite dois inteiros: ");
    scanf("%d %d", &a, &b);
    printf("Soma = %d\n", a + b); // tinha um printf solto na linha de cima, desnecesario E TAMBEM o operador está incorreto

    // 4. Maior numero
    printf("\nDigite dois inteiros: ");
    scanf("%d %d", &a, &b); // falou um %d
    if (a > b){
        printf("Maior = %d\n", a); // sinal de maior errado e falta de chaves
    }
    else{
        printf("Maior = %d\n", b); // e dois ;
    }
	
    // 5. Media
    printf("\nDigite duas notas: ");
    scanf("%f %f", &nota1, &nota2);

    media = (nota1 + nota2) / 2; // subtração por adição e divisao por 2 faltante

    if (media >= 7){
        printf("Aprovado\n");
    }
    else{
        printf("Reprovado\n"); // falta ; e falta de chaves nos if e no else
    }

    // 6. Positivo, negativo ou zero
    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if (numero < 0){ // sinais invertidos
        printf("Negativo\n");
    }
    else if (numero > 0){ // sinais invertidos e falta de chaves no if, no else
        printf("Positivo\n"); 
    }
    else{
        printf("Zero\n"); 
    }
	
    // 7. Par ou impar
    printf("\nDigite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) // para ser par tem que ser zero no lugar de 1. Trocado == 1 para == 0
        printf("Par\n");
    else
        printf("Impar\n");

    // 8. Calculadora
    printf("\nDigite dois numeros: ");
    scanf("%f %f", &x, &y);

    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            resultado = x + y;
            break;
        case 2:
            resultado = x - y;
            break;
        case 3:
            resultado = x * y;
            break;
        case 4:
            if (y != 0) { // seguranca para nao travar o programa dividindo por zero
                resultado = x / y;
            } else {
                printf("Erro: Divisao por zero\n");
                resultado = 0;
            }
            break;
        default:
            printf("Opcao invalida\n");
    }

    printf("Resultado = %.2f\n", resultado); // era %d mas resultado é float, trocado para %.2f

    // 9. Salario
    printf("\nDigite seu salario: ");
    scanf("%f", &salario);

    salario = salario - (salario * 0.10); // falta os parenteses

    printf("Novo salario: %.2f\n", salario);

    // 10. Concurso
    printf("\nDigite seu nome: ");
    scanf(" %s", nome); // adicionado espaco antes do %s para limpar o buffer do teclado do enter anterior

    printf("Digite sua nota: ");
    scanf("%f", &nota1); // era %d mas nota1 é float, trocado para %f

    if (nota1 >= 60)
        printf("%s: aprovado\n", nome); // era %f, trocado para %s porque nome é string
    else
        printf("%s: reprovado\n", nome); // era %f, trocado para %s porque nome é string

    // DESAFIO
    printf("\n===== RELATORIO =====\n");

    printf("Nome: ");
    scanf(" %s", nome); // era %c e lia so uma letra e pulava tudo, trocado para " %s" com espaco para limpar o buffer

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Altura: ");
    scanf("%f", &altura); // era %d mas altura é float, mudou para %f

    printf("Peso: ");
    scanf("%f", &peso); // era %d mas peso é float, mudou para %f


    printf("\n===== RELATORIO DE DADOS =====\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f m\n", altura);
    printf("Peso: %.2f kg\n", peso);


    // Etapa 2: Forma de Pagamento
    valor_original = salario; // pegando o valor gerado la na etapa 3/item 9
    valor_final = valor_original;

    printf("\n===== ETAPA 2: FORMA DE PAGAMENTO =====\n");
    printf("1 - A vista (Dinheiro/Pix)\n");
    printf("2 - Cartao de Credito\n");
    printf("Escolha a opcao de pagamento: ");
    scanf("%d", &opcao_pagamento);

    switch (opcao_pagamento) {
        case 1:
            valor_final = valor_original - (valor_original * 0.05); // aplicando 5% de desconto extra
            printf("Desconto de 5%% aplicado com sucesso!\n");
            break;
        case 2:
            valor_final = valor_original; // mantem o valor sem desconto
            break;
        default:
            printf("Opcao invalida. Valor mantido sem desconto extra.\n"); // erro padrao se digitar errado
            valor_final = valor_original;
    }


    // Etapa 3: Relatório Final
    printf("\n===== ETAPA 3: RELATORIO FINAL =====\n");
    printf("Nome do cliente: %s\n", nome);
    printf("Valor original da compra: R$ %.2f\n", valor_original);
    printf("Valor final a pagar: R$ %.2f\n", valor_final); // formatado certinho com duas casas decimais

    return 0; // era 01, o correto padrao é retornar 0
}




