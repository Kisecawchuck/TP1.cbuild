# Cbuild

Ferramenta de automatização para projetos em C, implementada em Bash. Compila, executa, limpa artefatos e coleta metadados de projetos C, com suporte a compilação incremental, modos de depuração e geração de logs.

## Autores

- Ezequiel Gomes de Carvalho - 15510880
- Igor Nascimento Silva - 17076671
- Lucas Pires da Silva - 16885060
- Miguel da Silva Damasceno - 17838677

## Sobre

O `cbuild` foi desenvolvido para a disciplina MAC0216 — Técnicas de Programação (IME-USP), com foco em versionamento de código, modularização lógica através de funções e tratamento de erros.

## Configuração

O comportamento da ferramenta é definido pelo arquivo `cbuild.conf`, que permite configurar:

- Diretório de execução do `cbuild`
- Compilador C utilizado (`CC`)
- Nome do executável gerado (`TARGET`)
- Flags de compilação

## Arquitetura

O script é organizado em três camadas:

1. **Camada de Configuração (Flags)** — leitura de opções via `getopts`
2. **Camada de Módulos (Funções)** — lógica de cada comando
3. **Camada de Roteamento (Case)** — despacho de comandos via `case`

## Comandos

### `build`

Compila o projeto. Antes de iniciar:

- Verifica se o compilador definido em `CC` está disponível.
- Cria os diretórios `build/` e `logs/`, caso não existam.
- Verifica se há arquivos `.c` em `src/`.

Cada arquivo-fonte é compilado individualmente em um objeto `.o` dentro de `build/`, buscando os arquivos de forma recursiva.

**Códigos de erro:**

| Código | Significado |
|--------|-------------|
| `2` | Compilador (`CC`) não encontrado |
| `3` | Nenhum arquivo de código-fonte válido |
| `6` | Houve um erro durante a compilação |

### `rebuild`

Compilação incremental — recompila apenas arquivos-fonte modificados desde a última build, usando o operador `-nt` do Bash para comparar datas de modificação entre `.c` e `.o`. A etapa de linkagem só ocorre se algum arquivo tiver sido recompilado. 

**Códigos de erro:**

| Código | Significado |
|--------|-------------|
| `2` | Compilador (`CC`) não encontrado |
| `3` | Nenhum arquivo de código-fonte válido |
| `6` | Houve um erro durante a compilação |
| `7` | Não houve compilação anterior |

### `run`

Executa o programa compilado.

- Cria/atualiza `build/.last_run`, registrando a última execução.
- Verifica se `BUILD_DIR` e o executável (`TARGET`) existem.
- Repassa argumentos ao programa via a opção `-r`.

**Código de erro:**

| Código | Significado |
|--------|-------------|
| `4` | Diretório de build ou executável não encontrado |

### `clean`

Remove os artefatos gerados (`build/` e `logs/`), exibindo antes os arquivos que serão excluídos.

### `info`

Exibe metadados do projeto:

- Contagem de arquivos e linhas de código (`.c` e `.h`), usando `find` + `wc -l`
- Tamanho em disco do executável (`du -h`)
- Data da última compilação e da última execução

Os dados são exibidos na saída padrão e exportados para `relatorios/`.

## Modos verbose e debug

Ativados via flags na linha de comando:

```bash
./cbuild -V build       # modo verbose
./cbuild -D build       # modo debug
./cbuild -r "args" run  # passa argumentos ao executável
```

- **`verbose_mode()`** — ativa impressão de comandos (`set -v`) até `end_mode()` ser chamado.
- **`debug_mode()`** — ativa rastreamento de execução (`set -x`) até `end_mode()` ser chamado.
- **`end_mode()`** — encerra ambos os modos.

## Geração de logs

A função `gerar_logs()` registra, a cada execução, um log contendo:

- Data/horário de execução
- Código de retorno
- Comando executado e sua saída
- Tempo de execução
- Status da execução

O redirecionamento do rastreamento de debug (`BASH_XTRACEFD`) é direcionado para o descritor 3 (ligado ao `stderr` do terminal), evitando que a saída de `set -x` seja capturada junto com a saída do comando no log gerado via `tee`.
