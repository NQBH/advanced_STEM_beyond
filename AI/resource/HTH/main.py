from pathlib import Path
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import collections as mc
import heapq

# --- CẤU HÌNH ---
MAZE_FILENAME = "20 by 20 orthogonal maze.png"

# --- 1) Tải ảnh và chuyển xám ---
base = Path(__file__).parent
img  = Image.open(base/MAZE_FILENAME).convert("L")
arr  = np.array(img)
free = arr > 128
h, w = free.shape

# Tính độ rộng của mõi ô
NUM_COLS = 20
NUM_ROWS = 20
px_col = w / NUM_COLS
px_row = h / NUM_ROWS
pixel_per_cell = int(round((px_col + px_row) / 2))

print(f"Mê cung đã tải lên: {w} x {h} px, mỗi ô ≈ {pixel_per_cell} pixel")

# --- 2) Tìm Start / Goal (mép trên → mép dưới) ---
tops    = [(0,   x) for x in range(w) if free[0,   x]]
bottoms = [(h-1, x) for x in range(w) if free[h-1, x]]

if not tops or not bottoms:
    raise RuntimeError("Không tìm thấy cửa trên hoặc dưới.")

start, goal = tops[0], bottoms[0]

# In dưới dạng (x, y)
sx, sy = start[1], start[0]
gx, gy = goal[1],  goal[0]
print(f"Start = ({sx}, {sy}), Goal = ({gx}, {gy})")

# --- 3) A* tìm đường trên grid 4-connectivity ---
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def astar(start, goal):
    open_h    = [(heuristic(start, goal), 0, start)]
    g_score   = {start: 0}
    came_from = {}
    closed    = set()
    
    while open_h:
        f, g, cur = heapq.heappop(open_h)
        if cur in closed:
            continue
        closed.add(cur)
        
        if cur == goal:
            # Dừng tìm, dựng lại đường đi
            path = [cur]
            while path[-1] in came_from:
                path.append(came_from[path[-1]])
            return path[::-1]
        
        y, x = cur
        for dy, dx in [(0,1), (1,0), (0,-1), (-1,0)]:
            v = (y+dy, x+dx)
            if 0 <= v[0] < h and 0 <= v[1] < w and free[v] and v not in closed:
                ng = g + 1
                if ng < g_score.get(v, float('inf')):
                    g_score[v]   = ng
                    came_from[v] = cur
                    heapq.heappush(open_h, (ng + heuristic(v, goal), ng, v))
    return None

path = astar(start, goal)

if path is None:
    print("Mê cung không có lối thoát!")
    import sys; sys.exit(1)

print(f"Độ dài của đường đi = {len(path)} pixel bước")

# --- 4) Nén path thành đoạn (direction, pixel_length) ---
def compress(path):
    dir_map = {
        ( 0,  1): "Sang phải",
        ( 0, -1): "Sang trái",
        ( 1,  0): "Xuống",
        (-1,  0): "Lên"
    }
    segs = []
    if len(path) < 2:
        return segs

    (y0,x0), (y1,x1) = path[0], path[1]
    d       = (y1-y0, x1-x0)
    cur_dir = dir_map[d]
    cnt     = 1

    for (yp,xp), (yc,xc) in zip(path[1:], path[2:]):
        dv = (yc-yp, xc-xp)
        if dv == d:
            cnt += 1
        else:
            segs.append((cur_dir, cnt))
            d       = dv
            cur_dir = dir_map[d]
            cnt     = 1

    segs.append((cur_dir, cnt))
    return segs

segments = compress(path)

# --- 5) Chuyển pixel_length → cell_length & in kết quả ---
cell_segs = []
for direction, pixlen in segments:
    cells = max(1, int(round(pixlen / pixel_per_cell)))
    cell_segs.append((direction, cells))

total_pix  = sum(p for _,p in segments)
total_cell = sum(c for _,c in cell_segs)

print("\n------------------------------------")
print("Tổng bước đi:")
print(f"  - Tính bằng pixel = {total_pix}")
print(f"  - Tính bằng ô  = {total_cell}\n")
print("Các đoạn di chuyển (Hướng → ô):")
for i, (d, c) in enumerate(cell_segs, 1):
    print(f"{i:3d}. {d:<5s} → {c} ô")

# --- 6) VẼ ĐƯỜNG ĐI Ở GIỮA HÀNH LANG, START “NHÔ” NGOÀI + Legend ngoài khung ---

# 6.1) Chuyển pixel-path (path) → chỉ số cell
cell_indices = [(y // pixel_per_cell, x // pixel_per_cell) for y, x in path]

# 6.2) Lọc bỏ các bước lặp cùng cell để không vẽ thừa
cell_path = []
prev = None
for rc in cell_indices:
    if rc != prev:
        cell_path.append(rc)
        prev = rc

# 6.3) Tính tọa độ pixel giữa mỗi ô từ cell_path
half = pixel_per_cell / 2
xs = [c * pixel_per_cell + half for r, c in cell_path]
ys = [r * pixel_per_cell + half for r, c in cell_path]

# 6.4) Tính Start “nhô” ra ngoài nửa ô theo hướng bước đầu
x0, y0 = xs[0], ys[0]
x1, y1 = xs[1], ys[1]
dx0, dy0 = x1 - x0, y1 - y0
norm0 = (dx0*dx0 + dy0*dy0)**0.5 or 1
ux0, uy0 = dx0/norm0, dy0/norm0
# chỉ offset Start:
sx, sy = x0 - ux0*half, y0 - uy0*half

# 6.5) Goal giữ nguyên tại tâm ô cuối
gx, gy = xs[-1], ys[-1]

# 6.6) Nối Start→cells→Goal
xs_ext = [sx] + xs + [gx]
ys_ext = [sy] + ys + [gy]

# 6.7) Vẽ mê cung gốc + đường đỏ mịn giữa hành lang
imgc = Image.open(base/MAZE_FILENAME).convert("RGB")
arrc = np.array(imgc)
fig, ax = plt.subplots(figsize=(8,8))
ax.imshow(arrc)
ax.plot(xs_ext, ys_ext,
        color="red", linewidth=4,
        solid_capstyle="round", solid_joinstyle="round")

# 6.8) Vẽ marker Start và Goal
ax.scatter(sx, sy,
           color="lime", s=120, marker="o",
           edgecolors="black", zorder=5)
ax.scatter(gx, gy,
           color="blue", s=120, marker="X",
           edgecolors="black", zorder=5)

ax.axis('off')
plt.tight_layout()
plt.show()
