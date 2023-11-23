FIRST = {}

sentences = [
'E->TG',
'G->+TG',
'G->ε',
'T->FS',
'S->*FS',
'S->ε',
'F->(E)',
'F->i',]

#初始化 first 集 和follow集合字典的键值对中的 值 为空
def initail():
    for str  in sentences :
        part_begin = str.split("->")[0]
        part_end = str.split("->")[1]
        FIRST[part_begin] = ""


###求first集 中第第一部分针对 ->  直接推出第一个字符为终结符 部分
def getFirst():
    for str in sentences:
        part_begin = str.split("->")[0]
        part_end = str.split("->")[1]
        if not part_end[0].isupper():
            FIRST[part_begin] = FIRST.get(part_begin) + part_end[0]

##求first第二部分 针对 A -> B型  把B的first集加到A 的first集合中
def getFirst_2():
    for str in sentences:
        part_begin = ''
        part_end = ''
        part_begin += str.split('->')[0]
        part_end += str.split('->')[1]
        ##如果型如A ->B 则把B的first集加到A 的first集中去
        if part_end[0].isupper():
            FIRST[part_begin] = FIRST.get(part_begin) + FIRST.get(part_end[0])


def getFisrt_3():
    while(1):
        test = FIRST
        getFirst_2()
        ##去除重复项
        for i , j  in FIRST.items():
            temp = ""
            for word in list(set(j)):
                temp += word
            FIRST[i] = temp
        if test == FIRST:
            break



initail()
getFirst()
getFisrt_3()
getFisrt_3()
#print(  FIRST )


for i ,j in FIRST.items() :
    str = j[0]
    for temp in j[1:]:
        str = str+ ',' +temp
    print("FIRST("+ i + ")" + " = {"+str+"}")
