import numpy as np
import cv2
import os

# Carrega a imagem usando o OpenCV
caminho_imagem = 'C:/Users/isabe/OneDrive/Documentos/GitHub/ComputerScienceUFFS/Inteligencia-Artificial/Trabalho-1/imagens/gato1.png'
imagem = cv2.imread(caminho_imagem)

# Verifica se a imagem foi carregada corretamente
if imagem is not None:
    # Converte a imagem para um formato adequado
    pixels = imagem.reshape((-1, 3))  # Redimensiona para uma lista de pixels (formato: [número de pixels, 3])

    # Encontra as cores únicas da imagem
    cores_unicas = np.unique(pixels, axis=0)

    # Imprimi no console a quantidade de cores únicas da imagem
    quantidade_cores_unicas = len(cores_unicas)
    print(f"A quantidade de cores únicas na imagem gerada é: {quantidade_cores_unicas}")

    # Calcula o tamanho da imagem em KB
    tamanho_bytes = os.path.getsize('C:/Users/isabe/OneDrive/Documentos/GitHub/ComputerScienceUFFS/Inteligencia-Artificial/Trabalho-1/imagens/gato1.png')  # Tamanho em bytes
    tamanho_kb = tamanho_bytes / 1024  # Tamanho em KB

    print(f"O tamanho em KB da imagem é: {tamanho_kb:.2f} KB")
else:
    print("Não foi possível carregar a imagem.")