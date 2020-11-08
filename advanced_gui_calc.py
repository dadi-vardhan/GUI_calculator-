import sys
from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow
from simple_gui_calc.py import MainWindow
import numpy as np

class MainWindowExt(MainWindow,Advance_Calc_Func):

	def __init__(self):
		super().__init__()
		self.setWindowTitle('Sci-calculator')
        self.setLayout(qtw.QVBoxLayout())
        self.keypad_ext()
        self.show()

	def keypad_ext(self):
		container = qtw.QWidget()
        container.setLayout(qtw.QGridLayout())
		self.label = QLabel(self)
		self.result_field = qtw.QLineEdit()
        result_button = qtw.QPushButton('Enter')    # Enter Button
        clear_button = qtw.QPushButton('Clear')     # Clear Button

		button_log = qtw.QPushButton('log')             
        button_sin = qtw.QPushButton('sin')             
        button_tan = qtw.QPushButton('tan')             
        button_cos = qtw.QPushButton('cos')             
        button_sqrt = qtw.QPushButton('sqrt')    
        button_pow = qtw.QPushButton('^')

		container.layout().addWidget(button_backspace, 1, 0, 1, 1)         
        container.layout().addWidget(clear_button, 1, 2, 1, 1)        
        container.layout().addWidget(self.result_field, 0, 0, 1, 4)
        container.layout().addWidget(button_log, 2, 2)
        container.layout().addWidget(button_sin, 2, 1)
        container.layout().addWidget(button_tan, 2, 0)
        container.layout().addWidget(button_cos, 2, 3)
		container.layout().addWidget(button_sqrt, 2, 2)
        container.layout().addWidget(button_pow, 2, 1)

		button_log.clicked.connect(self.log)
		button_cos.clicked.connect(self.cos)
		button_sin.clicked.cooect(self.sin)
		self.layout().addWidget(container)

# app = qtw.QApplication([])
# mainWindow = MainWindow_ext()
# app.setStyle(qtw.QStyleFactory.create('Fusion'))
# app.exec_()

class Advance_Calc_Func(MainWindowExt):

	def self.__init__(self):
		super().__init__()
		self.input_val = input_val
		self.pow_val = pow_val
		self.log()
		self.tan()
		self.cos()
		self.sin()
		self.sqrt()
		self.pow()

	def log(self,input_val):
		return np.log(input_val)

	def tan(self,input_val):
		return np.tan(input_val)

	def cos(self,input_val):
		return np.cos(input_val)

	def sin(self,input_val):
		return np.sin(input_val)

	def sqrt(self,input_val):
		return np.sqrt(input_val)

	def pow(self,input_val,pow_val):
		return (input_val**pow_val)