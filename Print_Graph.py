import networkx as nx
import matplotlib.pyplot as plt

def draw_graph_with_paths(edges, source):
    G = nx.DiGraph()

    for u, v, weight in edges:
        G.add_edge(u, v, weight=weight)

    # Obliczanie najkrótszych ścieżek
    path_lengths = nx.single_source_dijkstra_path_length(G, source)
    paths = nx.single_source_dijkstra_path(G, source)

    pos = nx.spring_layout(G)  # Pozycje dla wizualizacji
    nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=500)
    nx.draw_networkx_labels(G, pos)
    nx.draw_networkx_edges(G, pos, edge_color='gray')
    edge_labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

    # Rysowanie najkrótszych ścieżek czerwonym kolorem
    for target, path in paths.items():
        path_edges = list(zip(path[:-1], path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=2)

    plt.title('Graf z najkrótszymi ścieżkami od wierzchołka ' + str(source))
    plt.show()

edges = [
    (0, 1, 10), (0, 3, 5), (1, 2, 1), (1, 3, 2),
    (2, 4, 4), (3, 1, 3), (3, 2, 9), (3, 4, 2),
    (4, 0, 7), (4, 2, 6)
]

draw_graph_with_paths(edges, 0)  # 0 to wierzchołek startowy dla algorytmu Dijkstry
