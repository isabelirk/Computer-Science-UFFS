import numpy as np
import cv2
import os

# Carrega a imagem usando o OpenCV
caminho_imagem = 'C:/Users/isabe/OneDrive/Documentos/GitHub/ComputerScienceUFFS/Inteligencia-Artificial/Trabalho-1/imagens/gato6.png'
imagem = cv2.imread(caminho_imagem)

# Verifica se a imagem foi carregada corretamente
if imagem is not None:
    # Converte a imagem para um formato adequado para o k-médias
    pixels = imagem.reshape((-1, 3))  # Redimensiona para uma lista de pixels (formato: [número de pixels, 3])

    # Define os parâmetros do algoritmo k-médias
    numero_clusters = 10  # Número de clusters desejados
    criterios = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 100, 0.2) # Critérios de parada do algoritmo k-médias
    print("Carregando...")

    # Aplica o algoritmo k-médias
    _, rotulos, centros = cv2.kmeans(pixels.astype(np.float32), numero_clusters, None, criterios, 10, cv2.KMEANS_RANDOM_CENTERS)
    
    # Converte os centros dos clusters para uint8 (valores inteiros sem sinal de 8 bits - no k-médias são utilizados números do tipo float para representar os centros dos clusters)
    centros = np.uint8(centros)
    
    # Atribui as cores dos clusters aos pixels
    pixels_segmentados = centros[rotulos.flatten()]
    
    # Reformata a imagem para as dimensões da imagem original
    imagem_segmentada = pixels_segmentados.reshape(imagem.shape)
    
    # Salva a nova imagem gerada
    cv2.imwrite('C:/Users/isabe/OneDrive/Documentos/GitHub/ComputerScienceUFFS/Inteligencia-Artificial/Trabalho-1/imagens/imagens-geradas/imagem_segmentada6_10.png', imagem_segmentada)
    print("Imagem salva com sucesso!")

    # Encontra as cores únicas da imagem gerada
    cores_unicas = np.unique(pixels_segmentados, axis=0)

    # Imprimi no console a quantidade de cores únicas da imagem gerada
    quantidade_cores_unicas = len(cores_unicas)
    print(f"A quantidade de cores únicas na imagem gerada é: {quantidade_cores_unicas}")

    # Calcula o tamanho da imagem gerada em KB
    tamanho_bytes = os.path.getsize('C:/Users/isabe/OneDrive/Documentos/GitHub/ComputerScienceUFFS/Inteligencia-Artificial/Trabalho-1/imagens/imagens-geradas/imagem_segmentada6_10.png')  # Tamanho em bytes
    tamanho_kb = tamanho_bytes / 1024  # Tamanho em KB

    print(f"O tamanho em KB da imagem gerada é: {tamanho_kb:.2f} KB")
else:
    print("Não foi possível carregar a imagem.")