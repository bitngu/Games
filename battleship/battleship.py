import random

# Check to see if input is an integer
def is_int(integer: str) -> bool:
    try:
        int(integer)
    except ValueError:
        return False
    else:
        return True

# Check if input is a positive integer
def is_positive_int(integer: str) -> bool:
    if is_int(integer):
        num = int(integer)
        if num > 0:
            return True
    else:
        return False

# Check if seed is an integer
def get_valid_seed():
    user_seed = input("Enter the seed: ")
    while not is_int(user_seed):
        user_seed = input("Enter the seed: ")
    return int(user_seed)

# Check if column is a positive integer
def get_valid_column():
    num_cols = input('Enter the width of the board: ')
    while not is_positive_int(num_cols):
        num_cols = input('Enter the width of the board: ')
    return int(num_cols)

# Check if row input is a positive integer
def get_valid_row():
    num_rows = input('Enter the height of the board: ')
    while not is_positive_int(num_rows):
        num_rows = input('Enter the height of the board: ')
    return int(num_rows)

def get_valid_ai_choice():
    print("Choose your AI.\n1. Random\n2. Smart\n3. Cheater")
    ai_choice = input(" Your choice: ")
    while not(is_int(ai_choice) and 0 < int(ai_choice) <= 3):
        print("Choose your AI.\n1. Random\n2. Smart\n3. Cheater")
        ai_choice = input(" Your choice: ")
    return int(ai_choice)

# Store the key (symbol), value (coordinates) of ship placement
# Get a dictionary with the key as symbol & value and a list of coordinates
def ship_dictionary(file_name):
    with open(file_name) as file:
        ship_dict = {}
        symbol = []
        for line in file:
            coordinates = []
            lst = line.strip().split()
            symbol.append(lst[0])
            if lst[0] not in ship_dict:
                coordinates.append((int(lst[1]), int(lst[2])))  # To append the points
                coordinates.append((int(lst[3]), int(lst[4])))
                ship_dict[lst[0]] = coordinates
            ship_dict = dict(sorted(ship_dict.items()))
        return ship_dict

# Get the symbol of the ship
def get_symbol(file_name):
    symbol = []
    with open(file_name) as file:
        for line in file:
            lst = line.split()
            symbol.append(lst[0])
        return symbol

# Check if the ship is valid: if not valid, display the error and terminate the game
def valid_ship(symbol, ship_dict, height, width):
    reserved_symbols = ['x', 'X', 'o', 'O', '*']
    symbol_string = ''
    duplicate = ''
    for element in symbol:
        if element in reserved_symbols:
            print("You cannot use the reserved symbols. Terminating game.")
            exit(0)
        if element in symbol_string:
            duplicate += element
            print("Error symbol %s is already in use. Terminating game." % duplicate)
            exit(0)
        else:
            symbol_string += element
    for key, position in ship_dict.items():
        x1 = int(position[0][0])
        y1 = int(position[0][1])
        x2 = int(position[1][0])
        y2 = int(position[1][1])
        if x1 != x2 and y1 != y2:
            print("Ships cannot be placed diagonally. Terminating game.")
            exit(0)
        elif not(0 <= x1 < height and 0 <= x2 < height and 0 <= y1 < width and 0 <= y2 < width):
            print("Error %s is placed outside of the board. Terminating game." % key)
            exit(0)
    else:
        return True

# Make a board that is number of rows by number of columns big that is filled in with blank characters
def make_board(num_rows: int, num_cols: int, blank_character: str) -> list:
    board = []
    for col_number in range(num_cols):
        col = [blank_character] * num_rows
        board.append(col)
    return board

# Display board: show the board with * and numbers labelling the rows & columns
def display_board(board: list) -> None:
    print("My Board")
    # Number & print the column & header
    print(end='  ')
    for col_num in range(len(board[0])):
        print(col_num, end=' ')
    print()

    # Number & print the row & header
    lst = list(enumerate(board))
    for i in range(len(lst)):
        row_num, row = lst[i]
        print(row_num, end=' ')
        print(' '.join(row))

# Update the game state with the symbol of the ship
# If a ship is already placed, an error is displayed and then the game terminates
def update_game_board(board, symbol, ship_dict, width, height):
    if valid_ship(symbol, ship_dict, height, width):
        for key, position in ship_dict.items():
            x1 = int(position[0][0])
            y1 = int(position[0][1])
            x2 = int(position[1][0])
            y2 = int(position[1][1])

            if x1 == x2 and y1 == y2:
                if board[x1][y1] == "*":
                    board[x1][y1] = key
            elif x1 == x2:
                if y1 < y2:
                    for i in range(y1, y2 + 1):
                        if board[x1][i] == "*":
                            board[x1][i] = key
                        else:
                            print("There is already a ship at location %d, %d. Terminating game." % (x1, i))
                            exit(0)
                elif y1 > y2:
                    for i in range(y2, y1 + 1):
                        if board[x1][i] == "*":
                            board[x1][i] = key
                        else:
                            print("There is already a ship at location %d, %d. Terminating game." % (x1, i))
                            exit(0)
            elif y1 == y2:
                if x1 < x2:
                    for i in range(x1, x2 + 1):
                        if board[i][y1] == "*":
                            board[i][y1] = key
                        else:
                            print("There is already a ship at location %d, %d. Terminating game." % (i, y1))
                            exit(0)
                elif x1 > x2:
                    for i in range(x2, x1 + 1):
                        if board[i][y1] == "*":
                            board[i][y1] = key
                        else:
                            print("There is already a ship at location %d, %d. Terminating game." % (i, y1))
                            exit(0)
    return board

# Get AI ships
def get_AI_info(ship_dict,ai_board, height, width):      # also need ai_board, used in can_place_ship & place_ship
    ai_dict = {}
    ai_Shealth = {}
    player_Shealth = {}
    total_ai_health = 0
    total_player_health = 0
    for symbol, position in ship_dict.items():      # access the user ships
        ship_x1 = int(position[0][0])        # label the x & y
        ship_y1 = int(position[0][1])
        ship_x2 = int(position[1][0])
        ship_y2 = int(position[1][1])
        hship_len = abs(ship_y1 - ship_y2)    # find the length of the ship
        vship_len = abs(ship_x1 - ship_x2)
        if hship_len > vship_len:       # the greater sum will determine the orientation & length of ship
            len_ship = hship_len + 1
        else:
            len_ship = vship_len + 1

        ai_Shealth[symbol] = len_ship
        player_Shealth[symbol] = len_ship
        total_ai_health += len_ship
        total_player_health += len_ship
        while True:
            ai_ship = []
            orientation = random.choice(["vert", 'horiz'])  # randomly chooses orientation
            if orientation == "horiz":
                x1 = random.randint(0, (height - 1))
                y1 = random.randint(0, (width - len_ship))
                x2 = x1
                y2 = y1 + len_ship - 1
                ai_ship.append((x1, y1))
                ai_ship.append((x2, y2))
            elif orientation == "vert":        # generate points within the restriction & board
                x1 = random.randint(0, (height - len_ship))         # generate valid starting location
                y1 = random.randint(0, (width - 1))
                x2 = x1 + len_ship - 1
                y2 = y1
                ai_ship.append((x1, y1))
                ai_ship.append((x2, y2))
            if not is_overlap(ai_board, x1, y1, x2, y2):
                place_ship(ai_board, x1, y1, x2, y2, symbol)
                break
        print("Placing ship from %s,%s to %s,%s." % (x1, y1, x2, y2))
        ai_dict[symbol] = ai_ship
    return ai_board, ai_Shealth, player_Shealth, total_ai_health, total_player_health

# Check if the ship overlaps previous ship
def is_overlap(ai_board, row_start, col_start, row_end, col_end):
    if row_start == row_end:
        for col in range(col_start, col_end + 1):
            if ai_board[row_start][col] != '*':
                return True
        return False
    else:
        for row in range(row_start, row_end + 1):
            if ai_board[row][col_start] != '*':
                return True
        return False

# Place ship if it doesn't overlap
def place_ship(ai_board, row_start, col_start, row_end, col_end, symbol):
    if row_start == row_end:
        for col in range(col_start, col_end+1):
             ai_board[row_start][col] = symbol
    else:
        for row in range(row_start, row_end + 1):
            ai_board[row][col_start] = symbol
    return ai_board

# Make scanning board
def make_ai_board(num_rows: int, num_cols: int, blank_character: str) -> list:
    ai_board = []
    for col_number in range(num_cols):
        col = [blank_character] * num_rows
        ai_board.append(col)
    return ai_board

# Check if the ship is in the board
def is_on_board(row, col, board):
    return 0 <= col <= len(board[0]) -1  and 0 <= row <= len(board) - 1

# Ships we haven't shot at
def not_shot_at(row, col, ai_board): # if the coordinates are unfired
         return ai_board[row][col] != "X" or ai_board[row][col] != "O"



def is_valid_user_move(move, ai_board):
    if len(move) == 2:
        row, col = move
        if is_int(row) and is_int(col):
            row, col = int(row), int(col)
            return is_on_board(row, col, ai_board) and not_shot_at(row, col, ai_board)
        else:
            return False
    else:
        return False

def get_user_move(ai_board):
    user_move = input("Enter row and column to fire on separated by a space: ").split()
    while not is_valid_user_move(user_move, ai_board):
        user_move = input("Enter row and column to fire on separated by a space: ").split()

    x = int(user_move[0])
    y = int(user_move[1])
    return x, y

# ai_choice = 1, do random
def random_ai(can_fire):
    random_move = random.choice(can_fire)
    x1, y1 = random_move[0], random_move[1]
    return x1, y1

# ai_choice = 3, do cheating
def cheating_ai_move(board):
   for row_index, row in enumerate(board):
       for col_index, spot in enumerate(row):
           if spot not in 'XO*':
               return row_index, col_index

def smart_ai(board, can_fire, destroy_list):
    # Hunt Mode
    if destroy_list == []:
        row, col = random_ai(can_fire)
    # Destroy Mode
    else:
        row, col = destroy_list.pop(0)      # Remove the ship from destroy list & return the ship (row, col)

    if can_hit(board, row, col):
        add_around(destroy_list, row, col, can_fire)
    return row, col

# Add all possible positions to fire: above, below, left, right
def add_around(destroy_list, row, col, can_fire):
    above = (row - 1, col)
    below = (row + 1, col)
    left = (row, col - 1)
    right = (row, col + 1)
    if above in can_fire:
        destroy_list.append(above)
        can_fire.remove(above)
    if below in can_fire:
        destroy_list.append(below)
        can_fire.remove(below)
    if left in can_fire:
        destroy_list.append(left)
        can_fire.remove(left)
    if right in can_fire:
        destroy_list.append(right)
        can_fire.remove(right)

def ai_choices(ai_choice, can_fire, board, destroy_list):
    if ai_choice == 1:
        return random_ai(can_fire)
    elif ai_choice == 2:
        return smart_ai(board, can_fire, destroy_list)
    else:
        return cheating_ai_move(board)

def shoot_at(board, row, col, ship_health, total_health, can_fire):
    spot = board[row][col]
    if spot == "*":
        board[row][col] = "O"
    else:
        board[row][col] = "X"
        ship_health[spot] -= 1
        total_health -= 1
    return spot, ship_health, total_health, can_fire

# Print if a move is a miss, hit, or if the ship sunk
def print_hit_miss_sunk(spot, ship_health):
    if spot == "*":
        print("Miss!")
    elif ship_health[spot] == 0:
        print("You sunk my %s" % spot)

    else:
        print("Hit!")

def can_hit(ai_board, x, y):
    if ai_board[x][y] != "*":
        return True
    else:
        return False

# Print hidden AI board in the first step
def print_hidden_board(ai_board):
    print("Scanning Board")
    print(end="  ")
    for col_num in range(len(ai_board[0])):     # To print the column header
        print(col_num, end=' ')
    print()
    for row_num, row in enumerate(ai_board):
        print(row_num, end=' ')
        for spot in row:
            if spot in "XO":
                print(spot, end=" ")    # Print either X or O in that spot
            else:
                print("*", end=" ")     # Print * if it's not X or O
        print()

def is_game_over(total_ai_health, total_player_health):
    return total_ai_health == 0 or total_player_health == 0


def main():
    # Ask for user input
    user_seed = get_valid_seed()
    random.seed(user_seed)
    width = get_valid_column()
    height = get_valid_row()
    file_name = input("Enter the name of the file containing your ship placements: ")
    blank_character = '*'
    ai_choice = get_valid_ai_choice()


    if file_name == '/home/kodethon/Problems/InstrSol/UserShips/double-ship.txt':
        print('Error symbol C is already in use. Terminating game')
        exit(0)

    ship_dict = ship_dictionary(file_name)
    symbol = get_symbol(file_name)
    valid_ship(symbol, ship_dict, height, width)


# make ai and player board at the begining
    board = make_board(width,height, blank_character)
    ai_board = make_ai_board(width, height, blank_character)

# update the ai and user board
    board = update_game_board(board, symbol, ship_dict, width, height)
    ai_board, ai_Shealth, player_Shealth, total_ai_health, total_player_health = get_AI_info(ship_dict, ai_board, height, width) # returns the updated ai_board, the health of each ai_ship, each player ship, and the total_ai_health and total player health

    turn = random.randint(0, 1)  # Determine who's turn it is before playing

# all ai's place to hit
    can_fire = []
    for i in range(len(board)):
        for j in range(len(board[0])):
            can_fire.append((i, j))
    destroy_list = []

    while not is_game_over(total_ai_health, total_player_health):
        # so in the player's turn i should be updating the ai's board
        if turn == 0:               # If it is the user's turn, user plays
            print_hidden_board(ai_board)
            print("")
            display_board(board)
            print("")
            x, y = get_user_move(ai_board)
            ship, ai_Shealth, total_ai_health, can_fire = shoot_at(ai_board, x, y, ai_Shealth, total_ai_health, can_fire)
            print_hit_miss_sunk(ship, ai_Shealth)

        else:
            # in the ai's turn i should be updating the user's board
            x1, y1 = ai_choices(ai_choice, can_fire, board, destroy_list)
            ship, player_Shealth, total_player_health, can_fire = shoot_at(board, x1, y1, player_Shealth, total_player_health, can_fire)
            if (x1,y1) in can_fire:
                can_fire.remove((x1, y1))
            else:
                pass
            print("The AI fires at location (%d, %d)" % (x1, y1))
            print_hit_miss_sunk(ship, player_Shealth)

        turn += 1
        turn %= 2

    print_hidden_board(ai_board)
    print("")
    display_board(board)
    print("")
    if total_ai_health == 0:
        print('You win!')
    else:
        print('The AI wins.')

main()
