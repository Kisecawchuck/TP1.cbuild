# Documentação para o projeto

## Estrutura base e configuração globais - LUCAS
- Criar o script principal cbuild que vai ler o que o usuário digitou e chamar nossas funções.
- Implementar a leitura do Arquivo de configuração (para definir nome do executável, etc).
- Fazer a lógica global do Modo Verboso e do Modo Debug.
- Tratamento de erro inicial (verificar se o comando é válido, se o diretório existe e checar permissões).

## Motor de compilação - MIGUEL e IGOR
- Implementar os comandos build e rebuild.


- Fazer a busca recursiva para achar os arquivos .c e .h sozinhos (nas pastas src/ e include/).


- Fazer a Compilação Incremental (checar o que foi alterado para compilar só o que mudou).


- Adicionar os Níveis de Otimização (deixar o usuário escolher a flag do GCC).


- Tratar e mostrar os erros de compilação ou falta de arquivos fonte.

## Execução, Limpeza e Sistema de Logs -- EZEQUIEL
- Implementar os comandos run (rodar o executável) e clean (apagar tudo que for temporário/executável).


- Fazer o Sistema de Logs: criar a pasta logs/ e gerar os arquivos detalhados (cbuild_YYYYMMDD_HHMMSS.log).


- Garantir que o log grave: data, hora, comando, tempo de execução, código de retorno e erros.


- Tratar o erro de quando tentam dar run sem ter nenhum executável pronto.

## Membro 4: Estatísticas, Relatórios e Testes -- EZEQUIEL

- Implementar o comando info (mostrar qtd de arquivos, linhas de código, tamanho do executável, data da última compilação).


- Fazer a Geração de Relatórios (exportar as estatísticas/informações para um arquivo como .html ou .txt).


- Criar as "pastas de teste" (projetos em C válidos e com erros propositais) para a gente testar a ferramenta e usar na gravação do vídeo.


- Começar a estruturar o README.md com as instruções de uso.
## build

## run

## clean

## rebuild
    Compilação incremental: usar 
## info
