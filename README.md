# FILM-INATOR5000

Utilized C++ to read 3 data files from IMDB 
  1) Title.akas.tsv.gz: used to find movies that were in the English language
  2) Title.basics.tsv.gz: used to find the movies titles, genres, and year of release
  3) Title.crew.tsv.gz: used to find the movie's director
  
All these components were pulled to create the movie itself, which was represented by a node. 

We used an adjacency list implementation of a graph to link similar movies together. We calculated how similar the movies are by implementing our own weight function. 
Our weight was 1/(Similarrity Score) because the more similar the two movies, the closer they should be. The similarity score was increased by 2.5 for every genre that matched, increased by 1 if the director was the same, increased by 1.0 if there was explicit language, and increased by 1.0 if the start years of the two movies were within 5 years. 

We also implemented a breadth-first search and depth-first search to offer the user two different sets of movies they could watch. 

Our demonstration youtube video: https://youtu.be/N-vT5hFnFzc

Our documentation document: https://docs.google.com/document/d/15PXHhbESUSJbPOADwFNM8dlTRsYGWaA7kPrqL5VTQxk/edit?usp=sharing



