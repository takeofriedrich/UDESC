from modelos.Grafo import Grafo
from arquivos.LeitorGrafo import LeitorGrafo
from graphviz import Digraph

leitor = LeitorGrafo()

g = leitor.leGrafo()

dot = g.toGraphviz()

