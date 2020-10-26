class Componente:
    
    def __init__(self, id:int):
        self.__id = id

    def getId(self):
        return self.__id

    def __str__(self):
        return str(self.__id)