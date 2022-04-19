import tkinter as tk 
from functools import partial 

window = tk.Tk()
window.geometry("1000x1000")

initialX = 50 
initialY = 50

#Title 
projectTitle = tk.Label(text = "Film-Inator 5000") #creating the title label 
projectTitle.pack() #adding the widget to the window, pack sizes the window as small as it can while still fully encompassing the widget 

#Authors
authorTitle = tk.Label(text = "By Catherine Lawrence, Emily Lu, and M Vargo")
authorTitle.pack()

#Instruction 
instructionText = tk.Label( text = "Input either a title of a movie OR Input genres, year, explicit, director")
instructionText.pack()


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

year = tk.Label(text = "Year:")
year.pack(ipadx = 10, ipady = 10)
year.place(x = initialX, y = initialY + 160)
yearEntry = tk.Entry(fg = "black", bg = "white", width = 30)
yearEntry.pack() 
yearEntry.place(x = initialX, y = initialY + 180)

explicit = tk.Label(text = "Explicit Language(Yes or No):")
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


def getInfo(message, message2, message3, message4, message5): 
    title = titleEntry.get() 
    genre = genreEntry.get()
    genre2 = genreEntry2.get()
    genre3 = genreEntry3.get()
    year = yearEntry.get()
    explicit = explicitEntry.get()
    director = directorEntry.get()

    if title == "": 
        title = "None Given"

    message.config(text = "Title Selected:" + title)
    message2.config(text = "Genre Selected: " + genre + " " + genre2 + " " + genre3 )
    message3.config(text = "Year Selected:" + year)
    message4.config(text = "Explicit:" + explicit)
    message5.config(text = "Director:" + director)

message = tk.Label()
message2 = tk.Label()
message3 = tk.Label()
message4 = tk.Label()
message5 = tk.Label()

displayAnswer = partial(getInfo, message, message2, message3, message4, message5)
message.place(x=10, y=500) 
message2.place(x=10, y =525)
message3.place(x=10, y=550)
message4.place(x=10, y=575)
message5.place(x=10, y=600)

enterbutton = tk.Button(window, text = "Enter", command = displayAnswer)
enterbutton.place(x=50, y=400)

window.mainloop()
