# Manual do cbuild

# Sinopse

- `cbuild [OPÇÃO] [FUNÇÃO]`
- `cbuild -r ARGS run`

# Descrição

`cbuild` é um sistema de automação para projetos em C. Por padrão ele é executado no diretório atual, usando o GCC como compilador de C, com as flags `-Wall -Werror`, gera o executável com o nome `main`, tudo isso pode ser configurado no `cbuild.conf`.

# Funções

## build

Compila os arquivos-fonte em objetos e depois compila o executável principal. O nome do executável, Compilador de C usado e flags de compilação estão definidos no `cbuild.conf`.

## run

Roda o executável principal.

- `-r`: passa `ARGS` para os argumentos do programa principal

## clean

Limpa os fragmentos de compilação (build, logs).

## rebuild

Recompila se houve alguma alteração no projeto.

## info

Mostre as estatísticas do projeto. O número de linhas considera comentários e linhas vazias.
