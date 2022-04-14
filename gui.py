import tkinter as tk 

window = tk.Tk()
window.geometry("1000x1000")

initialX = 20 
initialY = 20

#Title 
projectTitle = tk.Label(text = "Film-Inator 5000") #creating the title label 
projectTitle.pack() #adding the widget to the window, pack sizes the window as small as it can while still fully encompassing the widget 

title = tk.Label(text = "Title:")
#title = tk.Label(text = "Title:", fg = "white", bg = "black") 
#title.pack(ipadx = 10, ipady = 10)
title.place(x = initialX, y =initialY)
titleEntry = tk.Entry(fg = "black", bg = "white", width = 30)
titleEntry.pack() #places the titleEntry on the window
titleEntry.place(x = initialX, y = initialY +20)

genre = tk.Label(text = "Genre:")
genre.pack(ipadx = 10, ipady = 10)
genre.place(x = initialX , y = initialY + 60)
genreEntry = tk.Entry(fg = "black", bg = "white", width = 30)
genreEntry.pack() 
genreEntry.place(x = initialX, y = initialY + 80)

rating = tk.Label(text = "Rating:")
rating.pack(ipadx = 10, ipady = 10)
rating.place(x = initialX, y = initialY + 120)
ratingEntry = tk.Entry(fg = "black", bg = "white", width = 30)
ratingEntry.pack() 
ratingEntry.place(x = initialX, y = initialY + 140)

explicit = tk.Label(text = "Explicit:")
explicit.pack(ipadx = 10, ipady = 10)
explicit.place(x = initialX, y = initialY + 180)
explicitEntry = tk.Entry(fg = "black", bg = "white", width = 30)
explicitEntry.pack() 
explicitEntry.place(x = initialX, y = initialY + 200)

keyword = tk.Label(text = "Keyword:")
keyword.pack(ipadx = 10, ipady = 10) 
keyword.place(x = initialX, y= initialY + 240)
keyWordEntry = tk.Entry(fg = "black", bg = "white", width = 30)
keyWordEntry.pack() 
keyWordEntry.place(x = initialX, y = initialY + 260)

language = tk.Label(text = "Language:")
language.pack(ipadx = 10, ipady = 10)
language.place(x = initialX, y = initialY + 300)
languageEntry = tk.Entry(fg = "black", bg = "white", width = 30)
languageEntry.pack() 
languageEntry.place(x = initialX, y = initialY + 320)

director = tk.Label(text = "Director:")
director.pack(ipadx = 10, ipady = 10)
director.place (x = initialX, y = initialY + 360)
directorEntry = tk.Entry(fg = "black", bg = "white", width = 30)
directorEntry.pack() 
directorEntry.place(x = initialX, y = initialY + 380)


window.mainloop()
