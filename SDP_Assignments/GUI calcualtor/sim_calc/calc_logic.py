
import PyQt5.QtWidgets as qtw
class MainWindow(qtw.QWidget):
    def __init__(self):
        super(qtw.QWidget,self).__init__()
        self.setWindowTitle('Calculator')
        self.setLayout(qtw.QVBoxLayout())
        self.keypad()
        self.show()
        self.temp_nums =[]
        self.fin_nums = []

    def keypad(self):
        container = qtw.QWidget()
        container.setLayout(qtw.QGridLayout())

        # Create Buttons
        self.result_field = qtw.QLineEdit()
        result_button = qtw.QPushButton('enter', clicked = self.func_result)    # Enter Button
        clear_button = qtw.QPushButton('Clear',clicked = self.clear_result)     # Clear Button
        button_0 = qtw.QPushButton('0', clicked = lambda:self.num_press('0'))             # Button-0 
        button_1 = qtw.QPushButton('1', clicked = lambda:self.num_press('1'))             # Button-1
        button_2 = qtw.QPushButton('2', clicked = lambda:self.num_press('2'))             # Button-2
        button_3 = qtw.QPushButton('3', clicked = lambda:self.num_press('3'))             # Button-3
        button_4 = qtw.QPushButton('4', clicked = lambda:self.num_press('4'))             # Button-4
        button_5 = qtw.QPushButton('5', clicked = lambda:self.num_press('5'))             # Button-5
        button_6 = qtw.QPushButton('6', clicked = lambda:self.num_press('6'))             # Button-6
        button_7 = qtw.QPushButton('7', clicked = lambda:self.num_press('7'))             # Button-7
        button_8 = qtw.QPushButton('8', clicked = lambda:self.num_press('8'))             # Button-8
        button_9 = qtw.QPushButton('9', clicked = lambda:self.num_press('9'))             # Button-9
        button_plus = qtw.QPushButton('+', clicked = lambda:self.func_press('+'))          # Button-+
        button_minus = qtw.QPushButton('-', clicked = lambda:self.func_press('-'))         # Button--
        button_mult = qtw.QPushButton('*', clicked = lambda:self.func_press('*'))          # Button-*
        button_divide = qtw.QPushButton('/', clicked = lambda:self.func_press('/'))        # Button-/
        
        

        # Settting Positions for the Buttons
        container.layout().addWidget(result_button, 1, 0, 1, 2)         
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
        self.layout().addWidget(container)

    # displaying numbers selected
    def num_press(self,number):
        self.temp_nums.append(number)
        temp_str = ''.join(self.temp_nums)
        if self.fin_nums:
            self.result_field.setText(''.join(self.fin_nums)+ temp_str)
        else:
            self.result_field.setText(temp_str)

    # displaying operator selected
    def func_press(self,operator):
        temp_str = ''.join(self.temp_nums)
        self.fin_nums.append(temp_str)
        self.fin_nums.append(operator)
        self.temp_nums = []
        self.result_field.setText(''.join(self.fin_nums))

    # displaying the result
    def func_result(self):
        fin_str = "".join(self.fin_nums) + ''.join(self.temp_nums)
        res_str = eval(fin_str)
        fin_str += '='
        fin_str += str(res_str)
        self.result_field.setText(fin_str)

    # clearing the result
    def clear_result(self):
        self.result_field.clear()
        self.temp_nums = []
        self.fin_nums = []
     
app = qtw.QApplication([])
mainWindow = MainWindow()
app.setStyle(qtw.QStyleFactory.create('Fusion'))
app.exec_()