import PyQt5.QtWidgets as qtw

class MainWindow(qtw.QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Calculator')
        self.setLayout(qtw.QVBoxLayout())
        self.keypad()
        self.show()

    def keypad(self):
        container = qtw.QWidget()
        container.setLayout(qtw.QGridLayout())

        # Create Buttons
        self.result_field = qtw.QLineEdit()
        result_button = qtw.QPushButton('Enter')    # Enter Button
        clear_button = qtw.QPushButton('Clear')     # Clear Button
        button_0 = qtw.QPushButton('0')             # Button-0 
        button_1 = qtw.QPushButton('1')             # Button-1
        button_2 = qtw.QPushButton('2')             # Button-2
        button_3 = qtw.QPushButton('3')             # Button-3
        button_4 = qtw.QPushButton('4')             # Button-4
        button_5 = qtw.QPushButton('5')             # Button-5
        button_6 = qtw.QPushButton('6')             # Button-6
        button_7 = qtw.QPushButton('7')             # Button-7
        button_8 = qtw.QPushButton('8')             # Button-8
        button_9 = qtw.QPushButton('9')             # Button-9
        button_plus = qtw.QPushButton('+')          # Button-+
        button_minus = qtw.QPushButton('-')         # Button--
        button_mult = qtw.QPushButton('*')          # Button-*
        button_divide = qtw.QPushButton('/')        # Button-/
        button_equal_to = qtw.QPushButton('=')      # Button-=
        button_backspace = qtw.QPushButton('<-')    # Button-<-
        

        # Settting Positions for the Buttons
        container.layout().addWidget(button_backspace, 1, 0, 1, 2)         
        container.layout().addWidget(clear_button, 1, 2, 1, 2)        
        container.layout().addWidget(self.result_field, 0, 0, 1, 4)
        container.layout().addWidget(button_9, 2, 2)
        container.layout().addWidget(button_8, 2, 1)
        container.layout().addWidget(button_7, 2, 0)
        container.layout().addWidget(button_plus, 2, 3)
        container.layout().addWidget(button_6, 3, 2)
        container.layout().addWidget(button_5, 3, 1)
        container.layout().addWidget(button_4, 3, 0)
        container.layout().addWidget(button_minus, 3, 3)
        container.layout().addWidget(button_3, 4, 2)
        container.layout().addWidget(button_2, 4, 1)
        container.layout().addWidget(button_1, 4, 0)
        container.layout().addWidget(button_mult, 4, 3)
        container.layout().addWidget(button_0, 5, 0, 1, 1)
        container.layout().addWidget(button_divide, 5, 3)
        container.layout().addWidget(button_equal_to, 5, 1, 1, 2)

        self.layout().addWidget(container)

app = qtw.QApplication([])
mainWindow = MainWindow()
app.setStyle(qtw.QStyleFactory.create('Fusion'))
app.exec_()