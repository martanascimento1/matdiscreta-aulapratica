import requests 
from tkinter import *
from tkinter import ttk

def soma(a, b):
    resultado = a + b
    return resultado
numero1 = float(input("Digite o primeiro número: "))
numero2 = float(input("Digite o segundo número: "))
resultado = soma(numero1, numero2)
print(f"A soma de {numero1} e {numero2} é igual a {resultado}")

    

soma(a, b)

window = Tk()
window.title("criptografia")

texto_one = Label(window, text="insira")
texto_one.grid(column=0, row=0)

botao = Button(window, text="criptografar", COMMAND= janela)
botao.grid(column=0, row=1)

texto_two = Label(window, text="descriptografar")
texto_two.grid(column=0, row=2)

window.mainloop()
