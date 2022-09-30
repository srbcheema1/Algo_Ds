package graphlib

//Node struct for the graph
type Node struct {
	Name  string
	links []Edge
}

//Edge struct for the graph
type Edge struct {
	from *Node
	to   *Node
	cost uint
}

//The final graph struct
type Graph struct {
	nodes     map[string]*Node
	exists    map[string]bool
	GraphType string
}

//Function to create a graph struct
func NewGraph(GT string) *Graph {
	if GT != "undirected" && GT != "directed" {
		panic("The argument for graph creation can be \"directed\" or \"undirected\" only")
	}
	return &Graph{nodes: map[string]*Node{}, exists: map[string]bool{}, GraphType: GT}
}

//Function to add nodes to the graph object
func (g *Graph) AddNodes(names []string) {
	for _, name := range names {
		if _, ok := g.nodes[name]; !ok {
			g.nodes[name] = &Node{Name: name, links: []Edge{}}
			g.exists[name] = true
		}
	}
}

//Function to create links between the nodes within the graph along with the cost of traversal
func (g *Graph) AddLink(a, b string, cost int) {
	aNode := g.nodes[a]
	bNode := g.nodes[b]
	if aNode == nil || bNode == nil {
		panic("creating edge for node that does not exist!")
	}
	aNode.links = append(aNode.links, Edge{from: aNode, to: bNode, cost: uint(cost)})
	if g.GraphType == "undirected" {
		bNode.links = append(bNode.links, Edge{from: bNode, to: aNode, cost: uint(cost)})
	}
}

//This function finds the shortest distance between the source and destination nodes along with the path using Dijkstra's algorithm
func (g *Graph) DistBetn(source string, destination string) ([]string, uint) {
	//initialising the dist and prev arrays for finding the minimum distances
	dist, prev := map[string]uint{}, map[string]string{}
	var path []string
	//function to reverse the array of nodes
	reverse := func(input []string) []string {
		var res []string
		for i := len(input) - 1; i >= 0; i-- {
			res = append(res, input[i])
		}
		return res
	}
	//function to find the next node to be processed, i.e, the node which has the minimum distance from the source node
	getClosestNonVisitedNode := func(dist map[string]uint, visited map[string]bool) string {
		lowestCost := INFINITY
		lowestNode := ""
		for key, dis := range dist {
			if _, ok := visited[key]; dis == INFINITY || ok {
				continue
			}
			if dis < lowestCost {
				lowestCost = dis
				lowestNode = key
			}
		}
		return lowestNode
	}
	//error check for node existence
	if !g.exists[source] || !g.exists[destination] {
		panic("one of the nodes does not exist!")
	}
	//initialising the distance and previous maps
	for _, node := range g.nodes {
		dist[node.Name] = INFINITY
		prev[node.Name] = ""
	}
	//initialising the visited map to check the already visited nodes
	visited := map[string]bool{}
	//setting the distance from source to 0
	dist[source] = 0
	//looping over the nodes to populate the distance and previous maps
	for u := source; u != ""; u = getClosestNonVisitedNode(dist, visited) {
		//checking if source is destination to return the distance as 0
		if source == destination {
			break
		}
		//setting current distance to the current traversal node
		currDist := dist[u]
		for _, link := range g.nodes[u].links {
			if _, ok := visited[link.to.Name]; ok {
				continue
			}
			//initialising alternate distance
			alt := currDist + link.cost
			v := link.to.Name
			//comparing and assigning the new values
			if alt < dist[v] {
				dist[v] = alt
				prev[v] = u
			}
		}
		//setting the visited value to the node as true
		visited[u] = true
	}
	cur := destination
	//finding the path
	for cur != "" {
		path = append(path, cur)
		cur = prev[cur]
	}
	path = reverse(path)
	//return the shortest path and distance
	return path, dist[destination]
}

const INFINITY = ^uint(0)

//similar to the previous algorithm, but will give the shortest path to all the nodes form a particular source
func (g *Graph) Dijkstra(source string) (map[string]uint, map[string]string) {
	getClosestNonVisitedNode := func(dist map[string]uint, visited map[string]bool) string {
		lowestCost := INFINITY
		lowestNode := ""
		for key, dis := range dist {
			if _, ok := visited[key]; dis == INFINITY || ok {
				continue
			}
			if dis < lowestCost {
				lowestCost = dis
				lowestNode = key
			}
		}
		return lowestNode
	}
	dist, prev := map[string]uint{}, map[string]string{}

	for _, node := range g.nodes {
		dist[node.Name] = INFINITY
		prev[node.Name] = ""
	}
	visited := map[string]bool{}
	dist[source] = 0
	for u := source; u != ""; u = getClosestNonVisitedNode(dist, visited) {
		// fmt.Println(u)
		currDist := dist[u]
		for _, link := range g.nodes[u].links {
			if _, ok := visited[link.to.Name]; ok {
				continue
			}
			alt := currDist + link.cost
			v := link.to.Name
			if alt < dist[v] {
				dist[v] = alt
				prev[v] = u
			}
		}
		visited[u] = true
	}
	return dist, prev
}

//Topological sorting of a graph (Kahn's Algorithm)
func (g *Graph) TopologicalSort() []string {
	//initialising the in-degree map for verification
	in_degree := make(map[string]int)
	//initialising in-degree for all the nodes
	for name := range g.nodes {
		for _, link := range g.nodes[name].links {
			if _, ok := in_degree[name]; !ok {
				in_degree[link.to.Name] = 1
			} else {
				in_degree[link.to.Name]++
			}
		}
	}
	// setting up the queue with nodes with in-degree 0
	var q []string
	for name := range g.nodes {
		if in_degree[name] == 0 {
			q = append(q, name)
		}
	}
	cnt := 0
	var result []string
	for len(q) > 0 {
		cur := q[0]
		q = q[1:]
		result = append(result, cur)
		for _, link := range g.nodes[cur].links {
			in_degree[link.to.Name]--
			if in_degree[link.to.Name] == 0 {
				q = append(q, link.to.Name)
			}
		}
		cnt++
	}
	//this condition occurs only when there is a loop in the graph
	if cnt != len(g.nodes) {
		panic("there exists a cycle in the graph")
	}
	return result
}
