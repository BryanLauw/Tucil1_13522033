buffer_size = 7
nRows = 3
nCols = 3

matriks = [[(0,0),(0,1),(0,2),(0,3),(0,4)],[(1,0),(1,1),(1,2),(1,3),(1,4)],[(2,0),(2,1),(2,2),(2,3),(2,4)],
           [(3,0),(3,1),(3,2),(3,3),(3,4)],[(4,0),(4,1),(4,2),(4,3),(4,4)]]

ctr = [0 for i in range (buffer_size)]
list = []
idx = 0

def notEksis(m, l, x, y):
    for i in range (len(l)):
        if (m[x][y] == l[i]):
            return False
    return True

while (ctr[0] < nCols):
    if (idx == 0): 
        list.append(matriks[0][ctr[idx]])
        idx += 1
    elif (idx < buffer_size-1):
        if (idx % 2 != 0):
            if (ctr[idx] != nRows):
                if (notEksis(matriks,list,ctr[idx],ctr[idx-1])):
                    list.append(matriks[ctr[idx]][ctr[idx-1]])
                    print(list)
                    # ctr[idx] += 1
                    idx += 1
                else:
                    ctr[idx] += 1
            else:
                list.pop()
                # list.pop()
                ctr[idx] = 0
                idx -= 1
                ctr[idx] += 1
        else:
            if (ctr[idx] != nCols):
                if (notEksis(matriks,list,ctr[idx-1],ctr[idx])):
                    list.append(matriks[ctr[idx-1]][ctr[idx]])
                    print(list)
                    # ctr[idx] += 1
                    idx += 1
                else:
                    ctr[idx] += 1
            else:
                list.pop()
                # list.pop()
                ctr[idx] = 0
                idx -= 1
                ctr[idx] += 1
    else:
        if (idx % 2 != 0):
            while (ctr[idx] < nRows):
                if(notEksis(matriks,list,ctr[idx],ctr[idx-1])):
                    list.append(matriks[ctr[idx]][ctr[idx-1]])
                    print(list)
                    ctr[idx] += 1
                    list.pop()
                else:
                    ctr[idx] += 1
        else:
            while (ctr[idx] < nCols):
                if(notEksis(matriks,list,ctr[idx-1],ctr[idx])):
                    list.append(matriks[ctr[idx-1]][ctr[idx]])
                    print(list)
                    ctr[idx] += 1
                    list.pop()
                else:
                    ctr[idx] += 1
        ctr[idx] = 0
        idx -= 1
        ctr[idx] += 1
        list.pop()


# list = []

# for i in range(5):
#     flag = True
#     list.append(matriks[0][0])
#     k = 1
#     j = 1
#     while (flag):
#         if (len(list) % 2 != 0):
#             list.append(matriks[j][i])
#             j += 1
#         else:
#             list.append(matriks[i][k])
#             k += 1

#         if (len(list) == 3):
#             j = 1
#             k = 1
#             print(list)
#             list = []
#             flag = False