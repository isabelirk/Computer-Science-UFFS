import heapq

# Função para calcular a distância de Manhattan entre dois estados
def manhattan_distance(state, goal_state):
    distance = 0
    for i in range(3):
        for j in range(3):
            value = state[i][j]
            if value != 0:
                goal_i, goal_j = divmod(value - 1, 3)
                distance += abs(i - goal_i) + abs(j - goal_j)
    return distance

# Função para verificar se um estado é igual a outro
def is_goal_state(state, goal_state):
    return state == goal_state

# Função para gerar os movimentos possíveis a partir de um estado
def generate_moves(state):
    moves = []
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                if i > 0:
                    new_state = [list(row) for row in state]
                    new_state[i][j], new_state[i - 1][j] = new_state[i - 1][j], new_state[i][j]
                    moves.append(new_state)
                if i < 2:
                    new_state = [list(row) for row in state]
                    new_state[i][j], new_state[i + 1][j] = new_state[i + 1][j], new_state[i][j]
                    moves.append(new_state)
                if j > 0:
                    new_state = [list(row) for row in state]
                    new_state[i][j], new_state[i][j - 1] = new_state[i][j - 1], new_state[i][j]
                    moves.append(new_state)
                if j < 2:
                    new_state = [list(row) for row in state]
                    new_state[i][j], new_state[i][j + 1] = new_state[i][j + 1], new_state[i][j]
                    moves.append(new_state)
    return moves

# Classe para representar um nó na árvore de busca
class Node:
    def __init__(self, state, parent=None):
        self.state = state
        self.parent = parent
        self.g = 0
        self.h = 0

    def __lt__(self, other):
        return (self.g + self.h) < (other.g + other.h)

# Algoritmo A* para encontrar a solução
def a_star(initial_state, goal_state):
    open_list = []
    closed_set = set()

    # Inicialize o nó raiz
    root = Node(initial_state)
    root.g = 0
    root.h = manhattan_distance(initial_state, goal_state)

    # Adicione o nó raiz à lista aberta
    heapq.heappush(open_list, root)

    while open_list:
        # Obtenha o nó com o menor f(n)
        current_node = heapq.heappop(open_list)

        # Verifique se o estado atual é o estado meta
        if is_goal_state(current_node.state, goal_state):
            # Reconstrua o caminho da solução
            actions = []
            while current_node.parent:
                actions.append(current_node.state)
                current_node = current_node.parent
            actions.reverse()
            return actions

        # Adicione o estado atual ao conjunto fechado
        closed_set.add(tuple(map(tuple, current_node.state)))

        # Gere os movimentos possíveis a partir do estado atual
        for move in generate_moves(current_node.state):
            if tuple(map(tuple, move)) not in closed_set:
                child = Node(move, current_node)
                child.g = current_node.g + 1
                child.h = manhattan_distance(move, goal_state)

                # Evite a expansão de estados cuja ação reversa trouxe a busca para o estado atual
                if current_node.parent is None or current_node.parent.state != move:
                    heapq.heappush(open_list, child)

    return None

# Função para imprimir um estado de quebra-cabeça
def print_puzzle(state):
    for row in state:
        print(" | ".join(map(str, row)))
        print("-" * 9)

# Função principal
def main():
    print("Bem-vindo ao solucionador do quebra-cabeça das 8 peças!")
    
    # Solicite ao usuário inserir o estado inicial e o estado meta
    print("Insira o estado inicial (uma linha por vez, use 0 para representar o espaço em branco):")
    initial_state = []
    for _ in range(3):
        row = [int(x) for x in input().split()]
        initial_state.append(row)

    print("Insira o estado meta:")
    goal_state = []
    for _ in range(3):
        row = [int(x) for x in input().split()]
        goal_state.append(row)

    # Encontrar a solução ótima
    solution = a_star(initial_state, goal_state)

    if solution:
        print("Solução encontrada! Sequência de ações para a solução ótima:")
        for step, state in enumerate(solution):
            print(f"Passo {step + 1}:")
            print_puzzle(state)
            print()
    else:
        print("Não foi encontrada uma solução.")

if __name__ == "__main__":
    main()
