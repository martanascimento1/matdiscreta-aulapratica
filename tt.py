import tkinter as tk


def main():

    janela_principal = tk.Tk()
    janela_principal.title("Criptografia RSA")
    # janela_principal.iconbitmap("icon.ico")
    texto_one = Label(janela_principal, text="insira")
    texto_one.grid(column=0, row=0)
    # janela_principal.geometry("700x400")
    # janela_principal.maxsize(width=900, height=550)
    # janela_principal.minsize(width=500, height=300)
   # entrada = Entry(janela_principal,width=10)
   # entrada.grid(column=1, row=0)
    botao = Button(janela_principal, text="Clica aqui", command=ola)
    botao.grid(column=2, row=0, padx=5, pady=15)

janela_principal.mainloop()

if __name__ == "__main__":
    main()
