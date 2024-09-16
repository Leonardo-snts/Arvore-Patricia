# Arvore Patricia

Este projeto implementa um Sistema de Indexação de Palavras a partir de um arquivo de texto, utilizando uma Árvore Patricia (Trie Compressa) para armazenar palavras e as respectivas linhas em que aparecem. O programa lê um arquivo de texto, insere cada palavra com mais de 3 letras na árvore Patricia, e depois imprime essas palavras em ordem alfabética, juntamente com as linhas onde elas foram encontradas.

## Sobre o Projeto

Este projeto tem como objetivo indexar palavras de um arquivo de texto utilizando uma Árvore Patricia. As palavras com mais de três letras são armazenadas e vinculadas às linhas em que aparecem no texto. Ao final, as palavras são impressas em ordem alfabética, juntamente com as linhas em que foram encontradas.

### Estrutura de Dados

O sistema utiliza uma Árvore Patricia para armazenar as palavras e suas ocorrências no texto:

- Cada nó da árvore contém um array de filhos que aponta para os próximos caracteres possíveis.
- Quando uma palavra é completamente inserida, o nó correspondente armazena um array indicando em quais linhas a palavra aparece.
- A Árvore Patricia é otimizada para armazenar sequências de caracteres, permitindo busca e inserção eficientes.

#### Requisitos

Para compilar e executar o projeto, você precisará de:

- Um compilador C (como GCC)
- Um ambiente com suporte para C (Windows, Linux ou macOS)

#### Como Executar
Clone o repositório:

```
git clone https://github.com/Leonardo-snts/Arvore-Patricia.git
```

Compile o código:

```
gcc patricia.c -o patricia
```

Coloque o arquivo de texto que deseja indexar no mesmo diretório do executável e nomeie-o como texto.txt.

Execute o programa:

```
./patricia
```

O programa irá imprimir as palavras encontradas e as linhas em que cada uma aparece.

##### Exemplo de Execução

Dado um arquivo texto.txt com o seguinte conteúdo:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit.
Vestibulum sit amet erat at risus tristique.
Vestibulum consectetur ligula sit amet quam tristique.
```
O programa retornará:
```
A palavra (amet) foi encontrada nas linhas: 1 2 3 
A palavra (consectetur) foi encontrada nas linhas: 1 3 
A palavra (dolor) foi encontrada nas linhas: 1 
A palavra (erat) foi encontrada nas linhas: 2 
A palavra (ipsum) foi encontrada nas linhas: 1 
A palavra (ligula) foi encontrada nas linhas: 3 
A palavra (lorem) foi encontrada nas linhas: 1 
A palavra (quam) foi encontrada nas linhas: 3 
A palavra (risus) foi encontrada nas linhas: 2 
A palavra (sit) foi encontrada nas linhas: 1 2 3 
A palavra (tristique) foi encontrada nas linhas: 2 3 
A palavra (vestibulum) foi encontrada nas linhas: 2 3 
```
##### Detalhes do Código

O código principal é implementado em C e possui as seguintes funções:

- novo_no(): Cria um novo nó para a árvore Patricia, inicializando os arrays de filhos e de linhas.
- inserir(): Insere uma palavra na árvore Patricia, associando-a ao número da linha onde foi encontrada.
- imprimir_palavras(): Percorre a árvore e imprime as palavras em ordem alfabética, juntamente com as linhas onde aparecem.
- main(): Lê o arquivo texto.txt, insere as palavras na árvore e, ao final, imprime o resultado.
- Fluxo de Execução:
- O arquivo de texto é aberto e lido linha por linha.
- As palavras são extraídas e inseridas na árvore, associando-as às respectivas linhas do texto.
- O programa imprime todas as palavras com mais de três letras, junto com as linhas em que aparecem.
