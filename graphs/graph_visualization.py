import tkinter as tk
import queue

class GraphVisualization:
    def __init__(self, root):              #constructor used to create and visualize the graph
        self.root = root                            
        self.canvas = tk.Canvas(root, width=800, height=600)
        self.canvas.pack()
        self.graph = {}
        self.node_radius = 20
        self.node_positions = {}           #saves the coordinates of the nodes placed
        self.selected_nodes = []           
        self.canvas.bind("<Button-1>", self.handle_click)
        self.visited_nodes = set()  # Initialize an empty set to track visited nodes
        self.path = []  # List to store the path during traversal

    def handle_click(self, event):         #function called when left mouse button is clicked
        x, y = event.x, event.y            #extracts the x and y coordinates of the mouse click
        clicked_node = self.find_node_at_position(x, y)

        if not clicked_node:
            self.create_node(x, y)                      #creating a node
        elif len(self.selected_nodes) == 0:   
            self.selected_nodes.append(clicked_node)    #to select a node
        else:
            source_node = self.selected_nodes[0]        #to create an edge
            target_node = clicked_node
            self.add_edge(source_node, target_node)
            self.selected_nodes = []

    def find_node_at_position(self, x, y):
        for node, (node_x, node_y) in self.node_positions.items():
            if (node_x - self.node_radius) <= x <= (node_x + self.node_radius) and \
               (node_y - self.node_radius) <= y <= (node_y + self.node_radius):
                return node
        return None

    def create_node(self, x, y):
        node_name = len(self.graph) + 1  # Assign labels 1,2,3...
        self.graph[node_name] = []
        self.node_positions[node_name] = (x, y)
        self.draw_node(node_name, x, y)

    def add_edge(self, node1, node2):
        self.graph.setdefault(node1, []).append(node2)
        self.graph.setdefault(node2, []).append(node1)
        self.draw_edge(node1, node2)

    def draw_node(self, node, x, y):
        self.canvas.create_oval(x - self.node_radius, y - self.node_radius,
                                x + self.node_radius, y + self.node_radius,
                                fill="lightblue")
        self.canvas.create_text(x, y, text=str(node))    #dispay numeric label
        self.root.update()

    def draw_edge(self, source_node, target_node):
        x1, y1 = self.node_positions[source_node]
        x2, y2 = self.node_positions[target_node]
        self.canvas.create_line(x1, y1, x2, y2)
        self.root.update()

    def mainloop(self):
        self.root.mainloop()
    
    def draw_bfs_step(self, node):
        x, y = self.node_positions[node]
        fill_color = "orange"
        if node in self.visited_nodes:  # Check if the node is already visited
            fill_color = "red"
        self.canvas.create_oval(x - self.node_radius, y - self.node_radius,
                                x + self.node_radius, y + self.node_radius,
                                fill=fill_color)
        self.canvas.create_text(x, y, text=str(node))  # Redraw numeric label
        self.root.update()
        self.root.after(1000)
        self.canvas.create_oval(x - self.node_radius, y - self.node_radius,
                                x + self.node_radius, y + self.node_radius,
                                fill=fill_color)
        self.canvas.create_text(x, y, text=str(node))  # Redraw numeric label
        self.root.update()

    def draw_dfs_step(self, node):
        x, y = self.node_positions[node]
        fill_color = "orange"
        if node in self.visited_nodes:  # Check if the node is already visited
            fill_color = "red"
        self.canvas.create_oval(x - self.node_radius, y - self.node_radius,
                                x + self.node_radius, y + self.node_radius,
                                fill=fill_color)
        self.canvas.create_text(x, y, text=str(node))  # Redraw numeric label
        self.root.update()
        self.root.after(1000)
        self.canvas.create_oval(x - self.node_radius, y - self.node_radius,
                                x + self.node_radius, y + self.node_radius,
                                fill=fill_color)
        self.canvas.create_text(x, y, text=str(node))  # Redraw numeric label
        self.root.update()

    def reset_node_colors(self):
        for node in self.visited_nodes:
            x, y = self.node_positions[node]
            self.canvas.create_oval(x - self.node_radius, y - self.node_radius,
                                    x + self.node_radius, y + self.node_radius,
                                    fill="lightblue")
            self.canvas.create_text(x, y, text=str(node))
            self.root.update()
        self.visited_nodes = set()  # Reset the visited nodes
        self.path = []  # Reset the path list
        self.print_path()  # Print the path after resetting colors
    
    def bfsprint(self, sv):
        q = queue.Queue()
        q.put(sv)
        self.visited_nodes.add(sv)  # Mark the starting node as visited
        self.path = [sv]  # Reset the path list with the starting node
        
        
        while not q.empty():
            cv = q.get()
            self.draw_bfs_step(cv)
            neighbors = self.graph[cv]
            for i in neighbors:
                if i not in self.visited_nodes:
                    q.put(i)
                    self.visited_nodes.add(i)  # Mark the newly visited node
        self.reset_node_colors()  # Reset colors after traversal
        self.print_path()  # Print the path after traversal
        
    def dfsprint(self, sv, visited):
        self.visited_nodes = set()  # Initialize the set to track visited nodes
        self.dfsprint_recursive(sv, visited)
        self.reset_node_colors()  # Reset colors after traversal

    def dfsprint_recursive(self, sv, visited):
        self.path = [sv]  # Reset the path list with the starting node
        self.draw_dfs_step(sv)
        visited[sv - 1] = True
        self.visited_nodes.add(sv)  # Mark the visited node
        neighbors = self.graph[sv]
        for i in neighbors:
            if not visited[i - 1]:
                self.dfsprint_recursive(i, visited)
                
    def print_path(self):
        if self.path:
            print("Path:", " -> ".join(map(str, self.path)))

def main():
    root = tk.Tk()
    root.title("Graph Visualization")

    visualization = GraphVisualization(root)
    
    bfs_button = tk.Button(root, text="Visualize BFS", command=lambda: visualization.bfsprint(1))
    bfs_button.pack()

    dfs_button = tk.Button(root, text="Visualize DFS", command=lambda: visualization.dfsprint(1, [False] * len(visualization.graph)))
    dfs_button.pack()
    
    root.mainloop()

if __name__ == "__main__":
    main()

