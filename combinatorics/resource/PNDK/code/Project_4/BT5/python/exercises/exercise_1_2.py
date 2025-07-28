import random

class SGBGraph:
    def __init__(self):
        self.vertices = {}
        self.edges = []
        self.name = "Sample Graph"
    
    def add_vertex(self, vertex_id, label, first_edge=0):
        self.vertices[vertex_id] = {
            'label': label,
            'first_edge': first_edge
        }
    
    def add_edge(self, source, target, label=0, next_edge=0):
        self.edges.append({
            'source': source,
            'target': target,
            'label': label,
            'next_edge': next_edge
        })
    
    def get_sgb_format(self):
        """Chuyển sang định dạng SGB"""
        lines = []
        lines.append(f"* GraphBase graph ({len(self.vertices)},{len(self.edges)})")
        lines.append(self.name)
        lines.append("* Vertices")
        
        for vid in sorted(self.vertices.keys()):
            vertex = self.vertices[vid]
            lines.append(f"{vertex['label']},{vertex['first_edge']},0,0")
        
        lines.append("* Arcs")
        for edge in self.edges:
            lines.append(f"V {edge['target']},{edge['next_edge']},{edge['label']},0")
        
        lines.append("* Checksum 0")
        return "\n".join(lines)
    
    @staticmethod
    def read_sgb_file(filename):
        """Đọc từ file SGB"""
        graph = SGBGraph()
        try:
            with open(filename, 'r') as f:
                lines = [line.strip() for line in f.readlines()]
            
            i = 0
            while i < len(lines):
                if lines[i].startswith("* Vertices"):
                    i += 1
                    vertex_count = 0
                    while i < len(lines) and not lines[i].startswith("*"):
                        if lines[i] and not lines[i].startswith("*"):
                            parts = lines[i].split(',')
                            if len(parts) >= 4:
                                label = parts[0]
                                first_edge = int(parts[1])
                                graph.add_vertex(vertex_count, label, first_edge)
                                vertex_count += 1
                        i += 1
                elif lines[i].startswith("* Arcs"):
                    i += 1
                    while i < len(lines) and not lines[i].startswith("*"):
                        if lines[i] and lines[i].startswith("V"):
                            # Parse edge
                            pass
                        i += 1
                else:
                    i += 1
                    
        except FileNotFoundError:
            print(f"File {filename} not found")
        return graph

def main():
    # Tạo đồ thị ví dụ
    g = SGBGraph()
    g.name = "Test Graph"
    g.add_vertex(0, "A", 0)
    g.add_vertex(1, "B", 1)
    g.add_vertex(2, "C", 0)
    g.add_edge(0, 1, 1, 0)
    g.add_edge(1, 2, 2, 0)
    
    # Ghi ra định dạng SGB
    print("SGB format:")
    print(g.get_sgb_format())
    
    # Ghi vào file
    with open('sample.sgb', 'w') as f:
        f.write(g.get_sgb_format())

if __name__ == "__main__":
    main()