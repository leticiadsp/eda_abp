# Árvore Binária de Busca (ABP/BST) em C

Implementações e exercícios de Árvore Binária de Busca desenvolvidos durante a disciplina de Estruturas de Dados e Algoritmos (EDA) na Universidade de Brasília (UnB).

## Sobre

Este repositório reúne o estudo prático de árvores binárias de busca, cobrindo desde a construção da estrutura até operações mais avançadas de manipulação e validação.

## Estrutura

```
├── src/
│   └── abp.c                              # Implementação principal com todas as operações
└── exercicios/
    ├── construcao_a_partir_de_entrada.c   # Construção recursiva de árvore via leitura de entrada
    └── busca_menor_diferenca.cpp          # Variante: busca do valor mais próximo (estilo competitive programming)
```

## `src/abp.c` — Implementação principal

Implementação completa de uma ABP com:

- **Inserção** recursiva
- **Busca** recursiva
- **Remoção** com tratamento dos três casos (nó folha, um filho, dois filhos — usando o sucessor in-order)
- **Percurso in-order**
- **Contagem de nós**
- **Contagem de folhas**
- **Cálculo de altura**
- **Validação de ABP** (verifica se a árvore respeita a propriedade de busca binária, propagando limites min/max)

Compilar e rodar:
```bash
gcc src/abp.c -o abp
./abp
```

## `exercicios/construcao_a_partir_de_entrada.c`

Constrói uma árvore binária lendo valores da entrada padrão recursivamente, usando `-1` como marcador de nó nulo (pré-ordem). Também inclui inserção e busca padrão de ABP.

## `exercicios/busca_menor_diferenca.cpp`

Variante do problema de busca em ABP: para cada valor de consulta, encontra a menor diferença absoluta entre o valor e algum nó da árvore, somando os resultados. Escrito em C++ com estilo mais próximo de competitive programming (Codeforces).

## Tecnologias

- C / C++
- Recursão e manipulação de ponteiros
- Alocação dinâmica de memória (`malloc`/`free`)

## Contexto

Desenvolvido como parte da disciplina de Estruturas de Dados e Algoritmos (EDA) — Engenharia de Software, UnB.
