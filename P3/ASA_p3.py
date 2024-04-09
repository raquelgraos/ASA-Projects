from pulp import *
import warnings
warnings.filterwarnings("ignore", category=UserWarning)
#tirar o UserWarning: Spaces are not permitted in the name

var_names = [] #Xi para brinquedos e Pi para pacotes
bundles = {} #Pacotes em que cada brinquedo Xi está presente
bundle_names = [] #Pi
profits = {} #lucros dos Xi e Pi
capacity = {} #capacidade dos Xi
t, p, max_toys = map(int, input().split())
prob = LpProblem("UbiquityInc Profit Maximizator", LpMaximize)

for b in range(t):
    l, c = map(int, input().split())
    var_name = f"X{b + 1}"
    var_names.append(var_name)
    bundles[var_name] = []
    profits[var_name] = l
    capacity[var_name] = c

for b in range(p):
    i, j, k, Lijk = map(int, input().split())

    bundle_name = f"P{b + 1}"
    var_names.append(bundle_name)
    bundle_names.append(bundle_name)
    bundles[f"X{i}"].append(bundle_name)
    bundles[f"X{j}"].append(bundle_name)
    bundles[f"X{k}"].append(bundle_name)
    capacity[bundle_name] = min(capacity[f"X{i}"] , capacity[f"X{j}"] , capacity[f"X{k}"])
    profits[bundle_name] = Lijk

vars = {}
for var_name in var_names:
    vars[var_name] = LpVariable(var_name, 0, capacity[var_name], LpInteger)

prob += lpSum([vars[b]*profits[b] for b in var_names]), "objective"

for var_name in var_names:
    if var_name not in bundle_names:
        prob += (vars[var_name] +  lpSum([vars[b] for b in bundles[var_name]])) <= capacity[var_name]

prob += lpSum([vars[b] * (1 + 2 * (b in bundle_names)) for b in var_names]) <= max_toys

prob.solve(GLPK(msg=0))
print(int(prob.objective.value()))
