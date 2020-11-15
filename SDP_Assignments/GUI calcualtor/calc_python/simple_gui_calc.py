import sys
import PyQt5.QtWidgets as qtw

class Simple_Calc(qtw.QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Calculator')
        self.setLayout(qtw.QVBoxLayout())
        self.keypad()
        self.show()

    def keypad(self):
        container = qtw.QWidget()
        container.setLayout(qtw.QGridLayout())
        self.label = qtw.QLabel(self)
        ####################
        self.label.setGeometry(0, 0,1000,150)
        self.label.setWordWrap(True)
        self.label.setStyleSheet("QLabel"
                                 "{"
                                 "border : 4px solid black;"
                                 "background : white;"
                                 "}") 

        #################
        
        # Create Buttons
        #self.result_field = qtw.QLineEdit()
        #result_button = qtw.QPushButton('Enter')    # Enter Button
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
        button_ext = qtw.QPushButton('ext')         # button for extending calc
        

        # Settting Positions for the Buttons
        container.layout().addWidget(button_backspace, 10, 220, 40, 20)         
        container.layout().addWidget(clear_button, 10, 250, 40, 20)        
        #container.layout().addWidget(self.result_field, 0, 0, 1, 4)
        container.layout().addWidget(button_9, 10,200,40,20)
        container.layout().addWidget(button_8, 10,175,40,20)
        container.layout().addWidget(button_7, 10, 155,40,20)
        container.layout().addWidget(button_6, 15, 200,40,20)
        container.layout().addWidget(button_5, 15, 175,40,20)
        container.layout().addWidget(button_4, 15,155,40,20)
        container.layout().addWidget(button_3, 20,200,40,20)
        container.layout().addWidget(button_2, 20,175,40,20)
        container.layout().addWidget(button_1, 20, 155,40,20)
        container.layout().addWidget(button_0, 25, 155, 40, 20)
        container.layout().addWidget(button_plus, 20,220,40,20)
        container.layout().addWidget(button_minus, 20,250,40,20)
        container.layout().addWidget(button_mult, 15,220,40,20)
        container.layout().addWidget(button_divide, 15,250,40,20)
        container.layout().addWidget(button_equal_to, 25, 250, 40, 20)
        container.layout().addWidget(button_ext, 25,220,40,20)
        self.layout().addWidget(container)
        #button actions
        button_1.clicked.connect(self.action1)
        button_0.clicked.connect(self.action0)
        button_2.clicked.connect(self.action2)
        button_3.clicked.connect(self.action3)
        button_4.clicked.connect(self.action4)
        button_5.clicked.connect(self.action5)
        button_6.clicked.connect(self.action6)
        button_7.clicked.connect(self.action7)
        button_8.clicked.connect(self.action8)
        button_9.clicked.connect(self.action9)
        button_plus.clicked.connect(self.add)
        button_minus.clicked.connect(self.substract)
        button_mult.clicked.connect(self.multiply)
        button_divide.clicked.connect(self.divide)
        button_equal_to.clicked.connect(self.result)
        clear_button.clicked.connect(self.clear_func)
        button_backspace.clicked.connect(self.delete_func)

        
    # calaculator functions
    def result(self):  
        equation = self.label.text() 
  
        try: 
            ans = eval(equation)  
            self.label.setText(str(ans)) 
        except: 
            self.label.setText("Invalid input") 
  
    def add(self): 
        text = self.label.text() 
        self.label.setText(text + " + ") 
  
    def substract(self): 
        text = self.label.text() 
        self.label.setText(text + " - ") 

    def divide(self): 
        text = self.label.text() 
        self.label.setText(text + " / ") 
  
    def multiply(self): 
        text = self.label.text() 
        self.label.setText(text + " * ") 
  
    def action_point(self): 
        text = self.label.text() 
        self.label.setText(text + ".") 
  
    def action0(self): 
        text = self.label.text() 
        self.label.setText(text + "0") 
  
    def action1(self): 
        text = self.label.text() 
        self.label.setText(text + "1") 
  
    def action2(self): 
        text = self.label.text() 
        self.label.setText(text + "2") 
  
    def action3(self): 
        text = self.label.text() 
        self.label.setText(text + "3") 
  
    def action4(self): 
        text = self.label.text() 
        self.label.setText(text + "4") 
  
    def action5(self): 
        text = self.label.text() 
        self.label.setText(text + "5") 
  
    def action6(self): 
        text = self.label.text() 
        self.label.setText(text + "6") 
  
    def action7(self): 
        text = self.label.text() 
        self.label.setText(text + "7") 
  
    def action8(self): 
        text = self.label.text() 
        self.label.setText(text + "8") 
  
    def action9(self): 
        text = self.label.text() 
        self.label.setText(text + "9") 
  
    def clear_func(self): 
        self.label.setText("") 
  
    def delete_func(self): 
        text = self.label.text() 
        print(text[:len(text)-1]) 
        self.label.setText(text[:len(text)-1]) 


# app = qtw.QApplication(sys.argv)
# mainWindow = Simple_Calc()
# app.setStyle(qtw.QStyleFactory.create('Fusion'))
# app.exec_()


