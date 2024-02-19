# Finite Automaton and Pushdown Automaton Implementation

This project contains the implementation of both a finite automaton and a pushdown automaton. The finite automaton is designed to manage a regular language, making transitions through predefined states based on the input characters it processes. The pushdown automaton, on the other hand, evaluates strings composed of `0`s and `1`s to determine their adherence to a specific context-free language pattern.

## Compilation Instructions

To compile this project, you will need a C++ compiler installed on your system. The source code is written in standard C++ and should compile with most C++ compilers without requiring any special flags or configurations.

# Context-Free Language Algorithms

Included in this repository are implementations for algorithms simulating automata for various context-free languages. The codebase showcases a finite automaton for basic state transitions, a pushdown automaton designed for the language `a^nb^n`, and an innovative double stacked pushdown automaton for the more complex language `a^nb^nc^n`.

## Overview of Functions

- `pushdown_automaton`: This function simulates a pushdown automaton tailored for processing the language `a^nb^n`, where `n` represents a positive integer. It checks whether the input word matches the language criteria, specifically ensuring an equal number of `a`s followed by an equal number of `b`s.

- `double_pushdown_automaton`: Expanding on the concept, this function simulates a double stacked pushdown automaton for the language `a^nb^nc^n`. It assesses whether the input string follows the specified pattern, validating that the counts of `a`s, `b`s, and `c`s are equal, thus belonging to the intended context-free language.
