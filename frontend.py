from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton, QLineEdit, QFrame, QVBoxLayout, QLabel
import sys
from PySide6.QtCore import QSize
import PySide6.QtCore

class janela(QMainWindow):
    def init(self):
        super().init()

        self.setWindowTitle("QlineEDIT")
        self.setFixedSize(QSize(300, 200))

        self.input = QLineEdit()
        self.input2 = QLineEdit()
        self.lb1 = QLabel("email")
        self.lb2 = QLabel(("senha"))
        self.lb3 = QLabel((""))
        
        self.email = "blablabls"
        self.senha = "2003"
        
        self.layout = QVBoxLayout()
        self.button = QPushButton("Login")
        
        self.layout.addWidget(self.lb1)
        self.layout.addWidget(self.input)
        self.layout.addWidget(self.lb2)
        self.layout.addWidget(self.input2)
        self.layout.addWidget(self.button)
        self.layout.addWidget(self.lb3)
        
        self.container = QFrame()
        
        self.container.setLayout((self.layout))
        
        self.setCentralWidget(self.container)
        self.button.clicked.connect(self.login)
        
        def login(self):
            self.texto1 = self.input.text()
            self.texto2 = self.input2.text()
            if self.button:
                if self.texto1 == self.email and self.texto2 == self.senha:
                    self.lb3.setText("tudo ok")
                else:
                    self.lb3.setText("error404")
                    
app = QApplication(sys.argv)
obj = janela()
obj.show()
app.exec()

            
        
        