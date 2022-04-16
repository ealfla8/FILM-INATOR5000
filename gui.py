import tkinter as tk 
from functools import partial 

window = tk.Tk()
window.geometry("1000x1000")

initialX = 20 
initialY = 20

#feels like kinda messy.. consider writing a function that sets up the entire GUI

#Title 
projectTitle = tk.Label(text = "Film-Inator 5000") #creating the title label 
projectTitle.pack() #adding the widget to the window, pack sizes the window as small as it can while still fully encompassing the widget 

title = tk.Label(text = "Title:")
title.place(x = initialX, y =initialY)
titleEntry = tk.Entry(fg = "black", bg = "white", width = 30)
titleEntry.pack() #places the titleEntry on the window
titleEntry.place(x = initialX, y = initialY +20)
titleInput = titleEntry.get() #prob need to add a button so it knows when to get the text

genre = tk.Label(text = "Genre:")
genre.pack(ipadx = 10, ipady = 10)
genre.place(x = initialX , y = initialY + 60)
genreEntry = tk.Entry(fg = "black", bg = "white", width = 30)
genreEntry.pack() 
genreEntry.place(x = initialX, y = initialY + 80)

genreEntry2 = tk.Entry(fg = "black", bg = "white", width = 30)
genreEntry2.pack()
genreEntry2.place(x = initialX, y = initialY + 100)

genreEntry3 = tk.Entry(fg = "black", bg = "white", width = 30)
genreEntry3.pack()
genreEntry3.place(x = initialX, y = initialY + 120)

genreInput = genreEntry.get()
genreInput2 = genreEntry2.get()


year = tk.Label(text = "Year:")
year.pack(ipadx = 10, ipady = 10)
year.place(x = initialX, y = initialY + 160)
yearEntry = tk.Entry(fg = "black", bg = "white", width = 30)
yearEntry.pack() 
yearEntry.place(x = initialX, y = initialY + 180)
yearInput = yearEntry.get()

explicit = tk.Label(text = "Explicit:")
explicit.pack(ipadx = 10, ipady = 10)
explicit.place(x = initialX, y = initialY + 220)
explicitEntry = tk.Entry(fg = "black", bg = "white", width = 30)
explicitEntry.pack() 
explicitEntry.place(x = initialX, y = initialY + 240)
explicitInput = explicitEntry.get()

director = tk.Label(text = "Director:")
director.pack(ipadx = 10, ipady = 10)
director.place (x = initialX, y = initialY + 280)
directorEntry = tk.Entry(fg = "black", bg = "white", width = 30)
directorEntry.pack() 
directorEntry.place(x = initialX, y = initialY + 300)
directorInput = directorEntry.get()

#enterButton = tk.Button(
   # text="Enter",
   # width=28,
   # height=1,
   # bg="white",
   # fg="black",
#) 
#button.place(x = initialX, y = initialY + 360)

def getInfo(message, e1, e2, e3, e4, e5, e6, e7): 
    title = titleEntry.get() 
    genre = genreEntry.get()
    genre2 = genreEntry2.get()
    genre3 = genreEntry3.get()
    year = yearEntry.get()
    explicit = explicitEntry.get()
    director = directorEntry.get()

    message.config(text = "The movie's title you selected is " + str(e1.get())) 

message = tk.Label()

displayAnswer = partial(getInfo, message, titleEntry, genreEntry, genreEntry2, genreEntry3, yearEntry, explicitEntry, directorEntry)
message.place(x=10, y=500) 

enterbutton = tk.Button(window, text = "Enter", command = displayAnswer)
enterbutton.place(x=10, y=400)

window.mainloop()
