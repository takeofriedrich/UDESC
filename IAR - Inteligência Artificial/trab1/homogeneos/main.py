from Simulation import Simulation
from View import View
import sys

print(sys.argv)

Simulation.k1 = float(sys.argv[2])
Simulation.k2 = int(sys.argv[3])
Simulation.alpha = float(sys.argv[4])
View.jumps = int(sys.argv[5])


if __name__ == '__main__':
    View().standalone()
