import random

class Ponto:
    
    id = 0
    random.seed()

    def __init__(self, x = 0 , y = 0 , aleatorio = True):
        if(aleatorio):
            self.__x = round(random.random(), 4)
            self.__y = round(random.random(), 4)
        else:
            self.__x = x
            self.__y = y
        self.__id = Ponto.id
        Ponto.id += 1


    def getX(self):
        return self.__x

    def getY(self):
        return self.__y

    def getId(self):
        return self.__id

    def distancia(self, ponto):
        if isinstance(ponto, Ponto):
            x2 = (self.__x - ponto.getX())**2
            y2 = (self.__y - ponto.getY())**2
            return round((x2+y2)**(0.5),3)
        else:
            raise Exception("Objeto passado não é ponto")
    
    def __str__(self):
        return '(' + str(self.__x) + ',' +str(self.__y) + ')'
