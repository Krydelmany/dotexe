# dotexe

## How to build from source
### Requeriments:
- A C/C++ 32/64 bits compiler
  - [MSYS2](https://www.msys2.org/)
- Compiler parameters:
```sh
g++ -Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8 -g3 -Icabecalhos main.cpp funcoes/entra_programa.cpp funcoes/gravar_jogo.cpp funcoes/excluir_jogo.cpp funcoes/buscar_jogo.cpp funcoes/id_manager.cpp funcoes/atualizar_jogo.cpp funcoes/FilaDeProcessamento.cpp funcoes/relatorio_jogo.cpp funcoes/buscas_variadas.cpp -o dot_exe.exe
```