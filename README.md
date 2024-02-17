# Finite Automaton Implementation

This project contains the implementation of a finite automaton and a pushdown automaton. The finite automaton manages a regular language, transitioning through states based on input characters. The pushdown automaton evaluates strings of `0`s and `1`s to determine if they belong to a specific context-free language.

## Compilation

To compile this project, ensure you have a C++ compiler installed 


# Context-Free Language Algorithms

This repository contains implementations for algorithms that simulate automata for different context-free languages, including a finite automaton, a pushdown automaton for the language `a^nb^n`, and a double stacked pushdown automaton for the language `a^nb^nc^n`.

## Overview

The code provides two main functions:

- `pushdown_automaton`: Simulates a pushdown automaton for the language `a^nb^n`, where `n` is a positive integer. This function ensures that the input word belongs to the language where the number of `a`s is followed by the same number of `b`s.

- `double_pushdown_automaton`: Simulates a double stacked pushdown automaton for the language `a^nb^nc^n`, where `n` is a positive integer. It verifies if the input word correctly follows the pattern where the number of `a`s is equal to the number of `b`s, which in turn is equal to the number of `c`s.

## Compilation

To compile the project, ensure you have a C++ compiler installed and use the following command:

```bash
g++ -o contextFreeAlgorithms main.cpp
