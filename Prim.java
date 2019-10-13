
import java.util.*; 
import java.lang.*; 
import java.io.*; 

class Prim { 
	// Number of vertices in the graph 
	private static int V; 
        
        //Constructor to initialise V
        Prim(int V)
        {
            this.V = V;
        }

	int minKey(int key[], Boolean mstSet[]) 
	{ 
		// Initialize min value 
		int min = Integer.MAX_VALUE, min_index = -1; 

		for (int v = 0; v < V; v++) 
			if (mstSet[v] == false && key[v] < min) { 
				min = key[v]; 
				min_index = v; 
			} 

		return min_index; 
	} 

	void printMST(int parent[], int graph[][]) 
	{ 
		System.out.println("Edge \tWeight"); 
		for (int i = 1; i < V; i++) 
			System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]); 
	} 

	// Function to construct and print MST for a graph represented 
	// using adjacency matrix representation 
	void primMST(int graph[][]) 
	{ 
		int parent[] = new int[V]; 

		int key[] = new int[V]; 

		Boolean mstSet[] = new Boolean[V]; 

		for (int i = 0; i < V; i++) { 
			key[i] = Integer.MAX_VALUE; 
			mstSet[i] = false; 
		} 

		key[0] = 0; 
		parent[0] = -1; 
		for (int count = 0; count < V - 1; count++) { 
			
			int u = minKey(key, mstSet); 

			mstSet[u] = true; 

			for (int v = 0; v < V; v++) 
				if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) { 
					parent[v] = u; 
					key[v] = graph[u][v]; 
				} 
		} 

		printMST(parent, graph); 
	} 

	public static void main(String[] args) 
	{ 
		Scanner in = new Scanner(System.in);
                System.out.println("Enter number of vertices: ");
                int n = in.nextInt();
		Prim t = new Prim(n); 
                System.out.println("Enter adjacency matrix: ");
		int graph[][] = new int[n][n];
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        graph[i][j] = in.nextInt();
		
		t.primMST(graph); 
	} 
} 

