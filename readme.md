# Projeto dotexe

## Compilação

Para compilar o programa, execute o seguinte comando na pasta raiz do projeto:

```sh
g++ -Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8 -g3 -Icabecalhos main.cpp funcoes/entra_programa.cpp funcoes/gravar_jogo.cpp funcoes/excluir_jogo.cpp funcoes/buscar_jogo.cpp funcoes/id_manager.cpp funcoes/atualizar_jogo.cpp funcoes/FilaDeProcessamento.cpp funcoes/relatorio_jogo.cpp -o output/main.exe
```

## Execução

Após a compilação, execute o arquivo `main.exe` dentro da pasta `output`:

```sh
./output/main.exe
```

## Compilação facilitada
### OBS: Esta parte não foi atualizada ainda!

Para compilar o programa com o tasks.json aperte Crtl + Shift + b (para fazer isso voce precisa criar um arquivo tasks.json dentro da sua pasta .vscode e colocar esse código abaixo)

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar Programa",
            "type": "shell",
            "command": "g++",
            "args": [
                "-Wall",
                "-Wextra",
                "-finput-charset=UTF-8",
                "-fexec-charset=UTF-8",
                "-g3",
                "-Iinicio",
                "-Iatualizar",
                "-Igravar",
                "-Iexcluir",
                "-Ibuscar",
                "-Iid_manager",
                "main.cpp",
                "atualizar/atualizar-jogo.cpp",
                "gravar/gravar-jogo.cpp",
                "buscar/buscar-jogo.cpp",
                "excluir/excluir-jogo.cpp",
                "id_manager/id_manager.cpp",
                "inicio/entra-programa.cpp",
                "-o",
                "output/main.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"],
            "detail": "Compilação do programa com g++"
        }
    ]
}


```
