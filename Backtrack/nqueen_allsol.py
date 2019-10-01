def initialize(board,n):
    keys=['queen','row','col','pdiag','sdiag']
    for i in keys:
        board[i]={}
    for i in range(n):
        board['queen'][i]=-1
        board['row'][i]=0
        board['col'][i]=0
    for i in range(-(n-1),n):
        board['pdiag'][i]=0
    for i in range(0,2*n-1):
        board['sdiag'][i]=0

def placequeen(r,board,n):
    return True

def printboard(board,n):
    for row in board['queen'].keys():
        print('(',row,',',board['queen'][row],')',end=' ')
    print('')

def isfree(i,j,board):
    return (board['row'][i]==0 and board['col'][j]==0 and board['pdiag'][j-i]==0 and board['sdiag'][j+i]==0)

def addqueen(i,j,board):
    board['queen'][i]=j
    board['row'][i]=1
    board['col'][j]=1
    board['pdiag'][j-i]=1
    board['sdiag'][j+i]=1

def undoqueen(i,j,board):
    board['queen'][i]=-1
    board['row'][i]=0
    board['col'][j]=0
    board['pdiag'][j-i]=0
    board['sdiag'][j+i]=0

def placequeen(i,board,n):
    for j in range(n):
        if isfree(i,j,board):
            addqueen(i,j,board)
            if i==n-1:
                printboard(board,n)
            else:
                extend=placequeen(i+1,board,n)
            undoqueen(i,j,board)
   
#main
n=int(input('Enter the number of queens:'))
board={}
initialize(board,n)
placequeen(0,board,n)
