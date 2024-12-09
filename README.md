# tutorato-programmazione1-24-25

Tutorato del corso di Programmazione 1 del professor Marco Roveri per l'A.A. 2024/25.

## Files

I file markdown possono essere compilati in PDF con [pandoc](https://pandoc.org/) (serve aver installato [TeX](https://tug.org/texlive/)!)

```sh
pandoc --metadata-file pandoc_metadata.yaml <file_in>.md -o <file_out>.pdf
```

da dentro la cartella:

```sh
pandoc --metadata-file ../pandoc_metadata.yaml <file_in>.md -o <file_out>.pdf
```

Alcuni file contengono immagini in `svg`. Il file `./12-10/graph.dot`, ad esempio, genera un'immagine `graph.svg` richiesta dal file di esercizi nella stessa cartella. Per generare tale immagine è necessario utilizzare [graphviz](https://graphviz.org/) con il comando

```sh
dot -Tsvg graph.dot -o graph.svg
```
