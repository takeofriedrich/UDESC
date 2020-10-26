#!/bin/bash

make clean
make
echo 'Caso de teste do enunciado do professor:'
make t1
echo 'Caso de teste do livro do Maziero:'
make t2
echo 'Caso de teste para páginas menores que 0:'
make t3
