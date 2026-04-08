def main()
    jogadores = []

    for i in range(3):
        print(f"--- Cadastro do jogador {i + 1} ---")

        try:
            num = int(input("Digite o número da camisa: "))
            peso = float(input("Digite o peso: "))
            altura = float(input("Digite a altura: "))
            inicial_nome = input("Digite a letra inicial do nome: ").strip()[0]

            