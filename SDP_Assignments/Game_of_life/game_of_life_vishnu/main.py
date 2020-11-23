import argparse
from GameConsole import Console


def main():
    '''
    Uses argparse to diplay the console and calls the fucntions
    to implement the game.
    Parameters : none

    Returns: none
    '''
    ap = argparse.ArgumentParser(add_help = False) 
    ap.add_argument('-h', '--height', help = 'Board Height', default = 256)
    ap.add_argument('-w', '--width', help = 'Board Width', default = 256)
    args = vars(ap.parse_args()) # Gather Arguments
    board_height = int(args['height'])
    board_width = int(args['width'])
    board = Console((board_height,board_width))
    for _ in board.animate():
        pass


if __name__ == '__main__':
   main()