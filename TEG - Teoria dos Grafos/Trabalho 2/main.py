from arquivos.LeitorGrafo import LeitorGrafo
from arquivos.LeitorCidades import LeitorCidades

leitor2 = LeitorCidades(caminho='files/cidades.txt', direcionado=False)
estado = leitor2.leCidades()
print(estado)

estado.graphVizOrdenacaoPesos()
estado.graphVizArvore()
