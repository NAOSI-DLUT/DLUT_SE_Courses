setence1 = (
    'E->TG',
    'G->+TG',
    'G->ε',
    'T->FS',
    'S->*FS',
    'S->ε',
    'F->(E)',
    'F->i',
)
setence = (
    "E->TE'",
    "E'->+TE'",
    "E'->ε",
    "T->FT'",
    "T'->* FT'",
    "T'->ε",
    "F->(E)",
    "F->x",
    "A->E",
    #id=x

)
terminate_set = ["(", ")", "*", "+", "ε",]
unterminate_set = []
next_untermin = {}
first_closure = {}


def pre_analyze():
    for produce in setence:
        begin = produce.split("->")[0]
        later = produce.split("->")[1]
        if (begin not in unterminate_set):
            unterminate_set.append(begin)
        if (later.islower() and later not in terminate_set):
            terminate_set.append(later)

    for untermin_item in unterminate_set:
        first_closure[untermin_item] = ""

    for produce in setence:
        begin = produce.split("->")[0]
        later = produce.split("->")[1][0]
        if not (next_untermin.__contains__(begin)):
            next_untermin[begin] = []
        if (later in unterminate_set):
            next_untermin[begin].append(later)
    print("next_untermin", next_untermin)

    print("unterminate_set", unterminate_set)
    print("terminate_set", terminate_set)
    # print("first_closure", first_closure)


def solve_first_closure_part1():
    # A->a
    for terminate_item in terminate_set:
        first_closure[terminate_item] = terminate_item
    for produce in setence:
        begin = produce.split("->")[0]
        later = produce.split("->")[1][0]
        if (later in terminate_set):
            first_closure[begin] = first_closure[begin] + \
                ' '+first_closure[later]
            # first_closure[begin].append(first_closure[later])


def solve_first_closure_part2():
    # A->B

    for untermin_item in next_untermin.keys():
        if (len(next_untermin[untermin_item]) != 0):
            first_closure[untermin_item] = []

    for produce in setence:
        begin = produce.split("->")[0]
        later = produce.split("->")[1][0]
        if (later in unterminate_set):
            first_closure[begin].append(first_closure[later])
    print("first_closure", first_closure)


def clean_anw():
    for item in first_closure:
        if (item in terminate_set):
            continue
        if (isinstance(first_closure[item], str)):
            print(f"{item}:{first_closure[item].split()}")
            first_closure[item] = first_closure[item].split()

        elif (isinstance(first_closure[item][0], list)):
            for subitem in first_closure[item]:
                for string in subitem:
                    print(f"{item}:{string.split()}")
                    first_closure[item] = string.split()
        else:
            for subitem in first_closure[item]:
                print(f"{item}:{subitem.split()}")
                first_closure[item] = subitem.split()


pre_analyze()
solve_first_closure_part1()
solve_first_closure_part2()
#clean_anw()
print("first_closure", first_closure)
