package main

import (
	"fmt"

	"github.com/drakcoder/graphlib"
)

func main() {
	g := graphlib.NewGraph("directed")
	g.AddNodes([]string{"a", "b", "c", "d", "e"})
	g.AddLink("a", "b", 6)
	g.AddLink("d", "a", 1)
	g.AddLink("b", "e", 2)
	g.AddLink("b", "d", 1)
	g.AddLink("c", "e", 5)
	g.AddLink("c", "b", 5)
	g.AddLink("e", "d", 1)
	g.AddLink("e", "c", 4)
	// dist, prev := g.Dijkstra("a")
	path1, dist1 := g.DistBetn("a", "e")
	fmt.Println(dist1, path1)

	mg := graphlib.NewMapGraph()
	mg.AddNodes(map[string][]uint{
		"a": {1, 2},
		"b": {2, 4},
		"c": {6, 7},
		"d": {10, 11},
	})
	mg.CreatePath("a", "b", "bi", 10)
	mg.CreatePath("a", "c", "bi", 20)
	mg.CreatePath("a", "d", "bi", 30)
	mg.CreatePath("b", "c", "bi", 40)
	mg.CreatePath("b", "d", "bi", 50)
	mg.CreatePath("c", "d", "bi", 60)
	path2, dist2 := mg.AStar("a")
	fmt.Println(path2, dist2)
}
