import folium
import pandas as pd

# Reading the CSV file output from C++
df = pd.read_csv("tsp_result.csv")

# Calculating center coordinates for the map
center_lat = df["Latitude"].mean()
center_lon = df["Longitude"].mean()

# Creating the map
m = folium.Map(location=[center_lat, center_lon], zoom_start=6)

# Adding points and drawing the route
route = []
for i, row in df.iterrows():
    lat, lon = row["Latitude"], row["Longitude"]
    name = row["Name"]
    start_time = row["StartTime"]
    end_time = row["EndTime"]
    # Adding marker with time window in popup
    popup_text = f"{name}<br>Time Window: {start_time:.1f} - {end_time:.1f}"
    folium.Marker([lat, lon], popup=popup_text).add_to(m)
    route.append([lat, lon])

# Connecting points with a line
folium.PolyLine(route, color="blue", weight=3).add_to(m)

# Adding total distance, time, and cost (approximated from CSV route)
total_distance = 0.0
total_time = 8.0  # Start at 8 AM
speed_kmh = 50.0
cost_per_km = 10.0
total_cost = 0.0
for i in range(len(route) - 1):
    dx = route[i + 1][1] - route[i][1]
    dy = route[i + 1][0] - route[i][0]
    dist = (dx**2 + dy**2)**0.5
    total_distance += dist
    total_time += dist / speed_kmh
    total_cost += dist * cost_per_km
    if i < len(route) - 1:
        if total_time < df["StartTime"].iloc[i + 1]:
            total_time = df["StartTime"].iloc[i + 1]

# Adding summary to the map
summary_html = f"""
<div style="position: fixed; bottom: 50px; left: 50px; background-color: white; padding: 10px; border: 1px solid black;">
    <h4>Route Summary</h4>
    <p>Total Distance: {total_distance:.2f} degrees</p>
    <p>Total Time: {total_time:.2f} hours</p>
    <p>Total Cost: {total_cost:.2f} units</p>
</div>
"""
folium.Element(summary_html).add_to(m)

# Saving the map to HTML
m.save("tsp_map.html")
print("✅ Saved map to tsp_map.html")