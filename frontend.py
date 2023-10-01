from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
 
def inserir():
  p = txt_p.get()
  q = txt_q.get()
  
  #if(usuario == "admin" and senha == "1234"):
  #  messagebox.showinfo("Aviso", "Usuário e senha corretos")
  #else:
   # messagebox.showinfo("Aviso", "Usuário e senha não conferem")
 
def main():
  global inicial
  global txt_p
  global txt_q
 
  # vamos criar a tela de login
  inicial = Tk()
 
  # vamos definir o tamanho da janela
  inicial.geometry("260x120")
 
  # o titulo da janela
  inicial.title("Criptografia RSA")
 
  # evitamos que a janela seja redimensionada
  inicial.resizable(False, False)
 
  # vamos configurar o grid
  inicial.columnconfigure(0, weight=1)
  inicial.columnconfigure(1, weight=3)
 
  # nome do usuário
  label_usuario = Label(inicial, text="Usuário:")
  label_usuario.grid(column=0, row=0, sticky=W, padx=15, pady=10)
  txt_p = Entry(inicial, width=28)
  txt_p.grid(column=1, row=0, sticky=E, padx=15, pady=10)
 
  # senha
  label_senha = Label(inicial, text="Senha:")
  label_senha.grid(column=0, row=1, sticky=W, padx=15, pady=0)
  txt_q = Entry(inicial, show="*", width=28)
  txt_q.grid(column=1, row=1, sticky=E, padx=15, pady=0)
 
  # botão de login
  btn_login = Button(inicial, text="Entrar", command=autenticar_usuario)
  btn_login.grid(column=1, row=3, sticky=E, padx=15, pady=10)
 
  # entramos no loop de eventos 
  inicial.mainloop() 
 
if __name__== "__main__":
  main()           
        
        