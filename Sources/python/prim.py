def setAdj(G):
    Adj = dict()
    for v in G['vertices']:
        Adj[v] = []
    for e in G['edges']:
        weight, u, v = e
        Adj[u].append(e)
    return Adj
def PrimMST(G, Adj):
    print("              T            고려되는 점들 또는 선분들                                              선택")
    T = dict()
    Bound = []
    p = G['vertices'][4]
    T[p] = "start"
    while len(T) < len(G['vertices']):
        
        for e in Adj[p]:
            w, p, u = e
            if u in T:
                Bound.remove((w, u, p))
            else:
                Bound.append(e)
        print(list(T.keys()) ,end='')
        mine = min(Bound, key=lambda x:x[0])
        p = mine[2]
        T[p] = mine
        print("          " ,Bound, "           ",mine)
    return T
graph = {
'vertices': ['A', 'B', 'C', 
'D', 'E', 'F', 'G'],
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
(8, 'E', 'F'),
(9, 'E', 'G'),
(6, 'F', 'D'),
(8, 'F', 'E'),
(11, 'F', 'G'),
(9, 'G', 'E'),
(11, 'G', 'F'),
])
}
Adj = setAdj(graph)
print(Adj)
PrimMST(graph,Adj)