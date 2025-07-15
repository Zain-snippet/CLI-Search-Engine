# CLI-Search-Engine

# 🔍 CLI Search Engine (C++)

A simple command-line tool that indexes `.txt` files and lets you search words across them — like a mini offline search engine!

## ✅ Features

- Scans all `.txt` files in a folder
- Tokenizes and cleans text
- Builds inverted index (word → file → count)
- CLI menu to search any word
- Clean modular C++17 code

## 🛠 How to Run

1. Compile the code:
   ```bash
   g++ -std=c++17 main.cpp tokenizer.cpp -o search_engine
