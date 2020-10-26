class Pai(Componente):
    
    def __init__(self):
        self.__id = None
        self.__filhos = []

    def addFilho(self,no):
        self.__filhos.append(no)
