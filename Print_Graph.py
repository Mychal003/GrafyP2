import networkx as nx
import matplotlib.pyplot as plt

def create_and_draw_graph(edges, source):
    G = nx.DiGraph()
    for start, end, weight in edges:
        G.add_edge(start, end, weight=weight)

    # Wyznaczanie najkrótszych ścieżek z użyciem algorytmu Dijkstry
    path_lengths = nx.single_source_dijkstra_path_length(G, source)
    paths = nx.single_source_dijkstra_path(G, source)

    # Ustawienia wizualne dla grafu
    pos = nx.spring_layout(G)
    edge_labels = nx.get_edge_attributes(G, 'weight')

    # Rysowanie grafu
    nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=700, edge_color='gray')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

    # Wyróżnianie najkrótszych ścieżek
    for target, path in paths.items():
        if target != source:  # Pomijamy wierzchołek źródłowy
            path_edges = list(zip(path[:-1], path[1:]))
            nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=2)
            nx.draw_networkx_nodes(G, pos, nodelist=path, node_color='red')

    plt.title('Najkrótsze ścieżki z wierzchołka {}'.format(source))
    plt.show()

# Krawędzie w formacie (start, koniec, waga)
edges = [
    (0, 1, 10), (0, 3, 5), (1, 2, 1), (1, 3, 2),
    (2, 4, 4), (3, 1, 3), (3, 2, 9), (3, 4, 2),
    (4, 0, 7), (4, 2, 6)
]

create_and_draw_graph(edges, 0)  # 0 jest wierzchołkiem źródłowym
