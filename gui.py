import tkinter as tk 

window = tk.Tk()
window.geometry("1000x1000")

title = tk.Label(text = "Film-Inator 5000") #creating the title label 
title.pack() #adding the widget to the window, pack sizes the window as small as it can while still fully encompassing the widget 

window.mainloop() 
