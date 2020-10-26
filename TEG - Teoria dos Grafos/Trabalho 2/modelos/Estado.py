from modelos.Grafo import Grafo
from graphviz import Graph


class Estado:

    def __init__(self):
        super().__init__()
        self.__nome = ''
        self.__cidades = {}
        self.__grafo = None

    def setNome(self, nome):
        self.__nome = nome

    def nome(self):
        return self.__nome

    def cidades(self):
        return self.__cidades.keys()

    def grafo(self):
        return self.__grafo

    def setGrafo(self, grafo: Grafo):
        self.__grafo = grafo

    def possuiCidade(self, cidade):
        return cidade in self.__cidades.keys()

    def addCidade(self, cidade):
        if cidade not in self.__cidades.keys():
            self.__cidades[cidade] = len(self.__cidades.items())
        return self.__cidades[cidade]

    def __str__(self):
        s = '\nEstado de ' + self.__nome + ':\n\n'
        for i in self.__cidades.keys():
            s += str(self.__cidades[i]) + ' - ' + i + '\n'
        s += '\n'
        s += str(self.__grafo)
        s += '\n'
        s += str(self.__grafo.stringPesos())
        return s

    def toGraphviz(self, caminho='sc'):
        self.__dot = Graph(engine='circo')
        matrizAdj = self.__grafo.getMatrizAdjacente()
        matrizPesos = self.__grafo.getMatrizPesos()
        for i in self.__cidades.keys():
            self.__dot.node(str(self.__cidades[i]), label=str(i))
        for i in range(self.__grafo.getNumeroNos()):
            for j in range(i, self.__grafo.getNumeroNos()):
                if(matrizAdj[i][j] == 1):
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]))
        self.__dot.render(caminho, view=False, format='jpg')

############################################################################################################################

    def graphVizArvore(self, caminho='arvores'):
        matrizAdj = self.__grafo.getMatrizAdjacente()
        matrizPesos = self.__grafo.getMatrizPesos()
        solucao = self.__grafo.arvoreCustoMinimo()
        comentario = 'Algoritmo da Construção de árvores:\nRota por ' + \
            self.__nome + ' com custo '+str(solucao['custo'])
        self.__dot = Graph(engine='circo', graph_attr={
                           'label': comentario, 'fontsize': '30'})
        grafo = solucao['matriz']
        cont = 0
        for i in self.__cidades.keys():
            if cont != 0:
                self.__dot.node(str(self.__cidades[i]), label=str(i))
            else:
                self.__dot.node(str(self.__cidades[i]), label=str(
                    i), _attributes={'color': 'red', 'penwidth': '7'})
                cont += 1
        for i in range(self.__grafo.getNumeroNos()):
            for j in range(i, self.__grafo.getNumeroNos()):
                if grafo[i][j] == 1:
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]),
                        _attributes={'style': 'filled', 'color': 'red', 'penwidth': '7', 'fontsize': '30'})
                elif matrizAdj[i][j]:
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]))
        self.__dot.render(caminho, view=False, format='jpg')

############################################################################################################################

    def graphVizOrdenacaoPesos(self, caminho='ordenacao', original=False):
        self.__dot = Graph(engine='circo')
        matrizAdj = self.__grafo.getMatrizAdjacente()
        matrizPesos = self.__grafo.getMatrizPesos()
        if original:
            solucao = self.__grafo.ordenacaoPeso()
        else:
            arco = []
            solucao = self.__grafo.ordenacaoPeso(takeo=True, arcoExtra=arco)
            if len(arco) == 3:
                matrizAdj[arco[0]][arco[1]] = 0
        comentario = 'Algoritmo da Ordenação dos pesos das arestas:\nRota por '+self.__nome + \
            ' com custo ' + str(solucao['custo'])
        self.__dot = Graph(engine='circo', graph_attr={
            'label': comentario, 'fontsize': '30'})
        grafo = solucao['grafo'].getMatrizAdjacente()

        cont = 0
        for i in self.__cidades.keys():
            if cont != 0:
                self.__dot.node(str(self.__cidades[i]), label=str(i))
            else:
                self.__dot.node(str(self.__cidades[i]), label=str(
                    i), _attributes={'color': 'red', 'penwidth': '7'})
                cont += 1
        for i in range(self.__grafo.getNumeroNos()):
            for j in range(i, self.__grafo.getNumeroNos()):
                if grafo[i][j] == 1:
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]),
                        _attributes={'style': 'filled', 'color': 'red', 'penwidth': '7', 'fontsize': '30'})
                elif matrizAdj[i][j]:
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]))
        if not original and len(arco) == 3:
            self.__dot.edge(str(arco[0]), str(arco[1]), label=str(arco[2]),
                            _attributes={'style': 'filled', 'color': 'purple', 'penwidth': '7', 'fontsize': '30'})
        self.__dot.render(caminho, view=False, format='jpg')

############################################################################################################################

    def graphVizMinimos(self, caminho='minimos'):
        matrizAdj = self.__grafo.getMatrizAdjacente()
        matrizPesos = self.__grafo.getMatrizPesos()
        solucao = self.__grafo.ordenacaoPeso()
        comentario = 'Algoritmo dos Mínimos Suscessivos:\nRota por ' + \
            self.__nome + ' com custo ' + str(solucao['custo'])
        self.__dot = Graph(engine='circo', graph_attr={
            'label': comentario, 'fontsize': '30'})
        grafo = solucao['grafo']
        cont = 0
        for i in self.__cidades.keys():
            if cont != 0:
                self.__dot.node(str(self.__cidades[i]), label=str(i))
            else:
                self.__dot.node(str(self.__cidades[i]), label=str(
                    i), _attributes={'color': 'red', 'penwidth': '7'})
                cont += 1
        for i in range(self.__grafo.getNumeroNos()):
            for j in range(i, self.__grafo.getNumeroNos()):
                if grafo[i][j] == 1:
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]),
                        _attributes={'style': 'filled', 'color': 'red', 'penwidth': '7', 'fontsize': '30'})
                elif matrizAdj[i][j]:
                    self.__dot.edge(str(i), str(
                        j), label=str(matrizPesos[i][j]))
        self.__dot.render(caminho, view=False, format='jpg')

############################################################################################################################
