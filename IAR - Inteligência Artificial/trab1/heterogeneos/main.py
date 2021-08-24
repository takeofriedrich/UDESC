from Simulation import Simulation
from View import View
import sys

print(sys.argv)

Simulation.k1 = float(sys.argv[2])
Simulation.k2 = float(sys.argv[3])
Simulation.alpha = float(sys.argv[4])
View.jumps = int(sys.argv[5])
Simulation.ray = int(sys.argv[6])
View.tipo = int(sys.argv[7])

# FILE K1 K2 ALPHA JUMPS RAIO TIPO

if __name__ == '__main__':
    View(sys.argv[1]).standalone()
