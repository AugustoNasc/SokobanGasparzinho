# Variáveis para os compiladores e as flags de compilação
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Variável para os diretórios de inclusão
INCLUDE_DIRS = -I../SFML-2.6.1-linux-gcc-64-bit/include

# Variável para as bibliotecas
LIBS = -L../SFML-2.6.1-linux-gcc-64-bit/lib -lsfml-graphics -lsfml-window -lsfml-system

# Nome do executável
EXEC = SokobanGasparzinho

# Arquivos objeto
OBJS = main.o

# Regra padrão
all: $(EXEC)

# Regra para o link dos arquivos objeto
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)

# Regra para a compilação dos arquivos fonte
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Regra para limpar os arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(EXEC)

