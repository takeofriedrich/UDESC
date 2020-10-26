from modelos.Grafo import Grafo
from modelos.Ponto import Ponto
import math
import shutil
import os
import imageio


class Algoritmo:

    def __init__(self, n):
        self.__n = n
        self.__pontos = []  # vetor vazio para guardar os pontos
        self.__grafo = None  # ponteiro pro grafo

    def gerarPontos(self):
        for i in range(self.__n):
            p = Ponto()
            self.__pontos.append(p)

    def __log(self):
        return int(math.log(self.__n, 2))

    def __iniciaMatrizDistancias(self):
        distancias = []
        for i in range(self.__n):
            aux = []
            for j in range(self.__n):
                aux.append(0)
            distancias.append(aux)
        return distancias

    def __calculaDistancias(self, distancias):
        for i in range(self.__n):
            ponto = self.__pontos[i]
            for j in range(i, self.__n):
                distancias[i][j] = ponto.distancia(self.__pontos[j])
                distancias[j][i] = ponto.distancia(self.__pontos[j])

    def __imprimeMatriz(self, distancias):
        for i in range(self.__n):
            linha = ''
            for j in range(self.__n):
                linha += str(distancias[i][j]) + ','

    def __calculaVizinhosGrafo(self, distancias, maxVizinhos):
        for i in range(self.__n):

            if self.__grafo.grau(i) >= maxVizinhos:
                continue

            viz = distancias[i].copy()

            for k in sorted(viz):

                for j in range(self.__n):

                    if i == j or self.__grafo.grau(j) >= maxVizinhos:
                        continue

                    if distancias[i][j] == k:

                        if self.__grafo.grau(i) < maxVizinhos and self.__grafo.grau(j) < maxVizinhos:
                            self.__grafo.insereArco(i, j)

    def __melhora(self, distancias, maxVizinhos):

        incompletos = []

        for i in range(self.__n):
            if self.__grafo.grau(i) < maxVizinhos:
                incompletos.append(i)

        for i in range(0, len(incompletos)-1, 2):
            self.__grafo.insereArco(incompletos[i], incompletos[i+1])

        if len(incompletos) % 2 == 1:
            for i in range(self.__n):
                if i == incompletos[-1]:
                    continue
                if self.__grafo.grau(i) < maxVizinhos:
                    self.__grafo.insereArco(incompletos[-1], i)

    def construirGrafo(self):

        # Define o maximo de vizinhos a partir do log n
        maxVizinhos = self.__log()

        # Cria uma matriz n x n e enche ela de 0s
        distancias = self.__iniciaMatrizDistancias()

        # Para a diagonal triangular superior, calcula a distancia ponto a ponto
        self.__calculaDistancias(distancias)

        # Cria um novo grafo
        self.__grafo = Grafo(direcionado=False)

        # Imprime a matriz de distancias
        self.__imprimeMatriz(distancias)

        # Adiciona os n nós ao grafo
        for i in range(self.__n):
            self.__grafo.insereNo()

        # Percorre a matriz de distancias e pega os log n vizinhos
        self.__calculaVizinhosGrafo(distancias, maxVizinhos)

        self.__melhora(distancias, maxVizinhos)

        self.__grafo.toGraphviz()

    def geraImagens(self, no):
        self.__grafo.dfs(no, self.__grafo.aoVisitar, self.__grafo.aoSair)

    def reinicia(self):
        self.__grafo.reinicia()

    def recriaPasta(self):
        shutil.rmtree(Grafo.caminho)
        os.mkdir(Grafo.caminho)

    def geraGif(self):
        self.__grafo.gif()
        # self.recriaPasta() # OLHA
        self.__grafo.reinicia()
