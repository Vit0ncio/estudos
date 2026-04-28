def main():
    jogadores = []

    for i in range(3):
        print(f"--- Cadastro do jogador {i + 1} ---")

        try:
            num = int(input("Digite o número da camisa: "))
            peso = float(input("Digite o peso: "))
            altura = float(input("Digite a altura: "))
            inicial_nome = input("Digite a letra inicial do nome: ").strip()[0]

            jogadores.append({
                "num": num,
                "peso": peso,
                "alt": altura,
                "i_nome": inicial_nome
            })

            print()
        except(ValueError, IndexError):
            print("Entrada inválida. Certifique-se de digitar números e letras corretamente.")
            return
        
    mais_baixo = jogadores[0]["alt"]
    inicial_do_mais_baixo = jogadores[0]["i_nome"]
    mais_gordo = jogadores[0]["peso"]

    for i in range(1, len(jogadores)):
        if jogadores[i]["peso"] > mais_gordo:
            mais_gordo = jogadores[i]["peso"]

        if jogadores[i]["alt"] < mais_baixo:
            mais_baixo = jogadores[i]["alt"]
            inicial_do_mais_baixo = jogadores[i]["i_nome"]

    print("\n" + "="*30)
    print(f"A inicial do jogador mais baixo é: {inicial_do_mais_baixo}")
    print(f"O jogador mais pesado tem: {mais_gordo:.2f} quilos")
    print("="*30)

    input("\nPressione Enter para finalizar.")

    if __name__ == "__main__":
        main()
