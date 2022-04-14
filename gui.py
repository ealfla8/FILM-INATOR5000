import tkinter as tk 

window = tk.Tk()
window.geometry("1000x1000")

initialX = 20 
initialY = 20

#Title 
projectTitle = tk.Label(text = "Film-Inator 5000") #creating the title label 
projectTitle.pack() #adding the widget to the window, pack sizes the window as small as it can while still fully encompassing the widget 

title = tk.Label(text = "Title:")
#title = tk.Label(text = "Title:", fg = "white", bg = "black") #idk if this cute .. kinda ugly.. 
#title.pack(ipadx = 10, ipady = 10)
title.place(x = initialX, y =initialY)

genre = tk.Label(text = "Genre:")
genre.pack(ipadx = 10, ipady = 10)
genre.place(x = initialX , y = initialY + 40)

rating = tk.Label(text = "Rating:")
rating.pack(ipadx = 10, ipady = 10)
rating.place(x = initialX, y = initialY + 80)

explicit = tk.Label(text = "Explicit:")
explicit.pack(ipadx = 10, ipady = 10)
explicit.place(x = initialX, y = initialY + 120)

keyword = tk.Label(text = "Keyword:")
keyword.pack(ipadx = 10, ipady = 10) 
keyword.place(x = initialX, y= initialY + 160)

language = tk.Label(text = "Language:")
language.pack(ipadx = 10, ipady = 10)
language.place(x = initialX, y = initialY + 200)

director = tk.Label(text = "Director:")
director.pack(ipadx = 10, ipady = 10)
director.place (x = initialX, y = initialY + 240)


window.mainloop()
