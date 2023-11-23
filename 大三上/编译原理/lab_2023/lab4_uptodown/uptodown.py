synch_table = {
    "E": [")", "$"],
    "T": ["+", ")", "$"],
    "F": ["+", "*", ")", "$"]
}

origin = "(x)*x+x"+'$'
next_char='s'
print(origin)
now_id = 0


def move_to_next():
    # while (origin[now_id+1] == ' ' and now_id < len(origin)-1):
    #     now_id += 1
    # now_id += 1
    global now_id
    global next_char
    if(origin[now_id]=="x"):
        next_char='x'
    else:
        next_char=origin[now_id]

    now_id = now_id+1


def E():
    # next_char = origin[now_id]
    if (next_char == "x" or next_char == "("):
        print("E->TE'")
        T()
        Ep()
    elif (next_char in synch_table["E"]):
        print("pop stack: pop E,lack x")
    else:
        print("jump", origin[now_id], sep=",")


def Ep():
    # next_char = origin[now_id+1]
    if (next_char == "+"):
        print("E'->+TE'")
        move_to_next()
        T()
        Ep()
    elif (next_char == "$" or next_char == ")"):
        print("E'->#")
    else:
        print("jump", next_char)
        move_to_next()
        Ep()


def T():
    # next_char = origin[now_id+1]
    if (next_char == "(" or next_char == "x"):
        print("T->FT'")
        F()
        Tp()
    elif (next_char in synch_table["T"]):
        print("pop stack: T")
    else:
        print(f"jump {next_char}because more {next_char}")
        move_to_next()
        T()


def Tp():
    # next_char = origin[now_id+1]
    if (next_char == "*"):
        print("T'->*FT'")
        move_to_next()
        F()
        Tp()
    elif (next_char in ["$", "+", ")"]):
        print("T'->#")

    else:
        print(f"jump {next_char}because more {next_char}")
        move_to_next()
        Tp()


def F():
    # next_char = origin[now_id+1]
    if (next_char == "x"):
        print("F->id")
        move_to_next()
    elif (next_char == '('):
        print("F->(E)")
        move_to_next()
        E()
        if (next_char != ')'):
            print("pop stack: ),lack )")
        #pay attention to )
        move_to_next()
    elif (next_char in synch_table["F"]):
        print("pop stack: F,lack id")
    else:
        print(f"jump {next_char}because more {next_char}")
        move_to_next()
        F()


def main():
    move_to_next()
    E()


main()

# id+id
# E->TE'
# T->FT'
# F->id
# T'->#
# E'->TE'
# T->FT'
# F->id
# T'->#
# E'->#
