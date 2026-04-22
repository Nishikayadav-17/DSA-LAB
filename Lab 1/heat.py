import numpy as np
import matplotlib.pyplot as plt
import calendar
import random

def generate_spaced_heatmap(year, month):
    num_days = calendar.monthrange(year, month)[1]
    
    heatmap = np.zeros((6, 7))
    
    active_days = []
    day = 0
    
    while day < num_days:
        gap = random.randint(2, 4)  # gap of 2–4 days
        day += gap
        if day < num_days:
            active_days.append(day)
    
    # Fill heatmap
    day_counter = 0
    for week in range(6):
        for weekday in range(7):
            if day_counter < num_days:
                if day_counter in active_days:
                    heatmap[week][weekday] = random.randint(2, 4)  # green intensity
                day_counter += 1
    
    return heatmap

def plot_heatmap(heatmap, month, year):
    plt.figure(figsize=(10, 3))
    plt.imshow(heatmap, cmap='Greens', aspect='auto')
    
    plt.title(f"Heatmap - {calendar.month_name[month]} {year}")
    plt.xticks(range(7), ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'])
    plt.yticks([])
    
    plt.colorbar(label='Activity')
    plt.show()

# 👉 Choose your month
year = 2025
month = 11  # change this

heatmap = generate_spaced_heatmap(year, month)
plot_heatmap(heatmap, month, year)