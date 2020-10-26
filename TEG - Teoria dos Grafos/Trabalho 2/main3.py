from arquivos.LeitorGrafo import LeitorGrafo
from modelos.Grafo import Grafo

grafo = Grafo(direcionado=False)
grafo.insereNo()
grafo.insereNo()
grafo.insereNo()
grafo.insereNo()
grafo.insereNo()
grafo.insereArco(0, 1, 5)
grafo.insereArco(0, 2, 8)
grafo.insereArco(0, 3, 9)
grafo.insereArco(0, 4, 7)
grafo.insereArco(1, 2, 10)
grafo.insereArco(1, 3, 4)
grafo.insereArco(1, 4, 2)
grafo.insereArco(2, 3, 12)
grafo.insereArco(2, 4, 11)
grafo.insereArco(3, 4, 3)

print(grafo)

a = grafo.minimos()

print(a['grafo'])
