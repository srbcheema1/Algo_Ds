class Graph:
    def __init__(self,m,v):
        self.adj=m
        self.V=v

def mColoring(k,m,g,x):

    while(True):
        
        x[k]=getNodeColor(k,m,g,x)
        if(x[k]==0):
            return
        if(k==g.V-1):
            print(x) 
        else:
            mColoring(k+1,m,g,x)
    
def getNodeColor(k,m,g,x):

    while(True):
        
        x[k]=(x[k]+1)%(m+1)   #bcoz any vertex should be assigned from 1 to m
        
        if(x[k]==0):
            return x[k]

        #checking for any collisions of color
        for j in range(g.V):
            if(g.adj[k][j]==1 and x[k]==x[j]):   #same color
                break
        else:
            return x[k]
            
        


def main():
    matrix=[[0,1,1,1],
            [1,0,1,0],
            [1,1,0,1],
            [1,0,1,0] ]
    g=Graph(matrix,4)

    m=3  #Number of colors
    x=[0 for i in range(g.V)]
    mColoring(0,m,g,x)

if __name__=='__main__':
    main()


'''
Possible Coloring:
[1, 2, 3, 2]
[1, 3, 2, 3]
[2, 1, 3, 1]
[2, 3, 1, 3]
[3, 1, 2, 1]
[3, 2, 1, 2]
'''
