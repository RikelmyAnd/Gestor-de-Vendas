Aluno: Rikelmy Andrade de Araújo

Respostas da Atividade:

1 - As mudanças de estado na linguagem imperativa ocorrem nos contadores (int i) dos laços (for), conforme pode ser visto dentro da função (void filtrarRoupasImperativo) no trecho a seguir:

for (int i = 0; i < tamanho; i++) {
        if (strcmp(vendas[i].categoria, "Roupas") == 0) {
            printf("%s\n", vendas[i].produto);
        }

Onde ele incrementa o contador (int i) conforme o laço (for) vai rodando, para que a estrutura condicional (if) teste se a condição é atendida, onde o contador (int i) serve como indice da posição do item na struct.
As mudanças ocorrem também nas variavéis utilizadas para armazenar somas parciais, conforme pode ser visto dentro da função (double calcularFaturamentoImperativo) no trecho a seguir:

double total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += vendas[i].quantidade * vendas[i].precoUnitario;
    }

Onde a variavél (double total) armazena a soma de cada item, onde utilizando o contador (int i) do laço (for) acessamos o item e usando um metodo de iteração, o valor total (inicialmente declarado como 0) é adicionado do resultado da multiplicação do preço unitario pela quantidade de venda, onde cada passagem do laço, salva o valor anterior e adiciona o valor referente ao item seguinte.
Outra mudança de estado, ocorre quando utilizamos variavéis temporarias para armazenar o vetor temporiamente, e altera o estado do vetor original, conforme pode ser visto dentro da função (void retornarPorTotalInterativo) no trecho a seguir:

for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            double totalVendaJ = vendas[j].quantidade * vendas[j].precoUnitario;
            double totalVendaJ1 = vendas[j + 1].quantidade * vendas[j + 1].precoUnitario;
            if (totalVendaJ < totalVendaJ1) {
                Venda temp = vendas[j];
                vendas[j] = vendas[j + 1];
                vendas[j + 1] = temp;
            }

A variavél (Vendas temp), armazena o vetor que atualmente está sendo acessado, para que a posição dele original, seja movida para a posição seguinte.

2 - Utilizei variavéis totais em 3 situações distintas:

double calcularFaturamentoImperativo(Venda vendas[], int tamanho) {
    double total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += vendas[i].quantidade * vendas[i].precoUnitario;
    }
    return total;
}

Onde a variavél (total) é o valor total de todas as vendas realizadas (inicialmente declarado como 0) é adicionado do resultado da multiplicação do preço unitario pela quantidade de venda, onde cada passagem do laço, salva o valor anterior e adiciona o valor referente ao item seguinte.

void totalPorVendedorImperativo(Venda vendas[], int tamanho) {
    typedef struct {
        char vendedor[30];
        double total;
    } TotalVendedor;

  TotalVendedor totais[10]; // Supondo no máximo 10 vendedores
    int numVendedores = 0;

  for (int i = 0; i < tamanho; i++) {
        double totalVenda = vendas[i].quantidade * vendas[i].precoUnitario;
        int j;
        for (j = 0; j < numVendedores; j++) {
            if (strcmp(totais[j].vendedor, vendas[i].vendedor) == 0) {
                totais[j].total += totalVenda;
                break;
            }
        }
        if (j == numVendedores) { // Novo vendedor
            strcpy(totais[numVendedores].vendedor, vendas[i].vendedor);
            totais[numVendedores].total = totalVenda;
            numVendedores++;
        }
    }

No trecho acima, a variavél total (totais[j].total += totalVenda) armazena o total que cada vendedor realizou em vendas.
Dentro do mesmo trecho, temos a variavél (int numVendedores) responsável por armazenar o total de vendedores unicos registrados nas vendas.


3 - Os laços foram substituidos por metodos encadeados (.forEach, .toList, ou sum) da API Streams, que funcionam como laços, mas sem a necessidade de escrevermos manualmente laço por laço (for e while), sendo necessario a passagem apenas dos parametros, com o metodo realizando a iteração por contra propia, podemos comparar abaixo as mesmas funções, mas escritas de modo imperativo e funcional (respectivamente):

void filtrarRoupasImperativo(Venda vendas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(vendas[i].categoria, "Roupas") == 0) {
            printf("%s\n", vendas[i].produto);
        }
    }
}

public static List<Venda> filtrarRoupasFuncional(List<Venda> vendas) {
        return vendas.stream()
                .filter(v -> v.getCategoria().equalsIgnoreCase("Roupas"))
                .toList();
    }

Conforme pode ser visto, enquanto na imperativa precisamos escrever passo a passo aquilo que a linguagem deve fazern na funcional apenas passamos os parametros para o metodo, que percorre por conta propia os elementos.

4 - O metodo (.filter()) substitui as estruturas condicionais (if) que existiam dentro dos laços (for) imperativos, ele funciona retendo apenas os dados que atendem determinada condição, e descarta aqueles que não atendem, conforme podemos ver no trecho abaixo:

public static List<Venda> filtrarRoupasFuncional(List<Venda> vendas) {
        return vendas.stream()
                .filter(v -> v.getCategoria().equalsIgnoreCase("Roupas"))
                .toList();
    }

O metodo dispensa a necessidade de defirnirmos a estrutura condicional, onde o parametro passado é um outro metodo que percorre todos os elementos, destacando aqueles elementos que atendem os requisitos, e o .filter os captura.

5 - O metodo (.map), serve para que consigamos utilzar apenas os dados necessários para a etapa seguinte, transformando o Objeto completo na informação que desajamos utilizar, conforme pode ser observado no trecho abaixo:

public static double calcularFaturamentoFuncional(List<Venda> vendas) {
        return vendas.stream()
                .mapToDouble(Venda::getTotal)
                .sum();
    }

Utilizamos o metodo (.mapToDouble) para capturamos apenas as informações referentes ao elemento Total de cada venda (Venda::getTotal) para que o metodo (.sum) as utilize.

6 - O metodo (.sum) substitui as variavéis acumuladoras, pegando um fluxo continuo de valores e devolvendo o somatorio deles, igual pode ser vizualizado no trecho da questão anterior, onde o metodo soma o total de cada venda.

7 - O metodo (.collect) serve para "armazenar" e juntar o e resultado de um fluxo continuo de dados de uma Stream em uma estrutura de dados concreta, conforme o trecho abaixo:

public static Map<String, Double> totalPorVendedorFuncional(List<Venda> vendas) {
        return vendas.stream()
                .collect(Collectors.groupingBy(Venda::getVendedor, Collectors.summingDouble(Venda::getTotal))); 
                
  }

Onde no trecho, o metodo (.collect) serviu para criar um pacote das informações das vendas de cada vendedor em um Map (.groupingBy()) e passar esse agrupamento para o (.summingDouble) que vai retornar o total das vendas de cada vendedor.

8 - A versão Funcional, pois economizamos muitas linhas ao não escrevermos diretamente as estruturas iterativas.

9 - A versão funcional apesar de necessitar do entendimento do leitor sobre os metodos, ele facilita a compreensão, pois usa nomes proximos da linguagem humana, que descrevem bem o aquilo que cada Metodo faz.

10 - Na versão imperativa, nela precisamos ditar o passo a passo daquilo que a maquina precisa fazer, desde a inicializar o contador (int i dentro dos laços (for)), até onde ele deve ir (i < tamanho), como ele avança (++i), e onde, quando e o que ele deve verificar na estrutura condicional (if), conforme podemos observar nas funções exibidas nas primeiras questões.

11 - Na versão Funcional, ela depende totalmente disso, devemos informar o que queremos que ele retorne como saída onde após falarmos aquilo que desejamos obter, a API e a maquina se responsabilizam pela forma de como faram isso. 
