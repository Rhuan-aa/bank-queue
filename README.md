# Projeto: Fila de Banco em C

## Descrição

Este projeto simula o atendimento em uma fila de banco utilizando a linguagem C. O sistema gerencia duas filas: uma para clientes do público geral e outra para clientes prioritários. O atendimento segue regras específicas para alternância entre as filas, garantindo prioridade sem deixar de atender o público geral.

## Estrutura do Projeto

- `queue.c` e `queue.h`: Implementação e definição das funções e estrutura da fila circular de nomes (strings).
- `main.c`: Função principal que processa os comandos de entrada e simula o atendimento do banco.
- `Makefile`: Facilita a compilação do projeto.

## Funcionalidades

- Inserção de clientes nas filas de prioridade e geral.
- Atendimento alternado conforme as regras do banco:
  - Até 3 clientes prioritários podem ser atendidos em sequência.
  - Após 3 prioridades, um cliente do público geral deve ser atendido (se houver).
  - Se a fila geral estiver vazia, continua atendendo prioridades.
- Impressão da ordem de atendimento ao final do expediente.

## Como Compilar

Para compilar o projeto, utilize o comando:
```
make
```
O executável será gerado no diretório principal.

## Como Executar

Após compilar, execute o programa com:
```
./main.exe
```
ou, no Windows:
```
main.exe
```

Você pode digitar os comandos manualmente ou redirecionar a entrada de um arquivo:
```
main.exe < entrada.txt
```

## Exemplo de Entrada

```
g Rodrigo
g Bia
p Joel
s
g Fatima
p Frederico
p Luciana
s
s
p Fabiana
f
```

## Exemplo de Saída

```
Joel
Frederico
Luciana
Rodrigo
Fabiana
```

## Autoria

Projeto desenvolvido por Rhuan Boni para a disciplina de Estrutura de Dados.