import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import numpy as np
import os

DATA_PATH = os.path.join("data", "path.csv")

def animate(i):
    try:
        data = pd.read_csv(DATA_PATH, names=["x","y"])
        if data.empty:
            ax.clear()
            ax.text(0.5,0.5, "Waiting for robot...", ha="center", va="center", fontsize= 14)
            return
        
        ax.clear()
        ax.plot(data["x"], data["y"], marker='o', linestyle='-')
        ax.set_title("CompBot Path")
        ax.set_xlim(-10, 10)
        ax.set_ylim(-10,10)
        ax.set_xlabel("x")
        ax.set_ylabel("y")
    except FileNotFoundError:
        ax.clear()
        ax.text(0.5, 0.5, "Waiting for path.csv...", ha="center", va="center", fontsize=14)
    except Exception as e:
        print("Error:", e)
        pass
    
fig, ax = plt.subplots()
ani = animation.FuncAnimation(fig, animate, interval=200)
plt.show()
