import tkinter as tk
from tkinter import ttk
import subprocess
import json

# Função para executar o código C e lidar com a resposta
def executar_codigo_c(entrada):
    try:
        processo = subprocess.Popen(['./seu_programa_em_c'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        stdout, stderr = processo.communicate(input=json.dumps(entrada))
        return stdout
    except Exception as e:
        return str(e)

# Função para lidar com a escolha do usuário
def selecionar_opcao():
    opcao = opcao_var.get()
    
    if opcao == 1:
        # Gerar chave pública
        resultado = executar_codigo_c({'opcao': 'gerar_chave_publica'})
        resultado_text.config(state=tk.NORMAL)
        resultado_text.delete('1.0', tk.END)
        resultado_text.insert(tk.END, resultado)
        resultado_text.config(state=tk.DISABLED)
    elif opcao == 2:
        # Encriptar
        mensagem = mensagem_entry.get()
        chave_publica = chave_publica_entry.get()
        entrada = {'opcao': 'encriptar', 'mensagem': mensagem, 'chave_publica': chave_publica}
        resultado = executar_codigo_c(entrada)
        resultado_text.config(state=tk.NORMAL)
        resultado_text.delete('1.0', tk.END)
        resultado_text.insert(tk.END, resultado)
        resultado_text.config(state=tk.DISABLED)
    elif opcao == 3:
        # Desencriptar
        chave_privada = chave_privada_entry.get()
        entrada = {'opcao': 'desencriptar', 'chave_privada': chave_privada}
        resultado = executar_codigo_c(entrada)
        resultado_text.config(state=tk.NORMAL)
        resultado_text.delete('1.0', tk.END)
        resultado_text.insert(tk.END, resultado)
        resultado_text.config(state=tk.DISABLED)

# Configurar a janela principal
root = tk.Tk()
root.title("Criptografia RSA")

# Configurar a escolha do usuário
opcao_label = ttk.Label(root, text="Escolha uma opção:")
opcao_label.pack()

opcao_var = tk.IntVar()
opcao_var.set(1)

opcao_gerar_chave = ttk.Radiobutton(root, text="Gerar chave pública", variable=opcao_var, value=1)
opcao_encriptar = ttk.Radiobutton(root, text="Encriptar", variable=opcao_var, value=2)
opcao_desencriptar = ttk.Radiobutton(root, text="Desencriptar", variable=opcao_var, value=3)

opcao_gerar_chave.pack()
opcao_encriptar.pack()
opcao_desencriptar.pack()

# Configurar entrada de dados
mensagem_label = ttk.Label(root, text="Mensagem:")
mensagem_label.pack()

mensagem_entry = ttk.Entry(root)
mensagem_entry.pack()

chave_publica_label = ttk.Label(root, text="Chave Pública:")
chave_publica_label.pack()

chave_publica_entry = ttk.Entry(root)
chave_publica_entry.pack()

chave_privada_label = ttk.Label(root, text="Chave Privada:")
chave_privada_label.pack()

chave_privada_entry = ttk.Entry(root)
chave_privada_entry.pack()

# Botão para executar a ação selecionada
executar_button = ttk.Button(root, text="Executar", command=selecionar_opcao)
executar_button.pack()

# Área para exibir o resultado
resultado_text = tk.Text(root, height=10, width=50, state=tk.DISABLED)
resultado_text.pack()

root.mainloop()