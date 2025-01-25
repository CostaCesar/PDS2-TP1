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

Ou escolha manualmente uma seleção dentre os seguintes target:
- test_board
- test_reversi
- test_puzzle
- test_liga4
- test_velha

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

## Estrutura do repositório
- **bin:** Arquivos binários finais (Windows & Linux)
    - **/data:** Arquivos de dados gerados pelo programa
    - **/input:** Arquivos de entrada de dados para os testes
- **inc:** Arquivos de cabeçalho (.h e .hpp)
- **src:** Arquivos de código fonte (.cpp)
- **tmp:** Arquivos de cache para compilação (.o gerados pelo *make*)
- **test:** Arquivos de código que testam o programa (testes escritos em C++)

## Terminologia
*dummy-file* é um arquivo vazio, criado para forçar a estrutura de diretório no repositório. Serão apagados quando o projeto estiver concluido

**_Test* são os arquivos de teste gerados pelo make ou pela geração individual de cada target ou pelo comando:
```
make tests
```
## Andamento

- **Tabuleiro base:** Caio César Moraes Costa
- **Jogo da velha:** Vinicius de Alcantara Garrido
- **Lig4:** Leonardo Barreto Gaiao
- **Reversi:** Caio César Moraes Costa
- **Sistema de jogador**: Rafic Alves Magalhães Farah Leão
- **Puzzle (Jogo do 8):** Caio César Moraes Costa
