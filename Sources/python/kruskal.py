parent = dict()
rank = dict()
def find(vertice):
    if parent[vertice] != vertice:
        parent[vertice] = find(parent[vertice])
    return parent[vertice]
def union(vertice1, vertice2):
    root1 = find(vertice1)
    root2 = find(vertice2)
    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root1] = root2
        if rank[root1] == rank[root2]:
            rank[root2] += 1
def make_set(vertice):
    parent[vertice] = vertice
    rank[vertice] = 0
def kruskal(graph):
    for vertice in graph['vertices']:
        make_set(vertice)
    minimum_spanning_tree = set()
    edges = list(graph['edges'])
    edges.sort()
    i =0
    for edge in edges:
        _, vertice1, vertice2 = edge
        if find(vertice1) != find(vertice2):
            union(vertice1, vertice2)
            minimum_spanning_tree.add(edge)
        i+=1
        if(i ==9):
            break
    return sorted(minimum_spanning_tree)
graph = {
'vertices': ['A', 'B', 'C', 
'D', 'E', 'F', 'G','H' , 'I' , 'J'],
'edges': set([
(7, 'A', 'B'),
(5, 'A', 'D'),
(7, 'B', 'A'),
(8, 'B', 'C'),
(9, 'B', 'D'),
(7, 'B', 'E'),
(8, 'C', 'B'),
(5, 'C', 'E'),
(5, 'D', 'A'),
(9, 'D', 'B'),
(7, 'D', 'E'),
(6, 'D', 'F'),
(7, 'E', 'B'),
(5, 'E', 'C'),
(7, 'E', 'D'),
(8, 'I', 'F'),
(9, 'H', 'G'),
(6, 'J', 'D'),
(8, 'F', 'E'),
(11, 'F', 'G')
])
}
print(kruskal(graph))
