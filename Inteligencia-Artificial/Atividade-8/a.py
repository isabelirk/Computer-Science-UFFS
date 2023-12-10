
prob_ensolarado = 2 / 5
prob_nublado = 3 / 5

indice_gini = 1 - (prob_ensolarado**2 + prob_nublado**2)
print(f"Índice de Gini para 'clima': {indice_gini}")


prob_chuvoso = 2 / 5
prob_ensolarado = 2 / 5
prob_nublado = 1 / 5

indice_gini = 1 - (prob_chuvoso**2 + prob_ensolarado**2 + prob_nublado**2)
print(f"Índice de Gini para 'temperatura': {indice_gini}")
