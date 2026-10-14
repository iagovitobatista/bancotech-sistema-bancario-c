# 🏦 BancoTech — Simulador Bancário em C

![Linguagem C](https://img.shields.io/badge/Linguagem-C-00599C?style=flat-square&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/Compilador-GCC-555?style=flat-square)
![Projeto acadêmico](https://img.shields.io/badge/Projeto-Acad%C3%AAmico-6B46C1?style=flat-square)

**BancoTech** é um simulador de operações bancárias executado no terminal, desenvolvido em **linguagem C** como parte da disciplina de **Algoritmos e Pensamento Computacional — Experiência Prática II**.

O objetivo é aplicar lógica de programação em um cenário cotidiano: um menu persistente que permite realizar operações simuladas, consultar os resultados e lidar com entradas incorretas sem interromper inesperadamente o programa.

> **Aviso:** projeto educacional. Não é um banco real, não movimenta dinheiro, não possui autenticação, persistência de dados nem garantias financeiras de produção.

## ✨ Funcionalidades

| Opção | Funcionalidade | Comportamento |
|:--:|---|---|
| `1` | Consultar saldo | Exibe o saldo disponível |
| `2` | Realizar depósito | Aceita valor positivo e atualiza o saldo |
| `3` | Realizar saque | Valida valor e saldo suficiente |
| `4` | Resumo de movimentações | Exibe quantidades e totais de depósitos e saques |
| `0` | Encerrar | Mostra resumo final e mensagem de despedida |

O saldo inicial fictício é **R$ 1.000,00** e permanece apenas durante a execução. O item 4 é um **resumo agregado**, não um extrato detalhado de transações.

## 🧠 Conceitos praticados

- `do-while` para manter o menu ativo.
- `switch/case` para encaminhar cada opção.
- `if/else if/else` para validar operações.
- `fgets` e `sscanf` para ler e verificar entradas.
- Funções, variáveis, operadores aritméticos e saída formatada com `printf`.

O programa rejeita opções inexistentes, texto digitado no lugar de números, valores não positivos, saques acima do saldo e valores não finitos. Para simplificar o estudo, os valores usam `double` e ponto decimal. **Em sistemas financeiros reais, são necessárias representações monetárias exatas**, regras de arredondamento, segurança e auditoria.

## 📂 Estrutura

```text
bancotech-sistema-bancario-c/
├── src/
│   └── bancotech.c       # Código-fonte do simulador
├── tests/
│   └── teste_bancotech.sh # Testes automatizados de cenários
├── .gitignore
└── README.md
```

## 🚀 Como executar no computador

Pré-requisitos: GCC e um terminal. Na raiz do repositório:

```bash
gcc -std=c11 -Wall -Wextra -pedantic src/bancotech.c -o bancotech -lm
./bancotech
```

No Windows, o executável gerado pode ser `bancotech.exe`; execute com `.\bancotech.exe` no PowerShell.

Informe números com **ponto decimal**, por exemplo `150.50`, no ambiente de teste usado no projeto.

### No Google Colab

O Colab executa Python por padrão, então o código C precisa ser salvo e compilado. Em uma célula, use `%%writefile bancotech.c` seguido do conteúdo de [src/bancotech.c](src/bancotech.c). Em outra:

```python
!gcc -std=c11 -Wall -Wextra -pedantic bancotech.c -o bancotech -lm
!printf "1\n2\n300\n3\n150\n4\n0\n" | ./bancotech
```

## 🧪 Cenário de teste

| Ação | Valor | Saldo esperado |
|---|---:|---:|
| Saldo inicial | — | R$ 1.000,00 |
| Depósito | + R$ 300,00 | R$ 1.300,00 |
| Saque | − R$ 150,00 | **R$ 1.150,00** |

Ao escolher `4`, o resumo deve apresentar **1 depósito**, **1 saque**, total depositado de **R$ 300,00**, total sacado de **R$ 150,00** e saldo de **R$ 1.150,00**. Testes adicionais cobrem entradas inválidas e saldo insuficiente.

Em Linux ou Colab, rode os testes automatizados com:

```bash
bash tests/teste_bancotech.sh
```

## 🔧 Possíveis evoluções

- Registrar um histórico de transações individualizadas.
- Usar valores monetários em centavos inteiros para evitar erros de ponto flutuante.
- Separar a lógica em módulos e adicionar testes mais abrangentes.
- Persistir dados em arquivo ou banco de dados.
- Adicionar integração contínua quando necessário.

## 👨‍💻 Autor

**Iago Vito Batista** — projeto de aprendizagem e portfólio em desenvolvimento de software.

[Perfil no GitHub](https://github.com/iagovitobatista)
