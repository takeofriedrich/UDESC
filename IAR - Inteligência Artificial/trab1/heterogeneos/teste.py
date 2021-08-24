from Simulation import Simulation
from ParserDados import ParserDados

p = ParserDados.parseDados('dados15.txt')


sim = Simulation(1, p)

p = ParserDados.parseDados('dados4.txt')

sim = Simulation(1, p)
