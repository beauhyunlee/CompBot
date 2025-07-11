import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd

# every animatino starts witha clearn file
with open("path.csv",  "w") as f:
    f.truncate(0)
# lead data repeatedly
def animate(i):
    try:
        data = pd.read_csv("path.csv", names=["x","y"])
        if data.empty:
            ax.clear()
            ax.text(0.5,0.5, "Waiting for robot...", ha="center", va="Center", fontsize= 14)
            return
        ax.clear()
        ax.plot(data["x"], data["y"], marker='o', linestyle='-')
        ax.set_title("CompBot Path")
        ax.set_xlim(-10, 10)
        ax.set_ylim(-10,10)
        ax.set_xlabel("x")
        ax.set_ylabe("y")
    except:
        pass
fig, ax = plt.subplots()
ani = animation.FuncAnimation(fig, animate, interval=200)
plt.show()
