import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carregar os dados do CSV
dados = pd.read_csv("resultados.csv")

# Configurar o gráfico de barras
plt.figure(figsize=(10, 6))
largura_barra = 0.25  # Largura de cada barra
posicoes = np.arange(len(dados["Tamanho"]))  # Posições das barras no eixo X

# Criar as barras para cada algoritmo
plt.bar(posicoes, dados["BubbleSort"], width=largura_barra, label="BubbleSort")
plt.bar(posicoes + largura_barra, dados["MergeSort"], width=largura_barra, label="MergeSort")
plt.bar(posicoes + 2 * largura_barra, dados["QuickSort"], width=largura_barra, label="QuickSort")

# Configurar os rótulos do eixo X
plt.xticks(posicoes + largura_barra, dados["Tamanho"])

# Adicionar título e legendas
plt.title("Comparação de Algoritmos de Ordenação")
plt.xlabel("Tamanho do Vetor")
plt.ylabel("Tempo (microsegundos)")
plt.legend()
plt.grid(axis="y")
plt.savefig("grafico_resultados.png")
plt.show()