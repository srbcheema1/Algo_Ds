package graphlib

import (
	"math"
	"strconv"
)

//point structure for map-graph
type Point struct {
	X uint
	Y uint
}

//Node strucure for map-graph
type MapNode struct {
	point Point
	name  string
	Links []MapEdge
}

//Edge structure for map-graph
type MapEdge struct {
	Dist uint
	from *MapNode
	to   *MapNode
}

// map-graph structure
type MapGraph struct {
	nodes      map[string]*MapNode
	CoorExists map[string]bool
	NodeExists map[string]bool
}

//Function to create a new mapGraph
func NewMapGraph() *MapGraph {
	return &MapGraph{nodes: map[string]*MapNode{}, CoorExists: map[string]bool{}, NodeExists: map[string]bool{}}
}

//function to add nodes to the graph along with heurestics
func (g *MapGraph) AddNodes(names map[string][]uint) {
	for name, coordinates := range names {
		if len(coordinates) != 2 {
			panic("there can only be 2 coordinates for each node")
		}
		coor := strconv.FormatUint(uint64(coordinates[0]), 10) + strconv.FormatUint(uint64(coordinates[1]), 10)
		if g.CoorExists[coor] {
			panic("same coordinates cannot have different points")
		}
		if g.NodeExists[name] {
			panic("points cannot have the same names")
		}
		g.CoorExists[coor] = true
		g.NodeExists[name] = true
		g.nodes[name] = &MapNode{point: Point{X: coordinates[0], Y: coordinates[1]}, name: name, Links: []MapEdge{}}
	}
}

//function to add links between the map nodes
func (g *MapGraph) CreatePath(from, to, ptype string, dist uint) {
	if ptype != "bi" && ptype != "u" {
		panic("path type can be either \"bi\"(bidirectional) or \"u\"(unidirectional)")
	}
	toNode := g.nodes[to]
	fromNode := g.nodes[from]
	if toNode == nil || fromNode == nil {
		panic("creating edge for node that does not exist!")
	}
	fromNode.Links = append(fromNode.Links, MapEdge{from: fromNode, to: toNode, Dist: dist})
	if ptype == "bi" {
		toNode.Links = append(toNode.Links, MapEdge{to: fromNode, from: toNode, Dist: dist})
	}
}

//function to demonstrate A star algorithm using heuristics
//refer to the DistBetn function in the previous file for explanation of the function
//A-start uses heurestic distances to compare and traverse to the next node which may lead to more time efficient results
func (g *MapGraph) AStar(source string) (map[string]uint, map[string]string) {
	GetNext := func(hdist, visited map[string]uint) string {
		min := INFINITY
		u := ""
		for key, value := range hdist {
			if _, ok := visited[key]; ok || value == INFINITY {
				continue
			} else if min > value {
				min = value
				u = key
			}
		}
		return u
	}
	dist, hdist, prev := map[string]uint{}, map[string]uint{}, map[string]string{}
	if _, ok := g.nodes[source]; !ok {
		panic("the given source node does not exist")
	}
	for _, node := range g.nodes {
		dist[node.name] = INFINITY
		hdist[node.name] = INFINITY
		prev[node.name] = ""
	}
	CalculateDist := func(p1, p2 Point) float64 {
		return math.Sqrt(float64(float64((p1.X-p2.X))*float64((p1.X-p2.X)) + float64((p1.Y-p2.Y))*float64((p1.Y-p2.Y))))
	}

	dist[source] = 0
	hdist[source] = 0

	visited := map[string]uint{}
	//the next node is mainly obtained by using the heuristic distances rather than the original distances
	for u := source; u != ""; u = GetNext(hdist, visited) {
		visited[u] = 1
		for _, link := range g.nodes[u].Links {
			if _, ok := visited[link.to.name]; !ok {
				cdist := dist[u]
				alt := cdist + link.Dist
				if alt < dist[link.to.name] {
					dist[link.to.name] = alt
					hdist[link.to.name] = alt + uint(CalculateDist(g.nodes[source].point, g.nodes[u].point))
					prev[link.to.name] = u
				}
			}
		}
	}

	return dist, prev

}
