from random import shuffle
from pygame import display

from pygame.draw import rect
from ParserDados import ParserDados
from Simulation import Simulation
import pygame
from pygame import surface
from pygame.locals import *
import sys
import os


class View:

    jumps = 10
    __simulation = None
    __currentState = 0
    __ages = 0
    __screen = None
    __showAnts = False
    __stop = False
    __simulationNumber = None
    # __labels = [(255, 0, 0),
    #             (128, 128, 128),
    #             (128, 128, 0),
    #             (128, 0, 0),
    #             (0, 128, 0),
    #             (128, 0, 128),
    #             (0, 128, 128),
    #             (255, 127, 80),
    #             (255, 140, 0),
    #             (184, 134, 11),
    #             (50, 205, 50),
    #             (0, 191, 255),
    #             (75, 0, 130),
    #             (238, 130, 238),
    #             (245, 222, 179),
    #             (188, 143, 143),
    #             (176, 196, 222), ]
    __labels = [(255, 0, 0), (255, 0, 255), (0, 0, 255), (0, 255, 0), ]

    def __init__(self, path=None) -> None:
        shuffle(View.__labels)
        View.__simulationNumber = View.getCounter()
        View.__simulation = Simulation(
            era=1, dados=ParserDados.parseDados(path) if path is not None else None)

    # Returna 0 se for formiga e 1 caso dado e 2 caso outro

    @staticmethod
    def __draw_grid() -> None:
        for i in range(View.__simulation.getN()):
            for j in range(View.__simulation.getM()):
                elementAt = View.__simulation.getTypeInGrid(
                    i, j)
                color = None
                if elementAt == 1:
                    positions = View.__simulation.getDataAtributes(
                        i, j)
                    if not View.__simulation.hasLabels():
                        color = (0, 0, 0)
                    else:
                        # print('>>>>>>>', positions[2])
                        color = View.__labels[positions[2]-1]

                elif elementAt == 2:
                    color = (255, 255, 255)

                elif View.__showAnts:
                    if View.__simulation.getAntInPoint(i, j).isCarrying():
                        color = (255, 0, 0)
                    else:
                        color = (0, 0, 0)
                else:
                    if View.__simulation.getAntInPoint(i, j).isCarrying():

                        positions = View.__simulation.getDataAtributesFromAnts(
                            i, j).getDatas()
                        if not View.__simulation.hasLabels():

                            color = (0, 0, 0)
                        else:
                            color = View.__labels[positions[2]-1]
                    else:
                        color = (255, 255, 255)
                View.__draw_pixel(color=color, x=20+(i*9), y=20+(j*9))
        pygame.display.flip()

    @staticmethod
    def __draw_pixel(color: tuple, x: int, y: int):
        # print(color)
        s = pygame.Surface((9, 9))
        s.fill(color)
        r, r.x, r.y = s.get_rect(), x+1, y+1
        View.__screen.blit(s, r)

    @staticmethod
    def __take_screenshot(filename):
        image = pygame.Surface((500, 500))
        image.blit(View.__screen, (0, 0), ((0, 0), (500, 500)))
        pygame.image.save(image, filename)

    @staticmethod
    def titleType():
        return 'vê-las' if not View.__showAnts else 'ocutá-las'

    @staticmethod
    def __run():

        View.__screen.fill((255, 255, 255))
        programIcon = pygame.image.load('ant.png')
        pygame.display.set_icon(programIcon)
        pygame.display.flip()

        View.__draw_grid()
        clock = pygame.time.Clock()
        while 1:
            pygame.display.set_caption(
                '{} Formiguinhas {} - Pressione SPACE para {} - {}'.format('>' if Simulation.stop else ' ', View.__currentState+(View.jumps*View.__ages), View.titleType(), View.__simulation.countsCarringAnts()))
            clock.tick(120)
            for event in pygame.event.get():
                if event.type == QUIT:
                    return
            if(pygame.key.get_pressed()[K_ESCAPE]):
                View.__stop = not View.__stop
            if(pygame.key.get_pressed()[K_SPACE]):
                View.__showAnts = not View.__showAnts
            if(pygame.key.get_pressed()[K_s]):
                Simulation.stop = not Simulation.stop
            if(pygame.key.get_pressed()[K_0]):
                image = pygame.Surface((500, 500))
                image.blit(View.__screen, (0, 0), ((0, 0), (500, 500)))
                pygame.image.save(
                    image, 'screenshots/{}.jpg'.format(View.getCounter()))
            if(pygame.key.get_pressed()[K_1]):
                open('alpha.txt', 'w').write('{}'.format(
                    View.__simulation.calculateAlpha()))

            if not View.__stop:

                View.__currentState += 1
                View.__simulation = View.__simulation.next()

                if(View.__currentState == View.jumps):

                    View.__ages += 1
                    View.__currentState = 0
                    View.__draw_grid()

            age = View.__currentState+(10*View.__ages)

            if(((age-1) % 1000) == 0):
                coef = View.__simulation.agglomerateCoef2(5)
                print('taking: COEF {}'.format(coef))
                View.__take_screenshot(
                    'screenshots/raio-{}-cons-{}-age-{}.png'.format(Simulation.k2, Simulation.k1, age))
            if age == 30000:
                Simulation.stop = not Simulation.stop
            if age > 30000 and View.__simulation.countCarring() == 0:
                print('taking FINAL')
                View.__take_screenshot(
                    'screenshots/raio-{}-cons-{}-age-{}.png'.format(Simulation.k2, Simulation.k1, age))
                return

    @ staticmethod
    def getCounter() -> int:
        read = open('counter.txt', 'r').readline()
        cont = int(open('counter.txt', 'r').readline()
                   ) if read is not '' else 0
        open('counter.txt', 'w').write(str(cont+1))
        return cont

    @ staticmethod
    def standalone():
        pygame.init()
        View.__screen = pygame.display.set_mode((500, 500), DOUBLEBUF)
        View.__run()
        pygame.quit()
