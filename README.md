# cbuild - Sistema de Automação para Projetos em C

O **cbuild** é uma ferramenta de linha de comando desenvolvida em Shell Script (Bash) para automatizar tarefas comuns em projetos escritos em C, como compilação, execução, limpeza e geração de relatórios.

## ⚙️ Pré-requisitos
Para executar esta ferramenta, você precisará de:
* Ambiente Linux (nativo ou WSL).
* Interpretador `bash`.
* Compilador `gcc` instalado no sistema.

## 📁 Estrutura de Diretórios Esperada
A ferramenta espera que o seu projeto em C esteja organizado da seguinte forma:
\`\`\`text
projeto/
├── src/          # Arquivos fonte (.c)
├── include/      # Arquivos de cabeçalho (.h)
├── build/        # (Gerado automaticamente) Executável e objetos
├── logs/         # (Gerado automaticamente) Histórico de execuções
└── relatorios/   # (Gerado automaticamente) Relatórios do projeto
\`\`\`

## 🚀 Como Executar
Antes do primeiro uso, voce deve dar permissão de execução ao script:
\`\`\`bash
chmod +x cbuild
\`\`\`

Par usar, voce deve usar a seguinte sintaxe:
\`\`\`bash
./cbuild [OPÇÕES...] <comando>
\`\`\`

## 🛠️ Comandos Disponíveis

* \`build\`: Descobre os arquivos fonte nas pastas \`src/\` e \`include/\`, compila o projeto usando o GCC e gera o executável na pasta \`build/\`.
* \`run\`: Executa o programa gerado após a compilação.
* \`clean\`: Remove o executável e todos os arquivos temporários gerados.
* \`rebuild\`: Executa a limpeza (\`clean\`) seguida de uma nova compilação (\`build\`).
* \`info\`: Exibe estatísticas do projeto (quantidade de arquivos, total de linhas de código, tamanho do executável, datas de modificação) e gera um relatório detalhado na pasta \`relatorios/\`.

## ⚙️ Opções (Flags)
* \`-V\`: **Modo Verboso.** Imprime no terminal as linhas do script à medida que são lidas, detalhando a execução.
* \`-D\`: **Modo Debug.** Exibe os comandos e seus argumentos à medida que são executados (útil para diagnóstico de falhas).

## 💡 Exemplos de Uso

Compilando o projeto normalmente:
\`\`\`bash
./cbuild build
\`\`\`

Limpando o projeto e executando em modo verboso:
\`\`\`bash
./cbuild -V clean
\`\`\`

Gerando o relatório e visualizando as estatísticas do código:
\`\`\`bash
./cbuild info
\`\`\`