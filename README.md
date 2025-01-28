# Requisitos
- g++ (capaz de compilar c++11)
- doxygen (opcional, para gerar a documentação)

# Detalhes
## Integrantes
- Caio César Moraes Costa
- Rafic Alves Magalhães Farah Leão
- Leonardo Barreto Gaiao
- Vinicius de Alcantara Garrido

## Fazendo o Build
Rode esse comando para gerar o programa principal e os testes:

```
make all
```

Ou rode eles como targets separados
```
make main
make tests
```

Ou escolha manualmente uma seleção dentre os seguintes target:
- test_board
- test_reversi
- test_puzzle
- test_liga4
- test_velha
- test_velha_infity

Se precisa fazer o debug desses binários:
```
make DEBUG=1 <sua_seleção>
```

Utilize a flag **-B** do make para forçar a recompilação

Para limpexa do projeto:
```
make clean     # remove todos os objetos em ./temp
make delete    # remove todos os binarios em ./bin
```

## Documentação

Para acessar a documentação completa do código, abra o arquivo em **./docs/html/index.html**. 

A documentação vem inclusa no projeto, mas pode ser regerado através de:

```
make doc
```

*O comando acima precisa que [**doxygen**](https://doxygen.nl/index.html) esteja presente na pasta **./doxygen***

## Estrutura do repositório
- **bin:** Arquivos binários finais (Windows & Linux)
    - **/input:** Arquivos de entrada de dados para os testes
- **inc:** Arquivos de cabeçalho (.h e .hpp)
- **src:** Arquivos de código fonte (.cpp)
- **tmp:** Arquivos de cache para compilação (.o gerados pelo *make*)
- **test:** Arquivos de código que testam o programa (testes escritos em C++)
- **cadastro.csv** Arquivo gerado pelo main com as informações dos jogadores

## Terminologia
*dummy-file* é um arquivo vazio, criado para forçar a estrutura de diretório no repositório. Serão apagados quando o projeto estiver concluido

**_Test* são os arquivos de teste gerados pelo make ou pela geração individual de cada target ou pelo comando:
```
make tests
```
## Distribuição

- **Tabuleiro base:** Caio César Moraes Costa
- **Jogo da velha:** Vinicius de Alcantara Garrido
- **Jogo da velha infinito:** Vinicius de Alcantara Garrido
- **Lig4:** Leonardo Barreto Gaiao
- **Reversi:** Caio César Moraes Costa
- **Puzzle (Jogo do 8):** Caio César Moraes Costa
- **Sistema de jogador**: Rafic Alves Magalhães Farah Leão
- **Programa final**: Rafic Alves Magalhães Farah Leão

# Informações extra

## Lig4 (by Leo)

### Visão Geral
A classe implementa a lógica necessária para jogar Lig4(Connect 4)
Permite a customização do tamanho do Board
Aceita tanto a entrada padrão quanto a input
Utiliza funcionalidades do Board para implementar a lógica da classe o que demonstra um uso de técnicas de POO

### Dificuldades
A principal dificuldade da implentação da classe foi a possibilidade de ler um arquivo de texto como entrada(fazer os testes)
Intepretar completamente as requisições do TP foi um desafio também

### Extras da Classe
Apresenta cores para cada jogador
Limpa o tabuleiro no stdin, tornando o jogo dinâmico