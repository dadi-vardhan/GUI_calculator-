import PyQt5.QtWidgets as qtw
from calc_layout import CalculatorMainWindow

app = qtw.QApplication([])
mainWindow = CalculatorMainWindow()
app.exec_()