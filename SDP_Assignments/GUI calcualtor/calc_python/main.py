import sys
import PyQt5.QtWidgets as qtw
from simple_gui_calc import Simple_Calc


if __name__ == '__main__':
    app = qtw.QApplication(sys.argv)
    mainWindow = Simple_Calc()
    sys.exit(app.exec_())

